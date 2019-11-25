/********************************************************************************************************
 * @File  : wrpsystem.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpsystem.hpp"

namespace WrpSys {
namespace System {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

#if LVGL_PC_SIMU
static wrpthread_handler_t g_taskfunc = NULL;
static int sdl_thread_handler(void* param)
{
	g_taskfunc(param);
	return 0;
}
#endif

wrpthread_t WrpCreateThread(wrpthread_handler_t threadfunc, const char* threadname, void* arg)
{
	wrpthread_t thrHandle = NULL;
#if LVGL_PC_SIMU
	g_taskfunc = threadfunc;
	thrHandle = SDL_CreateThread(sdl_thread_handler, threadname, arg);
#elif LVGL_ESP32_ILI9341
	xTaskCreate(threadfunc, threadname, 4*1024, arg, uxTaskPriorityGet(NULL), &thrHandle);
#endif
	return thrHandle;
}

void SwReset()
{

}

void HwReset()
{

}

void PrintChipInfo()
{
	WRPPRINT("%s\n", "WrpSys::PrintChipInfo() Begin");
#if USE_ESP_IDF
	esp_chip_info_t chipInfo;

    esp_chip_info(&chipInfo);
    WRPPRINT("This is ESP32 chip with %d CPU cores, WiFi%s%s, ", chipInfo.cores, (chipInfo.features & CHIP_FEATURE_BT) ? "/BT" : "", (chipInfo.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    WRPPRINT("silicon revision %d, ", chipInfo.revision);
    WRPPRINT("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024), (chipInfo.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
#endif
	WRPPRINT("%s\n", "WrpSys::PrintChipInfo() End");
}

} /* Namespace Storage */
} /* Namespace WrpSys */
