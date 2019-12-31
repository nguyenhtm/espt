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


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpMidwApp::WrpMidwApp()
: m_pWsClient(NULL)
, m_threadid(NULL)
, m_pCurrentState(NULL)
{
	WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() Begin");
	m_listOfObservers.clear();
	m_status = MIDWAPP_STATUS_STOP;
	WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() End");
}

WrpMidwApp::~WrpMidwApp()
{
	WRPPRINT("%s\n", "WrpMidwApp::~WrpMidwApp() Begin");
	m_listOfObservers.clear();
	m_status = MIDWAPP_STATUS_STOP;
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

void WrpMidwApp::SetState(WrpMidwState* state)
{
	if(m_pCurrentState)
	{
		delete m_pCurrentState;
	}
	m_pCurrentState = state;
	m_pCurrentState->Handle();
}

void WrpMidwApp::ReadConfig()
{
	WRPPRINT("%s\n", "WrpMidw::ReadConfig() Begin");
	if (WrpSys::Storage::m_uStorageStatus && STORAGE_STATUS_INITSPIFFS)
	{

	}
	WRPPRINT("%s\n", "WrpMidw::ReadConfig() End");
}

void WrpMidwApp::Stop()
{
	m_status = MIDWAPP_STATUS_STOP;
	usleep(2000*1000);
}

void WrpMidwApp::ThreadWrpMidwApp(void* param)
{
	WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() Begin");

	char buf[255]={0};
	uint32_t len=0;

	WrpMidwApp* app = (WrpMidwApp*)param;

	while(app->m_status != MIDWAPP_STATUS_STOP)
	{
		// MidwApp WebSocket client polling incoming data of web socket client in 100ms
		len = app->m_pWsClient->Receive(buf, sizeof(buf));
		if (len > 0 )
		{
			WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED");
			app->m_status = MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED;
			app->Notify(buf, len);
			usleep(100*1000);
			app->m_status = MIDWAPP_WSCLIENT_STATUS_DATA_CLEAR;
			app->m_pWsClient->ClearBuffer();
		}

	}
	WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() End");
}
