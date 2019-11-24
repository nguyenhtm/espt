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
#elif LVGL_ESP32_ILI9341                    // LVGL for ESP32 Wrover Kit
#include "drv/disp_spi.h"
#include "drv/ili9341.h"
#include "drv/tp_spi.h"
#include "drv/xpt2046.h"
#endif
#include "lvgl/lvgl.h"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

#endif /* WRPGUI_WRPGUI_HPP_ */
