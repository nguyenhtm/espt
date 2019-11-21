/*
 * File  : wrpnetwork.cpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpnetwork.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
#if USE_ESP_IDF
#define WRPESP_WIFI_CONNECTED_BIT  BIT0

static EventGroupHandle_t g_EventGroup = xEventGroupCreate();
#endif

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpSys {
namespace WrpSysNetwork {

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
			break;
		}
		case SYSTEM_EVENT_STA_GOT_IP:
		{
			WRPPRINT("WrpBase:%s%s\n", "WrpSysNetwork::LegacyEventHandler() Got IP:", ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
			xEventGroupSetBits(g_EventGroup, WRPESP_WIFI_CONNECTED_BIT);
			break;
		}
		case SYSTEM_EVENT_STA_DISCONNECTED:
		{
			WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::LegacyEventHandler() Disconnected!");
			esp_wifi_connect();
			xEventGroupClearBits(g_EventGroup, WRPESP_WIFI_CONNECTED_BIT);
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
	WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::InitWifiStation() Begin");
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
	WRPPRINT("WrpBase:%s\n", "WrpSysNetwork::InitWifiStation() End");
}

eWrpWebSocketStatus WrpWebSocketClient::m_status = WSCLIENT_STATUS_INIT;
struct mg_mgr WrpWebSocketClient::mgr;
struct mg_connection *WrpWebSocketClient::nc;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

char WrpWebSocketClient::m_data[255] = {0};
unsigned int WrpWebSocketClient::m_datalength = 0;

void WrpWebSocketClient::EventHandler(struct mg_connection *nc, int ev, void *ev_data)
{
	switch (ev)
	{
		case MG_EV_CONNECT:
		{
			int status = *((int *) ev_data);
			if (status != 0)
			{
				WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() Connected Failed!");
				m_status = WSCLIENT_STATUS_CONNECTED_ERROR;
			}
			break;
		}

		case MG_EV_WEBSOCKET_HANDSHAKE_DONE:
		{
			struct http_message *hm = (struct http_message *) ev_data;
			if (hm->resp_code == 101)
			{
				WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() Connected Successfully");
				m_status = WSCLIENT_STATUS_CONNECTED;
			}
			else
			{
				WRPPRINT("%s%d\n", "WrpWebSocketClient::EventHandler() Connected Failed! HTTP Code:", hm->resp_code);
				/* Connection will be closed after this. */
				m_status = WSCLIENT_STATUS_CONNECTED_ERROR;
			}
			break;
		}
		case MG_EV_POLL:
		{
		  //WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() MG_EV_POLL");
		  break;
		}
		case MG_EV_WEBSOCKET_FRAME:
		{
			struct websocket_message *wm = (struct websocket_message *) ev_data;
			WrpWebSocketClient::m_datalength = wm->size;
			if (wm->size)
			{
				m_status = WSCLIENT_STATUS_DATA_RECEIVED;
				snprintf(WrpWebSocketClient::m_data, sizeof(WrpWebSocketClient::m_data), "%.*s", wm->size, wm->data);
				WRPPRINT("%s%s%d\n", "WrpWebSocketClient::EventHandler() Received Data:", WrpWebSocketClient::m_data, wm->size);
			}
			break;
		}
		case MG_EV_CLOSE:
		{
			if (m_status == WSCLIENT_STATUS_CONNECTED)
			{
				WRPPRINT("%s\n", "WrpWebSocketClient::EventHandler() Closed");
				m_status = WSCLIENT_STATUS_CLOSED;
			}
			break;
		}

	}
}

WrpWebSocketClient::WrpWebSocketClient()
{
	WRPPRINT("%s\n", "WrpWebSocketClient::WrpWebSocketClient() Begin");

	WRPPRINT("%s\n", "WrpWebSocketClient::WrpWebSocketClient() End");
}

WrpWebSocketClient::~WrpWebSocketClient()
{
	WRPPRINT("%s\n", "WrpWebSocketClient::~WrpWebSocketClient() Begin");

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

	mg_mgr_init(&WrpWebSocketClient::mgr, NULL);
	WrpWebSocketClient::nc = mg_connect_ws(&WrpWebSocketClient::mgr, WrpWebSocketClient::EventHandler, addr, "ws_chat", NULL);
	if (WrpWebSocketClient::nc == NULL)
	{
		WRPPRINT("%s\n", "WrpWebSocketClient::Create() Connection Failed!");
		return false;
	}
	m_status = WSCLIENT_STATUS_CREATED;

	WRPPRINT("%s\n", "WrpWebSocketClient::Create() End");
	return true;
}

void WrpWebSocketClient::Poll()
{
	mg_mgr_poll(&WrpWebSocketClient::mgr, 1000);
}

void WrpWebSocketClient::Close()
{
	WRPPRINT("%s\n", "WrpWebSocketClient::Close() Begin\n");
	mg_mgr_free(&WrpWebSocketClient::mgr);
	WRPPRINT("%s\n", "WrpWebSocketClient::Close() End\n");
}

int WrpWebSocketClient::Receive(char* buf, int size)
{
	if (m_status != WSCLIENT_STATUS_INIT)
	{
		mg_mgr_poll(&WrpWebSocketClient::mgr, 100);
		if (WrpWebSocketClient::m_datalength > 0)
		{
			snprintf(buf, size, "%s",  WrpWebSocketClient::m_data);
		}
		return WrpWebSocketClient::m_datalength;
	}
	return 0;
}

void WrpWebSocketClient::ClearBuffer()
{
	//memset(WrpWebSocketClient::m_data, sizeof(WrpWebSocketClient::m_data), 0);
	WrpWebSocketClient::m_datalength = 0;
}

} /* Namespace WrpSysNetwork */
} /* Namespace WrpSys */
