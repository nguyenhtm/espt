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
 * FUNCTIONS
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

} /* WrpGui Namespace */
