/********************************************************************************************************
 * @File  : wrpsys.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPSYS_WRPSYS_HPP_
#define WRPSYS_WRPSYS_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

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
#endif

#define WRPESP_WIFI_SSID           "iPhone"
#define WRPESP_WIFI_PASS           "123321123"

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

#endif /* WRPSYS_WRPSYS_HPP_ */
