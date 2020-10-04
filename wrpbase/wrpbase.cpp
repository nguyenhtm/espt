/********************************************************************************************************
 * @File  : wrpbaseapp.cpp
 * @Date  : 2020-09-23
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbase.hpp"
#include "wrpbase/wrpmidw/wrpmidwbuilder.hpp"
#include "wrpbase/wrpmidw/wrpmidw.hpp"
#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
#include "wrpbase/wrphmi/wrphmi.hpp"
#endif
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
 * FUNCTIONS - WrpMidwApp
 ********************************************************************************************************/
WrpMidwApp::WrpMidwApp()
: mpMidwBuilder(NULL)
, mpMidw(NULL)
{
   WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() Begin");
   mpMidwBuilder = new WrpSimpleMidwBuilder;
   WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() End");
}
WrpMidwApp::~WrpMidwApp()
{
   WRPPRINT("%s\n", "WrpMidwApp::~WrpMidwApp() Begin");
   delete mpMidwBuilder;
   WRPPRINT("%s\n", "WrpMidwApp::~WrpMidwApp() End");
}
void WrpMidwApp::ConstructMidw()
{
   WRPPRINT("%s\n", "WrpMidwApp::ConstructMidw() Begin");
   WRPNULL_CHECK(mpMidwBuilder)
   mpMidwBuilder->BuildStorage();
   mpMidwBuilder->BuildConnectivity();
   mpMidw = mpMidwBuilder->GetMidw();
   WRPPRINT("%s\n", "WrpMidwApp::ConstructMidw() End");
}
WrpMidwApp::WrpMidwApp(const WrpMidwApp& cp)
: mpMidwBuilder(NULL)
, mpMidw(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpHmiApp
 ********************************************************************************************************/
#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
WrpHmiApp::WrpHmiApp()
: mpMidwBuilder(NULL)
, mpMidw(NULL)
, mpHmi(NULL)
{
   WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() Begin");
   mpHmi = new WrpHmiLvgl;
   mpMidwBuilder = new WrpStandardMidwBuilder;
   WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() End");
}
WrpHmiApp::~WrpHmiApp()
{
   WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() Begin");
   delete mpHmi;
   delete mpMidwBuilder;
   WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() End");
}
void WrpHmiApp::Initialize()
{
   WRPPRINT("%s\n", "WrpHmiApp::Initialize() Begin");
   // Construct a midw object
   mpMidwBuilder->BuildStorage();
   mpMidwBuilder->BuildConnectivity();
   mpMidwBuilder->BuildSystem();
   mpMidw = mpMidwBuilder->GetMidw();

   // Create a list of commands
   WrpCommand* starthmicmd = new StartWrpHmiCmd(mpHmi);
   WrpCommand* diagcmd = new DiagnosisCmd(mpMidw);
   starthmicmd->Execute();
   diagcmd->Execute();
   delete starthmicmd;
   delete diagcmd;
   WRPPRINT("%s\n", "WrpHmiApp::Initialize() End");
}
void WrpHmiApp::DeInitialize()
{
   WRPPRINT("%s\n", "WrpHmiApp::DeInitialize() Begin");
   WRPNULL_CHECK(mpMidw)
   WRPNULL_CHECK(mpHmi)
   WrpCommand* stophmicmd = new StopWrpHmiCmd(mpHmi);
   stophmicmd->Execute();
   delete stophmicmd;
   WRPPRINT("%s\n", "WrpHmiApp::DeInitialize() End");
}
WrpHmi* WrpHmiApp::GetHmiInstance()
{
   return mpHmi;
}
WrpMidw* WrpHmiApp::GetMidwInstance()
{
   return mpMidw;
}
WrpHmiApp::WrpHmiApp(const WrpHmiApp& cp)
: mpMidwBuilder(NULL)
, mpMidw(NULL)
, mpHmi(NULL)
{
}
#endif /* (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU) */
