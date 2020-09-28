/********************************************************************************************************
 * @File  : wrpwidget.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpwidget.hpp"
#include "wrpscreen.hpp"
#include "wrpstyle.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpWidget
 ********************************************************************************************************/
WrpWidget::WrpWidget(WrpScreen* parent)
: mpScreenHandle(parent)
, mpWidgetHandle(NULL)
{
   WRPPRINT("%s\n", "WrpWidget::WrpWidget() Begin");
   if (parent)
   {
      //widget must be a WrpScreen child
      mpWidgetHandle = lv_obj_create(parent->GetHandle(), NULL);
      mpAppearance = new WrpStyle(mpWidgetHandle);
      mpAppearance->SetStyle(BUTTON_TGL_RELEASE);
   }
   WRPPRINT("%s\n", "WrpWidget::WrpWidget() End");
}
WrpWidget::~WrpWidget()
{
   WRPPRINT("%s\n", "WrpWidget::~WrpWidget() Begin");
   WRPNULL_CHECK(mpScreenHandle)
   delete mpAppearance;
   delete mpWidgetHandle;
   WRPPRINT("%s\n", "WrpWidget::~WrpWidget() End");
}
wrpgui_pos_t WrpWidget::GetX()
{
   WRPNULL_CHECKRET(mpWidgetHandle)
   return lv_obj_get_x(mpWidgetHandle);
}
wrpgui_pos_t WrpWidget::GetY()
{
   WRPNULL_CHECKRET(mpWidgetHandle)
   return lv_obj_get_y(mpWidgetHandle);
}
wrpgui_size_t WrpWidget::GetW()
{
   WRPNULL_CHECKRET(mpWidgetHandle)
   return lv_obj_get_width(mpWidgetHandle);
}
wrpgui_size_t WrpWidget::GetH()
{
   WRPNULL_CHECKRET(mpWidgetHandle)
   return lv_obj_get_height(mpWidgetHandle);
}
void WrpWidget::SetX(const wrpgui_pos_t x)
{
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_x(mpWidgetHandle, x);
}
void WrpWidget::SetY(const wrpgui_pos_t y)
{
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_y(mpWidgetHandle, y);
}
void WrpWidget::SetW(const wrpgui_size_t w)
{
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_width(mpWidgetHandle, w);
}
void WrpWidget::SetH(const wrpgui_size_t h)
{
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_height(mpWidgetHandle, h);
}
void WrpWidget::SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y)
{
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_pos(mpWidgetHandle, x, y);
}
void WrpWidget::SetSize(const wrpgui_size_t w, const wrpgui_size_t h)
{
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_size(mpWidgetHandle, w, h);
}
WrpWidget::WrpWidget()
: mpScreenHandle(NULL)
, mpWidgetHandle(NULL)
{
}
WrpWidget::WrpWidget(const WrpWidget& cp)
: mpScreenHandle(NULL)
, mpWidgetHandle(NULL)
{
}

/*********************************************************:***********************************************
 * FUNCTIONS - WrpDecorator
 ********************************************************************************************************/
WrpDecorator::WrpDecorator(WrpWidget* component)
: mpComponent(component)
{
}
WrpDecorator::~WrpDecorator()
{
}
void WrpDecorator::SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y)
{
   //delegates all work to the wrapped component
   mpComponent->SetPos(x, y);
}
WrpDecorator::WrpDecorator(const WrpDecorator& cp)
: mpComponent(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpAnim
 ********************************************************************************************************/
WrpAnimEx::WrpAnimEx(WrpWidget* component, uint16_t duration)
: WrpDecorator(component)
, mDuration(duration)
{
}
WrpAnimEx::~WrpAnimEx()
{
}
void WrpAnimEx::SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y)
{
   WRPPRINT("%s\n", "WrpAnimEx::SetPos() Begin");
   // Do fade in first
   lv_obj_set_opa_scale_enable(mpComponent->mpWidgetHandle, true);
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, mDuration, 0);
   lv_anim_set_values(&anim, LV_OPA_TRANSP, LV_OPA_COVER);
   lv_anim_set_exec_cb(&anim, mpComponent->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_opa_scale);
   lv_anim_clear_playback(&anim);
   lv_anim_create(&anim);
   // and the Set to position
   WrpDecorator::SetPos(x, y);
   WRPPRINT("%s\n", "WrpAnimEx::SetPos() End");
}
void WrpAnimEx::MoveX(const wrpgui_pos_t x1, const wrpgui_pos_t x2) const
{
   WRPPRINT("%s\n", "WrpAnim::MoveX() Begin");
   lv_obj_set_opa_scale_enable(mpComponent->mpWidgetHandle, true);
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, mDuration, 0);
   lv_anim_set_values(&anim, x1, x2);
   lv_anim_set_exec_cb(&anim, mpComponent->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_x);
   lv_anim_clear_playback(&anim);
   //playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
   lv_anim_create(&anim);
   WRPPRINT("%s\n", "WrpAnim::MoveX() End");
}
void WrpAnimEx::MoveY(const wrpgui_pos_t y1, const wrpgui_pos_t y2) const
{
   WRPPRINT("%s\n", "WrpAnim::MoveX() Begin");
   lv_obj_set_opa_scale_enable(mpComponent->mpWidgetHandle, true);
   lv_anim_t anim;
   lv_anim_init(&anim);
   lv_anim_set_time(&anim, mDuration, 0);
   lv_anim_set_values(&anim, y1, y2);
   lv_anim_set_exec_cb(&anim, mpComponent->mpWidgetHandle, (lv_anim_exec_xcb_t)lv_obj_set_y);
   lv_anim_clear_playback(&anim);
   //playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
   lv_anim_create(&anim);
   WRPPRINT("%s\n", "WrpAnim::MoveX() End");
}
WrpAnimEx::WrpAnimEx(const WrpAnimEx& cp)
: WrpDecorator(NULL)
, mDuration(0)
{
}

} /* WrpGui Namespace */
