set(srcs "src/hal_init.c"
         "src/hal_encoder.c"
         "src/hal_buzzer.c"
         "src/hal_bat.c"
         "src/hal_led.c"
         "src/hal_lcd.c"
         "src/hal_sd.c"
         "src/hal_nv3007.c"
         )

set(public_include "inc")

set(requires baji_sys led_strip driver fatfs esp_adc button)

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS ${public_include}
                       REQUIRES ${requires}
                      )