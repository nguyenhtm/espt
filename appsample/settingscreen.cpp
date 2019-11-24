/********************************************************************************************************
 * @File  : settingscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
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
