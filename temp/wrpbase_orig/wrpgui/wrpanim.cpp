/********************************************************************************************************
 * @File  : wrpanim.cpp
 * @Date  : 2019-12-03
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpanim.hpp"
#include "wrpwidget.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpAnim::WrpAnim()
: mSelected(0)
{
   WRPPRINT("%s\n", "WrpAnim::WrpAnim() Begin");
   WRPPRINT("%s\n", "WrpAnim::WrpAnim() End");
}

WrpAnim::~WrpAnim()
{
   WRPPRINT("%s\n", "WrpAnim::~WrpAnim() Begin");
   WRPPRINT("%s\n", "WrpAnim::~WrpAnim() End");
}

void WrpAnim::SetWidgets(WrpWidget* widgets[], const uint16_t size)
{
   mpListOfWidgets = widgets;
   mNumOfWidgets = size;
}

void WrpAnim::Liverpool()
{
   WRPPRINT("%s\n", "WrpAnim::Liverpool() Begin");
   static int flag = 0;
   mPosX = 140; mPosY = 60;
   wrpgui_pos_t _xI = 140;
   wrpgui_pos_t _yI = 120;

   if (mSelected)
   {
      mpListOfWidgets[0]->SetPos(mPosX, mPosY);
   }
   else if (!flag)
   {
      mpListOfWidgets[0]->SetPos(mPosX, mPosY);
      flag = ~flag;
   }

	for (int i = 1; i < mNumOfWidgets; i++)
	{
		float alpha = ((2 * 3.14159 * i)/mNumOfWidgets);
		int32_t x = _xI + (mpListOfWidgets[0]->GetX() - _xI)*cos(alpha) - (mpListOfWidgets[0]->GetY() - _yI)*sin(alpha);
		int32_t y = _yI + (mpListOfWidgets[0]->GetX() - _xI)*sin(alpha) + (mpListOfWidgets[0]->GetY() - _yI)*cos(alpha);
		mpListOfWidgets[i]->SetPos(x, y);
	}
	for (int i = 0; i < mNumOfWidgets; i++)
	{
		if (i != mNumOfWidgets-1)
		{
			MoveXY(mpListOfWidgets[i], mpListOfWidgets[i]->GetX(), mpListOfWidgets[i]->GetY(), mpListOfWidgets[i+1]->GetX(), mpListOfWidgets[i+1]->GetY(), 400, false);
		}
		else
		{
			MoveXY(mpListOfWidgets[mNumOfWidgets-1], mpListOfWidgets[mNumOfWidgets-1]->GetX(), mpListOfWidgets[mNumOfWidgets-1]->GetY(), mpListOfWidgets[0]->GetX(), mpListOfWidgets[0]->GetY(), 400, false);
		}
	}

   WrpWidget* tmp = mpListOfWidgets[0];
   for (int i = 0; i < mNumOfWidgets-1; i++)
   {
      mpListOfWidgets[i] = mpListOfWidgets[i+1];
   }
   mpListOfWidgets[mNumOfWidgets-1] = tmp;

   mSelected = 0;
   WRPPRINT("%s\n", "WrpCoverFlow::Liverpool() End");
}

void WrpAnim::Barcelona()
{
   WRPPRINT("%s\n", "WrpAnim::Barcelona() Begin");
   // Set start position of list of widgets
   mPosX = 10; mPosY = 40;
   mpListOfWidgets[0]->SetPos(mPosX, mPosY);
   for (int i = 1; i < mNumOfWidgets; i++)
   {
      mpListOfWidgets[i]->SetPos(mPosX, mpListOfWidgets[i-1]->GetY() + 40);
   }
   // Do Barcelona animation type
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      MoveX(mpListOfWidgets[i], mpListOfWidgets[i]->GetX(), mpListOfWidgets[i]->GetX() + 10, 300, true);
      usleep(350*1000);
   }
   mSelected = 1;
   WRPPRINT("%s\n", "WrpAnim::Barcelona() End");
}

void WrpAnim::RealMadrid()
{
   WRPPRINT("%s\n", "WrpAnim::RealMadrid() Begin");
   // Set start position of list of widgets
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      mpListOfWidgets[i]->SetPos((320/mNumOfWidgets)*i + 10, mPosY + 20);
   }
   // Do Real Madrid animation type
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      MoveY(mpListOfWidgets[i], mpListOfWidgets[i]->GetY(), mpListOfWidgets[i]->GetY()+80, 1000, true);
      usleep(350*1000);
   }
   mSelected = 2;
   WRPPRINT("%s\n", "WrpAnim::RealMadrid() End");
}

void WrpAnim::Chealse()
{
   WRPPRINT("%s\n", "WrpAnim::Chealse() Begin");
   // Set start position of list of widgets
   mPosX = 40; mPosY = 80;
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      mpListOfWidgets[i]->SetPos(mPosX, mPosY);
   }
   // Do Chealse animation type
   for (int i = mNumOfWidgets-1; i > 0; i--)
   {
      MoveX(mpListOfWidgets[i], mpListOfWidgets[0]->GetX(), mpListOfWidgets[0]->GetX() + 40*i, 150*i, false);
      usleep(350*1000);
   }
   mSelected = 3;
   WRPPRINT("%s\n", "WrpAnim::Chealse() End");
}

void WrpAnim::Messi()
{
   WRPPRINT("%s\n", "WrpAnim::Messi() Begin");
   mPosX = 140; mPosY = 60;
   wrpgui_pos_t _xI = 140, _yI = 120;

   // move to circle positions
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      mpListOfWidgets[i]->SetPos(_xI, _yI);
   }
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      float alpha = ((2 * 3.14159 * i)/mNumOfWidgets);
      int32_t x = _xI + (mPosX - _xI)*cos(alpha) - (mPosY - _yI)*sin(alpha);
      int32_t y = _yI + (mPosX - _xI)*sin(alpha) + (mPosY - _yI)*cos(alpha);
      MoveXY(mpListOfWidgets[i], mpListOfWidgets[i]->GetX(), mpListOfWidgets[i]->GetY(), x, y, 500, false);
   }
   usleep(2000*1000);

   // rotate
   Liverpool();
   usleep(1500*1000);
   Liverpool();
   usleep(1500*1000);

   // move to center
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      MoveXY(mpListOfWidgets[i], mpListOfWidgets[i]->GetX(), mpListOfWidgets[i]->GetY(), _xI, _yI, 500, false);
   }
   usleep(2000*1000);

   // move to RealMadrid
   for (int i = 0; i < mNumOfWidgets; i++)
   {
      MoveXY(mpListOfWidgets[i], mpListOfWidgets[i]->GetX(), mpListOfWidgets[i]->GetY(), (320/mNumOfWidgets)*i + 10, 80, 500, false);
   }
   usleep(2000*1000);
   RealMadrid();

   mSelected = 4;
   WRPPRINT("%s\n", "WrpAnim::Messi() End");
}

void WrpAnim::FadeIn(const WrpWidget* widget, const uint16_t duration)
{
   WRPPRINT("%s\n", "WrpAnim::FadeIn() Begin");
   lv_obj_set_opa_scale_enable(widget->mpWidgetHandle, true);
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, duration, 0);
   lv_anim_set_values(&anim, LV_OPA_TRANSP, LV_OPA_COVER);
   lv_anim_set_exec_cb(&anim, widget->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_opa_scale);
   lv_anim_create(&anim);
   WRPPRINT("%s\n", "WrpAnim::FadeIn() End");
}

void WrpAnim::FadeOut(const WrpWidget* widget, const uint16_t duration)
{
   WRPPRINT("%s\n", "WrpAnim::FadeOut() Begin");
   lv_obj_set_opa_scale_enable(widget->mpWidgetHandle, true);
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, duration, 0);
   lv_anim_set_values(&anim, LV_OPA_TRANSP, LV_OPA_COVER);
   lv_anim_set_exec_cb(&anim, widget->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_opa_scale);
   lv_anim_create(&anim);
   WRPPRINT("%s\n", "WrpAnim::FadeOut() End");
}

void WrpAnim::MoveX(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t x2, const uint16_t duration, const bool playback)
{
   WRPPRINT("%s\n", "WrpAnim::MoveX() Begin");
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, duration, 0);
   lv_anim_set_playback(&anim, 0);
   lv_anim_set_values(&anim, x1, x2);
   lv_anim_set_exec_cb(&anim, widget->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_x);
   playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
   lv_anim_create(&anim);
   WRPPRINT("%s\n", "WrpAnim::MoveX() End");
}

void WrpAnim::MoveY(const WrpWidget* widget, const wrpgui_pos_t y1, const wrpgui_pos_t y2, const uint16_t duration, const bool playback)
{
   WRPPRINT("%s\n", "WrpAnim::MoveY() Begin");
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, duration, 0);
   lv_anim_set_values(&anim, y1, y2);
   lv_anim_set_exec_cb(&anim, widget->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_y);
   playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
   lv_anim_create(&anim);
   WRPPRINT("%s\n", "WrpAnim::MoveY() End");
}

void WrpAnim::MoveXY(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t y1, const wrpgui_pos_t x2, const wrpgui_pos_t y2, const uint16_t duration, const bool playback)
{
   WRPPRINT("%s\n", "WrpAnim::MoveXY() Begin");
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, duration, 0);

   lv_anim_set_values(&anim, x1, x2);
   lv_anim_set_exec_cb(&anim, widget->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_x);
   lv_anim_create(&anim);

   lv_anim_set_values(&anim, y1, y2);
   lv_anim_set_exec_cb(&anim, widget->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_y);
   lv_anim_create(&anim);

   playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
   lv_anim_create(&anim);
   WRPPRINT("%s\n", "WrpAnim::MoveXY() End");
}

} /* WrpGui Namespace */
