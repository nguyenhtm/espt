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
	m_pScreenHandle->SetStyle(WrpGui::BUTTON_TGL_RELEASE);

	// homescreen has a main menu
	//m_pMenuItem[0] = new WrpGui::WrpImage(m_pScreenHandle);
	//m_pMenuItem[0]->SetImage(WRPRESIMG_HOME);
	//m_pMenuItem[0]->SetPos(WRPSCREEN_MENU_POSX, WRPSCREEN_MENU_POSY);
	m_pMenuItem[1] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuItem[1]->SetImage(WRPRESIMG_AUTOTEST);
	m_pMenuItem[1]->SetPos(WRPSCREEN_WIDTH-30, WRPSCREEN_MENU_POSY);
	m_pMenuItem[2] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuItem[2]->SetImage(WRPRESIMG_DIAGNOSIS);
	m_pMenuItem[2]->SetPos(WRPSCREEN_WIDTH-60, WRPSCREEN_MENU_POSY);

	// homescreen has a logo
	m_pLogo = new WrpGui::WrpImage(m_pScreenHandle);
	m_pLogo->SetImage(WRPRESIMG_LOGO);
	m_pLogo->SetPos(WRPSCREEN_MENU_POSX+120, WRPSCREEN_MENU_POSY+80);

	WRPPRINT("%s", "HomeScreen::HomeScreen() End\n");
}

HomeScreen::~HomeScreen()
{
	delete [] m_pMenuItem;
}

void HomeScreen::CreateAndShow()
{
	WRPPRINT("%s", "HomeScreen::CreateAndShow() Begin\n");
	// homescreen is a master screen, must create in constructor
	m_anim.FadeIn((WrpGui::WrpWidget*)m_pLogo, 2000);
	WRPPRINT("%s", "HomeScreen::CreateAndShow() End\n");
}

void HomeScreen::HideAndDestroy()
{
	WRPPRINT("%s", "HomeScreen::HideAndDestroy() Begin\n");
	// homescreen is a master screen, must not delete it
	WRPPRINT("%s", "HomeScreen::HideAndDestroy() End\n");
}

void HomeScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
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
			else if (!strcmp(buffer, "cflow"))
			{
				m_pHmiApp->LoadScreen(CFLOWSCREEN);
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
				//m_anim.Select();
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

