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
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"
#endif

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>

//#define WRPESP_WIFI_SSID           "iPhone"
//#define WRPESP_WIFI_PASS           "123321123"
#define WRPESP_WIFI_SSID           "Nguyen"
#define WRPESP_WIFI_PASS           "08505046"


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

#endif /* WRPSYS_WRPSYS_HPP_ */
