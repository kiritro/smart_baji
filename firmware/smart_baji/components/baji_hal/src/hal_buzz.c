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
 * FileName : baji_hal/buzz_tag.c
 * Author: Kiritro  Version: v0.1  Date: 2025/4/7
 * Description: Function introduction
 * ChangeLog: Change Notes
 *
***********************************************************/

/*********************************************************************
 * INCLUDES
 */
#include "driver/ledc.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include "sys_log.h"
#include "hal_buzz.h"

/*********************************************************************
 * MACROS
 */
#define BUZZ_TAG                     "HAL_BUZZ"
#define BUZZ_QUEUE_SIZE              (10)
#define BUZZ_STACK_SIZE              (4096)
#define BUZZ_DEFAUT_FREQUENCY        (2500)

#define BUZZ_GPIO_NUM                GPIO_NUM_18
#define BUZZ_CLK_CFG                 LEDC_AUTO_CLK
#define BUZZ_SPEED_MODE              LEDC_LOW_SPEED_MODE
#define BUZZ_TIMER_BIT               LEDC_TIMER_13_BIT
#define BUZZ_TIMER_NUM               LEDC_TIMER_0
#define BUZZ_CHANNEL                 LEDC_CHANNEL_0
#define BUZZ_IDLE_LEVEL              (0)


/*********************************************************************
* TYPEDEFS
*/
typedef struct
{
    uint32_t frequency;
    uint32_t duration_ms;
} buzzer_message_t;

typedef struct
{
    TaskHandle_t task_handle;
    QueueHandle_t queue_handle;
    ledc_mode_t speed_mode;
    ledc_timer_bit_t timer_bit;
    ledc_timer_t timer_num;
    ledc_channel_t channel;
    uint32_t idle_level;
} buzzer_t;


/*********************************************************************
 * CONSTANTS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */
static buzzer_t *m_buzzer = NULL;


/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * LOCAL FUNCTIONS
 */
static void buzzer_stop(buzzer_t *buzzer);
static void buzzer_start(buzzer_t *buzzer, uint32_t frequency);
static void buzzer_task(void *param);
static void buzzer_destroy(buzzer_t *buzzer);
static void buzzer_beep(buzzer_t *buzzer, uint32_t frequency, uint32_t duration_ms);
static buzzer_t *buzzer_create(gpio_num_t gpio_num,
                               ledc_clk_cfg_t clk_cfg,
                               ledc_mode_t speed_mode,
                               ledc_timer_bit_t timer_bit,
                               ledc_timer_t timer_num,
                               ledc_channel_t channel,
                               uint32_t idle_level);

/*********************************************************************
 * GLOBAL FUNCTIONS
 */



/**
* @brief 初始化蜂鸣器硬件
*
* 此函数用于初始化蜂鸣器所需的硬件资源，如GPIO、定时器等。
* 调用此函数后，蜂鸣器将处于可使用状态。
*/
void hal_buzz_init(void)
{
    m_buzzer = buzzer_create(BUZZ_GPIO_NUM, BUZZ_CLK_CFG, BUZZ_SPEED_MODE, BUZZ_TIMER_BIT, BUZZ_TIMER_NUM, BUZZ_CHANNEL, BUZZ_IDLE_LEVEL);

    sys_logi(BUZZ_TAG, "buzz init");

    if (m_buzzer == NULL)
    {
        sys_loge(BUZZ_TAG, "Failed to create buzzer");
    }
    else
    {
        hal_buzz_set(2000, 500); // 测试蜂鸣器
    }
}

/**
 * @brief 设置蜂鸣器的频率和持续时间
 *
 * 此函数用于设置蜂鸣器的发声频率和持续时间。
 * @param frequency 蜂鸣器的发声频率，单位为Hz
 * @param duration_ms 蜂鸣器的发声持续时间，单位为毫秒
 */
void hal_buzz_set(uint32_t frequency, uint32_t duration_ms)
{
    if (m_buzzer != NULL)
    {
        buzzer_beep(m_buzzer, frequency, duration_ms);
    }
}


static void buzzer_stop(buzzer_t *buzzer)
{
    esp_err_t err = ledc_set_duty(buzzer->speed_mode, buzzer->channel, 0);
    if (err != ESP_OK)
    {
        sys_loge(BUZZ_TAG, "Failed to set duty cycle to zero");
    }
    err = ledc_update_duty(buzzer->speed_mode, buzzer->channel);
    if (err != ESP_OK)
    {
        sys_loge(BUZZ_TAG, "Failed to update duty cycle");
    }
    err = ledc_stop(buzzer->speed_mode, buzzer->channel, buzzer->idle_level);
    if (err != ESP_OK)
    {
        sys_loge(BUZZ_TAG, "Failed to stop buzzer");
    }
}

static void buzzer_start(buzzer_t *buzzer, uint32_t frequency)
{
    uint32_t duty = (1 << buzzer->timer_bit) / 2;

    esp_err_t err = ledc_set_duty(buzzer->speed_mode, buzzer->channel, duty);
    if (err != ESP_OK)
    {
        sys_loge(BUZZ_TAG, "Failed to set duty cycle");
        return;
    }
    err = ledc_update_duty(buzzer->speed_mode, buzzer->channel);
    if (err != ESP_OK)
    {
        sys_loge(BUZZ_TAG, "Failed to update duty cycle");
        return;
    }
    err = ledc_set_freq(buzzer->speed_mode, buzzer->timer_num, frequency);
    if (err != ESP_OK)
    {
        sys_loge(BUZZ_TAG, "Failed to set frequency");
        return;
    }
}

static void buzzer_task(void *param)
{
    buzzer_t *buzzer = (buzzer_t *)param;
    buzzer_message_t message;
    TickType_t waitTime = portMAX_DELAY;

    for(;;)
    {
        BaseType_t res = xQueueReceive(buzzer->queue_handle, &message, waitTime);
        if (res != pdPASS)
        {
            sys_logd(BUZZ_TAG, "No new message, Stop beeping");
            buzzer_stop(buzzer);
            waitTime = portMAX_DELAY;
        }
        else
        {
            sys_logd(BUZZ_TAG,
                     "Beep at %" PRIu32 " Hz for %" PRIu32 " ms",
                     message.frequency,
                     message.duration_ms);
            buzzer_start(buzzer, message.frequency);
            waitTime = pdMS_TO_TICKS(message.duration_ms);
        }
    }
}

static buzzer_t *buzzer_create(gpio_num_t gpio_num,
                        ledc_clk_cfg_t clk_cfg,
                        ledc_mode_t speed_mode,
                        ledc_timer_bit_t timer_bit,
                        ledc_timer_t timer_num,
                        ledc_channel_t channel,
                        uint32_t idle_level)
{
    buzzer_t *buzzer = (buzzer_t *)malloc(sizeof(buzzer_t));
    if (buzzer == NULL)
    {
        return NULL;
    }

    buzzer->speed_mode = speed_mode;
    buzzer->timer_bit = timer_bit;
    buzzer->timer_num = timer_num;
    buzzer->channel = channel;
    buzzer->idle_level = idle_level;

    ledc_timer_config_t ledc_timer =
    {
        .speed_mode = speed_mode,
        .timer_num = timer_num,
        .duty_resolution = timer_bit,
        .freq_hz = BUZZ_DEFAUT_FREQUENCY,
        .clk_cfg = clk_cfg
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    ledc_channel_config_t ledc_channel =
    {
        .speed_mode = speed_mode,
        .channel = channel,
        .timer_sel = timer_num,
        .gpio_num = gpio_num,
        .duty = 0,
        .hpoint = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
    ESP_ERROR_CHECK(ledc_stop(speed_mode, channel, idle_level));

    buzzer->queue_handle = xQueueCreate(BUZZ_QUEUE_SIZE, sizeof(buzzer_message_t));
    BaseType_t res = xTaskCreate(buzzer_task, "buzz_task", BUZZ_STACK_SIZE,
                                 buzzer, uxTaskPriorityGet(NULL), &buzzer->task_handle);
    if (res != pdPASS)
    {
        vQueueDelete(buzzer->queue_handle);
        free(buzzer);
        return NULL;
    }
    return buzzer;
}

static void buzzer_destroy(buzzer_t *buzzer)
{
    if (buzzer != NULL)
    {
        vQueueDelete(buzzer->queue_handle);
        vTaskDelete(buzzer->task_handle);
        free(buzzer);
    }
}

static void buzzer_beep(buzzer_t *buzzer, uint32_t frequency, uint32_t duration_ms)
{
    if (buzzer != NULL)
    {
        buzzer_message_t message =
        {
            .frequency = frequency,
            .duration_ms = duration_ms,
        };
        xQueueSend(buzzer->queue_handle, &message, 0);
    }
}
