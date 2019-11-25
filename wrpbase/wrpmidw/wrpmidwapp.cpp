/********************************************************************************************************
 * @File  : wrpmidwapp.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwapp.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpMidwApp* WrpMidwApp::m_pInstance = NULL;
eWrpMidwAppStatus WrpMidwApp::m_status = MIDWAPP_STATUS_INIT;
std::vector<WrpMidwAppClient*> WrpMidwApp::m_listOfObservers = {};

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpMidwApp* WrpMidwApp::GetInstance()
{
	WRPPRINT("%s\n", "WrpMidwApp::GetInstance() Begin");
	if (!m_pInstance)
	{
		m_pInstance = new WrpMidwApp();
	}
	WRPPRINT("%s\n", "WrpMidwApp::GetInstance() End");
	return m_pInstance;
}

WrpMidwApp::WrpMidwApp()
: m_wsClient(NULL)
{
	WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() Begin");
	m_wsClient = new WrpSys::Network::WrpWebSocketClient;
	m_listOfObservers.clear();
	WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() End");
}

WrpMidwApp::~WrpMidwApp()
{
	WRPPRINT("%s\n", "WrpMidwApp::~WrpMidwApp() Begin");
	delete m_wsClient;
	m_listOfObservers.clear();
	WRPPRINT("%s\n", "WrpMidwApp::~WrpMidwApp() End");
}

void WrpMidwApp::Attach(WrpMidwAppClient* client)
{
	WRPNULL_CHECK(client)
	WRPPRINT("%s\n", "WrpMidwApp::Attach() Begin");
	m_listOfObservers.push_back(client);
	WRPPRINT("%s\n", "WrpMidwApp::Attach() End");
}

void WrpMidwApp::Detach(WrpMidwAppClient* client)
{
	WRPNULL_CHECK(client)
	WRPPRINT("%s\n", "WrpMidwApp::Detach() Begin");
	std::vector<WrpMidwAppClient*>::iterator it;
	it = std::find(m_listOfObservers.begin(), m_listOfObservers.end(), client);
	if (it != m_listOfObservers.end())
	{
		m_listOfObservers.erase(it);
	}
	WRPPRINT("%s\n", "WrpMidwApp::Detach() End");
}

void WrpMidwApp::Notify(char* buffer, unsigned int length)
{
	WRPPRINT("%s\n", "WrpMidwApp::Notify() Begin");
	size_t numOfElements = m_listOfObservers.size();
	for (int i = 0; i < numOfElements; i++)
	{
		m_listOfObservers[i]->Update(m_status, buffer, length);
	}
	WRPPRINT("%s\n", "WrpMidwApp::Notify() End");
}

eWrpMidwAppStatus WrpMidwApp::GetStatus()
{
	return m_status;
}

void WrpMidwApp::Start()
{
	WrpSys::System::PrintChipInfo();
	WrpSys::Storage::InitNVS(); // must 1st initialization
	WrpSys::Network::InitWifiStation();

	m_status = MIDWAPP_STATUS_STARTED;

	WrpSys::System::WrpCreateThread(WrpMidwApp::ThreadWrpMidwApp, "WrpMidwApp", this);
}

void WrpMidwApp::Stop()
{
	m_status = MIDWAPP_STATUS_STOPPED;
	usleep(2000*1000);
}

void WrpMidwApp::ThreadWrpMidwApp(void* param)
{
	WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() Begin");
	bool bEnableLoop = true;
	static eWrpMidwAppStatus preStatus = MIDWAPP_STATUS_INIT;
	char buf[255]={0};

	WrpMidwApp* app = (WrpMidwApp*)param;

	//TODO: check when wifi connection success then
	usleep(5000*1000);

#if LVGL_PC_SIMU
	app->m_wsClient->Create("127.0.0.1", 8000);
#elif LVGL_ESP32_ILI9341
	app->m_wsClient->Create("172.20.10.5", 8000);
#endif

	while(bEnableLoop)
	{
		// MidwApp WebSocket client polling incoming data of web socket client in 100ms
		int len = app->m_wsClient->Receive(buf, sizeof(buf));
		if (len > 0 )
		{
			m_status = MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED;
			Notify(buf, len);
			usleep(100*1000);
			WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED");
			m_status = MIDWAPP_WSCLIENT_STATUS_DATA_CLEAR;
			app->m_wsClient->ClearBuffer();
		}

		// MidwApp Status
		if (preStatus == m_status)
		{
			continue;
		}
		preStatus = m_status;
		switch(m_status)
		{
			case MIDWAPP_STATUS_INIT:
			case MIDWAPP_STATUS_STARTED:
			{
				Notify(NULL, 0);
			}
			break;
			case MIDWAPP_STATUS_STOPPED:
			{
				Notify(NULL, 0);
				bEnableLoop = false;
			}
			break;
			default:
			{
			}
			break;
		}
	}
	WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() End");
}
