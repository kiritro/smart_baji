#ifndef __HAL_LCD_H__
#define __HAL_LCD_H__


/*********************************************************************
 * INCLUDES
 */
#define LCD_H_RES                     (428)
#define LCD_V_RES                     (142)

#define LCD_DRAW_BUFF_DOUBLE          (1)
#define LCD_DRAW_BUFF_HEIGHT          (142)

/*********************************************************************
 * CPPMIX
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * MACROS
 */


/*********************************************************************
* TYPEDEFS
*/


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
 * @brief 初始化LCD硬件设备
 * 
 * 此函数用于对LCD硬件进行初始化操作，包括设置相关寄存器、初始化驱动等。
 * 调用此函数后，LCD设备将准备好接收后续的操作指令。
 */
extern void hal_lcd_init(void);

/**
 * @brief 设置LCD屏幕的亮度
 * 
 * @param brightness 亮度值，范围为0 - 100，数值越大亮度越高
 */
extern void hal_lcd_set_brightness(uint8_t brightness);

/**
 * @brief 获取LCD屏幕当前的亮度值
 * 
 * @return uint8_t 当前LCD屏幕的亮度值，范围为0 - 255
 */
extern uint8_t hal_lcd_get_brightness(void);

/**
 * @brief 获取LCD面板的指针
 * 
 * @return void* 指向LCD面板的指针，可用于后续对面板的操作
 */
extern void *hal_lcd_get_panel(void);

/**
 * @brief 获取LCD IO接口的指针
 * 
 * @return void* 指向LCD IO接口的指针，可用于对LCD的输入输出操作
 */
extern void *hal_lcd_get_io(void);


#ifdef __cplusplus
}
#endif

#endif /* __HAL_LCD_H__ */
