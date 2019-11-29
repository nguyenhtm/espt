/********************************************************************************************************
 * @File  : wrpscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpscreen.hpp"
#include "wrplabel.hpp"
#include "wrppopup.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpScreen::WrpScreen(const bool bMasterScreen)
: m_bMasterScreen(bMasterScreen)
, m_pMenuTitle(NULL)
, m_pTopPopup(NULL)
{
	WRPPRINT("WrpScreen::WrpScreen() bMaster=%d Begin\n", bMasterScreen);

	// screen creation
	if (bMasterScreen == true)
    {
    	// not create new screen, use current loaded screen as a master screen
    	m_pHandler = lv_disp_get_scr_act(NULL);
    }
    else
    {
    	// create a new screen
    	m_pHandler = lv_obj_create(NULL, NULL);
    }

	// screen menu items creation
	m_pMenuTitle = new WrpLabel(this);
	m_pMenuTitle->SetPos(WRPSCREEN_MENU_POSX, WRPSCREEN_MENU_POSY);

    WrpStyle::SetStyle(m_pHandler, SCREEN_PRETTY_COLOR);
    m_pTopPopup = new WrpPopup(this);
    WRPPRINT("WrpScreen::WrpScreen() bMaster=%d End\n", bMasterScreen);
}

WrpScreen::~WrpScreen()
{
	// delete screen 'm_pHandler' and all its children
	lv_obj_del(m_pHandler);
	delete m_pMenuTitle;
	delete m_pTopPopup;
}

void WrpScreen::Load()
{
	WRPNULL_CHECK(m_pHandler)
	m_pTopPopup->Hide();
	lv_disp_load_scr(m_pHandler);
}

void WrpScreen::ShowPopup(const bool bShowHide, const char* text)
{
	WRPNULL_CHECK(m_pTopPopup)
	if (bShowHide)
	{
		m_pTopPopup->SetText(text);
		m_pTopPopup->Show();
	}
	else
	{
		m_pTopPopup->Hide();
	}
}

void WrpScreen::SetTitle(const char* text)
{
	WRPNULL_CHECK(m_pMenuTitle)
	m_pMenuTitle->SetText(text);
}

void WrpScreen::SetStyle(const WrpStyleType style)
{
	WrpStyle::SetStyle(m_pHandler, style);
	WrpStyle::SetStyle(m_pTopPopup->m_pHandler, style);
}

} /* WrpGui Namespace */
