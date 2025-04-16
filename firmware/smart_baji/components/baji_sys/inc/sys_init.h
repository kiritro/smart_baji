#ifndef __SYS_INIT_H__
#define __SYS_INIT_H__


/*********************************************************************
 * INCLUDES
 */


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
 * @brief 初始化系统的全局函数声明
 * 
 * 该函数用于执行系统的初始化操作，包括但不限于硬件初始化、全局变量初始化等。
 * 具体的初始化逻辑在函数定义处实现。
 * 
 * @return void 该函数无返回值
 */
extern void sys_init(void);


#ifdef __cplusplus
}
#endif

#endif /* __SYS_INIT_H__ */
