/********************************************************************************************************
 * @File  : loadingscreen.cpp
 * @Date  : 2019-12-09
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "loadingscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
LoadingScreen::LoadingScreen(WrpHmiApp* app)
: m_pHmiApp(app)
, m_pLblLoadingStatus(NULL)
{
	WRPPRINT("%s", "LoadingScreen::LoadingScreen() Begin\n");

	WRPPRINT("%s", "LoadingScreen::LoadingScreen() End\n");
}

LoadingScreen::~LoadingScreen()
{
	WRPPRINT("%s", "LoadingScreen::~LoadingScreen() Begin\n");
	WRPPRINT("%s", "LoadingScreen::~LoadingScreen() End\n");
}

void LoadingScreen::CreateAndShow()
{
	WRPPRINT("%s", "LoadingScreen::CreateAndShow() Begin\n");
	m_pScreenHandle = new WrpGui::WrpScreen(false);
	m_pScreenHandle->SetTitle("");

	m_pLblLoadingStatus = new WrpGui::WrpLabel(m_pScreenHandle);
	m_pLblLoadingStatus->SetPos(100, 100);
	m_pLblLoadingStatus->SetText("Loading......0%");
	WRPPRINT("%s", "LoadingScreen::CreateAndShow() End\n");
}

void LoadingScreen::HideAndDestroy()
{
	WRPPRINT("%s", "LoadingScreen::HideAndDestroy() Begin\n");
	WRPNULL_CHECK(m_pScreenHandle)
	delete m_pScreenHandle;
	WRPPRINT("%s", "LoadingScreen::HideAndDestroy() End\n");
}

void LoadingScreen::Update(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
	WRPPRINT("%s", "LoadingScreen::Update() Begin\n");
	for(int i = 1; i <= 10; i++)
	{
		char str[100] = {0};
		sprintf(str, "Loading.......%d%%", i*10);
		m_pLblLoadingStatus->SetText(str);
		sleep(1);
	}
	m_pHmiApp->LoadScreen(HOMESCREEN);

	WRPPRINT("%s", "LoadingScreen::Update() End\n");
}
