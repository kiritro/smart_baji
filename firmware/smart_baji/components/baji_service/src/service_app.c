/***********************************************************
 *
 * MIT License
 *
 * Copyright (c) 2025 kiritro
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 * FileName : /baji_service/src/service_app.c
 * Author: Kiritro  Version: v0.1  Date: 2025/4/22
 * Description: Function introduction
 * ChangeLog: Change Notes
 *
***********************************************************/

/*********************************************************************
 * INCLUDES
 */
#include <string.h>

#include "sys_log.h"
#include "service_app.h"

/*********************************************************************
 * MACROS
 */
#define APP_TAG                        "SERVICE_APP"

/*********************************************************************
* TYPEDEFS
*/


/*********************************************************************
 * CONSTANTS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */
static app_config_t app_list[APP_ID_MAX];

/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * LOCAL FUNCTIONS
 */


/*********************************************************************
 * GLOBAL FUNCTIONS
 */



void service_app_init(void)
{

}

bool service_app_register(app_config_t *app_config)
{
    if (app_config->app_id < APP_ID_MAX && app_config != NULL)
    {
        memcpy(&app_list[app_config->app_id], app_config, sizeof(app_config_t));
        app_list[app_config->app_id].is_registered = true;
        return true;
    }
    else
    {
        sys_loge(APP_TAG, "app_id is out of range");
        return false;
    }
}

bool service_app_unregister(app_id_t app_id)
{
    if (app_id < APP_ID_MAX)
    {
        app_list[app_id].is_registered = false;
        return true;
    }
    else
    {
        sys_loge(APP_TAG, "app_id is out of range");
        return false;
    }
}


