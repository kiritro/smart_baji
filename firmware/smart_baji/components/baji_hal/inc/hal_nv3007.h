#ifndef __HAL_NV3307_H__
#define __HAL_NV3307_H__


/*********************************************************************
 * INCLUDES
 */
#include "esp_lcd_panel_vendor.h"

/*********************************************************************
 * CPPMIX
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * MACROS
 */
/**
  * @brief LCD panel bus configuration structure
  *
  * @param[in] sclk SPI clock pin number
  * @param[in] mosi SPI MOSI pin number
  * @param[in] max_trans_sz Maximum transfer size in bytes
  *
  */
#define NV3007A_PANEL_BUS_SPI_CONFIG(sclk, mosi, max_trans_sz)  \
  {                                                           \
      .sclk_io_num = sclk,                                    \
      .mosi_io_num = mosi,                                    \
      .miso_io_num = -1,                                      \
      .quadhd_io_num = -1,                                    \
      .quadwp_io_num = -1,                                    \
      .max_transfer_sz = max_trans_sz,                        \
  }

/**
* @brief LCD panel IO configuration structure
*
* @param[in] cs SPI chip select pin number
* @param[in] dc SPI data/command pin number
* @param[in] cb Callback function when SPI transfer is done
* @param[in] cb_ctx Callback function context
*
*/
#define NV3007A_PANEL_IO_SPI_CONFIG(cs, dc, callback, callback_ctx) \
  {                                                               \
      .cs_gpio_num = cs,                                          \
      .dc_gpio_num = dc,                                          \
      .spi_mode = 0,                                              \
      .pclk_hz = 40 * 1000 * 1000,                                \
      .trans_queue_depth = 10,                                    \
      .on_color_trans_done = callback,                            \
      .user_ctx = callback_ctx,                                   \
      .lcd_cmd_bits = 8,                                          \
      .lcd_param_bits = 8,                                        \
  }

/*********************************************************************
* TYPEDEFS
*/
typedef struct
{
    int cmd;                /*<! The specific LCD command */
    const void *data;       /*<! Buffer that holds the command specific data */
    size_t data_bytes;      /*<! Size of `data` in memory, in bytes */
    unsigned int delay_ms;  /*<! Delay in milliseconds after this command */
} nv3007a_lcd_init_cmd_t;

typedef struct
{
    const nv3007a_lcd_init_cmd_t *init_cmds;     /*!< Pointer to initialization commands array. Set to NULL if using default commands.
                                                 *   The array should be declared as `static const` and positioned outside the function.
                                                 *   Please refer to `vendor_specific_init_default` in source file.
                                                 */
    uint16_t init_cmds_size;                    /*<! Number of commands in above array */
} nv3007a_vendor_config_t;

/*********************************************************************
 * CONSTANTS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */


/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * LOCAL FUNCTIONS
 */


/*********************************************************************
 * GLOBAL FUNCTIONS
 */
/**
 * @brief Create LCD panel for model nv3007a
 *
 * @note  Vendor specific initialization can be different between manufacturers, should consult the LCD supplier for initialization sequence code.
 *
 * @param[in] io LCD panel IO handle
 * @param[in] panel_dev_config general panel device configuration
 * @param[out] ret_panel Returned LCD panel handle
 * @return
 *          - ESP_ERR_INVALID_ARG   if parameter is invalid
 *          - ESP_ERR_NO_MEM        if out of memory
 *          - ESP_OK                on success
 */
extern esp_err_t esp_lcd_new_panel_nv3007a(const esp_lcd_panel_io_handle_t io, const esp_lcd_panel_dev_config_t *panel_dev_config, esp_lcd_panel_handle_t *ret_panel);


#ifdef __cplusplus
}
#endif

#endif /* __HAL_NV3307_H__ */
