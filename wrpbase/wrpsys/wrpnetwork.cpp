/********************************************************************************************************
 * @File  : wrpnetwork.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpnetwork.hpp"

namespace WrpSys {
namespace Network {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
uint32_t gNetworkStatus = NETWORK_STATUS_INIT;

#if USE_ESP_IDF
#define WRPESP_WIFI_CONNECTED_BIT  BIT0

static EventGroupHandle_t g_EventGroup = xEventGroupCreate();
#endif

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

#if USE_ESP_IDF
// legacy event loop: events from Wifi driver, Ethernet driver, and TCP/IP stack were dispatched
esp_err_t LegacyEventHandler(void *ctx, system_event_t *event)
{
	//WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::LegacyEventHandler() Called");
    switch(event->event_id)
    {
		case SYSTEM_EVENT_STA_START:
		{
			WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::LegacyEventHandler() Wifi Connecting");
			esp_wifi_connect();
			gNetworkStatus = NETWORK_STATUS_CONNECTING;
			break;
		}
		case SYSTEM_EVENT_STA_GOT_IP:
		{
			WRPPRINT("WrpBase:%s%s\n", "WrpSysNetwork::LegacyEventHandler() Got IP:", ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
			xEventGroupSetBits(g_EventGroup, WRPESP_WIFI_CONNECTED_BIT);
			gNetworkStatus = NETWORK_STATUS_CONNECTED;
			break;
		}
		case SYSTEM_EVENT_STA_DISCONNECTED:
		{
			WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::LegacyEventHandler() Disconnected!");
			esp_wifi_connect();
			xEventGroupClearBits(g_EventGroup, WRPESP_WIFI_CONNECTED_BIT);
			gNetworkStatus = NETWORK_STATUS_NOTCONNECTED;
			break;
		}
		default:
		{
			//WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::LegacyEventHandler() Unknown!");
			break;
		}
    }
    return ESP_OK;
}
#endif

void InitWifiStation()
{
   WRPPRINT("%s\n", "WrpSys::Network::InitWifiStation() Begin");
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
   gNetworkStatus = NETWORK_STATUS_INIT;
   WRPPRINT("%s\n", "WrpSys::Network::InitWifiStation() End");
}

void DeInitWifiStation()
{
   WRPPRINT("%s\n", "WrpSys::Network::DeInitWifiStation() Begin");
#if USE_ESP_IDF
   esp_wifi_stop();
   esp_wifi_deinit();
#endif
   gNetworkStatus = NETWORK_STATUS_INIT;
   WRPPRINT("%s\n", "WrpSys::Network::DeInitWifiStation() End");
}

eWrpWebSocketStatus WrpWebSocketClient::m_status = WSCLIENT_STATUS_NOTCONNECTED;
char   WrpWebSocketClient::mRecvBuffer[] = {0};
size_t WrpWebSocketClient::mRecvBufferLength = 0;
char   WrpWebSocketClient::mSentBuffer[] = {0};
size_t WrpWebSocketClient::mSentBufferLength = 0;

//static WrpSys::Network::WrpWebSocketClient* gWSClient = NULL;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
void WrpWebSocketClient::EventHandler(struct mg_connection *nc, int ev, void *ev_data)
{
   //WRPPRINT("%s%d\n", "WrpWebSocketClient::EventHandler() Begin m_status:", m_status);
   switch (ev)
   {
      case MG_EV_CONNECT:
      {
         WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() CONNECT");
         int status = *((int *) ev_data);
         if (status != 0)
         {
            WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() Connected Failed!");
            m_status = WSCLIENT_STATUS_NOTCONNECTED;
            //reconnect
            //WrpWebSocketClient::nc = mg_connect_ws(WrpWebSocketClient::mgr, WrpWebSocketClient::EventHandler, WrpWebSocketClient::m_addr.c_str(), "ws_chat", NULL);
            //mg_set_timer(WrpWebSocketClient::nc, mg_time() + 3);
            //if(gWSClient)
            //{
            //	gWSClient->mpConnection = mg_connect_ws(&gWSClient->mEventManager, WrpWebSocketClient::EventHandler, gWSClient->msURI.c_str(), "ws_chat", NULL);
            //	mg_set_timer(gWSClient->mpConnection, mg_time() + 3);
            //}
         }
         break;
      }
      case MG_EV_WEBSOCKET_HANDSHAKE_DONE:
      {
         WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() HANDSHAKE");
         struct http_message *hm = (struct http_message *) ev_data;
         if (hm->resp_code == 101)
         {
            WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() Connected Successfully");
            m_status = WSCLIENT_STATUS_CONNECTED;
         }
         else
         {
            WRPPRINT("%s%d\n", "WrpWebSocketClient::EventHandler() Connected Failed! HTTP Code:", hm->resp_code);
            m_status = WSCLIENT_STATUS_NOTCONNECTED;
         }
         break;
      }
      case MG_EV_POLL:
      {
         //WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() MG_EV_POLL");
         if (WrpWebSocketClient::mSentBufferLength)
         {
            mg_send_websocket_frame(nc, WEBSOCKET_OP_TEXT, WrpWebSocketClient::mSentBuffer, WrpWebSocketClient::mSentBufferLength);
            WrpWebSocketClient::mSentBufferLength = 0;
         }
         break;
      }
      case MG_EV_WEBSOCKET_FRAME:
      {
         WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() MG_EV_WEBSOCKET_FRAME");
         struct websocket_message *wm = (struct websocket_message *) ev_data;
         if (wm->size)
         {
            WrpWebSocketClient::mRecvBufferLength = wm->size;
            snprintf(WrpWebSocketClient::mRecvBuffer, sizeof(WrpWebSocketClient::mRecvBuffer), "%.*s", wm->size, wm->data);
            WRPPRINT("%s%s%d\n", "WrpWebSocketClient::EventHandler() Received Data:", WrpWebSocketClient::mRecvBuffer, WrpWebSocketClient::mRecvBufferLength);
         }
         break;
      }
      case MG_EV_CLOSE:
      {
         WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() MG_EV_CLOSE");
         if (m_status == WSCLIENT_STATUS_CONNECTED)
         {
            WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() Closed");
            m_status = WSCLIENT_STATUS_NOTCONNECTED;
         }
         break;
      }
   }
   //WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() End");
}

WrpWebSocketClient::WrpWebSocketClient()
: mpConnection(NULL)
{
   WRPPRINT("%s\n", "WrpWebSocketClient::WrpWebSocketClient() Begin");
   m_status = WSCLIENT_STATUS_NOTCREATED;
   mg_mgr_init(&mEventManager, NULL);
   WRPPRINT("%s\n", "WrpWebSocketClient::WrpWebSocketClient() End");
}

WrpWebSocketClient::~WrpWebSocketClient()
{
   WRPPRINT("%s\n", "WrpWebSocketClient::~WrpWebSocketClient() Begin");
   m_status = WSCLIENT_STATUS_NOTCREATED;
   mg_mgr_free(&mEventManager);
   WRPPRINT("%s\n", "WrpWebSocketClient::~WrpWebSocketClient() End");
}

bool WrpWebSocketClient::Create(const char *serveraddr, const uint16_t serverport)
{
   WRPPRINT("%s\n", "WrpWebSocketClient::Create() Begin");
   char addr[125] = {0};
   uint32_t nTimeout=0;

   if (serveraddr)
   {
      snprintf(addr, sizeof(addr), "ws://%s:%d", serveraddr, serverport);
   }
   else
   {
      snprintf(addr, sizeof(addr), "ws://127.0.0.1:%d", serverport);
   }
   msURI = addr;
   WRPPRINT("%s%s\n", "WrpWebSocketClient::Create() Address: ", addr);

   mpConnection = mg_connect_ws(&mEventManager, &WrpWebSocketClient::EventHandler, msURI.c_str(), "ws_chat", NULL);
   if (!mpConnection)
   {
      WRPPRINT("%s\n", "WrpWebSocketClient::Create() Create connection failed!");
      return false;
   }
   m_status = WSCLIENT_STATUS_CREATED;

   // wait for server connection
   while (m_status != WSCLIENT_STATUS_CONNECTED)
   {
      mg_mgr_poll(&mEventManager, 100);
      nTimeout++;
      if (nTimeout > 300) break; //30seconds
   }
   if (nTimeout > 300)
   {
      WRPPRINT("%s\n", "WrpWebSocketClient::Create() Cannot connect to server!");
      m_status = WSCLIENT_STATUS_NOTCONNECTED;
   }

   //gWSClient = this;
   WRPPRINT("%s\n", "WrpWebSocketClient::Create() End");
   return true;
}

void WrpWebSocketClient::Close()
{
   WRPPRINT("%s\n", "WrpWebSocketClient::Close() Begin");
   //TODO: close connection before free event manager
   mg_mgr_free(&mEventManager);
   m_status = WSCLIENT_STATUS_NOTCREATED;
   WRPPRINT("%s\n", "WrpWebSocketClient::Close() End");
}

uint32_t WrpWebSocketClient::Receive(char* buf, int size)
{
   mg_mgr_poll(&mEventManager, 100);
   if (WrpWebSocketClient::mRecvBufferLength > 0)
   {
      snprintf(buf, size, "%s",  WrpWebSocketClient::mRecvBuffer);
   }
   return WrpWebSocketClient::mRecvBufferLength;
}

void WrpWebSocketClient::Send(const char* buf, const uint32_t size)
{
   WRPPRINT("%s\n", "WrpWebSocketClient::Send() Begin");
   snprintf(WrpWebSocketClient::mSentBuffer, size, "%s",  buf);
   WrpWebSocketClient::mSentBufferLength = size;
   mg_mgr_poll(&mEventManager, 100);
   WRPPRINT("%s\n", "WrpWebSocketClient::Send() End");
}

void WrpWebSocketClient::ClearBuffer()
{
   WrpWebSocketClient::mRecvBufferLength = 0;
}

WrpWebSocketClient::WrpWebSocketClient(const WrpWebSocketClient& cp)
: mpConnection(NULL)
{
}

} /* Namespace Network */
} /* Namespace WrpSys */
