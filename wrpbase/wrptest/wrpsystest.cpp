/********************************************************************************************************
 * @File  : wrpsystest.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrptest.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

namespace WrpTest {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
static WrpSys::Network::WrpWebSocketClient* gWSClient = NULL;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
void WrpSystemTest()
{
   WrpSys::System::PrintChipInfo();
   //WrpSys::System::SwReset();
}

void WrpStorageTest()
{
   WRPPRINT("%s\n", "WrpStorageTest() Begin");
   WrpSys::Storage::InitNVS(); // must 1st initialization
   //WrpSys::Storage::GetRestartCounter();
   WRPPRINT("%s\n", "WrpStorageTest() End");
}

void WrpNetworkTest()
{
   WRPPRINT("%s\n", "WrpNetworkTest() Begin");
   uint8_t nRetry = 0;
   const uint8_t nMaxTimeOut = 1; //seconds
   const uint8_t nMaxRetry = 10;  //times

   // Connect to wifi
   WrpSys::Network::InitWifiStation();
   while ((nRetry < nMaxRetry) && (WrpSys::Network::gNetworkStatus != NETWORK_STATUS_CONNECTED))
   {
      nRetry++;
      sleep(nMaxTimeOut);
      WRPPRINT("%s%d\n", "WrpNetworkTest() Network Connection Wait...", nRetry);
   }
   if (WrpSys::Network::gNetworkStatus != NETWORK_STATUS_CONNECTED)
   {
      WRPPRINT("%s\n", "WrpNetworkTest() Network Connection Failed!");
      WrpSys::Network::DeInitWifiStation();
      return;
   }
   WRPPRINT("%s\n", "WrpNetworkTest() Network Connection Successfully");
   // Connect to WS server
   gWSClient = new WrpSys::Network::WrpWebSocketClient;
#if USE_ESP_IDF
   gWSClient->Create("ws://192.168.1.10", 8000);
#else
   gWSClient->Create("ws://127.0.0.1", WRPWS_SERVER_PORT);
#endif
   while (WrpSys::Network::WSCLIENT_STATUS_CONNECTED != gWSClient->m_status) {
	   sleep(1);
	   WRPPRINT("%s:%d\n", "WrpNetworkTest() Connecting to websocket server...", gWSClient->m_status);
   }
   char buf[125]="Xin Chao!";
   gWSClient->Send(buf, 9);

   WRPPRINT("%s\n", "WrpNetworkTest() End");
}

void WrpSysTest(void)
{
   WRPPRINT("%s\n", "WrpSysTest() Begin");
   WrpStorageTest();
   WrpSystemTest();
   WrpNetworkTest();
   WRPPRINT("%s\n", "WrpSysTest() End");
}

} /* Namespace WrpTest */
