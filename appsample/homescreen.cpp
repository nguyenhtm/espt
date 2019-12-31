/********************************************************************************************************
 * @File  : homescreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "homescreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
HomeScreen::HomeScreen(WrpHmiApp* app)
: m_pLblProgramStatus(NULL)
, m_pLblSettingItem(NULL)
, m_pHmiApp(app)
{
	WRPPRINT("%s", "HomeScreen::HomeScreen() Begin\n");

	// homescreen is a master screen
	m_pScreenHandle = new WrpGui::WrpScreen(true);
	m_pScreenHandle->SetTitle("Home");
	// homescreen has one label program status
	m_pLblProgramStatus = new WrpGui::WrpLabel(m_pScreenHandle);
	m_pLblProgramStatus->SetPos(80, 80);
	m_pLblProgramStatus->SetText("");
	// homescreen has one setting item
	m_pLblSettingItem = new WrpGui::WrpLabel(m_pScreenHandle);
	m_pLblSettingItem->SetPos(260, 10);
	m_pLblSettingItem->SetText("Setting");

	WRPPRINT("%s", "HomeScreen::HomeScreen() End\n");
}

HomeScreen::~HomeScreen()
{

}

void HomeScreen::CreateAndShow()
{
	WRPPRINT("%s", "HomeScreen::CreateAndShow() Begin\n");
	// homescreen is a master screen, must create in constructor
	WRPPRINT("%s", "HomeScreen::CreateAndShow() End\n");
}

void HomeScreen::HideAndDestroy()
{
	WRPPRINT("%s", "HomeScreen::HideAndDestroy() Begin\n");
	// homescreen is a master screen, must not delete it
	WRPPRINT("%s", "HomeScreen::HideAndDestroy() End\n");
}

void HomeScreen::Update(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
	WRPPRINT("%s", "HomeScreen::Update() Begin\n");

	switch(status)
	{
		case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
		{
			if (!strcmp(buffer, "setting"))
			{
				m_pHmiApp->LoadScreen(SETTINGSCREEN);
			}
			else if (!strcmp(buffer, "shutdown"))
			{
				m_pScreenHandle->ShowPopup(true, "Shutting Down!");
			}
			else if(!strcmp(buffer, "SCREEN_PLAIN_COLOR"))
			{
				m_pScreenHandle->SetStyle(WrpGui::SCREEN_PLAIN_COLOR);
			}
			else if(!strcmp(buffer, "SCREEN_PRETTY"))
			{
				m_pScreenHandle->SetStyle(WrpGui::SCREEN_PRETTY);
			}
			else if(!strcmp(buffer, "SCREEN_PRETTY_COLOR"))
			{
				m_pScreenHandle->SetStyle(WrpGui::SCREEN_PRETTY_COLOR);
			}
			else if(!strcmp(buffer, "BUTTON_PRESS"))
			{
				m_pScreenHandle->SetStyle(WrpGui::BUTTON_PRESS);
			}
			else if(!strcmp(buffer, "BUTTON_RELEASE"))
			{
				m_pScreenHandle->SetStyle(WrpGui::BUTTON_RELEASE);
			}
			else if(!strcmp(buffer, "BUTTON_TGL_RELEASE"))
			{
				m_pScreenHandle->SetStyle(WrpGui::BUTTON_TGL_RELEASE);
			}
			else if(!strcmp(buffer, "BUTTON_TGL_PRESS"))
			{
				m_pScreenHandle->SetStyle(WrpGui::BUTTON_TGL_PRESS);
			}
			else if (strcmp(buffer, "back"))
			{
				m_pLblProgramStatus->SetText("Welcome Home");
			}

		}
		break;
		default:
		{
			//do nothing
		}
		break;
	}
	WRPPRINT("%s", "HomeScreen::Update() End\n");
}

