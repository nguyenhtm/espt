/*
 * File  : wrpscreen.cpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpGui
{

WrpScreen::WrpScreen(const bool bMaster)
: m_pHandler(NULL)
{
	WRPPRINT("WrpScreen::WrpScreen() bMaster=%d Begin\n", bMaster);

	if (bMaster == true)
    {
    	// get the current loaded screen as a master screen
    	m_pHandler = m_property._pHandler = lv_disp_get_scr_act(NULL);
    }
    else
    {
    	m_pHandler = m_property._pHandler = lv_obj_create(NULL, NULL);
    }
	// set screen properties
	m_property._bMaster = bMaster;
    m_property._pTitle  = lv_label_create(m_pHandler, NULL);
    m_property._width   = lv_obj_get_width(m_pHandler);
    m_property._height  = lv_obj_get_height(m_pHandler);
    WRPPRINT("WrpScreen::WrpScreen() screen width:%d, height:%d\n", m_property._width, m_property._height);

    // set title properties
    lv_obj_set_pos(m_property._pTitle, 10, 10);
    lv_obj_set_size(m_property._pTitle, 100, 66);

    WrpStyle::SetStyle(m_pHandler, SCREEN_PRETTY_COLOR);
    m_popup = new WrpPopup(this);
    WRPPRINT("WrpScreen::WrpScreen() bMaster=%d End\n", bMaster);
}

WrpScreen::~WrpScreen()
{
	WRPNULL_CHECK(m_property._pHandler)
	// delete screen 'm_pHandler' and all its children
	lv_obj_del(m_property._pHandler);
}

void WrpScreen::Load()
{
	WRPNULL_CHECK(m_property._pHandler)
	m_popup->Hide();
	lv_disp_load_scr(m_property._pHandler);
}

void WrpScreen::ShowPopup(bool bEnable, const char* text)
{
	WRPNULL_CHECK(m_popup)
	if (bEnable)
	{
		m_popup->SetText(text);
		m_popup->Show();
	}
	else
	{
		//lv_obj_set_hidden(m_popup, true);
		m_popup->Hide();
	}
}

void WrpScreen::SetTitle(const char* text)
{
	WRPNULL_CHECK(m_property._pTitle)
    lv_label_set_text(m_property._pTitle, text);
}

void WrpScreen::SetStyle(const WrpStyleType style)
{
	WrpStyle::SetStyle(m_pHandler, style);
}

} /* WrpGui Namespace */
