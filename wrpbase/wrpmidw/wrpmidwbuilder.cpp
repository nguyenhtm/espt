/********************************************************************************************************
 * @File  : wrpmidwbuilder.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwbuilder.hpp"
#include "wrpmidwstate.hpp"
#include "wrpmidwapp.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpdisplay.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS - WrpMidwESP32
 ********************************************************************************************************/

WrpMidwESP32::WrpMidwESP32()
{
	m_pMidwApp = new WrpMidwApp;
}

WrpMidwESP32::~WrpMidwESP32()
{
	delete m_pMidwApp;
}

void WrpMidwESP32::BuildStorage()
{
	WRPPRINT("%s\n", "WrpMidwESP32::BuildStorage() Begin");
	WrpSys::Storage::InitNVS();
	WrpSys::Storage::InitSPIFFS();
	WrpSys::Storage::InitSDCard();
	WRPPRINT("%s\n", "WrpMidwESP32::BuildStorage() End");
}

void WrpMidwESP32::BuildDisplay()
{
	WRPPRINT("%s\n", "WrpMidwESP32::BuildDisplay() Begin");
	WrpSys::InitLvglLib();
	WRPPRINT("%s\n", "WrpMidwESP32::BuildDisplay() End");
}

void WrpMidwESP32::BuildNetwork()
{
	WRPPRINT("%s\n", "WrpMidwESP32::BuildNetwork() Begin");
	uint8_t nRetry = 0;
	const uint8_t nMaxTimeOut = 1; //seconds

	WrpSys::Network::InitWifiStation();
	while ((nRetry < 10) && (WrpSys::Network::m_uNetworkStatus != NETWORK_STATUS_CONNECTED))
	{
		nRetry++;
		sleep(nMaxTimeOut);
		WRPPRINT("%s%d\n", "WrpMidwESP32::BuildNetwork() Retry ", nRetry);
	}
	WRPPRINT("%s\n", "WrpMidwESP32::BuildNetwork() End");
}

void WrpMidwESP32::BuildSystem()
{
	WRPPRINT("%s\n", "WrpMidwESP32::BuildSystem() Begin");
	WrpSys::System::PrintChipInfo();
	WRPPRINT("%s\n", "WrpMidwESP32::BuildSystem() End");
}

WrpMidwApp* WrpMidwESP32::GetMidwApp()
{
	return m_pMidwApp;
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwSIM
 ********************************************************************************************************/
WrpMidwSIM::WrpMidwSIM()
{
	m_pMidwApp = new WrpMidwApp;
}

WrpMidwSIM::~WrpMidwSIM()
{
	delete m_pMidwApp;
}

void WrpMidwSIM::BuildStorage()
{
	WRPPRINT("%s\n", "WrpMidwSIM::BuildStorage() Begin");
	WRPPRINT("%s\n", "WrpMidwSIM::BuildStorage() End");
}

void WrpMidwSIM::BuildDisplay()
{
	WRPPRINT("%s\n", "WrpMidwSIM::BuildDisplay() Begin");
	WrpSys::InitLvglLib();
	WRPPRINT("%s\n", "WrpMidwSIM::BuildDisplay() End");
}

void WrpMidwSIM::BuildNetwork()
{
	WRPPRINT("%s\n", "WrpMidwSIM::BuildNetwork() Begin");
	WrpSys::Network::m_uNetworkStatus = NETWORK_STATUS_CONNECTED;
	WRPPRINT("%s\n", "WrpMidwSIM::BuildNetwork() End");
}

void WrpMidwSIM::BuildSystem()
{
	WRPPRINT("%s\n", "WrpMidwSIM::BuildSystem() Begin");
	WRPPRINT("%s\n", "WrpMidwSIM::BuildSystem() End");
}

WrpMidwApp* WrpMidwSIM::GetMidwApp()
{
	return m_pMidwApp;
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwDirector
 ********************************************************************************************************/
WrpMidwDirector::WrpMidwDirector(WrpMidwBuilder *builder)
{
	m_pMidwAppBuilder = builder;
}

WrpMidwDirector::~WrpMidwDirector()
{
}

void WrpMidwDirector::BuildWrpMidwApp()
{
	// must 1st initialization
	m_pMidwAppBuilder->BuildStorage();
	// and then
	m_pMidwAppBuilder->BuildDisplay();
	m_pMidwAppBuilder->BuildNetwork();
	m_pMidwAppBuilder->BuildSystem();
}

WrpMidwApp* WrpMidwDirector::GetMidwApp()
{
	return m_pMidwAppBuilder->GetMidwApp();
}
