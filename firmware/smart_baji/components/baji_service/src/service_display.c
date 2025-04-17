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

/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * LOCAL FUNCTIONS
 */
static esp_err_t service_lvgl_init(void);

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
    /* Initialize LVGL */
    const lvgl_port_cfg_t lvgl_cfg =
    {
        .task_priority = LVGL_TASK_PRIORITY,         /* LVGL task priority */
        .task_stack = LVGL_TASK_STACK,         /* LVGL task stack size */
        .task_affinity = LVGL_TASK_AFFINITY,        /* LVGL task pinned to core (-1 is no affinity) */
        .task_max_sleep_ms = LVGL_TASK_MAX_SLEEP_MS,   /* Maximum sleep in LVGL task */
        .timer_period_ms = LVGL_TIMER_PERIOD_MS        /* LVGL timer tick period in ms */
    };
    ESP_RETURN_ON_ERROR(lvgl_port_init(&lvgl_cfg), DISPLAY_TAG, "LVGL port initialization failed");

    /* Add LCD screen */
    ESP_LOGI(DISPLAY_TAG, "Add LCD screen");
    const lvgl_port_display_cfg_t disp_cfg =
    {
        .io_handle = hal_lcd_get_io(),
        .panel_handle = hal_lcd_get_panel(),
        .buffer_size = LCD_H_RES * LCD_DRAW_BUFF_HEIGHT * sizeof(uint16_t),
        .double_buffer = LCD_DRAW_BUFF_DOUBLE,
        .hres = LCD_H_RES,
        .vres = LCD_V_RES,
        .monochrome = false,
        /* Rotation values must be same as used in esp_lcd for initial settings of the screen */
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

    // /* key pad init */
    // static lv_indev_drv_t keypad_drv;
    // lv_indev_drv_init(&keypad_drv);

    // keypad_drv.type = LV_INDEV_TYPE_KEYPAD;
    // keypad_drv.read_cb = keypad_read;
    // indev_keypad = lv_indev_drv_register(&keypad_drv);
    // group = lv_group_create();
    // lv_indev_set_group(indev_keypad, group);

    return ESP_OK;
}

