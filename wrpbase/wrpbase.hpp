/********************************************************************************************************
 * @File  : wrpbase.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPBASE_HPP
#define WRPBASE_WRPBASE_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
// c/c++ standard lib includes
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/unistd.h>
#include <sys/stat.h>
// math
#include <math.h>
// data types
#include <cstdint>
// signals
#include <csignal>

// esp idf framework includes
#if USE_ESP_IDF
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_freertos_hooks.h"
#include "esp_spi_flash.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "esp_spiffs.h"
#include "esp_websocket_client.h"
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"
#endif

#if LVGL_PC_SIMU                          // LVGL for PC Simulation
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/mousewheel.h"
#include "lv_drivers/indev/keyboard.h"
#include "lvgl/lvgl.h"
#endif

#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
//#include "wrpbase/wrphmi/wrphmi.hpp"
#endif

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPNULL_CHECK(p)      if(!p) return;
#define WRPNULL_CHECK2(p1,p2) if(!p1 && !p2) return;
#define WRPNULL_CHECKRET(p)   if(!p) return 0;
#define WRPPRINT(fmt, ...)    fprintf(stderr, fmt, __VA_ARGS__)
#define WRPPRINT2(fmt, ...)   fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__)

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Forward Classes
class WrpSimpleMidwBuilder;
class WrpStandardMidwBuilder;
class WrpMidw;

// Class WrpMidwApp
class WrpMidwApp
{
public:
   WrpMidwApp();
   ~WrpMidwApp();
   void ConstructMidw();

private:
   WrpMidwApp(const WrpMidwApp& cp);
   // methods

   // members
   WrpSimpleMidwBuilder* mpMidwBuilder;
   WrpMidw*              mpMidw;
};

#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
// Forward classes
// Remember include wrphmi.hpp & wrpbase.hpp file in .cpp file
class WrpHmi;

// Class WrpHmiApp
class WrpHmiApp
{
public:
   WrpHmiApp();
   ~WrpHmiApp();
   //create a midw and hmi instances
   void Initialize();
   //delete created midw and hmi instances
   void DeInitialize();
   //get instances
   WrpHmi* GetHmiInstance();
   WrpMidw* GetMidwInstance();

private:
   WrpHmiApp(const WrpHmiApp& cp);
   // methods

   // members
   WrpStandardMidwBuilder* mpMidwBuilder;
   WrpMidw*                mpMidw;
   WrpHmi*                 mpHmi;
};
#endif /* (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU) */

#endif /* WRPBASE_WRPBASE_HPP */
