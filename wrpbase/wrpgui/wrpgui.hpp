/********************************************************************************************************
 * @File  : wrpgui.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPGUI_HPP_
#define WRPGUI_WRPGUI_HPP_

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
#include "lvgl/lvgl.h"
#elif LVGL_ESP32_ILI9341 && USE_ESP_IDF     // LVGL for ESP32 Wrover Kit
#include "drv/disp_spi.h"
#include "drv/ili9341.h"
#include "drv/tp_spi.h"
#include "drv/xpt2046.h"
#include "lvgl/lvgl.h"
#endif

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPSCREEN_WIDTH      320
#define WRPSCREEN_HEIGHT     240
#define WRPLABEL_WIDTH       100
#define WRPLABEL_HEIGHT      66
#define WRPPOPUP_WIDTH       150
#define WRPPOPUP_HEIGHT      60
#define WRPSCREEN_MENU_POSX  0
#define WRPSCREEN_MENU_POSY  0

#if (LVGL_ESP32_ILI9341 && USE_ESP_IDF) || (LVGL_PC_SIMU)
typedef lv_obj_t     wrpgui_handle_t;
typedef lv_style_t   wrpgui_style_t;
typedef lv_coord_t   wrpgui_pos_t;
typedef lv_coord_t   wrpgui_size_t;
#endif

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPGUI_HPP_ */
