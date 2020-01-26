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

#define PIN_NUM_MISO 2
#define PIN_NUM_MOSI 15
#define PIN_NUM_CLK  14
#define PIN_NUM_CS   13

bool InitSDCard()
{
	WRPPRINT("%s\n", "WrpSys::Storage::InitSDCard() Begin");
#if USE_ESP_IDF
	/*
	WRPPRINT("%s\n", "WrpSys::Storage::InitSDCard() Using SPI peripheral");
	// SPI is using by LVGL display
    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    host.max_freq_khz = SDMMC_FREQ_PROBING;

    sdspi_slot_config_t slot_config = SDSPI_SLOT_CONFIG_DEFAULT();
    slot_config.gpio_miso = (gpio_num_t)PIN_NUM_MISO;
    slot_config.gpio_mosi = (gpio_num_t)PIN_NUM_MOSI;
    slot_config.gpio_sck  = (gpio_num_t)PIN_NUM_CLK;
    slot_config.gpio_cs   = (gpio_num_t)PIN_NUM_CS;
    */

 	WRPPRINT("%s\n", "WrpSys::Storage::InitSDCard() Using SDMMC peripheral");
    gpio_pullup_en((gpio_num_t)12); // must pull up this resistor
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();
 	host.max_freq_khz = SDMMC_FREQ_PROBING;
 	host.flags = SDMMC_HOST_FLAG_1BIT;

 	sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
    // To use 1-line SD mode, uncomment the following line:
    //slot_config.width = 1;

	    // GPIOs 15, 2, 4, 12, 13 should have external 10k pull-ups.
	    // Internal pull-ups are not sufficient. However, enabling internal pull-ups
	    // does make a difference some boards, so we do that here.
	    gpio_set_pull_mode((gpio_num_t)15, GPIO_PULLUP_ONLY);   // CMD, needed in 4- and 1- line modes
	    gpio_set_pull_mode((gpio_num_t)2, GPIO_PULLUP_ONLY);    // D0, needed in 4- and 1-line modes
	    gpio_set_pull_mode((gpio_num_t)4, GPIO_PULLUP_ONLY);    // D1, needed in 4-line mode only
	    gpio_set_pull_mode((gpio_num_t)12, GPIO_PULLUP_ONLY);   // D2, needed in 4-line mode only
	    gpio_set_pull_mode((gpio_num_t)13, GPIO_PULLUP_ONLY);

    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 4 * 1024
    };

    // Use settings defined above to initialize SD card and mount FAT filesystem.
    // Note: esp_vfs_fat_sdmmc_mount is an all-in-one convenience function.
    // Please check its source code and implement error recovery when developing
    // production applications.
    sdmmc_card_t* card;
    esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
        	WRPPRINT("%s\n", "WrpSys::Storage::InitSDCard() Failed to mount filesystem. ");
        } else {
        	WRPPRINT("%s%s\n", "Failed to initialize the card. Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
        }
        return false;
    }

    sdmmc_card_print_info(stdout, card);
    // All done, unmount partition and disable SDMMC or SPI peripheral
//        esp_vfs_fat_sdmmc_unmount();
//        WRPPRINT("%s\n", "Card unmounted");
#endif
    m_uStorageStatus |= STORAGE_STATUS_INITSDCARD;
	WRPPRINT("%s\n", "WrpSys::Storage::InitSDCard() End");
	return true;
}

void DeInitSDCard()
{
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitSDCard() Begin");
#if USE_ESP_IDF
	esp_vfs_fat_sdmmc_unmount();
#endif
    m_uStorageStatus &= ~STORAGE_STATUS_INITSDCARD;
	WRPPRINT("%s\n", "WrpSys::Storage::DeInitSDCard() End");
}

} /* Namespace Storage */
} /* Namespace WrpSys */
