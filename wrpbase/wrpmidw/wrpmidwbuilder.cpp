/********************************************************************************************************
 * @File  : wrpmidwbuilder.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwbuilder.hpp"
#include "wrpmidwstate.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpMidw::WrpMidw()
: m_pWsClient(NULL)
, m_pCurrentState(NULL)
{
	//m_pCurrentState = new WrpMidwInit(this);
}

WrpMidw::~WrpMidw()
{

}

void WrpMidw::SetState(WrpMidwState* state)
{
	if(m_pCurrentState)
	{
		delete m_pCurrentState;
	}
	m_pCurrentState = state;
	m_pCurrentState->Handle();
}

void WrpMidw::ReadConfig()
{
	WRPPRINT("%s\n", "WrpMidw::ReadConfig() Begin");
	if (WrpSys::Storage::m_uStorageStatus && STORAGE_STATUS_INITSPIFFS)
	{

	}
	WRPPRINT("%s\n", "WrpMidw::ReadConfig() Begin");
}

WrpMidwESP32::WrpMidwESP32()
{
	m_pMidwApp = new WrpMidw;
}

WrpMidwESP32::~WrpMidwESP32()
{
	delete m_pMidwApp;
}

void WrpMidwESP32::InitStorage()
{
	WRPPRINT("%s\n", "WrpMidwESP32::BuildStorage() Begin");
	WrpSys::Storage::InitNVS();
	WrpSys::Storage::InitSPIFFS();
	WrpSys::Storage::InitSDCard();
	WRPPRINT("%s\n", "WrpMidwESP32::BuildStorage() End");
}

void WrpMidwESP32::BuildDisplay()
{

}

void WrpMidwESP32::BuildNetwork()
{
	WRPPRINT("%s\n", "WrpMidwESP32::BuildNetwork() Begin");
	WrpSys::Network::InitWifiStation();
	WRPPRINT("%s\n", "WrpMidwESP32::BuildNetwork() End");
}

void WrpMidwESP32::BuildSystem()
{
	WrpSys::System::PrintChipInfo();
}

WrpMidw* WrpMidwESP32::GetMidwApp()
{
	return m_pMidwApp;
}

WrpMidwSIM::WrpMidwSIM()
{
	m_pMidwApp = new WrpMidw;
}

WrpMidwSIM::~WrpMidwSIM()
{
	delete m_pMidwApp;
}

void WrpMidwSIM::InitStorage()
{
	WRPPRINT("%s\n", "WrpMidwSIM::InitStorage() Begin");
	WRPPRINT("%s\n", "WrpMidwSIM::InitStorage() End");
}

void WrpMidwSIM::BuildDisplay()
{

}

void WrpMidwSIM::BuildNetwork()
{

}

void WrpMidwSIM::BuildSystem()
{

}

WrpMidw* WrpMidwSIM::GetMidwApp()
{
	return m_pMidwApp;
}

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
	m_pMidwAppBuilder->InitStorage();
	// then
	m_pMidwAppBuilder->BuildDisplay();
	m_pMidwAppBuilder->BuildNetwork();
	m_pMidwAppBuilder->BuildSystem();
}

WrpMidw* WrpMidwDirector::GetMidwApp()
{
	return m_pMidwAppBuilder->GetMidwApp();
}
