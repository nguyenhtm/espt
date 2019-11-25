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

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPLABEL_WIDTH       100
#define WRPLABEL_HEIGHT      66
#define WRPPOPUP_WIDTH       150
#define WRPPOPUP_HEIGHT      60
#define WRPSCREEN_MENU_POSX  10
#define WRPSCREEN_MENU_POSY  10

typedef lv_obj_t     wrpgui_handle_t;
typedef lv_style_t   wrpgui_style_t;
typedef lv_coord_t   wrpgui_pos_t;
typedef lv_coord_t   wrpgui_size_t;

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpGui
{
public:
	WrpGui();
	~WrpGui();
	wrpgui_pos_t  GetX();
	wrpgui_pos_t  GetY();
	wrpgui_size_t GetW();
	wrpgui_size_t GetH();
	void SetX(const wrpgui_pos_t x);
	void SetY(const wrpgui_pos_t y);
	void SetW(const wrpgui_size_t w);
	void SetH(const wrpgui_size_t h);
	void SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y);
	void SetSize(const wrpgui_size_t w, const wrpgui_size_t h);

	wrpgui_handle_t* m_pHandler;

protected:

private:

};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPGUI_HPP_ */
