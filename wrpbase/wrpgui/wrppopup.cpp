/********************************************************************************************************
 * @File  : wrpopup.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrppopup.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpPopup::WrpPopup(WrpScreen* parent)
: WrpWidget(parent)
{
   WRPPRINT("%s\n", "WrpPopup::WrpPopup() Begin");
   SetPos(WRPPOPUP_POSX, -WRPPOPUP_HEIGHT);
   SetSize(WRPPOPUP_WIDTH, WRPPOPUP_HEIGHT);
   //mpAppearance->SetStyle(BUTTON_TGL_RELEASE);
   mpPopupText = lv_label_create(mpWidgetHandle, NULL);
   lv_obj_align(mpPopupText, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
   WRPPRINT("%s\n", "WrpPopup::WrpPopup() End");
}

WrpPopup::~WrpPopup()
{
   WRPPRINT("%s\n", "WrpPopup::~WrpPopup() Begin");
   lv_obj_del(mpPopupText);
   WRPPRINT("%s\n", "WrpPopup::~WrpPopup() End");
}

void WrpPopup::Show()
{
   WRPPRINT("%s\n", "WrpPopup::Show() Begin");
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_hidden(mpWidgetHandle, false);
   EnableAnimation();
   WRPPRINT("%s\n", "WrpPopup::Show() End");
}

void WrpPopup::Hide()
{
   WRPPRINT("%s\n", "WrpPopup::Hide() Begin");
   WRPNULL_CHECK(mpWidgetHandle)
   lv_obj_set_hidden(mpWidgetHandle, true);
   WRPPRINT("%s\n", "WrpPopup::Hide() End");
}

void WrpPopup::SetText(const char* text)
{
   WRPPRINT("%s\n", "WrpPopup::SetText() Begin");
   //char tmp[100];
   //sprintf(tmp, "%s%s", "  ", text);
   //lv_label_set_text(mpPopupText, LV_SYMBOL_POWER "hello");
   lv_label_set_text(mpPopupText, text);
   WRPPRINT("%s\n", "WrpPopup::SetText() End");
}

void WrpPopup::EnableAnimation()
{
   WRPPRINT("%s\n", "WrpPopup::SetText() Begin");
   lv_anim_t a;
   // object need to be animated
   a.var = mpWidgetHandle;
   // func to execute anim y
   a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_y;
   a.path_cb = lv_anim_path_linear;
   a.ready_cb = NULL;
   // set start/end value
   a.start = -WRPPOPUP_HEIGHT; // move top down
   a.end = 40;
   a.time = 400;
   // make delay
   a.act_time = -400;
   // no play back
   a.playback = 1;
   a.playback_pause = 1500;
   // no repeat
   a.repeat = 0;
   a.repeat_pause = 0;
   lv_anim_create(&a);
}

} /* WrpGui Namespace */
