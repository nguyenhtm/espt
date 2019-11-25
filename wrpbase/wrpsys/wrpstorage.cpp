/********************************************************************************************************
 * @File  : wrpstorage.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpstorage.hpp"

namespace WrpSys {
namespace Storage {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

void InitNVS()
{
	WRPPRINT("%s\n", "WrpSys::Storage::InitNVS() Begin");
#if USE_ESP_IDF
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
    	nvs_flash_erase();
    	ret = nvs_flash_init();
    }
#endif
	WRPPRINT("%s\n", "WrpSys::Storage::InitNVS() End");
}

} /* Namespace Storage */
} /* Namespace WrpSys */
