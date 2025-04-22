#ifndef __SERVICE_APP_H__
#define __SERVICE_APP_H__


/*********************************************************************
 * INCLUDES
 */
#include "esp_lvgl_port.h"

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
typedef enum
{
    APP_SYS_MONITOR = 0,
    APP_USER_PIXEL,
    APP_USER_BAJI,
    APP_USER_STEP_COUNTER,
    APP_USER_FLASHLIGHT,
    APP_USER_RGB,
    APP_SYS_SETTINGS,

    APP_ID_MAX,
} app_id_t;

typedef enum
{
    APP_TYPE_SYSTEM,  // 系统app类型
    APP_TYPE_USER,    // 用户app类型
} app_type_t;

typedef struct
{
    bool allow_background;        // 是否允许后台运行
    void (*func)(void);           // 后台任务回调函数(后台服务统一管理)
    uint32_t execution_interval;  // 后台任务定时执行时间，单位：毫秒 最小100ms
    uint32_t interval_calc;
} app_background_task_t;

typedef enum
{
    APP_FOREGROUND_TASK_TIMED,  // 定时任务
    APP_FOREGROUND_TASK_CUSTOM, // 自定义任务
} app_foreground_task_type_t;

typedef struct
{
    bool is_running;                    // app是否正在前台运行
    app_foreground_task_type_t type;    // 任务类型
    void (*func)(void);                 // 定时任务回调函数
    uint32_t execution_interval;        // 定时任务执行时间，单位：毫秒 最小100ms
    uint32_t interval_calc;
} app_foreground_task_t;

typedef struct
{
    bool allow_indev_group;                     // 是否允许输入设备分组
    lv_obj_t *main_control;                     // 主屏幕对象指针
    void (*mian_control_init)(void);            // 主屏幕控件初始化
    void (*mian_control_event)(lv_event_t *e);  // 主屏幕事件处理函数指针 -> 单击进入app页面(内部响应事件码)
    // lv_event_code_t enter_event_coder;          // 进入app页面的事件码
    // lv_event_code_t setting_event_coder;        // 设置app页面的事件码
} app_ui_main_control_t;

typedef struct
{
    bool is_registered;  // app是否已注册，true:已注册，false:未注册
    app_id_t app_id;
    app_type_t app_type;
    app_background_task_t background_task;
    app_foreground_task_t foreground_task;
    app_ui_main_control_t ui_main_control;
    void (*app_init)(void);    // app初始化函数指针
    void (*app_deinit)(void);  // app反初始化函数指针
} app_config_t;

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
extern void service_app_init(void);
extern bool service_app_register(app_config_t *app_config);
extern bool service_app_unregister(app_id_t app_id);


#ifdef __cplusplus
}
#endif

#endif /* __SERVICE_APP_H__ */
