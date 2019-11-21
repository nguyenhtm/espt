/********************************************************************************************************
 * @File  : settingscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@yahoo.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "settingscreen.hpp"
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
SettingScreen::SettingScreen(WrpHmiApp* app)
: m_pScrHandler(NULL)
, m_pHmiApp(app)
, m_pLblBackItem(NULL)
{
	WRPPRINT("%s", "SettingScreen::SettingScreen() Begin\n");

	m_pScrHandler = new WrpGui::WrpScreen(false);
	m_pScrHandler->SetTitle("Setting");
	// settingscreen has one back item
	m_pLblBackItem = new WrpGui::WrpLabel(m_pScrHandler);
	m_pLblBackItem->SetPos(260, 10);
	m_pLblBackItem->SetText("Back");

	WRPPRINT("%s", "SettingScreen::SettingScreen() End\n");
}

SettingScreen::~SettingScreen()
{
	delete m_pScrHandler;
}

void SettingScreen::Update(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
	switch(status)
	{
		case MIDWAPP_STATUS_INIT:
		case MIDWAPP_STATUS_STARTED:
		{
		}
		break;
		case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
		{
			if (!strcmp(buffer, "back"))
			{
				m_pHmiApp->LoadScreen(HOMESCREEN);
			}
		}
		break;
		default:
		{
			//do nothing
		}
		break;
	}
}

void SettingScreen::EnableAnimation()
{
	lv_anim_t a;
	// object need to be animated
	a.var = m_pScrHandler->GetProperty()._pBackground;
	// func to execute anim x
	a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_x;
	a.path_cb = lv_anim_path_linear;
	a.ready_cb = NULL;
	// set start/end value
	a.start = 320; //240 / 2;
	a.end = 0;
    a.time = 200;
    // make delay
    a.act_time = -500;
    // no play back
    a.playback = 0;
    a.playback_pause = 0;
    // no repeat
    a.repeat = 0;
    a.repeat_pause = 0;
    lv_anim_create(&a);
}
