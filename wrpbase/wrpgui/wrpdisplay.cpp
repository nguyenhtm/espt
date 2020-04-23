/********************************************************************************************************
 * @File  : wrpdisplay.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdisplay.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

static lv_fs_res_t pcfs_open(lv_fs_drv_t * drv, void * file_p, const char * fn, lv_fs_mode_t mode);
static lv_fs_res_t pcfs_close(lv_fs_drv_t * drv, void * file_p);
static lv_fs_res_t pcfs_read(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br);
static lv_fs_res_t pcfs_seek(lv_fs_drv_t * drv, void * file_p, uint32_t pos);
static lv_fs_res_t pcfs_tell(lv_fs_drv_t * drv, void * file_p, uint32_t * pos_p);

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


bool InitLvglFileSystem()
{
	WRPPRINT("%s\n", "WrpSys::WrpDisplay::InitLVGLFileSystem() Begin");

	static lv_fs_drv_t pcfs_drv;
	//memset(&pcfs_drv, 0, sizeof(lv_fs_drv_t));
#if LVGL_PC_SIMU
    pcfs_drv.letter = 'D';
    pcfs_drv.file_size = sizeof(pc_file_t);       /*Set up fields...*/
#elif LVGL_ESP32_ILI9341
    lv_fs_drv_init(&pcfs_drv);
    pcfs_drv.letter = 'S';
    pcfs_drv.file_size = sizeof(FIL*);       /*Set up fields...*/
#endif

    pcfs_drv.open_cb = pcfs_open;
    pcfs_drv.close_cb = pcfs_close;
    pcfs_drv.read_cb = pcfs_read;
    pcfs_drv.seek_cb = pcfs_seek;
    pcfs_drv.tell_cb = pcfs_tell;
    lv_fs_drv_register(&pcfs_drv);
    //usleep(500*1000); //importance

	WRPPRINT("%s\n", "WrpSys::WrpDisplay::InitLVGLFileSystem() End");
	return true;
}

lv_fs_res_t pcfs_open(lv_fs_drv_t * drv, void * file_p, const char * fn, lv_fs_mode_t mode)
{
    (void) drv; /*Unused*/

    errno = 0;

    const char * flags = "";

    if(mode == LV_FS_MODE_WR) flags = "wb";
    else if(mode == LV_FS_MODE_RD) flags = "rb";
    else if(mode == (LV_FS_MODE_WR | LV_FS_MODE_RD)) flags = "a+";

    /*Make the path relative to the current directory (the projects root folder)*/
    char buf[256]={0};
#if LVGL_PC_SIMU
    sprintf(buf, "%c:/%s", drv->letter, fn);
#elif LVGL_ESP32_ILI9341
    sprintf(buf, "/%s", fn);
#endif
	WRPPRINT("%s{%s}\n", "pcfs_open() file:", buf);

#if LVGL_PC_SIMU
    pc_file_t f = fopen(buf, "rb");
    if(f == NULL)
    {
    	WRPPRINT("%s\n", "pcfs_open(): open file failed!");
    	return LV_FS_RES_UNKNOWN;
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        /* 'file_p' is pointer to a file descriptor and
         * we need to store our file descriptor here*/
        pc_file_t * fp = (pc_file_t*) file_p;        /*Just avoid the confusing casings*/
        *fp = f;
    }
	return LV_FS_RES_OK;
#elif LVGL_ESP32_ILI9341
	FIL* f = NULL;
    FRESULT res = f_open(f, buf, FA_READ);
    if(res == FR_OK) {
    	WRPPRINT("%s%p\n", "pcfs_open(): open file binary rat ok", f);
    	f_lseek(f, 0);
        FIL** fp = (FIL**) file_p;        /*Just avoid the confusing casings*/
        *fp = f;
    	return LV_FS_RES_OK;
    }
    return LV_FS_RES_UNKNOWN;
#endif
}

lv_fs_res_t pcfs_close(lv_fs_drv_t * drv, void * file_p)
{
    (void) drv; /*Unused*/
#if LVGL_PC_SIMU
    pc_file_t * fp = (pc_file_t*) file_p;        /*Just avoid the confusing casings*/
    fclose(*fp);
#elif LVGL_ESP32_ILI9341
    f_close((FIL*)file_p);
#endif
    return LV_FS_RES_OK;
}

lv_fs_res_t pcfs_read(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br)
{
    (void) drv; /*Unused*/
#if LVGL_PC_SIMU
    pc_file_t * fp = (pc_file_t*) file_p;        /*Just avoid the confusing casings*/
    *br = fread(buf, 1, btr, *fp);
    return LV_FS_RES_OK;
#elif LVGL_ESP32_ILI9341
    WRPPRINT("%s%p\n", "pcfs_read(): read file with file_p=", file_p);
    FRESULT res = f_read((FIL*)file_p, buf, btr, (UINT*)br);
    if(res == FR_OK)
    {
    	WRPPRINT("%s\n", "pcfs_read(): read file ok");
    	return LV_FS_RES_OK;
    }
    return LV_FS_RES_UNKNOWN;
#endif
}

lv_fs_res_t pcfs_seek(lv_fs_drv_t * drv, void * file_p, uint32_t pos)
{
    (void) drv; /*Unused*/
#if LVGL_PC_SIMU
    pc_file_t * fp = (pc_file_t*) file_p;        /*Just avoid the confusing casings*/
    fseek(*fp, pos, SEEK_SET);
#elif LVGL_ESP32_ILI9341
    f_lseek((FIL*)file_p, pos);
#endif
    return LV_FS_RES_OK;
}

lv_fs_res_t pcfs_tell(lv_fs_drv_t * drv, void * file_p, uint32_t * pos_p)
{
    (void) drv; /*Unused*/
#if LVGL_PC_SIMU
    pc_file_t * fp = (pc_file_t*) file_p;        /*Just avoid the confusing casings*/
    *pos_p = ftell(*fp);
#elif LVGL_ESP32_ILI9341
    *pos_p = f_tell((FIL*)file_p);
#endif
    return LV_FS_RES_OK;
}

} /* Namespace WrpSys */



