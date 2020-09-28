/********************************************************************************************************
 * @File  : diagscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "speedometer.hpp"
#include "appdefines.hpp"
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
LV_IMG_DECLARE(def01needle)

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - Speedometer
 ********************************************************************************************************/
Speedometer::Speedometer()
: WrpGui::WrpScreen(false)
, mpMeter(NULL)
, mpNeedle(NULL)
, mpLblBackItem(NULL)
, mCurrentSpeed(0)
, mpCanvas(NULL)
, mpCanvasBuf(NULL)
, mCanvasBufSize(0)
{
   WRPPRINT("%s\n", "Speedometer::Speedometer() Begin");
   mpCanvas = lv_canvas_create(this->GetHandle(), NULL);
   mpCanvasBuf = new lv_color_t[130 * 206]; // header.w + dist_canvas_needle * canvas_w
   mCanvasBufSize = sizeof(lv_color_t)*130*206;
   memset(mpCanvasBuf, 0x0, mCanvasBufSize);
   lv_canvas_set_buffer(mpCanvas, mpCanvasBuf, 206, 130, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED);
   WRPPRINT("%s\n", "Speedometer::Speedometer() End");
}
Speedometer::~Speedometer()
{
   WRPPRINT("%s\n", "Speedometer::~Speedometer() Begin");
   WRPPRINT("%s\n", "Speedometer::~Speedometer() End");
}
void Speedometer::CreateAndShow()
{
   WRPPRINT("%s\n", "Speedometer::CreateAndShow() Begin");
   mpMeter = new WrpGui::WrpImage(this);
   mpMeter->SetImage(WRPRESIMG_DEF01METER);
   WRPPRINT("%s\n", "Speedometer::CreateAndShow() End");
}
void Speedometer::HideAndDestroy()
{
   WRPPRINT("%s\n", "LoadingScreenEx::HideAndDestroy() Begin");
   WRPNULL_CHECK(mpMeter)
   delete mpMeter;
   //delete mpNeedle;
   lv_obj_del(mpCanvas);
   delete [] mpCanvasBuf;
   mCanvasBufSize = 0;
   WRPPRINT("%s\n", "LoadingScreenEx::HideAndDestroy() End");
}
void Speedometer::ActiveScreen(const WrpScreen& obj)
{
   WRPPRINT("%s%p:%p\n", "Speedometer::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WrpScreen::Load();
   }
   WRPPRINT("%s\n", "Speedometer::ActiveScreen() End");
}
void Speedometer::RunSpeedMeter(const uint16_t km)
{
   WRPPRINT("%s\n", "Speedometer::RunSpeedMeter() Begin");
   // needle size: .header.w = 110, .header.h = 18, needle circle width=7
   const uint8_t dist_canvas_needle = 20; // distance between needle and bottom of canvas ->needle can point to km0
   const uint8_t needle_circle_w = 7; // circle radia
   //lv_color_t canvas_buf[130 * 206]; // header.w + dist_canvas_needle * canvas_w
   int16_t angle;

   uint8_t canvas_w = (def01needle.header.w - needle_circle_w)*2; //206
   uint8_t canvas_h = def01needle.header.w + dist_canvas_needle; //110: if angle < 0, the needle shall be lost-> 110 not enough
   uint8_t canvas_x = 52; //move canvas to posx
   uint8_t canvas_y = canvas_h - dist_canvas_needle - 5; //move canvas to posy

   int16_t angledest = (int16_t)km*0.5-6;

   lv_coord_t canvas_needle_imgX = 0; //after rotate, needle is at position X of canvas
   lv_coord_t canvas_needle_imgY = canvas_h - def01needle.header.h - dist_canvas_needle; //after rotate, needle is at position Y of canvas
   lv_coord_t pivotX = canvas_w/2; //relative source canvas
   lv_coord_t pivotY = def01needle.header.h/2; //relative source canvas

   memset(mpCanvasBuf, 0x0, mCanvasBufSize);
   lv_obj_set_pos(mpCanvas, canvas_x, canvas_y);
   angle = (int16_t)mCurrentSpeed*0.5-6;
   lv_canvas_rotate(mpCanvas, &def01needle, angle, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);

   int16_t diff = angledest - angle;
   while(diff)
   {
      /* Periodically call the lv_task handler.*/
      //lv_task_handler();
#if LVGL_PC_SIMU
      usleep(40*1000);
#elif LVGL_ESP32_ILI9341
      usleep(60*1000);// no flicker
#endif
      /*Clear the canvas*/
      if (diff%20 == 0)
      {
         memset(mpCanvasBuf, 0x0, mCanvasBufSize);
      }
      if (diff > 0) {
         lv_canvas_rotate(mpCanvas, &def01needle, angle++, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
         diff--;
      }
      else
      {
          lv_canvas_rotate(mpCanvas, &def01needle, angle--, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);
          diff++;
      }
   }
   // clear, area of below pivot?
   memset(mpCanvasBuf, 0x0, mCanvasBufSize);
   lv_canvas_rotate(mpCanvas, &def01needle, angle, canvas_needle_imgX, canvas_needle_imgY, pivotX, pivotY);

   mCurrentSpeed = km;
   WRPPRINT("%s\n", "Speedometer::RunSpeedMeter() End");
}

Speedometer::Speedometer(const Speedometer& cp)
: WrpGui::WrpScreen(false)
, mpMeter(NULL)
, mpNeedle(NULL)
, mpLblBackItem(NULL)
, mCurrentSpeed(0)
, mpCanvas(NULL)
, mpCanvasBuf(NULL)
, mCanvasBufSize(0)
{
}
