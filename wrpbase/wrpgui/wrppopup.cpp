/********************************************************************************************************
 * @File  : wrpopup.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrppopup.hpp"
#include "wrpscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpGui {

// WrpPopup Class Methods

WrpPopup::WrpPopup(WrpScreen* parent)
{
	WRPPRINT("%s", "WrpPopup::WrpPopup() Begin\n");
	SetPos(100, -20);
	SetSize(WRPPOPUP_WIDTH, WRPPOPUP_HEIGHT);
	SetStyle(m_pHandler, BUTTON_PRESS);
	WRPPRINT("%s", "WrpPopup::WrpPopup() End\n");
}

WrpPopup::~WrpPopup()
{
	WRPNULL_CHECK(m_pHandler)
	// delete screen 'm_pHandler' and all its children
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
	a.start = -20; //240 / 2;
	a.end = 120;
    a.time = 400;
    // make delay
    a.act_time = -500;
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
