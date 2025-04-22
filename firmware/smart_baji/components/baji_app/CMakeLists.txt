# 查找所有子目录的src/*.c文件
file(GLOB component_srcs 
    "app/src/*.c"
    "app_baji/src/*.c" 
    "app_flashlight/src/*.c"
    "app_monitor/src/*.c"
    "app_pixel/src/*.c"
    "app_rgb/src/*.c" 
    "app_settings/src/*.c"
    "app_step_counter/src/*.c")

# 自动包含所有子目录的inc路径
file(GLOB component_incs 
    "app/inc"
    "app_baji/inc"
    "app_flashlight/inc" 
    "app_monitor/inc"
    "app_pixel/inc"
    "app_rgb/inc"
    "app_settings/inc"
    "app_step_counter/inc")

set(requires baji_sys baji_service)

idf_component_register(SRCS ${srcs} ${component_srcs}
                       INCLUDE_DIRS ${component_incs}
                       REQUIRES ${requires}
                      )