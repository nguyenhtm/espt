/********************************************************************************************************
 * @File  : wrphmiscreen.cpp
 * @Date  : 2020-03-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrphmiscreen.hpp"
#include "wrpbase/wrpsys/wrpdisplay.hpp"
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

/********************************************************************************************************
 * FUNCTIONS - WrpScreenManager
 ********************************************************************************************************/
WrpScreenManager::WrpScreenManager()
: m_pHmiApp(NULL)
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

}

void WrpScreenManager::Add(WrpHmiScreen* pHmiScreen)
{
	m_listOfScreens.push_back(pHmiScreen);
}

void WrpScreenManager::Remove(WrpHmiScreen* pHmiScreen)
{

}

WrpHmiScreen* WrpScreenManager::GetChild(uint8_t id)
{
return NULL;
}

void WrpScreenManager::CreateWrpHmiApp()
{
	m_pHmiApp = WrpHmiApp::GetInstance();
	m_pHmiApp->Start();
}

WrpHmiApp* WrpScreenManager::GetWrpHmiAppInstance()
{
	return m_pHmiApp;
}
