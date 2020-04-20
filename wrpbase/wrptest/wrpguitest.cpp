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
      WrpSys::InitLvglLib();
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

} /* Namespace WrpTest */
