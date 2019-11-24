/********************************************************************************************************
 * @File  : appsample.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "homescreen.hpp"
#include "settingscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

void appsample()
{
	WrpMidwApp* midwApp = WrpMidwApp::GetInstance();
	midwApp->Start();
	if (midwApp->GetStatus() != eWrpMidwAppStatus::MIDWAPP_STATUS_STARTED)
	{
		usleep(1000*1000);
	}

	WrpHmiApp* hmiApp = WrpHmiApp::GetInstance();
	hmiApp->Start();
	if (hmiApp->GetStatus() != eWrpHmiAppStatus::HMIAPP_STATUS_STARTED)
	{
		usleep(1000*1000);
	}

	HomeScreen*    homeScreen    = new HomeScreen(hmiApp);
	SettingScreen* settingScreen = new SettingScreen(hmiApp);
	hmiApp->AddScreen(homeScreen->m_pScrHandler, HOMESCREEN);
	hmiApp->AddScreen(settingScreen->m_pScrHandler, SETTINGSCREEN);
	hmiApp->LoadScreen(HOMESCREEN);

	midwApp->Attach(homeScreen);
	midwApp->Attach(settingScreen);

    while(1)
    {
        usleep(1000);
        lv_task_handler();
    }

	midwApp->Stop();
	midwApp->Stop();
	delete midwApp;
	delete homeScreen;
	delete settingScreen;
	delete hmiApp;
}
