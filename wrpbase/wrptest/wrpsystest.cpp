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

#include "wrpbase/wrpmidw/wrpmidwbuilder.hpp"
#include "wrpbase/wrpsys/wrpstoragefactory.hpp"

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
   WRPPRINT("%s\n", "void WrpSystemTest() Begin");
   WrpSys::System::PrintChipInfo();

   //WrpSys::System::SwReset();
   WRPPRINT("%s\n", "void WrpSystemTest() End");
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

#if USE_ESP_IDF
   // Connect to wifi if using ESP32
   WrpSys::Network::InitWifiStation();
#elif LVGL_PC_SIMU
   WrpSys::Network::gNetworkStatus = NETWORK_STATUS_CONNECTED;
#endif
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
   bool ret;
#if USE_ESP_IDF
   ret = gWSClient->Create(WRPWS_SERVER_ADDRESS, WRPWS_SERVER_PORT);
#elif LVGL_PC_SIMU
   ret = gWSClient->Create("127.0.0.1", WRPWS_SERVER_PORT);
#endif

   char buf1[125]={0};
   while(!gWSClient->mRecvBufferLength)
   {
      gWSClient->Receive(buf1, 9);
#if USE_ESP_IDF
      vTaskDelay(1000 / portTICK_PERIOD_MS);
#endif
   }
   char buf[125]="Xin Chao!";
   if (ret)
   {
      gWSClient->Send(buf, 9);
   }

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
