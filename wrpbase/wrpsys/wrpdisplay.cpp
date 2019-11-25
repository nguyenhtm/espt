/********************************************************************************************************
 * @File  : wrpdisplay.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdisplay.hpp"

namespace WrpSys {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

#if LVGL_PC_SIMU
static int lv_tick_task(void*);
#elif LVGL_ESP32_ILI9341
static void IRAM_ATTR lv_tick_task(void);
#endif

void InitLvglLib()
{

	static lv_disp_buf_t m_dispBuffer;                // lvgl display buffer
	static lv_color_t    m_buf[LV_HOR_RES_MAX * 40];  // lvgl display buffer for 10 lines
	static lv_color_t    m_buf2[LV_HOR_RES_MAX * 40]; // lvgl display buffer for 10 lines
	static lv_disp_drv_t m_dispDriver;                // lvgl display driver

	WRPPRINT("%s\n", "WrpSys::WrpDisplay::InitLvglLib() Begin");

	// initialize LVGL library
	lv_init();

	// initalize monitor display
	#if LVGL_PC_SIMU
	monitor_init(); // SDL monitor simulation
	#elif LVGL_ESP32_ILI9341
	disp_spi_init();
	ili9341_init(); // ILI9341 monitor
	#endif

	// initialize LVGL display buffer
	static lv_disp_buf_t disp_buf;
	lv_disp_buf_init(&m_dispBuffer, m_buf, m_buf2, LV_HOR_RES_MAX * 40);

	// initialize LVGL display driver
	lv_disp_drv_init(&m_dispDriver);

	// set the driver function
	#if LVGL_PC_SIMU
	m_dispDriver.flush_cb = monitor_flush;
	#elif LVGL_ESP32_ILI9341
	m_dispDriver.flush_cb = ili9341_flush;
	#endif

	// assign the buffer to the display
	m_dispDriver.buffer = &m_dispBuffer;

	// register the driver
	lv_disp_drv_register(&m_dispDriver);

	#if LVGL_PC_SIMU
	// call lv_tick_inc(x) every x milliseconds in a Timer or Task (x should be between 1 and 10).
	// it is required for the internal timing of LittlevGL. Use a SDL thread to do this
	SDL_CreateThread(lv_tick_task, "lvtick", NULL);
	#elif LVGL_ESP32_ILI9341
	esp_register_freertos_tick_hook(lv_tick_task);
	#endif

	WRPPRINT("%s\n", "WrpSys::WrpDisplay::InitLvglLib() End");

}

#if LVGL_PC_SIMU
int lv_tick_task(void* data)
{
	while(1)
	{
		SDL_Delay(5);   /*Sleep for 5 millisecond*/
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }
    return 0;
}
#elif LVGL_ESP32_ILI9341
void IRAM_ATTR lv_tick_task(void)
{
	lv_tick_inc(portTICK_RATE_MS);
}
#endif

} /* Namespace WrpSys */



