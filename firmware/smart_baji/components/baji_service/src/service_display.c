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
 * FileName : /baji_service/src/service_display.c
 * Author: Kiritro  Version: v0.1  Date: 2025/4/16
 * Description: Function introduction
 * ChangeLog: Change Notes
 *
***********************************************************/

/*********************************************************************
 * INCLUDES
 */
#include <stdlib.h>
#include <sys/cdefs.h>
#include "esp_log.h"
#include "esp_check.h"
#include "esp_lvgl_port.h"

#include "lv_demos.h"

#include "sys_log.h"
#include "hal_lcd.h"
#include "hal_encoder.h"
#include "service_display.h"

/*********************************************************************
 * MACROS
 */
#define DISPLAY_TAG                        "SERVICE_DISP"

#define LVGL_TASK_PRIORITY                (4)
#define LVGL_TASK_STACK                   (8192)
#define LVGL_TASK_AFFINITY                (-1)
#define LVGL_TASK_MAX_SLEEP_MS            (500)
#define LVGL_TIMER_PERIOD_MS              (5)

/*********************************************************************
* TYPEDEFS
*/


/*********************************************************************
 * CONSTANTS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */
static lv_disp_t *lvgl_disp = NULL;
static lv_indev_t *indev_encoder = NULL;
static lv_group_t * lvgl_group = NULL;

/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * LOCAL FUNCTIONS
 */
static esp_err_t service_lvgl_init(void);
static void lvgl_port_encoder_read(lv_indev_t *indev_drv, lv_indev_data_t *data);

/*********************************************************************
 * GLOBAL FUNCTIONS
 */



void service_display_init(void)
{
    service_lvgl_init();

    lvgl_port_lock(0);
    lv_demo_widgets();
    lvgl_port_unlock();
}


static esp_err_t service_lvgl_init(void)
{
    const lvgl_port_cfg_t lvgl_cfg =
    {
        .task_priority = LVGL_TASK_PRIORITY,         /* LVGL task priority */
        .task_stack = LVGL_TASK_STACK,         /* LVGL task stack size */
        .task_affinity = LVGL_TASK_AFFINITY,        /* LVGL task pinned to core (-1 is no affinity) */
        .task_max_sleep_ms = LVGL_TASK_MAX_SLEEP_MS,   /* Maximum sleep in LVGL task */
        .timer_period_ms = LVGL_TIMER_PERIOD_MS        /* LVGL timer tick period in ms */
    };
    ESP_RETURN_ON_ERROR(lvgl_port_init(&lvgl_cfg), DISPLAY_TAG, "LVGL port initialization failed");

    sys_logi(DISPLAY_TAG, "Add LCD screen");
    const lvgl_port_display_cfg_t disp_cfg =
    {
        .io_handle = hal_lcd_get_io(),
        .panel_handle = hal_lcd_get_panel(),
        .buffer_size = LCD_H_RES * LCD_DRAW_BUFF_HEIGHT * sizeof(uint16_t),
        .double_buffer = LCD_DRAW_BUFF_DOUBLE,
        .hres = LCD_H_RES,
        .vres = LCD_V_RES,
        .monochrome = false,
        .rotation = {
            .swap_xy = true,
            .mirror_x = true,
            .mirror_y = false,
        },
        .flags = {
            .buff_dma = true,
            .swap_bytes = true,
            .buff_spiram = true,
        }
    };
    lvgl_disp = lvgl_port_add_disp(&disp_cfg);

    lvgl_group = lv_group_create();
    lv_group_set_default(lvgl_group);

    indev_encoder = lv_indev_create();
    lv_indev_set_type(indev_encoder, LV_INDEV_TYPE_ENCODER);
    lv_indev_set_read_cb(indev_encoder, lvgl_port_encoder_read);
    // lv_indev_set_disp(indev_encoder, lvgl_disp);
    lv_indev_set_group(indev_encoder, lvgl_group);

    return ESP_OK;
}

static void lvgl_port_encoder_read(lv_indev_t *indev_drv, lv_indev_data_t *data)
{
    encoder_press_type_t state = hal_encoder_get_press();

    if(state == ENCODER_PRESS_UP)
    {
        data->enc_diff++;
        // sys_logi(DISPLAY_TAG, "enc_diff: %d", data->enc_diff);
    }
    else if(state == ENCODER_PRESS_DOWN)
    {
        data->enc_diff--;
        // sys_logi(DISPLAY_TAG, "enc_diff: %d", data->enc_diff);
    }
    else if(state == ENCODER_PRESS_PRESSED)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        // sys_logi(DISPLAY_TAG, "state: %d", data->state);
    }
    else if(state == ENCODER_PRESS_NONE)
    {   
        data->state = LV_INDEV_STATE_RELEASED;
        data->enc_diff = 0;
    }
}
