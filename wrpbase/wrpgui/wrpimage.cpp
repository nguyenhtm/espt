/********************************************************************************************************
 * @File  : wrpimage.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpimage.hpp"
#include "wrpscreen.hpp"
#include "wrpbase/wrpbase.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
LV_IMG_DECLARE(def01home)
LV_IMG_DECLARE(def01app)
LV_IMG_DECLARE(def01setting)
LV_IMG_DECLARE(def01diagnosis)
LV_IMG_DECLARE(def01autotest)
LV_IMG_DECLARE(def01wifi0)
LV_IMG_DECLARE(def01wifi1)
LV_IMG_DECLARE(def01wifi2)
LV_IMG_DECLARE(def01logo)
LV_IMG_DECLARE(menuitem1)
LV_IMG_DECLARE(menuitem2)
LV_IMG_DECLARE(menuitem3)
LV_IMG_DECLARE(menuitem4)
LV_IMG_DECLARE(menuitem5)
LV_IMG_DECLARE(meter)
LV_IMG_DECLARE(needle)
//appcluster
LV_IMG_DECLARE(needle1)
LV_IMG_DECLARE(meter10)
LV_IMG_DECLARE(meter1_1)
LV_IMG_DECLARE(meter1_2)
LV_IMG_DECLARE(meter1_3)

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpImage::WrpImage(WrpScreen* parent)
: WrpWidget(NULL)
{
   WRPPRINT("%s\n", "WrpImage::WrpImage() Begin");
   mpScreenHandle = parent;
   if (parent)
   {
      mpWidgetHandle = lv_img_create(parent->GetHandle(), NULL);
   }
   WRPPRINT("%s\n", "WrpImage::WrpImage() End");
}

WrpImage::~WrpImage()
{
   WRPPRINT("%s\n", "WrpImage::~WrpImage() Begin");
   WRPNULL_CHECK(mpScreenHandle)
   delete mpWidgetHandle;
   WRPPRINT("%s\n", "WrpImage::~WrpImage() End");
}

bool WrpImage::LoadImageFromFile(const char* filepath)
{
#if 1
    //#if LV_COLOR_DEPTH == 16; Letter=D
    char tmp[255] = {0};
#if LVGL_PC_SIMU
    sprintf(tmp, "D:/iotprj/wrpbase/wrpres/%s", filepath);
#elif LVGL_ESP32_ILI9341
    sprintf(tmp, "S:/sdcard/resources/%s", filepath);
#endif
   WRPPRINT("%s{%s}\n", "WrpImage::LoadImageFromFile() Begin ", tmp);
   lv_img_set_src(mpWidgetHandle, tmp);
   lv_obj_set_drag(mpWidgetHandle, true);

	//lv_img_set_src(m_pHandler,"S:resources/background.bin");
	//lv_img_set_src(m_pHandler,"S:sdcard/resources/background.bin");
	//lv_img_set_src(m_pHandler,"0:resources/background.bin");
	//lv_img_set_src(m_pHandler,"0:sdcard/resources/background.bin");
	//lv_img_set_src(m_pHandler,"/sdcard/background.bin");
	//lv_img_set_src(m_pHandler, "D:/iotprj/wrpbase/resources/background1.bin");
	//lv_img_set_src(m_pHandler, &WRPRESIMG_BACKGROUND);
	//lv_img_set_src(m_pHandler, &bg2);
	//lv_obj_set_pos(mpWidgetHandle, 0, 0);
	//lv_obj_set_size(mpWidgetHandle, 320, 240);
   WRPPRINT("%s{%s}\n", "WrpImage::LoadImageFromFile() End ", tmp);
#endif
   return true;
}

bool WrpImage::SetImage(const uint16_t imgid)
{
   WRPPRINT("%s%d\n", "WrpImage::SetImage() Begin imgid=", imgid);
   switch(imgid)
   {
      case WRPRESIMG_HOME:         lv_img_set_src(mpWidgetHandle, &def01home); break;
      case WRPRESIMG_APP:          lv_img_set_src(mpWidgetHandle, &def01app); break;
      case WRPRESIMG_SETTING:      lv_img_set_src(mpWidgetHandle, &def01setting); break;
      case WRPRESIMG_DIAGNOSIS:    lv_img_set_src(mpWidgetHandle, &def01diagnosis); break;
      case WRPRESIMG_AUTOTEST:     lv_img_set_src(mpWidgetHandle, &def01autotest); break;
      case WRPRESIMG_WIFI0:        lv_img_set_src(mpWidgetHandle, &def01wifi0); break;
      case WRPRESIMG_WIFI1:        lv_img_set_src(mpWidgetHandle, &def01wifi1); break;
      case WRPRESIMG_WIFI2:        lv_img_set_src(mpWidgetHandle, &def01wifi2); break;
      case WRPRESIMG_LOGO:         lv_img_set_src(mpWidgetHandle, &def01logo); break;
      case WRPRESIMG_CFLOWITEM1:   lv_img_set_src(mpWidgetHandle, &menuitem1); break;
      case WRPRESIMG_CFLOWITEM2:   lv_img_set_src(mpWidgetHandle, &menuitem2); break;
      case WRPRESIMG_CFLOWITEM3:   lv_img_set_src(mpWidgetHandle, &menuitem3); break;
      case WRPRESIMG_CFLOWITEM4:   lv_img_set_src(mpWidgetHandle, &menuitem4); break;
      case WRPRESIMG_CFLOWITEM5:   lv_img_set_src(mpWidgetHandle, &menuitem5); break;
      case WRPRESIMG_METER:        lv_img_set_src(mpWidgetHandle, &meter); break;
      case WRPRESIMG_METER_NEEDLE: lv_img_set_src(mpWidgetHandle, &needle); break;
      //appcluster
      case WRPRESIMG_METER_NEEDLE1: lv_img_set_src(mpWidgetHandle, &needle1); break;
      case WRPRESIMG_METER1_0:      lv_img_set_src(mpWidgetHandle, &meter10); break;
      case WRPRESIMG_METER1_1:      lv_img_set_src(mpWidgetHandle, &meter1_1); break;
      case WRPRESIMG_METER1_2:      lv_img_set_src(mpWidgetHandle, &meter1_2); break;
      case WRPRESIMG_METER1_3:      lv_img_set_src(mpWidgetHandle, &meter1_3); break;
      default: return false;
   }
   WRPPRINT("%s%d\n", "WrpImage::SetImage() End imgid=", imgid);
   return true;
}

void WrpImage::SetHide()
{
   lv_obj_set_hidden(mpWidgetHandle, true);
}

void WrpImage::SetShow()
{
   lv_obj_set_hidden(mpWidgetHandle, false);
}

void WrpImage::SetTop()
{
   //lv_obj_set_top(mpWidgetHandle, true);
	lv_obj_move_foreground(mpWidgetHandle);
}

WrpImage::WrpImage()
: WrpWidget(NULL)
{
}

WrpImage::WrpImage(const WrpImage& cp)
: WrpWidget(NULL)
{
}

} /* WrpGui Namespace */
