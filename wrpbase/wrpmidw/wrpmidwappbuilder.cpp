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
#include "wrpbase/wrpgui/wrpdisplay.hpp"

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

WrpMidwAppBuilder::WrpMidwAppBuilder(const WrpMidwAppBuilder& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppESP32
 ********************************************************************************************************/
WrpMidwAppESP32::WrpMidwAppESP32()
{
   WRPPRINT("%s\n", "WrpMidwAppESP32::WrpMidwAppESP32() Begin");
   mpMidwApp = new WrpMidwApp;
   WRPPRINT("%s\n", "WrpMidwAppESP32::WrpMidwAppESP32() End");
}

WrpMidwAppESP32::~WrpMidwAppESP32()
{
   WRPPRINT("%s\n", "WrpMidwAppESP32::~WrpMidwAppESP32() Begin");
   delete mpMidwApp;
   WRPPRINT("%s\n", "WrpMidwAppESP32::~WrpMidwAppESP32() End");
}

void WrpMidwAppESP32::BuildStorage() const
{
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildStorage() Begin");
   WrpSys::Storage::InitNVS();
   WrpSys::Storage::InitSPIFFS();
   WrpSys::Storage::InitSDCard();
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildStorage() End");
}

void WrpMidwAppESP32::BuildDisplay() const
{
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildDisplay() Begin");
   WrpSys::InitLvglLib();
   WrpSys::InitLvglFileSystem();
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildDisplay() End");
}

void WrpMidwAppESP32::BuildNetwork() const
{
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildNetwork() Begin");
   uint8_t nRetry = 0;
   const uint8_t nMaxTimeOut = 1; //seconds
   const uint8_t nMaxRetry = 10;  //times

   WrpSys::Network::InitWifiStation();
   while ((nRetry < nMaxRetry) && (WrpSys::Network::m_uNetworkStatus != NETWORK_STATUS_CONNECTED))
   {
      nRetry++;
      sleep(nMaxTimeOut);
      WRPPRINT("%s%d\n", "WrpMidwAppESP32::BuildNetwork() Retry ", nRetry);
   }
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildNetwork() End");
}

void WrpMidwAppESP32::BuildSystem() const
{
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildSystem() Begin");
   WrpSys::System::PrintChipInfo();
   WRPPRINT("%s\n", "WrpMidwAppESP32::BuildSystem() End");
}

WrpMidwApp* WrpMidwAppESP32::GetWrpMidwApp() const
{
   return mpMidwApp;
}

WrpMidwAppESP32::WrpMidwAppESP32(const WrpMidwAppESP32& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppSIM
 ********************************************************************************************************/
WrpMidwAppSIM::WrpMidwAppSIM()
{
   WRPPRINT("%s\n", "WrpMidwAppSIM::WrpMidwAppSIM() Begin");
   mpMidwApp = new WrpMidwApp;
   WRPPRINT("%s\n", "WrpMidwAppSIM::WrpMidwAppSIM() End");
}

WrpMidwAppSIM::~WrpMidwAppSIM()
{
   WRPPRINT("%s\n", "WrpMidwAppSIM::~WrpMidwAppSIM() Begin");
   delete mpMidwApp;
   WRPPRINT("%s\n", "WrpMidwAppSIM::~WrpMidwAppSIM() End");
}

void WrpMidwAppSIM::BuildStorage() const
{
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildStorage() Begin");
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildStorage() End");
}

void WrpMidwAppSIM::BuildDisplay() const
{
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildDisplay() Begin");
   WrpSys::InitLvglLib();
   WrpSys::InitLvglFileSystem();
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildDisplay() End");
}

void WrpMidwAppSIM::BuildNetwork() const
{
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildNetwork() Begin");
   WrpSys::Network::m_uNetworkStatus = NETWORK_STATUS_CONNECTED;
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildNetwork() End");
}

void WrpMidwAppSIM::BuildSystem() const
{
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildSystem() Begin");
   WRPPRINT("%s\n", "WrpMidwAppSIM::BuildSystem() End");
}

WrpMidwApp* WrpMidwAppSIM::GetWrpMidwApp() const
{
   return mpMidwApp;
}

WrpMidwAppSIM::WrpMidwAppSIM(const WrpMidwAppSIM& cp)
{
}
