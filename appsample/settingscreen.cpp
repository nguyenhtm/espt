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
: m_pHmiApp(app)
, m_pLblBackItem(NULL)
{
	WRPPRINT("%s", "SettingScreen::SettingScreen() Begin\n");

	WRPPRINT("%s", "SettingScreen::SettingScreen() End\n");
}

SettingScreen::~SettingScreen()
{
	WRPPRINT("%s", "SettingScreen::~SettingScreen() Begin\n");

	WRPPRINT("%s", "SettingScreen::~SettingScreen() End\n");
}

void SettingScreen::CreateAndShow()
{
	WRPPRINT("%s", "SettingScreen::CreateAndShow() Begin\n");
	m_pScreenHandle = new WrpGui::WrpScreen(false);
	m_pScreenHandle->SetTitle("Setting");
	// settingscreen has one back item
	m_pLblBackItem = new WrpGui::WrpLabel(m_pScreenHandle);
	m_pLblBackItem->SetPos(260, 10);
	m_pLblBackItem->SetText("Back");

	// settingscreen has 4 menu items
	for (int i = 0; i < 5; i++)
	{
		m_pMenuItem[i] = new WrpGui::WrpWidget(m_pScreenHandle);
	}

	m_anim.SetWidgets(m_pMenuItem);
	WRPPRINT("%s", "SettingScreen::CreateAndShow() End\n");
}

void SettingScreen::HideAndDestroy()
{
	WRPPRINT("%s", "SettingScreen::HideAndDestroy() Begin\n");
	WRPNULL_CHECK(m_pScreenHandle)
	delete m_pScreenHandle;
	delete m_pLblBackItem;
	for (int i = 0; i < 5; i++)
	{
		//delete m_pMenuItem[i];
	}
	WRPPRINT("%s", "SettingScreen::HideAndDestroy() End\n");
}

void SettingScreen::Update(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
	WRPPRINT("%s", "SettingScreen::Update() Begin\n");

	switch(status)
	{
		case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
		{
			if (!strcmp(buffer, "setting"))
			{
				m_anim.Select();
			}
			else if (!strcmp(buffer, "next"))
			{
				m_anim.Select();
			}
			else if (!strcmp(buffer, "back"))
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
	WRPPRINT("%s", "SettingScreen::Update() End\n");
}
