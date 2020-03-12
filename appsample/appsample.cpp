/********************************************************************************************************
 * @File  : appsample.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "sampleapp.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwappfsm.hpp"
#include "homescreen.hpp"
#include "loadingscreen.hpp"
#include "diagscreen.hpp"
#include "cflowscreen.hpp"

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

   WrpHmiApp*  pHmiApp  = pScreenManager->GetWrpHmiAppInstance();
   WrpMidwApp* pMidwApp = pServiceManager->GetWrpMidwAppInstance();

   LoadingScreen* pLoadingScreen = new LoadingScreen(pHmiApp);
   HomeScreen*    pHomeScreen    = new HomeScreen(pHmiApp);
   DiagScreen*    pDiagScreen    = new DiagScreen(pHmiApp);
   CFlowScreen*   pCflowScreen   = new CFlowScreen(pHmiApp);
   pHmiApp->Attach(pHomeScreen, HOMESCREEN);
   pHmiApp->Attach(pDiagScreen, SETTINGSCREEN);
   pHmiApp->Attach(pLoadingScreen, LOADINGSCREEN);
   pHmiApp->Attach(pCflowScreen, CFLOWSCREEN);

   pHmiApp->LoadScreen(HOMESCREEN);

   pMidwApp->Attach(pHomeScreen);
   pMidwApp->Attach(pDiagScreen);
   pMidwApp->Attach(pLoadingScreen);
   pMidwApp->Attach(pCflowScreen);

   while(1)
   {
      // for display
      usleep(5*1000);
      lv_task_handler();
   }
}
