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
: m_pScrHandler(NULL)
, m_pLblProgramStatus(NULL)
, m_pHmiApp(app)
{
	WRPPRINT("%s", "HomeScreen::HomeScreen() Begin\n");

	// homescreen is a master screen
	m_pScrHandler = new WrpGui::WrpScreen(true);
	m_pScrHandler->SetTitle("Home");
	// homescreen has one label program status
	m_pLblProgramStatus = new WrpGui::WrpLabel(m_pScrHandler);
	m_pLblProgramStatus->SetPos(80, 80);
	m_pLblProgramStatus->SetText("");
	// homescreen has one setting item
	m_pLblSettingItem = new WrpGui::WrpLabel(m_pScrHandler);
	m_pLblSettingItem->SetPos(260, 10);
	m_pLblSettingItem->SetText("Setting");

	WRPPRINT("%s", "HomeScreen::HomeScreen() End\n");
}

HomeScreen::~HomeScreen()
{
	delete m_pScrHandler;
}

void HomeScreen::Update(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
	switch(status)
	{
		case MIDWAPP_STATUS_INIT:
		{
			m_pLblProgramStatus->SetText("Initialing...");
		}
		break;
		case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
		{
			if (!strcmp(buffer, "setting"))
			{
				m_pHmiApp->LoadScreen(SETTINGSCREEN);
			}
			else if (!strcmp(buffer, "shutdown"))
			{
				m_pScrHandler->ShowPopup(true, "Shutting Down!");
			}
			else if(!strcmp(buffer, "SCREEN_PLAIN_COLOR"))
			{
				m_pScrHandler->SetStyle(WrpGui::SCREEN_PLAIN_COLOR);
			}
			else if(!strcmp(buffer, "SCREEN_PRETTY"))
			{
				m_pScrHandler->SetStyle(WrpGui::SCREEN_PRETTY);
			}
			else if(!strcmp(buffer, "SCREEN_PRETTY_COLOR"))
			{
				m_pScrHandler->SetStyle(WrpGui::SCREEN_PRETTY_COLOR);
			}
			else if(!strcmp(buffer, "BUTTON_PRESS"))
			{
				m_pScrHandler->SetStyle(WrpGui::BUTTON_PRESS);
			}
			else if(!strcmp(buffer, "BUTTON_RELEASE"))
			{
				m_pScrHandler->SetStyle(WrpGui::BUTTON_RELEASE);
			}
			else if(!strcmp(buffer, "BUTTON_TGL_RELEASE"))
			{
				m_pScrHandler->SetStyle(WrpGui::BUTTON_TGL_RELEASE);
			}
			else if(!strcmp(buffer, "BUTTON_TGL_PRESS"))
			{
				m_pScrHandler->SetStyle(WrpGui::BUTTON_TGL_PRESS);
			}
			else if (strcmp(buffer, "back"))
			{
				m_pLblProgramStatus->SetText(buffer);
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

