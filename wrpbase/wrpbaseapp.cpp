/********************************************************************************************************
 * @File  : wrpbaseapp.cpp
 * @Date  : 2020-09-23
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbaseapp.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"
#include "wrpbase/wrpmidw/wrpcommand.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpSysTestApp
 ********************************************************************************************************/
WrpSysTestApp::WrpSysTestApp()
: mpMidwBuilder(NULL)
, mpMidw(NULL)
{
   WRPPRINT("%s\n", "WrpSysTestApp::WrpSysTestApp() Begin");
   mpMidwBuilder->BuildStorage();
   mpMidwBuilder->BuildConnectivity();
   mpMidw = mpMidwBuilder->GetMidw();
   WRPPRINT("%s\n", "WrpSysTestApp::WrpSysTestApp() End");
}
WrpSysTestApp::~WrpSysTestApp()
{
   WRPPRINT("%s\n", "WrpSysTestApp::~WrpSysTestApp() Begin");
   WRPPRINT("%s\n", "WrpSysTestApp::~WrpSysTestApp() End");
}
WrpSysTestApp::WrpSysTestApp(const WrpSysTestApp& cp)
: mpMidwBuilder(NULL)
, mpMidw(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpGuiTestApp
 ********************************************************************************************************/
WrpGuiApp::WrpGuiApp()
: mpMidwBuilder(NULL)
, mpMidw(NULL)
, mpHmi(NULL)
{
   WRPPRINT("%s\n", "WrpGuiApp::WrpGuiApp() Begin");
   mpHmi = new WrpHmiLvgl;
   mpMidwBuilder = new WrpGuiMidwBuilder;
   WRPPRINT("%s\n", "WrpGuiApp::WrpGuiApp() End");
}
WrpGuiApp::~WrpGuiApp()
{
   WRPPRINT("%s\n", "WrpGuiApp::~WrpGuiApp() Begin");
   delete mpHmi;
   delete mpMidwBuilder;
   WRPPRINT("%s\n", "WrpGuiApp::~WrpGuiApp() End");
}
void WrpGuiApp::Initialize()
{
   WRPPRINT("%s\n", "WrpGuiApp::Initialize() Begin");
   // Construct a midw object
   mpMidwBuilder->BuildStorage();
   mpMidwBuilder->BuildConnectivity();
   mpMidwBuilder->BuildDisplay();
   mpMidw = mpMidwBuilder->GetMidw();

   // Create a list of commands
   WrpCommand* starthmicmd = new StartWrpHmiCmd(mpHmi);
   WrpCommand* diagcmd = new DiagnosisCmd(mpMidw);
   starthmicmd->Execute();
   diagcmd->Execute();
   delete starthmicmd;
   delete diagcmd;
   WRPPRINT("%s\n", "WrpGuiApp::Initialize() End");
}
void WrpGuiApp::DeInitialize()
{
   WRPPRINT("%s\n", "WrpGuiApp::DeInitialize() Begin");
   WRPNULL_CHECK(mpMidw)
   WRPNULL_CHECK(mpHmi)
   WrpCommand* stophmicmd = new StopWrpHmiCmd(mpHmi);
   stophmicmd->Execute();
   delete stophmicmd;
   WRPPRINT("%s\n", "WrpGuiApp::DeInitialize() End");
}
WrpGuiApp::WrpGuiApp(const WrpGuiApp& cp)
: mpMidwBuilder(NULL)
, mpMidw(NULL)
, mpHmi(NULL)
{
}
