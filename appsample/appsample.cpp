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

	LoadingScreen* loadingScreen = new LoadingScreen(hmiApp);
	HomeScreen*    homeScreen    = new HomeScreen(hmiApp);
	SettingScreen* settingScreen = new SettingScreen(hmiApp);
	hmiApp->Attach(homeScreen, HOMESCREEN);
	hmiApp->Attach(settingScreen, SETTINGSCREEN);
	hmiApp->Attach(loadingScreen, LOADINGSCREEN);

	hmiApp->LoadScreen(LOADINGSCREEN);

	midwApp->Attach(homeScreen);
	midwApp->Attach(settingScreen);
	midwApp->Attach(loadingScreen);


	midwApp->Start();

	while(1)
	{
    	// for display
        usleep(5*1000); // 100ms
        lv_task_handler();
	}

}
