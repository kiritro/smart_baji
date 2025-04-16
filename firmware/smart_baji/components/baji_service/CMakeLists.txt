set(srcs "src/service_init.c"
         "src/service_display.c"
         )

set(public_include "inc")

set(requires baji_hal baji_sys )

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS ${public_include}
                       REQUIRES ${requires}
                      )