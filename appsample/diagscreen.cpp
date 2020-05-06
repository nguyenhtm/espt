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
, mCurrentSpeed(20)
, mpCanvas(NULL)
{
   WRPPRINT("%s\n", "DiagScreen::DiagScreen() Begin");
   mpHmiAppClientHandle = new WrpGui::WrpScreen(false);
   mpHmiAppClientHandle->SetTitle("");
   mpMeter = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMeter->SetImage(WRPRESIMG_METER);
   //mpMeter->LoadImageFromFile("def01background.bin");
   //mpMeter->SetPos(0,0);
   //mpNeedle = new WrpGui::WrpImage(mpHmiAppClientHandle);
   //mpNeedle->SetImage(WRPRESIMG_METER_NEEDLE);
   //mpNeedle->SetPos(0,0);
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
   mpCanvas = lv_canvas_create(mpHmiAppClientHandle->GetHandle(), NULL);
   WRPPRINT("%s\n", "DiagScreen::CreateAndShow() End");
}

void DiagScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "DiagScreen::HideAndDestroy() Begin");
   //WRPNULL_CHECK(m_pScreenHandle)
   //delete m_pScreenHandle;
   //delete m_pLblBackItem;
   lv_obj_del(mpCanvas);
   WRPPRINT("%s\n", "DiagScreen::HideAndDestroy() End");
}

void DiagScreen::RunSpeedMeter(const uint16_t km)
{
   WRPPRINT("%s\n", "DiagScreen::RunSpeedMeter() Begin");
   lv_color_t canvas_buf[206 * 206];
   int16_t angle = -3;
   uint8_t canvas_x = 50; //move canvas to appropriate posx
   uint8_t canvas_y = 5; //move canvas to appropriate posy
   uint8_t canvas_w = 206;//(size of needle - needle's circle) * 2
   uint8_t canvas_h = 206;//canvas square rotate
   int16_t angledest = (int16_t)km*0.8;

   lv_coord_t canvas_needle_imgX = 0; //after rotate, needle is at position X of canvas
   lv_coord_t canvas_needle_imgY = canvas_h - needle.header.h; //after rotate, needle is at position Y of canvas
   lv_coord_t pivotX = canvas_w/2; //relative source canvas
   lv_coord_t pivotY = needle.header.h/2; //relative source canvas

      lv_obj_set_pos(mpCanvas, canvas_x, canvas_y);
      lv_canvas_set_buffer(mpCanvas, canvas_buf, canvas_w, canvas_h, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED);
      //memset(canvas_buf, 0x0, sizeof(canvas_buf));
      angle = (int16_t)mCurrentSpeed*0.8;
      lv_canvas_rotate(mpCanvas, &needle, angle, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);

   int16_t diff = angledest - angle;
   while(diff)
   {
      /* Periodically call the lv_task handler.*/
      lv_task_handler();
      usleep(20*1000);
      /*Clear the canvas*/
      if (diff%5 == 0)  memset(canvas_buf, 0x0, sizeof(canvas_buf));
      if (diff > 0) {
         lv_canvas_rotate(mpCanvas, &needle, angle++, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
         diff--;
      }
      else
      {
          lv_canvas_rotate(mpCanvas, &needle, angle--, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
          diff++;
      }
   }
   mCurrentSpeed = km;

   WRPPRINT("%s\n", "DiagScreen::RunSpeedMeter() End");
}

void DiagScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
   WRPPRINT("%s%s\n", "DiagScreen::MidwAppUpdate() Begin buffer=", buffer);
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
               RunSpeedMeter(220);
               sleep(1);
               RunSpeedMeter(20);
               sleep(1);
               RunSpeedMeter(120);

            }
            else if (!strcmp(buffer, "diag40"))
            {
               RunSpeedMeter(40);
            }
            else if (!strcmp(buffer, "diag60"))
            {
               RunSpeedMeter(60);
            }
            else if (!strcmp(buffer, "diag80"))
            {
               RunSpeedMeter(80);
            }

         }
         break;
      default:
         {
            //do nothing
         }
         break;
   }
   WRPPRINT("%s%s\n", "DiagScreen::MidwAppUpdate() End buffer=", buffer);
}

DiagScreen::DiagScreen(const DiagScreen& cp)
: mpHmiApp(NULL)
, mpMeter(NULL)
, mpNeedle(NULL)
, mpLblBackItem(NULL)
{
}
