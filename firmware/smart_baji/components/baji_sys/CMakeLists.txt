set(srcs "src/sys_init.c"
         )

set(public_include "inc")

set(requires baji_hal baji_ui baji_service baji_app)

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS ${public_include}
                       REQUIRES ${requires}
                      )