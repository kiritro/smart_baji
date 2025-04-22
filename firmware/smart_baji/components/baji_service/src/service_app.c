/***********************************************************
 *
 * MIT License
 *
 * Copyright (c) 2025 kiritro
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 * FileName : /baji_service/src/service_app.c
 * Author: Kiritro  Version: v0.1  Date: 2025/4/22
 * Description: Function introduction
 * ChangeLog: Change Notes
 *
***********************************************************/

/*********************************************************************
 * INCLUDES
 */
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include "sys_log.h"
#include "service_app.h"

/*********************************************************************
 * MACROS
 */
#define APP_TAG                        "SERVICE_APP"

#define APP_TASK_STACK_SIZE            (4096)
#define APP_TASK_PRIORITY              (2)
#define APP_TASK_NAME                  "APP_TASK"

#define APP_MSG_QUEUE_LENGTH           (20)
#define APP_MSG_QUEUE_ITEM_SIZE        sizeof(app_msg_t)
#define APP_FUNCS_TIMER_TICKS          pdMS_TO_TICKS(100) //100mS

/*********************************************************************
* TYPEDEFS
*/
typedef struct
{
    app_id_t app_id;
    void (*func)(void);
} app_msg_t;

/*********************************************************************
 * CONSTANTS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */
static app_config_t app_list[APP_ID_MAX];

static TaskHandle_t m_app_task_hdl = NULL;
static QueueHandle_t m_app_msg_hdl = NULL;
static TimerHandle_t app_timer;

/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * LOCAL FUNCTIONS
 */
 static void app_task_handle(void *pvParameters);
 static void app_timer_callback(TimerHandle_t xTimer);
 static void app_task_init(void);
 static void app_msg_send(void *msg, bool in_isr);

/*********************************************************************
 * GLOBAL FUNCTIONS
 */



void service_app_init(void)
{
    app_task_init();
}

bool service_app_register(app_config_t *app_config)
{
    if (app_config->app_id < APP_ID_MAX && app_config != NULL)
    {
        memcpy(&app_list[app_config->app_id], app_config, sizeof(app_config_t));
        app_list[app_config->app_id].is_registered = true;
        return true;
    }
    else
    {
        sys_loge(APP_TAG, "app_id is out of range");
        return false;
    }
}

bool service_app_unregister(app_id_t app_id)
{
    if (app_id < APP_ID_MAX)
    {
        app_list[app_id].is_registered = false;
        return true;
    }
    else
    {
        sys_loge(APP_TAG, "app_id is out of range");
        return false;
    }
}


static void app_task_init(void)
{
    if(m_app_task_hdl == NULL)
    {
        if ( pdPASS != xTaskCreate( app_task_handle, APP_TASK_NAME, APP_TASK_STACK_SIZE, NULL, APP_TASK_PRIORITY, NULL ))
        {
            sys_loge(APP_TAG, "app task create error!");
        }
    }
}

static void app_task_handle(void *pvParameters)
{
    m_app_msg_hdl = xQueueCreate( APP_MSG_QUEUE_LENGTH, APP_MSG_QUEUE_ITEM_SIZE );
    SYS_ERROR_CHECK(m_app_msg_hdl == NULL);

    app_timer = xTimerCreate("app_timer", APP_FUNCS_TIMER_TICKS, pdTRUE, NULL, app_timer_callback);
    xTimerStart(app_timer, 0);
  
    for(;;)
    {
        app_msg_t msg;
        SYS_ERROR_CHECK( xQueueReceive( m_app_msg_hdl, (void *const)&msg, portMAX_DELAY ) != pdPASS );

        if(msg.app_id < APP_ID_MAX && msg.func != NULL)
        {
            msg.func();
            sys_logd(APP_TAG, "app_id: %d", msg.app_id);
        }
    }
}

static void app_timer_callback(TimerHandle_t xTimer)
{
    for (int i = 0; i < APP_ID_MAX; i++)
    {
        if (app_list[i].is_registered)
        {
            // 后台任务统一调度，降低系统开销
            if(app_list[i].background_task.allow_background && app_list[i].background_task.func!= NULL)
            {
                if(app_list[i].background_task.interval_calc >= app_list[i].background_task.execution_interval)
                {
                    app_msg_t msg = {.app_id = i, .func = app_list[i].background_task.func};
                    app_msg_send(&msg, 0);
                    app_list[i].background_task.interval_calc = 0;
                }
                else
                {
                    app_list[i].background_task.interval_calc += APP_FUNCS_TIMER_TICKS;
                }   
            }
            
            // 轻量前台任务使用统一调度，复杂任务建议独立task处理
            if(app_list[i].foreground_task.is_running && app_list[i].foreground_task.type == APP_FOREGROUND_TASK_TIMED && app_list[i].foreground_task.func!= NULL)
            {
                if(app_list[i].foreground_task.interval_calc >= app_list[i].foreground_task.execution_interval)
                {
                    app_msg_t msg = {.app_id = i,.func = app_list[i].foreground_task.func};
                    app_msg_send(&msg, 0);
                    app_list[i].foreground_task.interval_calc = 0;
                }
                else
                {
                    app_list[i].foreground_task.interval_calc += APP_FUNCS_TIMER_TICKS;
                }
            }
        }
    }
}

static void app_msg_send(void *msg, bool in_isr)
{
    if(m_app_msg_hdl != NULL)
    {
        if(in_isr == 0)
        {
            SYS_ERROR_CHECK((xQueueSend(m_app_msg_hdl, msg, portMAX_DELAY) != pdPASS));
        }
        else
        {
            BaseType_t xHigherPriorityTaskWoken;
            xHigherPriorityTaskWoken = pdFALSE;
            xQueueSendFromISR( m_app_msg_hdl, msg, &xHigherPriorityTaskWoken );
            portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
        }
    }
}


