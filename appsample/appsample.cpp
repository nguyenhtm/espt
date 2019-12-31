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
#include "wrpbase/wrpmidw/wrpmidwbuilder.hpp"
#include "wrpbase/wrpmidw/wrpmidwstate.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
const uint8_t  MAX_RETRY = 3;
const uint32_t MAX_WAIT_TIME = 300000; //300ms

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

void appsample()
{
#if USE_ESP_IDF
	WrpMidwBuilder *midwAppBuilder = new WrpMidwESP32;
#else
	WrpMidwBuilder *midwAppBuilder = new WrpMidwSIM;
#endif
	WrpMidwDirector *ctr = new WrpMidwDirector(midwAppBuilder);
	ctr->BuildWrpMidwApp();
	WrpMidwApp* midwApp = ctr->GetMidwApp();


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

	midwApp->SetState(new WrpMidwInitState(midwApp));
}

void appsample1()
{
#if 0
	uint8_t nRetry = 0;
	WrpMidwApp* midwApp = WrpMidwApp::GetInstance();
	while ((nRetry < MAX_RETRY) && (!midwApp->Start()))
	{
		nRetry++;
		usleep(MAX_WAIT_TIME);
		WRPPRINT("%s%d\n", "AppSample() WrpMidwApp Start Retry ", nRetry);
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
#endif
}
