/********************************************************************************************************
 * @File  : wrphmiscreen.cpp
 * @Date  : 2020-03-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrphmiscreen.hpp"
#include "wrpbase/wrpgui/wrpdisplay.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpHmiScreen
 ********************************************************************************************************/
WrpHmiScreen::WrpHmiScreen()
{
}

WrpHmiScreen::~WrpHmiScreen()
{
}

WrpHmiScreen::WrpHmiScreen(const WrpHmiScreen& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpScreenManager
 ********************************************************************************************************/
WrpScreenManager::WrpScreenManager()
: mpHmiApp(NULL)
{
   WRPPRINT("%s\n", "WrpScreenManager::WrpScreenManager() Begin");
   WRPPRINT("%s\n", "WrpScreenManager::WrpScreenManager() End");
}

WrpScreenManager::~WrpScreenManager()
{
   WRPPRINT("%s\n", "WrpScreenManager::~WrpScreenManager() Begin");
   WRPPRINT("%s\n", "WrpScreenManager::~WrpScreenManager() End");
}

void WrpScreenManager::LoadConfig()
{
   WRPPRINT("%s\n", "WrpScreenManager::LoadConfig() Begin");
   WRPPRINT("%s\n", "WrpScreenManager::LoadConfig() End");
}

void WrpScreenManager::Add(WrpHmiScreen* pHmiScreen)
{
   m_listOfScreens.push_back(pHmiScreen);
}

void WrpScreenManager::Remove(WrpHmiScreen* pHmiScreen)
{

}

WrpHmiScreen* WrpScreenManager::GetChild(uint8_t id) const
{
   return NULL;
}

void WrpScreenManager::CreateWrpHmiApp()
{
   mpHmiApp = WrpHmiApp::GetInstance();
   mpHmiApp->Start();
}

WrpHmiApp* WrpScreenManager::GetWrpHmiAppInstance()
{
   return mpHmiApp;
}
