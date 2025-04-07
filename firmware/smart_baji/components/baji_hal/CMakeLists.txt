set(srcs "src/hal_init.c"
         "src/hal_encoder.c"
         "src/hal_buzz.c"
         "src/hal_bat.c"
         "src/hal_led.c"
         "src/hal_sd.c"
         )

set(public_include "inc")

set(requires baji_sys led_strip driver fatfs esp_adc)

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS ${public_include}
                       REQUIRES ${requires}
                      )