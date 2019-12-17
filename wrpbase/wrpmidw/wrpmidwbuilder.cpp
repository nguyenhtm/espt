/********************************************************************************************************
 * @File  : wrpmidwbuilder.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwbuilder.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpMidw::WrpMidw()
: m_pWsClient(NULL)
{

}

WrpMidw::~WrpMidw()
{

}

WrpMidwESP32::WrpMidwESP32()
{
	m_pMidwApp = new WrpMidw;
}

WrpMidwESP32::~WrpMidwESP32()
{
	delete m_pMidwApp;
}

void WrpMidwESP32::BuildStorage()
{
	WRPPRINT("%s\n", "WrpMidwESP32::BuildStorage() Begin");
	WrpSys::Storage::InitNVS();
	WRPPRINT("%s\n", "WrpMidwESP32::BuildStorage() End");
}

void WrpMidwESP32::BuildDisplay()
{

}

void WrpMidwESP32::BuildNetwork()
{
	WrpSys::Network::InitWifiStation();
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

void WrpMidwSIM::BuildStorage()
{
	WRPPRINT("%s\n", "WrpMidwSIM::BuildStorage() Begin");
	WRPPRINT("%s\n", "WrpMidwSIM::BuildStorage() End");
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
	m_pMidwAppBuilder->BuildStorage();
	// then
	m_pMidwAppBuilder->BuildDisplay();
	m_pMidwAppBuilder->BuildNetwork();
	m_pMidwAppBuilder->BuildSystem();
}

WrpMidw* WrpMidwDirector::GetMidwApp()
{
	return m_pMidwAppBuilder->GetMidwApp();
}
