/********************************************************************************************************
 * @File  : diagscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "diagscreen.hpp"
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
LV_IMG_DECLARE(meter)
LV_IMG_DECLARE(needle)

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
DiagScreen::DiagScreen(WrpHmiApp* app)
: mpHmiApp(app)
, mpMeter(NULL)
, mpNeedle(NULL)
, mpLblBackItem(NULL)
{
   WRPPRINT("%s\n", "DiagScreen::DiagScreen() Begin");
   mpHmiAppClientHandle = new WrpGui::WrpScreen(false);
   mpHmiAppClientHandle->SetTitle("");
   mpMeter = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMeter->SetImage(WRPRESIMG_METER);
   //mpNeedle = new WrpGui::WrpImage(mpHmiAppClientHandle);
   //mpNeedle->SetImage(WRPRESIMG_METER_NEEDLE);
   WRPPRINT("%s\n", "DiagScreen::DiagScreen() End");
}

DiagScreen::~DiagScreen()
{
   WRPPRINT("%s\n", "DiagScreen::~DiagScreen() Begin");
   delete mpMeter;
   //delete mpNeedle;
   WRPPRINT("%s\n", "DiagScreen::~DiagScreen() End");
}

void DiagScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "DiagScreen::CreateAndShow() Begin");

   WRPPRINT("%s\n", "DiagScreen::CreateAndShow() End");
}

void DiagScreen::HideAndDestroy()
{
   WRPPRINT("%s", "DiagScreen::HideAndDestroy() Begin");
   //WRPNULL_CHECK(m_pScreenHandle)
   //delete m_pScreenHandle;
   //delete m_pLblBackItem;
   WRPPRINT("%s", "DiagScreen::HideAndDestroy() End");
}

void DiagScreen::RunSpeedMeter()
{
   static lv_color_t canvas_buf[206 * 206];
   int32_t angle = -3;
   const uint32_t canvas_x = 50; //move canvas to propriate posy
   const uint32_t canvas_y = 15; //move canvas to propriate posx
   const uint32_t canvas_w = 206;//(size of needle - needle's circle) * 2
   const uint32_t canvas_h = 206;//canvas square rotate

   lv_obj_t *canvas = lv_canvas_create(mpHmiAppClientHandle->GetHandle(), NULL);
   lv_obj_set_pos(canvas, canvas_x, canvas_y);
   lv_canvas_set_buffer(canvas, canvas_buf, canvas_w, canvas_h, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED);
   memset(canvas_buf, 0x0, sizeof(canvas_buf));
   //move the needle to first position
   lv_coord_t canvas_needle_imgX = 0; //after rotate, needle is at position X of canvas
   lv_coord_t canvas_needle_imgY = canvas_h - needle.header.h; //after rotate, needle is at position Y of canvas

   lv_coord_t pivotX = canvas_w/2;
   lv_coord_t pivotY = canvas_y/2;
   lv_canvas_rotate(canvas, &needle, angle, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);

   while(angle <185) {
      usleep(50*1000);
      /*Clear the canvas*/
      memset(canvas_buf, 0x0, sizeof(canvas_buf));
      lv_canvas_rotate(canvas, &needle, angle, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
      angle++;
   }
}

void DiagScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
   WRPPRINT("%s\n", "DiagScreen::MidwAppUpdate() Begin");
   switch(status)
   {
      case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
         {
            if (!strcmp(buffer, "back"))
            {
               mpHmiApp->LoadScreen(HOMESCREEN);
            }
            else if (!strcmp(buffer, "diagnosis"))
            {
            	   RunSpeedMeter();
            }
         }
         break;
      default:
         {
            //do nothing
         }
         break;
   }
   WRPPRINT("%s\n", "DiagScreen::MidwAppUpdate() End");
}

DiagScreen::DiagScreen(const DiagScreen& cp)
{
}
