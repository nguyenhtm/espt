/********************************************************************************************************
 * @File  : homescreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@yahoo.com
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
			else if(!strcmp(buffer, "style"))
			{
				static int count = 0;
				switch (count)
				{
				case 0: {m_pScrHandler->SetStyle(WrpGui::SCREEN_DEFAULT); count++;} break;
				case 1: {m_pScrHandler->SetStyle(WrpGui::SCREEN_PLAIN_COLOR); count++;} break;
				case 2: {m_pScrHandler->SetStyle(WrpGui::SCREEN_PRETTY); count++;} break;
				case 3: {m_pScrHandler->SetStyle(WrpGui::SCREEN_PRETTY_COLOR); count++;} break;
				case 4: {m_pScrHandler->SetStyle(WrpGui::BUTTON_PRESS); count++;} break;
				case 5: {m_pScrHandler->SetStyle(WrpGui::BUTTON_RELEASE); count++;} break;
				case 6: {m_pScrHandler->SetStyle(WrpGui::BUTTON_TGL_RELEASE); count++;} break;
				case 7: {m_pScrHandler->SetStyle(WrpGui::BUTTON_TGL_PRESS); count++;} break;


				default: count = 0; break;
				}
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

