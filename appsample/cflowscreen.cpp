/********************************************************************************************************
 * @File  : cflowscreen.cpp
 * @Date  : 2020-02-08
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "cflowscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
CFlowScreen::CFlowScreen(WrpHmiApp* app)
: m_pHmiApp(app)
{
	WRPPRINT("%s", "CFlowScreen::CFlowScreen() Begin\n");

	// cflowscreen is a normal screen
	m_pScreenHandle = new WrpGui::WrpScreen(false);
	m_pScreenHandle->SetTitle("");
	m_pScreenHandle->SetStyle(WrpGui::BUTTON_TGL_RELEASE);

	// cflowscreen has a main menu
	m_pMenuItem[0] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuItem[0]->SetImage(WRPRESIMG_CFLOWITEM1);
	m_pMenuItem[0]->SetPos(WRPSCREEN_WIDTH-60, WRPSCREEN_MENU_POSY);
	m_pMenuItem[1] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuItem[1]->SetImage(WRPRESIMG_CFLOWITEM2);
	m_pMenuItem[1]->SetPos(WRPSCREEN_WIDTH-120, WRPSCREEN_MENU_POSY);
	m_pMenuItem[2] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuItem[2]->SetImage(WRPRESIMG_CFLOWITEM3);
	m_pMenuItem[2]->SetPos(WRPSCREEN_WIDTH-180, WRPSCREEN_MENU_POSY);
	m_pMenuItem[3] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pMenuItem[3]->SetImage(WRPRESIMG_CFLOWITEM4);
	m_pMenuItem[3]->SetPos(WRPSCREEN_WIDTH-240, WRPSCREEN_MENU_POSY);

	// cflowscreen has items to demo many kinds of coverflow
	m_pAnimItem[0] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pAnimItem[0]->SetImage(WRPRESIMG_APP);
	m_pAnimItem[1] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pAnimItem[1]->SetImage(WRPRESIMG_SETTING);
	m_pAnimItem[2] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pAnimItem[2]->SetImage(WRPRESIMG_DIAGNOSIS);
	m_pAnimItem[3] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pAnimItem[3]->SetImage(WRPRESIMG_AUTOTEST);
	m_pAnimItem[4] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pAnimItem[4]->SetImage(WRPRESIMG_WIFI2);
	m_pAnimItem[5] = new WrpGui::WrpImage(m_pScreenHandle);
	m_pAnimItem[5]->SetImage(WRPRESIMG_HOME);
	m_anim.SetWidgets((WrpGui::WrpWidget**)m_pAnimItem, 6);

	// Do animation
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[0]);
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[1]);
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[2]);
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[3]);

	WRPPRINT("%s", "CFlowScreen::CFlowScreen() End\n");
}

CFlowScreen::~CFlowScreen()
{

}

void CFlowScreen::CreateAndShow()
{
	WRPPRINT("%s", "CFlowScreen::CreateAndShow() Begin\n");
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[0]);
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[1]);
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[2]);
	m_anim.FadeInOut((WrpGui::WrpWidget*)m_pMenuItem[3]);
	m_anim.Select2();
	WRPPRINT("%s", "CFlowScreen::CreateAndShow() End\n");
}

void CFlowScreen::HideAndDestroy()
{
	WRPPRINT("%s", "CFlowScreen::HideAndDestroy() Begin\n");

	WRPPRINT("%s", "CFlowScreen::HideAndDestroy() End\n");
}

void CFlowScreen::Update(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
	WRPPRINT("%s", "CFlowScreen::Update() Begin\n");
	switch(status)
	{
		case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
		{
			if (!strcmp(buffer, "home"))
			{
				m_pHmiApp->LoadScreen(HOMESCREEN);
			}
			else if (!strcmp(buffer, "cflow1"))
			{
				m_pAnimItem[5]->SetPos(0,0); // unhide it
				m_anim.SetWidgets((WrpGui::WrpWidget**)m_pAnimItem, 6);
				m_anim.Select2();
			}
			else if (!strcmp(buffer, "cflow2"))
			{
				m_pAnimItem[5]->SetPos(0,-30); // hide it
				m_anim.SetWidgets((WrpGui::WrpWidget**)m_pAnimItem, 5);
				m_anim.Select();
			}
			else if (!strcmp(buffer, "cflow3"))
			{
				m_pAnimItem[5]->SetPos(0,0); // unhide it
				m_anim.SetWidgets((WrpGui::WrpWidget**)m_pAnimItem, 6);
				m_anim.Eclipse();
			}
			break;
		}
		default:
			break;
	}

	WRPPRINT("%s", "CFlowScreen::Update() End\n");
}

