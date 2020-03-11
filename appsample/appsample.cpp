/********************************************************************************************************
 * @File  : appsample.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "sampleapp.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"

#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "homescreen.hpp"
#include "loadingscreen.hpp"
#include "diagscreen.hpp"
#include "cflowscreen.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpmidw/wrpmidwappfsm.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

void appsample()
{
	// Receivers
	WrpServiceManager* pServiceManager = new WrpServiceManager;
	WrpScreenManager*  pScreenManager  = new WrpScreenManager;
	// Commands
	SampleAppCommand* pServiceManagerStartCmd = new ServiceManagerOnCommand(pServiceManager);
	SampleAppCommand* pScreenManagerStartCmd  = new ScreenManagerOnCommand(pScreenManager);
	// Invoker
	SampleAppInvoker* pSampleApp = new SampleAppInvoker;
	pSampleApp->ExecuteCommand(pServiceManagerStartCmd);
	pSampleApp->ExecuteCommand(pScreenManagerStartCmd);

	WrpHmiApp*  hmiApp  = pScreenManager->GetWrpHmiAppInstance();
	WrpMidwApp* midwApp = pServiceManager->GetWrpMidwAppInstance();

	LoadingScreen* loadingScreen = new LoadingScreen(hmiApp);
	HomeScreen*    homeScreen    = new HomeScreen(hmiApp);
	DiagScreen*    diagScreen    = new DiagScreen(hmiApp);
	CFlowScreen*   cflowScreen   = new CFlowScreen(hmiApp);
	hmiApp->Attach(homeScreen, HOMESCREEN);
	hmiApp->Attach(diagScreen, SETTINGSCREEN);
	hmiApp->Attach(loadingScreen, LOADINGSCREEN);
	hmiApp->Attach(cflowScreen, CFLOWSCREEN);

	hmiApp->LoadScreen(HOMESCREEN);

	midwApp->Attach(homeScreen);
	midwApp->Attach(diagScreen);
	midwApp->Attach(loadingScreen);
	midwApp->Attach(cflowScreen);

	while(1)
	{
    	// for display
        usleep(5*1000);
        lv_task_handler();
	}

}
