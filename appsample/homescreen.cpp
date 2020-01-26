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
: m_pHmiApp(app)
{
	WRPPRINT("%s", "HomeScreen::HomeScreen() Begin\n");

	// homescreen is a master screen
	m_pScreenHandle = new WrpGui::WrpScreen(true);
	m_pScreenHandle->SetTitle("");
	// homescreen has a menu items
	m_pMenuImage[0] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuImage[0]->SetImage(WRPRESIMG_HOME);
	m_pMenuImage[0]->SetSize(30, 30);
	m_pMenuImage[1] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuImage[1]->SetImage(WRPRESIMG_APP);
	m_pMenuImage[1]->SetSize(30, 30);
	m_pMenuImage[2] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuImage[2]->SetImage(WRPRESIMG_SETTING);
	m_pMenuImage[2]->SetSize(30, 30);
	m_pMenuImage[3] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuImage[3]->SetImage(WRPRESIMG_DIAGNOSIS);
	m_pMenuImage[3]->SetSize(30, 30);
	m_anim.SetWidgets((WrpGui::WrpWidget**)m_pMenuImage, 4);
	WRPPRINT("%s", "HomeScreen::HomeScreen() End\n");
}

HomeScreen::~HomeScreen()
{
	for (int i = 0; i < 5; i++)
	{
		delete m_pMenuImage[i];
	}
}

void HomeScreen::CreateAndShow()
{
	WRPPRINT("%s", "HomeScreen::CreateAndShow() Begin\n");
	// homescreen is a master screen, must create in constructor
	m_anim.Select2();
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
		case MIDWAPP_STATUS_START:
		case MIDWAPP_STATUS_STOP:
			break;
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
			else if(!strcmp(buffer, "next"))
			{
				m_anim.Select2();
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

