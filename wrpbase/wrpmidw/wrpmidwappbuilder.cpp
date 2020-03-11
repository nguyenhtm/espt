/********************************************************************************************************
 * @File  : wrpmidwbuilder.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwappbuilder.hpp"
#include "wrpmidwappfsm.hpp"
#include "wrpmidwapp.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpdisplay.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppBuilder
 ********************************************************************************************************/
WrpMidwAppBuilder::WrpMidwAppBuilder()
{
}

WrpMidwAppBuilder::~WrpMidwAppBuilder()
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppESP32
 ********************************************************************************************************/
WrpMidwAppESP32::WrpMidwAppESP32()
{
	m_pMidwApp = new WrpMidwApp;
}

WrpMidwAppESP32::~WrpMidwAppESP32()
{
	delete m_pMidwApp;
}

void WrpMidwAppESP32::BuildStorage()
{
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildStorage() Begin");
	WrpSys::Storage::InitNVS();
	WrpSys::Storage::InitSPIFFS();
	WrpSys::Storage::InitSDCard();
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildStorage() End");
}

void WrpMidwAppESP32::BuildDisplay()
{
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildDisplay() Begin");
	WrpSys::InitLvglLib();
	WrpSys::InitLvglFileSystem();
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildDisplay() End");
}

void WrpMidwAppESP32::BuildNetwork()
{
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildNetwork() Begin");
	uint8_t nRetry = 0;
	const uint8_t nMaxTimeOut = 1; //seconds

	WrpSys::Network::InitWifiStation();
	while ((nRetry < 10) && (WrpSys::Network::m_uNetworkStatus != NETWORK_STATUS_CONNECTED))
	{
		nRetry++;
		sleep(nMaxTimeOut);
		WRPPRINT("%s%d\n", "WrpMidwAppESP32::BuildNetwork() Retry ", nRetry);
	}
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildNetwork() End");
}

void WrpMidwAppESP32::BuildSystem()
{
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildSystem() Begin");
	WrpSys::System::PrintChipInfo();
	WRPPRINT("%s\n", "WrpMidwAppESP32::BuildSystem() End");
}

WrpMidwApp* WrpMidwAppESP32::GetWrpMidwApp()
{
	return m_pMidwApp;
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppSIM
 ********************************************************************************************************/
WrpMidwAppSIM::WrpMidwAppSIM()
{
	m_pMidwApp = new WrpMidwApp;
}

WrpMidwAppSIM::~WrpMidwAppSIM()
{
	delete m_pMidwApp;
}

void WrpMidwAppSIM::BuildStorage()
{
	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildStorage() Begin");

	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildStorage() End");
}

void WrpMidwAppSIM::BuildDisplay()
{
	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildDisplay() Begin");
	WrpSys::InitLvglLib();
	WrpSys::InitLvglFileSystem();
	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildDisplay() End");
}

void WrpMidwAppSIM::BuildNetwork()
{
	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildNetwork() Begin");
	WrpSys::Network::m_uNetworkStatus = NETWORK_STATUS_CONNECTED;
	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildNetwork() End");
}

void WrpMidwAppSIM::BuildSystem()
{
	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildSystem() Begin");
	WRPPRINT("%s\n", "WrpMidwAppSIM::BuildSystem() End");
}

WrpMidwApp* WrpMidwAppSIM::GetWrpMidwApp()
{
	return m_pMidwApp;
}
