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
   wrpthread_t threadid = NULL;
#if LVGL_PC_SIMU
   g_taskfunc = threadfunc;
   threadid = SDL_CreateThread(sdl_thread_handler, threadname, arg);
#elif USE_ESP_IDF
   xTaskCreate(threadfunc, threadname, 4*1024, arg, uxTaskPriorityGet(NULL), &threadid);
#endif
   return threadid;
}

void SwReset()
{
   WRPPRINT("%s\n", "WrpSys::System::SwReset() Begin");
#if USE_ESP_IDF
   fflush(stdout);
   esp_restart();
#endif
   WRPPRINT("%s\n", "WrpSys::System::SwReset() End");
}

void HwReset()
{
   WRPPRINT("%s\n", "WrpSys::System::HwReset() Begin");
   WRPPRINT("%s\n", "WrpSys::System::HwReset() End");
}

void PrintChipInfo()
{
   WRPPRINT("%s\n", "WrpSys::System::PrintChipInfo() Begin");
#if USE_ESP_IDF
   esp_chip_info_t chipInfo;
   esp_chip_info(&chipInfo);
   WRPPRINT("WrpSys::System::PrintChipInfo() ESP32 Chip: %d CPU cores, WiFi%s%s, ", chipInfo.cores, (chipInfo.features & CHIP_FEATURE_BT) ? "/BT" : "", (chipInfo.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
   WRPPRINT("silicon revision %d, ", chipInfo.revision);
   WRPPRINT("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024), (chipInfo.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

   WRPPRINT("%s%d\n", "[APP] Free memory (bytes): ", esp_get_free_heap_size());
   WRPPRINT("%s%s\n", "[APP] IDF version: ", esp_get_idf_version());

#endif
   WRPPRINT("%s\n", "WrpSys::System::PrintChipInfo() End");
}

} /* Namespace Storage */
} /* Namespace WrpSys */
