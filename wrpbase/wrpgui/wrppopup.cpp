/********************************************************************************************************
 * @File  : wrpopup.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrppopup.hpp"
#include "wrpbase/wrpbase.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpGui {

// WrpPopup Class Methods

WrpPopup::WrpPopup(WrpScreen* parent)
: WrpWidget(parent)
{
	WRPPRINT("%s", "WrpPopup::WrpPopup() Begin\n");

	m_style.SetStyle(m_pHandler, BUTTON_TGL_RELEASE);
	SetPos(80, -WRPPOPUP_HEIGHT);
	SetSize(WRPPOPUP_WIDTH, WRPPOPUP_HEIGHT);

	m_pPopupText = lv_label_create(m_pHandler, NULL);
	lv_obj_align(m_pPopupText, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);

	WRPPRINT("%s", "WrpPopup::WrpPopup() End\n");
}

WrpPopup::~WrpPopup()
{
	//lv_obj_del(m_pHandler);
}

void WrpPopup::Show()
{
	WRPNULL_CHECK(m_pHandler)

	lv_obj_set_hidden(m_pHandler, false);
	EnableAnimation();
}

void WrpPopup::Hide()
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_hidden(m_pHandler, true);
}

void WrpPopup::SetText(const char* text)
{
	char tmp[255];
	sprintf(tmp, "%s%s", "  ", text);
	lv_label_set_text(m_pPopupText, LV_SYMBOL_POWER "hello");
}

void WrpPopup::EnableAnimation()
{
	lv_anim_t a;

	// object need to be animated
	a.var = m_pHandler;
	// func to execute anim y
	a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_y;
	a.path_cb = lv_anim_path_linear;
	a.ready_cb = NULL;
	// set start/end value
	a.start = -WRPPOPUP_HEIGHT; //240 / 2;
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
    lv_anim_create(&a); // move top down

/*
	// set start/end value
	a.start = 120;
	a.end = 0;
    lv_anim_create(&a); // move down top
*/
}

} /* WrpGui Namespace */
