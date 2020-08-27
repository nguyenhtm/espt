/********************************************************************************************************
 * @File  : clusterapp.cpp
 * @Date  : 2020-06-03
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpdisplay.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"
#include "wrpbase/wrpgui/wrpanim.hpp"
#endif
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

using namespace WrpSys::System;

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
LV_IMG_DECLARE(needle1)
LV_IMG_DECLARE(meter1_0)
LV_IMG_DECLARE(meter1_1)

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
static WrpGui::WrpScreen* gpHomeScreen = NULL;
static const uint8_t gSpeedometerX = 0;
static const uint8_t gSpeedometerY = 0;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
static void WrpThreadHmiApp(void* param)
{
   WRPPRINT("%s\n", "ThreadWrpHmiApp() Begin");
   while(1)
   {
      // for display
      usleep(5*1000);
      lv_task_handler();
   }
   WRPPRINT("%s\n", "ThreadWrpHmiApp() End");
}

static void WrpGuiInit(void)
{
   //ESP32 target need to initialize NVS before using LVGL library
   WrpSys::Storage::InitNVS(); // must 1st initialization
   WrpSys::Network::InitWifiStation();
   WrpGui::InitLvglLib();

   wrpthread_t mThreadId = WrpCreateThread(WrpThreadHmiApp, "WrpThreadHmiApp", NULL);
   if (!mThreadId)
   {
      WRPPRINT("%s\n", "WrpGuiInit() WrpCreateThread Failed!");
   }
}


lv_obj_t*   mpCanvasNeedle = NULL;
lv_color_t* mpCanvasBufNeedle = NULL;
uint16_t mCanvasBufNeedleSize = 0;
uint16_t mCurrentSpeed = 0;
WrpGui::WrpAnim mAnim;

static void DisplayNeedle(const uint16_t km, const uint16_t delay)
{
   WRPPRINT("%s\n", "ClusterApp::DisplayNeedle() Begin");
   static bool flag = false;

   const uint8_t dist_canvas_needle = 20; // distance between needle and bottom of canvas ->needle can point to km0
   const uint8_t needle_circle_radius = 30; // circle radius of needle
   const uint8_t canvas_w = (needle1.header.w - needle_circle_radius)*2;
   const uint8_t canvas_h = (needle1.header.w + dist_canvas_needle); //110: if angle < 0, the needle shall be lost-> 110 not enough
   lv_coord_t canvas_needle_imgX = 0; //after rotate, needle is at position X of canvas
   lv_coord_t canvas_needle_imgY = needle1.header.w - needle1.header.h; //after rotate, needle is at position Y of canvas
   lv_coord_t pivotX = canvas_w/2; //relative source canvas
   lv_coord_t pivotY = needle1.header.h/2; //relative source canvas
   const uint8_t canvas_x = gSpeedometerX + 30; // position x of canvas needle
   const uint8_t canvas_y = gSpeedometerY + 10; // position y of canvas needle

   int16_t angle = (int16_t)mCurrentSpeed*0.5-6;
   int16_t angledest = (int16_t)km*0.5-6;

   if (!flag)
   {
      mpCanvasNeedle       = lv_canvas_create(gpHomeScreen->GetHandle(), NULL);
      mpCanvasBufNeedle    = new lv_color_t[canvas_w*canvas_h];
      mCanvasBufNeedleSize = sizeof(lv_color_t)*canvas_w*canvas_h;
      memset(mpCanvasBufNeedle, 0x0, mCanvasBufNeedleSize);
      lv_canvas_set_buffer(mpCanvasNeedle, mpCanvasBufNeedle, canvas_w, canvas_h, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED);
      lv_obj_set_pos(mpCanvasNeedle, canvas_x, canvas_y);

      lv_canvas_rotate(mpCanvasNeedle, &needle1, angle, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
      flag = true;
   }

   // set top
   lv_obj_move_foreground(mpCanvasNeedle);
   //memset(mpCanvasBufNeedle, 0x0, mCanvasBufNeedleSize);
   //lv_canvas_set_buffer(mpCanvasNeedle, mpCanvasBufNeedle, canvas_w, canvas_h, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED);


   int16_t diff = angledest - angle;
   while(diff)
   {
      /* Periodically call the lv_task handler.*/
      //lv_task_handler();
#if LVGL_PC_SIMU
	   usleep(delay*1000);
      //usleep(40*1000);
#elif LVGL_ESP32_ILI9341
      usleep(60*1000);// no flicker
#endif
      /*Clear the canvas continueously -> flicker */
      //if (diff%20 == 0)
      //if (delay > 10)
      {
         memset(mpCanvasBufNeedle, 0x0, mCanvasBufNeedleSize);
      }
      if (diff > 0) {
         lv_canvas_rotate(mpCanvasNeedle, &needle1, angle++, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
         diff--;
      }
      else
      {
          lv_canvas_rotate(mpCanvasNeedle, &needle1, angle--, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
          diff++;
      }
   }

   mCurrentSpeed = km;
   WRPPRINT("%s\n", "ClusterApp::DisplayNeedle() End");
}

static void RotateMeter(lv_img_dsc_t meter, const uint16_t delay)
{
   WRPPRINT("%s\n", "ClusterApp::RotateMeter() Begin");
   lv_obj_t*   mpCanvasMeter = lv_canvas_create(gpHomeScreen->GetHandle(), NULL);

   lv_color_t* mpCanvasBufMeter = NULL;
   uint16_t mCanvasBufMeterSize = 0;
   int angle = 0;
   const uint8_t canvas_w = meter.header.w;
   const uint8_t canvas_h = meter.header.h;
   lv_coord_t canvas_needle_imgX = 0;
   lv_coord_t canvas_needle_imgY = 0;
   lv_coord_t pivotX = canvas_w/2; //relative source canvas
   lv_coord_t pivotY = canvas_h/2; //relative source canvas

   //set up position, buffer size of meter canvas
   mpCanvasBufMeter    = new lv_color_t[canvas_w*canvas_h];
   mCanvasBufMeterSize = sizeof(lv_color_t)*canvas_w*canvas_h;
   memset(mpCanvasBufMeter, 0x0, mCanvasBufMeterSize);

   lv_canvas_set_buffer(mpCanvasMeter, mpCanvasBufMeter, canvas_w, canvas_h, LV_IMG_CF_TRUE_COLOR);
   lv_obj_set_pos(mpCanvasMeter, gSpeedometerX, gSpeedometerY);

   memset(mpCanvasBufMeter, 0x0, mCanvasBufMeterSize);
   lv_canvas_rotate(mpCanvasMeter, &meter, angle, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);

   while(angle<220)
   {
#if LVGL_PC_SIMU
      usleep(2*1000);
#elif LVGL_ESP32_ILI9341
      usleep(60*1000);// no flicker
#endif
      lv_canvas_rotate(mpCanvasMeter, &meter, angle++, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
   }
   //memset(mpCanvasBufMeter, 0x0, mCanvasBufMeterSize);

   while(angle>0)
   {
#if LVGL_PC_SIMU
      usleep(2*1000);
#elif LVGL_ESP32_ILI9341
      usleep(60*1000);// no flicker
#endif
      lv_canvas_rotate(mpCanvasMeter, &meter, angle--, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
   }

   WRPPRINT("%s\n", "ClusterApp::DisplayNeedle() End");
}

void appcluster(void)
{
   WrpGuiInit();

   gpHomeScreen = new WrpGui::WrpScreen(true);
   gpHomeScreen->SetStyle(WrpGui::SCREEN_DEFAULT);
   usleep(2000*1000);

   WrpGui::WrpImage* mpMeter0 = new WrpGui::WrpImage(gpHomeScreen);
   mpMeter0->SetImage(WRPRESIMG_METER1_0);
   mpMeter0->SetPos(gSpeedometerX, gSpeedometerY);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMeter0, 700);
#if 0
   usleep(1300*1000); //700+500
   mpMeter0->SetHide();

   RotateMeter(meter1_0, 1);
   usleep(1500*1000);

   WrpGui::WrpImage* mpMeter1 = new WrpGui::WrpImage(gpHomeScreen);
   mpMeter1->SetImage(WRPRESIMG_METER1_1);
   mpMeter1->SetPos(gSpeedometerX, gSpeedometerY);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMeter1, 700);
   usleep(1500*1000);

   WrpGui::WrpImage* mpMeter2 = new WrpGui::WrpImage(gpHomeScreen);
   mpMeter2->SetImage(WRPRESIMG_METER1_2);
   mpMeter2->SetPos(gSpeedometerX, gSpeedometerY);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMeter2, 700);

   //display needle right after meter1_2 faded in
   WrpGui::WrpImage* mpNeedle = new WrpGui::WrpImage(gpHomeScreen);
   mpNeedle->SetImage(WRPRESIMG_METER_NEEDLE1);
   mpNeedle->SetPos(gSpeedometerX + 30, gSpeedometerY + 110);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpNeedle, 700);
   usleep(2000*1000);

   mpNeedle->SetHide();
   DisplayNeedle(400, 5);
   DisplayNeedle(0, 5);
   usleep(2000*1000);

   WrpGui::WrpImage* mpMeter3 = new WrpGui::WrpImage(gpHomeScreen);
   mpMeter3->SetImage(WRPRESIMG_METER1_3);
   mpMeter3->SetPos(gSpeedometerX-4, gSpeedometerY);//todo x-4
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMeter3, 700);
   DisplayNeedle(0, 40);
   usleep(2300*1000);

   DisplayNeedle(350, 40);
#endif
   while(1) {}

   delete gpHomeScreen;
}
