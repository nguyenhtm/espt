/********************************************************************************************************
 * @File  : wrpsystem.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpsystem.hpp"

namespace WrpSys {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
void SwReset()
{

}

void HwReset()
{

}

void PrintChipInfo()
{
	WRPPRINT("%s\n", "PrintChipInfo() Begin");
#if USE_ESP_IDF
	esp_chip_info_t chipInfo;

    esp_chip_info(&chipInfo);
    WRPPRINT("This is ESP32 chip with %d CPU cores, WiFi%s%s, ", chipInfo.cores, (chipInfo.features & CHIP_FEATURE_BT) ? "/BT" : "", (chipInfo.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    WRPPRINT("silicon revision %d, ", chipInfo.revision);
    WRPPRINT("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024), (chipInfo.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
#endif
	WRPPRINT("%s\n", "PrintChipInfo() End");
}

} /* Namespace WrpSys */
