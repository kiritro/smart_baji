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
 * FileName : /baji_hal/src/hal_lcd.c
 * Author: Kiritro  Version: v0.1  Date: 2025/4/15
 * Description: Function introduction
 * ChangeLog: Change Notes
 *
***********************************************************/

/*********************************************************************
 * INCLUDES
 */
#include <stdlib.h>
#include <sys/cdefs.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_lcd_panel_interface.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_commands.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_check.h"
#include "driver/ledc.h"

#include "sys_log.h"
#include "hal_lcd.h"
#include "hal_nv3007.h"

/*********************************************************************
 * MACROS
 */
#define LCD_TAG                        "HAL_LCD"

#define LCD_SPI_NUM                   (SPI2_HOST)
#define LCD_PIXEL_CLK_HZ              (60 * 1000 * 1000)
#define LCD_CMD_BITS                  (8)
#define LCD_PARAM_BITS                (8)
#define LCD_SPI_MODE                  (0)
#define LCD_TRANS_QUEUE_DEPTH         (10)
#define LCD_COLOR_SPACE               (ESP_LCD_COLOR_SPACE_RGB)
#define LCD_BITS_PER_PIXEL            (16)
#define LCD_BL_ON_LEVEL               (1)

#define LCD_GPIO_SCLK                 (GPIO_NUM_48)
#define LCD_GPIO_MOSI                 (GPIO_NUM_47)
#define LCD_GPIO_RST                  (GPIO_NUM_12)
#define LCD_GPIO_DC                   (GPIO_NUM_13)
#define LCD_GPIO_CS                   (GPIO_NUM_14)
#define LCD_GPIO_BL                   (GPIO_NUM_21)

#define LEDC_TIMER                    LEDC_TIMER_0
#define LEDC_MODE                     LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL                  LEDC_CHANNEL_0
#define LEDC_DUTY_RES                 LEDC_TIMER_10_BIT            // Set duty resolution to 10 bits
#define LEDC_DUTY                     (500)                        // Set duty to 50%. ((2 ^ 10) - 1) * 50% = 500
#define LEDC_FREQUENCY                (20000)                      // Frequency in Hertz. Set frequency at 20 kHz
#define BRIGHTNESS_PWM_DUTY_MIN       (0)
#define BRIGHTNESS_PWM_DUTY_MAX       (1000)
#define BRIGHTNESS_PWM_DUTY_STEP      (int)(abs(BRIGHTNESS_PWM_DUTY_MAX - BRIGHTNESS_PWM_DUTY_MIN) / 100 )

/*********************************************************************
* TYPEDEFS
*/
typedef struct
{
    uint8_t brightness;  // lcd亮度值，范围通常为0到100
    esp_lcd_panel_io_handle_t lcd_io;
    esp_lcd_panel_handle_t lcd_panel;
} lcd_t;

/*********************************************************************
 * CONSTANTS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */
static lcd_t m_lcd = {80, NULL, NULL}; // 初始亮度值为80%

/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * LOCAL FUNCTIONS
 */
static esp_err_t lcd_panel_init(void);
static void lcd_brightness_init(void);

/*********************************************************************
 * GLOBAL FUNCTIONS
 */



void hal_lcd_init(void)
{
    lcd_panel_init();
    hal_lcd_set_brightness(m_lcd.brightness);
}

void hal_lcd_set_brightness(uint8_t brightness)
{
    if(brightness <= 100)
    {
        m_lcd.brightness = brightness;
        int set_duty = BRIGHTNESS_PWM_DUTY_STEP * m_lcd.brightness;
    
        if(set_duty > BRIGHTNESS_PWM_DUTY_MAX)
        {
            set_duty = BRIGHTNESS_PWM_DUTY_MAX;
        }
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, set_duty);
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
    }
}

uint8_t hal_lcd_get_brightness(void)
{
    return m_lcd.brightness;
}

void *hal_lcd_get_panel(void)
{
    return m_lcd.lcd_panel;
}

void *hal_lcd_get_io(void)
{
    return m_lcd.lcd_io;
}


static void lcd_brightness_init(void)
{
    ledc_timer_config_t ledc_timer =
    {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK
    };
    SYS_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    ledc_channel_config_t ledc_channel =
    {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LCD_GPIO_BL,
        .duty = LEDC_DUTY,
        .hpoint = 0
    };
    SYS_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

static esp_err_t lcd_panel_init(void)
{
    esp_err_t ret = ESP_OK;

    lcd_brightness_init();

    /* LCD initialization */
    ESP_LOGI(LCD_TAG, "Initialize SPI bus");
    const spi_bus_config_t buscfg =
    {
        .sclk_io_num = LCD_GPIO_SCLK,
        .mosi_io_num = LCD_GPIO_MOSI,
        .miso_io_num = GPIO_NUM_NC,
        .quadwp_io_num = GPIO_NUM_NC,
        .quadhd_io_num = GPIO_NUM_NC,
        .max_transfer_sz = LCD_H_RES * LCD_DRAW_BUFF_HEIGHT * sizeof(uint16_t) * 2,
    };
    ESP_RETURN_ON_ERROR(spi_bus_initialize(LCD_SPI_NUM, &buscfg, SPI_DMA_CH_AUTO), LCD_TAG, "SPI init failed");

    ESP_LOGI(LCD_TAG, "Install panel IO");
    const esp_lcd_panel_io_spi_config_t io_config =
    {
        .dc_gpio_num = LCD_GPIO_DC,
        .cs_gpio_num = LCD_GPIO_CS,
        .pclk_hz = LCD_PIXEL_CLK_HZ,
        .lcd_cmd_bits = LCD_CMD_BITS,
        .lcd_param_bits = LCD_PARAM_BITS,
        .spi_mode = LCD_SPI_MODE,
        .trans_queue_depth = LCD_TRANS_QUEUE_DEPTH,
    };
    ESP_GOTO_ON_ERROR(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_SPI_NUM, &io_config, &m_lcd.lcd_io), err, LCD_TAG, "New panel IO failed");

    ESP_LOGI(LCD_TAG, "Install LCD driver");
    const esp_lcd_panel_dev_config_t panel_config =
    {
        .reset_gpio_num = LCD_GPIO_RST,
        .color_space = LCD_COLOR_SPACE,
        .bits_per_pixel = LCD_BITS_PER_PIXEL,
    };
    ESP_GOTO_ON_ERROR(esp_lcd_new_panel_nv3007a(m_lcd.lcd_io, &panel_config, &m_lcd.lcd_panel), err, LCD_TAG, "New panel failed");

    ESP_ERROR_CHECK(esp_lcd_panel_reset(m_lcd.lcd_panel));
    ESP_ERROR_CHECK(esp_lcd_panel_init(m_lcd.lcd_panel));
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(m_lcd.lcd_panel, true));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(m_lcd.lcd_panel, true, false));
    ESP_ERROR_CHECK(esp_lcd_panel_set_gap(m_lcd.lcd_panel, 0, 14));
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(m_lcd.lcd_panel, false));

    return ret;

err:
    if (m_lcd.lcd_panel)
    {
        esp_lcd_panel_del(m_lcd.lcd_panel);
    }
    if (m_lcd.lcd_io)
    {
        esp_lcd_panel_io_del(m_lcd.lcd_io);
    }
    spi_bus_free(LCD_SPI_NUM);
    return ret;
}


