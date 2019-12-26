/********************************************************************************************************
 * @File  : wrpmidwapp.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwapp.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpMidwApp* WrpMidwApp::m_pInstance = NULL;

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
: m_pWsClient(NULL)
, m_status(MIDWAPP_STATUS_INIT)
, m_threadid(NULL)
{
	WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() Begin");
	m_pWsClient = new WrpWebSocketClient;
	m_listOfObservers.clear();
	WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() End");
}

WrpMidwApp::~WrpMidwApp()
{
	WRPPRINT("%s\n", "WrpMidwApp::~WrpMidwApp() Begin");
	delete m_pWsClient;
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
	for (size_t i = 0; i < numOfElements; i++)
	{
		m_listOfObservers[i]->Update(m_status, buffer, length);
	}
	WRPPRINT("%s\n", "WrpMidwApp::Notify() End");
}

bool WrpMidwApp::Start()
{
	WRPPRINT("%s\n", "WrpMidwApp::Start() Begin");
	WrpSys::System::PrintChipInfo();
	WrpSys::Storage::InitNVS(); // must 1st initialization
	WrpSys::Network::InitWifiStation();

	m_threadid = WrpSys::System::WrpCreateThread(WrpMidwApp::ThreadWrpMidwApp, "WrpMidwApp", this);
	if (!m_threadid)
	{
		WRPPRINT("%s\n", "WrpMidwApp::Start() ThreadWrpMidwApp Started Unsuccessfully!");
		return false;
	}
	m_status = MIDWAPP_STATUS_START;
	WRPPRINT("%s\n", "WrpMidwApp::Start() End");
	return true;
}

void WrpMidwApp::Stop()
{
	m_status = MIDWAPP_STATUS_STOP;
	usleep(2000*1000);
}

void WrpMidwApp::ThreadWrpMidwApp(void* param)
{
	WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() Begin");

	static eWrpMidwAppStatus preStatus = MIDWAPP_STATUS_INIT;
	char buf[255]={0};

	WrpMidwApp* app = (WrpMidwApp*)param;

	//TODO: check when wifi connection success then
	usleep(5000*1000);

#if LVGL_PC_SIMU
	app->m_pWsClient->Create("127.0.0.1", 8000);
#elif LVGL_ESP32_ILI9341
	app->m_pWsClient->Create("172.20.10.5", 8000);
#endif

	while(app->m_status != MIDWAPP_STATUS_STOP)
	{
		// MidwApp WebSocket client polling incoming data of web socket client in 100ms
		int len = app->m_pWsClient->Receive(buf, sizeof(buf));
		if (len > 0 )
		{
			app->m_status = MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED;
			app->Notify(buf, len);
			usleep(100*1000);
			WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED");
			app->m_status = MIDWAPP_WSCLIENT_STATUS_DATA_CLEAR;
			app->m_pWsClient->ClearBuffer();
		}

		// MidwApp Status
		if (preStatus == app->m_status)
		{
			continue;
		}
		preStatus = app->m_status;
		switch(app->m_status)
		{
			case MIDWAPP_STATUS_INIT:
			case MIDWAPP_STATUS_START:
			case MIDWAPP_STATUS_STOP:
			{
				app->Notify(NULL, 0);
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
