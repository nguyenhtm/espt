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
struct mg_mgr* WrpWebSocketClient::mgr = NULL;
struct mg_connection* WrpWebSocketClient::nc = NULL;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

char WrpWebSocketClient::m_data[255] = {0};
unsigned int WrpWebSocketClient::m_datalength = 0;
std::string WrpWebSocketClient::m_addr = "";

void WrpWebSocketClient::EventHandler(struct mg_connection *nc, int ev, void *ev_data)
{
	WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() Begin");
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
				WrpWebSocketClient::nc = mg_connect_ws(WrpWebSocketClient::mgr, WrpWebSocketClient::EventHandler, WrpWebSocketClient::m_addr.c_str(), "ws_chat", NULL);
				mg_set_timer(WrpWebSocketClient::nc, mg_time() + 3);
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
		  WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() MG_EV_POLL");
		  break;
		}
		case MG_EV_WEBSOCKET_FRAME:
		{
			WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() MG_EV_WEBSOCKET_FRAME");
			struct websocket_message *wm = (struct websocket_message *) ev_data;
			WrpWebSocketClient::m_datalength = (uint16_t)wm->size;
			if (wm->size)
			{
				snprintf(WrpWebSocketClient::m_data, sizeof(WrpWebSocketClient::m_data), "%.*s", wm->size, wm->data);
				WRPPRINT("%s%s%d\n", "WrpWebSocketClient::EventHandler() Received Data:", WrpWebSocketClient::m_data, wm->size);
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
	WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() End");
}

WrpWebSocketClient::WrpWebSocketClient()
{
	WRPPRINT("%s\n", "WrpWebSocketClient::WrpWebSocketClient() Begin");
	m_status = WSCLIENT_STATUS_NOTCREATED;
	WRPPRINT("%s\n", "WrpWebSocketClient::WrpWebSocketClient() End");
}

WrpWebSocketClient::~WrpWebSocketClient()
{
	WRPPRINT("%s\n", "WrpWebSocketClient::~WrpWebSocketClient() Begin");
	m_status = WSCLIENT_STATUS_NOTCREATED;
	WRPPRINT("%s\n", "WrpWebSocketClient::~WrpWebSocketClient() End");
}

bool WrpWebSocketClient::Create(const char *uri, const unsigned int port)
{
	WRPPRINT("%s\n", "WrpWebSocketClient::Create() Begin");
	char addr[125] = {0};

	if (!uri)
	{
		snprintf(addr, sizeof(addr), "%s:%d", "localhost", port);
	}
	else
	{
		snprintf(addr, sizeof(addr), "%s:%d", uri, port);
	}
	m_addr = addr;
	m_port = port;
	WRPPRINT("%s%s\n", "WrpWebSocketClient::Create() Address:", addr);
	WrpWebSocketClient::mgr = new struct mg_mgr;
	mg_mgr_init(WrpWebSocketClient::mgr, NULL);

	WrpWebSocketClient::nc = mg_connect_ws(WrpWebSocketClient::mgr, WrpWebSocketClient::EventHandler, addr, "ws_chat", NULL);

	m_status = WSCLIENT_STATUS_CREATED;

	WRPPRINT("%s\n", "WrpWebSocketClient::Create() End");
	return true;
}

void WrpWebSocketClient::Close()
{
	WRPPRINT("%s\n", "WrpWebSocketClient::Close() Begin");
	mg_mgr_free(WrpWebSocketClient::mgr);
	m_status = WSCLIENT_STATUS_NOTCREATED;
	WRPPRINT("%s\n", "WrpWebSocketClient::Close() End");
}

uint32_t WrpWebSocketClient::Receive(char* buf, int size)
{
	//if (m_status != WSCLIENT_STATUS_NOTCONNECTED)
	{
		mg_mgr_poll(WrpWebSocketClient::mgr, 300);
		if (WrpWebSocketClient::m_datalength > 0)
		{
			snprintf(buf, size, "%s",  WrpWebSocketClient::m_data);
		}
		return WrpWebSocketClient::m_datalength;
	}
	return 0;
}

void WrpWebSocketClient::Send(const char* buf, const uint8_t size)
{
	mg_send_websocket_frame(WrpWebSocketClient::nc, WEBSOCKET_OP_TEXT, buf, size);
}

void WrpWebSocketClient::ClearBuffer()
{
	//memset(WrpWebSocketClient::m_data, sizeof(WrpWebSocketClient::m_data), 0);
	WrpWebSocketClient::m_datalength = 0;
}

} /* Namespace Network */
} /* Namespace WrpSys */
