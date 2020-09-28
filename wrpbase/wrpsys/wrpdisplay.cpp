/********************************************************************************************************
 * @File  : wrpdisplay.cpp
 * @Date  : 2020-08-20
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdisplay.hpp"

namespace WrpSys {
namespace WrpDisplay {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS - WrpDisplay
 ********************************************************************************************************/
WrpDisplay::WrpDisplay()
{
   WRPPRINT("%s\n", "WrpDisplay::WrpDisplay() Begin");
   WRPPRINT("%s\n", "WrpDisplay::WrpDisplay() End");
}
WrpDisplay::~WrpDisplay()
{
   WRPPRINT("%s\n", "WrpDisplay::~WrpDisplay() Begin");
   WRPPRINT("%s\n", "WrpDisplay::~WrpDisplay() End");
}
void WrpDisplay::Initialize()
{
   WRPPRINT("%s\n", "WrpDisplay::Initialize() Begin");
   static lv_disp_buf_t dispbuffer;                // lvgl display buffer
   static lv_color_t    buf1[LV_HOR_RES_MAX * 40]; // lvgl display buffer for 40 lines
   static lv_color_t    buf2[LV_HOR_RES_MAX * 40]; // lvgl display buffer for 40 lines
   static lv_disp_drv_t dispdriver;                // lvgl display driver

   // initialize LVGL library
   lv_init();
   // initialize monitor display
#if LVGL_PC_SIMU
   monitor_init(); // SDL simulation monitor
#elif LVGL_ESP32_ILI9341
   disp_spi_init();
   ili9341_init(); // ILI9341 monitor
#endif
   // initialize LVGL display buffer
   lv_disp_buf_init(&dispbuffer, buf1, buf2, LV_HOR_RES_MAX * 40);
   // initialize LVGL display driver
   lv_disp_drv_init(&dispdriver);

   // set the driver function
#if LVGL_PC_SIMU
   dispdriver.flush_cb = monitor_flush;
#elif LVGL_ESP32_ILI9341
   dispdriver.flush_cb = ili9341_flush;
#endif
   dispdriver.buffer = &dispbuffer;  // assign the buffer to the display
   lv_disp_drv_register(&dispdriver);// register the driver

   WRPPRINT("%s\n", "WrpDisplay::Initialize() End");
}
void WrpDisplay::DeInitialize()
{
   WRPPRINT("%s\n", "WrpDisplay::DeInitialize() Begin");
   WRPPRINT("%s\n", "WrpDisplay::DeInitialize() End");
}
WrpDisplay::WrpDisplay(const WrpDisplay& cp)
{
}

} /* Namespace WrpDisplay */
} /* Namespace WrpSys */
