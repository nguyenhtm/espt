/********************************************************************************************************
 * @File  : wrpbase.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPDEFINE_HPP_
#define WRPBASE_WRPDEFINE_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/

// LVGL INCLUDES
#if LVGL_PC_SIMU                            // LVGL for PC Simulation
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/mousewheel.h"
#include "lv_drivers/indev/keyboard.h"
#elif LVGL_ESP32_ILI9341                    // LVGL for ESP32 Wrover Kit
#include "drv/disp_spi.h"
#include "drv/ili9341.h"
#include "drv/tp_spi.h"
#include "drv/xpt2046.h"
#endif
#include "lvgl/lvgl.h"

// ESP IDF INCLUDES
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
#include "esp_websocket_client.h"
#endif

// c/c++ standard lib INCLUDES
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <vector>
#include <string>
#include <algorithm>

// Base Data Types:
//this header defines a set of integral type
#include <cstdint>

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPNULL_CHECK(p)    if(!p) return;
#define WRPPRINT(fmt, ...)  fprintf(stderr, fmt, __VA_ARGS__)
#define WRPPRINT2(fmt, ...) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__)

// GUI defines
typedef lv_obj_t     wrp_handler_t;
typedef lv_coord_t   wrp_pos_t;
typedef lv_style_t   wrp_style_t;


#endif /* WRPBASE_WRPDEFINE_HPP_ */
