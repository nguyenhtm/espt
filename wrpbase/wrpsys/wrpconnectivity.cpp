/********************************************************************************************************
 * @File  : wrpconnectivity.cpp
 * @Date  : 2020-08-05
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpconnectivity.hpp"

namespace WrpSys {
namespace WrpConnectivity{

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpWifiStation
 ********************************************************************************************************/
WrpWifiStation::WrpWifiStation()
{
   WRPPRINT("%s\n", "WrpWifiStation::WrpWifiStation() Begin");
   WRPPRINT("%s\n", "WrpWifiStation::WrpWifiStation() End");
}
WrpWifiStation::~WrpWifiStation()
{
   WRPPRINT("%s\n", "WrpWifiStation::~WrpWifiStation() Begin");
   WRPPRINT("%s\n", "WrpWifiStation::~WrpWifiStation() End");
}
void WrpWifiStation::Connect()
{
   WRPPRINT("%s\n", "WrpWifiStation::Connect() Begin");
#if USE_ESP_IDF
   esp_event_loop_init(LegacyEventHandler, NULL);
   wifi_init_config_t cfgInit = WIFI_INIT_CONFIG_DEFAULT();
   wifi_config_t      cfgWifi = { .sta = { {.ssid = WRPESP_WIFI_SSID}, {.password = WRPESP_WIFI_PASS} }, };

   tcpip_adapter_init();
   esp_wifi_init(&cfgInit);
   esp_wifi_set_mode(WIFI_MODE_STA);
   esp_wifi_set_config(ESP_IF_WIFI_STA, &cfgWifi);
   esp_wifi_start();
#endif
   WRPPRINT("%s\n", "WrpWifiStation::Connect() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpWsClient
 ********************************************************************************************************/
WrpWsClient::WrpWsClient()
{
   WRPPRINT("%s\n", "WrpWsClient::WrpWsClient() Begin");
   WRPPRINT("%s\n", "WrpWsClient::WrpWsClient() End");
}
WrpWsClient::~WrpWsClient()
{
   WRPPRINT("%s\n", "WrpWsClient::~WrpWsClient() Begin");
   WRPPRINT("%s\n", "WrpWsClient::~WrpWsClient() End");
}
void WrpWsClient::Connect()
{
   WRPPRINT("%s\n", "WrpWsClient::Connect() Begin");
   WRPPRINT("%s\n", "WrpWsClient::Connect() End");
}
void WrpWsClient::Add(WrpConnection* pItem)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpWsServer
 ********************************************************************************************************/
WrpWsServer::WrpWsServer()
{
}
WrpWsServer::~WrpWsServer()
{
}
void WrpWsServer::Add(WrpConnection* pItem)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpConnectivity
 ********************************************************************************************************/
WrpConnectivity::WrpConnectivity()
: mpWsClient(NULL)
, mpWsServer(NULL)
{
   WRPPRINT("%s\n", "WrpConnectivity::WrpConnectivity() Begin");
   mpWsClient = new WrpWsClient;
   WRPPRINT("%s\n", "WrpConnectivity::WrpConnectivity() End");
}
WrpConnectivity::~WrpConnectivity()
{
   WRPPRINT("%s\n", "WrpConnectivity::~WrpConnectivity() Begin");
   delete mpWsClient;
   WRPPRINT("%s\n", "WrpConnectivity::~WrpConnectivity() End");
}
void WrpConnectivity::Initialize()
{
   WRPPRINT("%s\n", "WrpConnectivity::Initialize() Begin");
   WrpWifiStation* wifistation = new WrpSys::WrpConnectivity::WrpWifiStation;
   wifistation->Connect();
   mpWsClient->Add(wifistation);
   WRPPRINT("%s\n", "WrpConnectivity::Initialize() End");
}
void WrpConnectivity::DeInitialize()
{
   WRPPRINT("%s\n", "WrpConnectivity::DeInitialize() Begin");

   WRPPRINT("%s\n", "WrpConnectivity::DeInitialize() End");
}
WrpWsClient* WrpConnectivity::GetWsClient()
{
   return mpWsClient;
}

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

} /* Namespace WrpConnectivity */
} /* Namespace WrpSys */
