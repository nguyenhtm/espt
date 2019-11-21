/*
 * File  : wrpstorage.cpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpstorage.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpSys {
namespace WrpSysStorage {

void InitNVS()
{
	WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::InitNVS() Begin");
#if USE_ESP_IDF
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
    	nvs_flash_erase();
    	ret = nvs_flash_init();
    }
#endif
	WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::InitNVS() End");
}

} /* Namespace WrpSysStorage */
} /* Namespace WrpSys */
