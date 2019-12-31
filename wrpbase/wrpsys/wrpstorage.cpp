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
uint32_t m_uStorageStatus = STORAGE_STATUS_INIT;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

bool InitNVS()
{
	WRPPRINT("%s\n", "WrpSys::Storage::InitNVS() Begin");
#if USE_ESP_IDF
	// A ESP32 Flash contains multiple apps and different kinds of data,
	// a partition table is flashed to 0x8000 in this Flash
	// a data region defined in the partition table with labeled 'nvs' for storing NVS library partition
    esp_err_t ret = ESP_OK;

	// initialize the default NVS partition
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        // NVS partition with label "nvs" was truncated and needs to be erased
    	ret = nvs_flash_erase();
    	if (ret == ESP_ERR_NOT_FOUND)
    	{
    		WRPPRINT("%s\n", "WrpSys::Storage::InitNVS() No NVS partition in the partition table!");
    		return false;
    	}

        // Retry nvs_flash_init
    	ret = nvs_flash_init();
    	if (ret != ESP_OK)
    	{
    		WRPPRINT("%s\n", "WrpSys::Storage::InitNVS() Retry failed!");
    		return false;
    	}
    }
#endif
    m_uStorageStatus |= STORAGE_STATUS_INITNVS;
	WRPPRINT("%s\n", "WrpSys::Storage::InitNVS() End");
	return true;
}

void DeInitNVS()
{
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitNVS() Begin");
#if USE_ESP_IDF
    esp_err_t ret = ESP_OK;

	// deinitialize the default NVS partition
    ret = nvs_flash_deinit();
    if (ret == ESP_ERR_NVS_NOT_INITIALIZED)
    {
   		WRPPRINT("%s\n", "WrpSys::Storage::DeInitNVS() NVS partition was not initialized!");
    }
#endif
    m_uStorageStatus &= ~STORAGE_STATUS_INITNVS;
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitNVS() End");
}

bool InitSPIFFS()
{
	WRPPRINT("%s\n", "WrpSys::Storage::InitSPIFFS() Begin");
#if USE_ESP_IDF
	// A ESP32 Flash contains multiple apps and different kinds of data,
	// a partition table is flashed to 0x8000 in this Flash
	// a data region defined in the partition table storing SPIFFS partition
    esp_err_t ret = ESP_OK;
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };

	// initialize and mount SPIFFS filesystem to VFS
    ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
    		WRPPRINT("%s\n", "WrpSys::Storage::InitSPIFFS() Failed to mount or format filesystem!");
        }
        else if (ret == ESP_ERR_NOT_FOUND)
        {
    		WRPPRINT("%s\n", "WrpSys::Storage::InitSPIFFS() Failed to find SPIFFS partition!");
        }
        else
        {
    		WRPPRINT("%s%s\n", "WrpSys::Storage::InitSPIFFS() Failed to initialize SPIFFS! ", esp_err_to_name(ret));
        }
        return false;
    }
#endif
    m_uStorageStatus |= STORAGE_STATUS_INITSPIFFS;
	WRPPRINT("%s\n", "WrpSys::Storage::InitSPIFFS() End");
	return true;
}

void DeInitSPIFFS()
{
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitSPIFFS() Begin");
#if USE_ESP_IDF
    // All done, unmount partition and disable SPIFFS
    esp_err_t ret = esp_vfs_spiffs_unregister(NULL); // 1st partition with subtype=spiffs is used
    if (ret == ESP_ERR_INVALID_STATE)
    {
   		WRPPRINT("%s\n", "WrpSys::Storage::DeInitNVS() SPIFFS partition already unregistered!");
   		return;
    }
#endif
    m_uStorageStatus &= ~STORAGE_STATUS_INITSPIFFS;
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitSPIFFS() End");
}

bool InitSDCard()
{
	WRPPRINT("%s\n", "WrpSys::Storage::InitSDCard() Begin");
    m_uStorageStatus |= STORAGE_STATUS_INITSDCARD;
	WRPPRINT("%s\n", "WrpSys::Storage::InitSDCard() End");
	return true;
}

void DeInitSDCard()
{
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitSDCard() Begin");
    m_uStorageStatus &= ~STORAGE_STATUS_INITSDCARD;
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitSDCard() End");
}

} /* Namespace Storage */
} /* Namespace WrpSys */
