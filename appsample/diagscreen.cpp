/********************************************************************************************************
 * @File  : diagscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "diagscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
DiagScreen::DiagScreen(WrpHmiApp* app)
: m_pHmiApp(app)
, m_pLblBackItem(NULL)
{
	WRPPRINT("%s", "DiagScreen::DiagScreen() Begin\n");

	WRPPRINT("%s", "DiagScreen::DiagScreen() End\n");
}

DiagScreen::~DiagScreen()
{
	WRPPRINT("%s", "DiagScreen::~DiagScreen() Begin\n");

	WRPPRINT("%s", "DiagScreen::~DiagScreen() End\n");
}

void DiagScreen::CreateAndShow()
{
	WRPPRINT("%s", "DiagScreen::CreateAndShow() Begin\n");
	m_pScreenHandle = new WrpGui::WrpScreen(false);
	m_pScreenHandle->SetTitle("Setting");
	m_pLblBackItem = new WrpGui::WrpLabel(m_pScreenHandle);
	m_pLblBackItem->SetPos(260, 10);
	m_pLblBackItem->SetText("Back");
	WRPPRINT("%s", "DiagScreen::CreateAndShow() End\n");
}

void DiagScreen::HideAndDestroy()
{
	WRPPRINT("%s", "DiagScreen::HideAndDestroy() Begin\n");
	//WRPNULL_CHECK(m_pScreenHandle)
	//delete m_pScreenHandle;
	//delete m_pLblBackItem;
	WRPPRINT("%s", "DiagScreen::HideAndDestroy() End\n");
}

void DiagScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
	WRPPRINT("%s", "DiagScreen::Update() Begin\n");

	switch(status)
	{
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
	WRPPRINT("%s", "DiagScreen::Update() End\n");
}
