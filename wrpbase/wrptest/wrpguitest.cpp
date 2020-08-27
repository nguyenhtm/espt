/********************************************************************************************************
 * @File  : wrpguitest.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrptest.hpp"
#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpdisplay.hpp"
#endif
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

namespace WrpTest {

#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
static WrpGui::WrpScreen* gpHomeScreen    = NULL;
static WrpGui::WrpScreen* gpSettingScreen = NULL;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
static void WrpGuiInitTest(void)
{
   static bool flag = false;
   if(!flag)
   {
      //ESP32 target need to initialize NVS before using LVGL library
      WrpSys::Storage::InitNVS(); // must 1st initialization
      WrpSys::Network::InitWifiStation();
      WrpGui::InitLvglLib();
      flag = true;
   }
}

void WrpGuiScreenCreationTest(void)
{
   WrpGuiInitTest();
   gpHomeScreen = new WrpGui::WrpScreen(true); // loaded by default
   gpHomeScreen->SetTitle("Home");
   gpHomeScreen->SetStyle(WrpGui::SCREEN_DEFAULT);
   sleep(3);
   gpHomeScreen->ShowPopup(true, "HomeScreen");

   gpSettingScreen = new WrpGui::WrpScreen(false);
   gpSettingScreen->SetTitle("Setting");
   gpSettingScreen->SetStyle(WrpGui::BUTTON_PRESS);
   sleep(3);
   gpSettingScreen->Load();
}

void WrpGuiTest(void)
{
   WrpGuiInitTest();
   WrpGuiScreenCreationTest();
   delete gpSettingScreen;
   delete gpHomeScreen;
}

#endif //(LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)


WrpGuiTestApp::WrpGuiTestApp()
: mpMidw(NULL)
, mpHmi(NULL)
{
   WRPPRINT("%s\n", "WrpGuiTestApp::WrpGuiTestApp() Begin");
   WRPPRINT("%s\n", "WrpGuiTestApp::WrpGuiTestApp() End");
}
WrpGuiTestApp::~WrpGuiTestApp()
{
   WRPPRINT("%s\n", "WrpGuiTestApp::~WrpGuiTestApp() Begin");
   delete mpHmi;
   WRPPRINT("%s\n", "WrpGuiTestApp::~WrpGuiTestApp() End");
}
void WrpGuiTestApp::ConstructMidw()
{
   WRPPRINT("%s\n", "WrpGuiTestApp::ConstructMidw() Begin");
   mMidwBuilder.BuildStorage();
   mMidwBuilder.BuildConnectivity();
   mMidwBuilder.BuildDisplay();
   mpMidw = mMidwBuilder.GetMidw();
   WrpSys::WrpDiagnosis::WrpDiagnosis::Instance()->SelfDiagnosis();
   WRPPRINT("%s\n", "WrpGuiTestApp::ConstructMidw() End");
}
void WrpGuiTestApp::DestructMidw()
{
   WRPPRINT("%s\n", "WrpGuiTestApp::DestructMidw() Begin");
   WRPNULL_CHECK(mpMidw)
   mpMidw->DeInitialize();
   WRPPRINT("%s\n", "WrpGuiTestApp::DestructMidw() End");
}
void WrpGuiTestApp::ConstructHmi(uint8_t productid)
{
   if (0 == productid) mpHmi = new WrpHmiLvgl;
   if (1 == productid) mpHmi = new WrpHmiUgfx;
}
TestScreen::TestScreen()
: mpScreen(NULL)
, mpLabel(NULL)
{
}
TestScreen::~TestScreen()
{
}
void TestScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "TestScreen::CreateAndShow() Begin");
   mpScreen = new WrpGui::WrpScreen(true);
   mpScreen->SetTitle("Test");
   mpLabel = new WrpGui::WrpLabel(mpScreen);
   mpLabel->SetPos(100, 90);
   mpLabel->SetText("Loading......0%");
   mpScreen->Load();
   WRPPRINT("%s\n", "TestScreen::CreateAndShow() End");
}
void TestScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "TestScreen::HideAndDestroy() Begin");
   WRPNULL_CHECK2(mpScreen, mpLabel)
   delete mpLabel;
   delete mpScreen;
   WRPPRINT("%s\n", "TestScreen::HideAndDestroy() End");
}
void TestScreen::ActiveScreen(const WrpHmiObserver& obj)
{
   WRPPRINT("%s%p:%p\n", "TestScreen::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WRPNULL_CHECK(mpScreen)
      mpScreen->Load();
   }
   WRPPRINT("%s\n", "TestScreen::ActiveScreen() End");
}
TestScreen::TestScreen(const TestScreen& cp)
: mpScreen(NULL)
, mpLabel(NULL)
{
}


} /* Namespace WrpTest */
