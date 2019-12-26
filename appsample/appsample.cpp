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
#include "loadingscreen.hpp"
#include "settingscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

void appsample()
{
	uint8_t retry = 0;
	WrpMidwApp* midwApp = WrpMidwApp::GetInstance();
	while ((retry < 3) && (!midwApp->Start()))
	{
		retry++;
		usleep(300*1000);
		WRPPRINT("%s%d\n", "AppSample() WrpMidwApp Start Retry ", retry);
	}

	WrpHmiApp* hmiApp = WrpHmiApp::GetInstance();
	hmiApp->Start();
	if (hmiApp->GetStatus() != eWrpHmiAppStatus::HMIAPP_STATUS_STARTED)
	{
		usleep(1000*1000);
	}

	HomeScreen*    homeScreen    = new HomeScreen(hmiApp);
	LoadingScreen* loadingScreen = new LoadingScreen(hmiApp);
	SettingScreen* settingScreen = new SettingScreen(hmiApp);
	hmiApp->Attach(homeScreen, HOMESCREEN);
	hmiApp->Attach(settingScreen, SETTINGSCREEN);
	hmiApp->Attach(loadingScreen, LOADINGSCREEN);

	hmiApp->LoadScreen(LOADINGSCREEN);

	midwApp->Attach(homeScreen);
	midwApp->Attach(settingScreen);
	midwApp->Attach(loadingScreen);

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
	delete loadingScreen;
	delete hmiApp;
}
