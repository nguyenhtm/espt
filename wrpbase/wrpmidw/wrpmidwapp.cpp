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

void WrpMidwApp::ThreadWrpMidwApp(void* param)
{
	WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() Begin");
	usleep(100*1000);

	char buf[255]={0};
	uint32_t len=0;

	WrpMidwApp* midwApp = (WrpMidwApp*)param;
	midwApp->SetState(new WrpMidwReadyState(midwApp));

	while(midwApp->m_status != MIDWAPP_STATUS_STOP)
	{
		// MidwApp WebSocket client polling incoming data of web socket client in 100ms
		len = midwApp->m_pWsClient->Receive(buf, sizeof(buf));
		if (len > 0 )
		{
			WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED");
			midwApp->m_status = MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED;
			midwApp->Notify(buf, len);
			usleep(100*1000);
			midwApp->m_status = MIDWAPP_WSCLIENT_STATUS_DATA_CLEAR;
			midwApp->m_pWsClient->ClearBuffer();
		}

		// MidwApp State Context handling state based on ws server, wifi,...status
        // for wifi connection
    	if (WrpSys::Network::m_uNetworkStatus != NETWORK_STATUS_CONNECTED)
    	{
    		//TODO: display no wifi icon
    	}

    	// for websocket server connection
    	switch(midwApp->GetWSClient()->m_status)
    	{
			case WSCLIENT_STATUS_NOTCONNECTED:
			{
				midwApp->SetState(new WrpMidwWsNotConnectedState(midwApp));
			}
			break;
			/*
			case WSCLIENT_STATUS_CONNECTED:
			{
				midwApp->SetState(new WrpMidwReadyState(midwApp));
			}
			break;
			*/
			default:
			{
				// fall through
			}
			break;
    	}
	}
	WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() End");
}
