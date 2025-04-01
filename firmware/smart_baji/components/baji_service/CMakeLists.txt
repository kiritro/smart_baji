set(srcs "")

set(public_include "inc")

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS ${public_include}
                       REQUIRES 
                      )