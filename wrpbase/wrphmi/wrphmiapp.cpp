/********************************************************************************************************
 * @File  : wrphmiapp.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrphmiapp.hpp"
#include "wrpbase/wrpsys/wrpdisplay.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpHmiApp* WrpHmiApp::m_pInstance = NULL;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpHmiAppClient::WrpHmiAppClient()
: m_pScreenHandle(NULL)
, m_ScreenId(0)
, m_status(HMIAPP_CLIENT_UNLOADED)
{

}

WrpHmiAppClient::~WrpHmiAppClient()
{

}

WrpHmiApp* WrpHmiApp::GetInstance()
{
	WRPPRINT("%s\n", "WrpHmiApp::GetInstance() Begin");
	if (!m_pInstance)
	{
		m_pInstance = new WrpHmiApp();
	}
	WRPPRINT("%s\n", "WrpHmiApp::GetInstance() End");
	return m_pInstance;
}

WrpHmiApp::WrpHmiApp()
: m_threadid(NULL)
{
	WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() Begin");
	m_listOfObservers.clear();
	m_status = HMIAPP_STATUS_STOP;
	WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() End");
}

WrpHmiApp::~WrpHmiApp()
{
	WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() Begin");
	m_listOfObservers.clear();
	m_status = HMIAPP_STATUS_STOP;
	WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() End");
}

eWrpHmiAppStatus WrpHmiApp::GetStatus()
{
	return m_status;
}

bool WrpHmiApp::Start()
{
	WRPPRINT("%s\n", "WrpHmiApp::Start() Begin");
	m_status = eWrpHmiAppStatus::HMIAPP_STATUS_START;
	m_threadid = WrpSys::System::WrpCreateThread(WrpHmiApp::ThreadWrpHmiApp, "WrpHmiApp", this);
	if (!m_threadid)
	{
		WRPPRINT("%s\n", "WrpHmiApp::Start() WrpCreateThread Failed!");
		m_status = HMIAPP_STATUS_STOP;
		return false;
	}
	WRPPRINT("%s\n", "WrpHmiApp::Start() End");
	return true;
}

void WrpHmiApp::Stop()
{
	m_status = HMIAPP_STATUS_STOP;
}

void WrpHmiApp::ThreadWrpHmiApp(void* param)
{
	WRPPRINT("%s\n", "WrpHmiApp::ThreadWrpHmiApp() Begin");

	WrpHmiApp* app = (WrpHmiApp*)param;
	while(app->m_status == HMIAPP_STATUS_START)
	{
    	// for display
        usleep(100*1000); // 100ms
        lv_task_handler();
	}

	WRPPRINT("%s\n", "WrpHmiApp::ThreadWrpHmiApp() End");
}

void WrpHmiApp::LoadScreen(const uint16_t id)
{
	WRPPRINT("%s\n", "WrpHmiApp::LoadScreen() Begin");

	std::vector<WrpHmiAppClient*>::iterator it;

	// destroy and hide the current screen
	for (it = m_listOfObservers.begin(); it != m_listOfObservers.end(); ++it)
	{
		if (((*it)->GetScreenStatus() == HMIAPP_CLIENT_LOADED) && ((*it)->GetClientId() != id))
		{
			break;
		}
	}
	if (it != m_listOfObservers.end())
	{
		(*it)->HideAndDestroy();
		(*it)->SetScreenStatus(HMIAPP_CLIENT_UNLOADED);
	}

	// then create and show the screen with id
	for (it = m_listOfObservers.begin(); it != m_listOfObservers.end(); ++it)
	{
		if ((*it)->GetClientId() == id)
		{
			break;
		}
	}
	if (it != m_listOfObservers.end())
	{
		(*it)->CreateAndShow();
		(*it)->GetScreenHandle()->Load();
		(*it)->SetScreenStatus(HMIAPP_CLIENT_LOADED);
	}

	WRPPRINT("%s\n", "WrpHmiApp::LoadScreen() End");
}

void WrpHmiApp::Attach(WrpHmiAppClient* client, const uint16_t id)
{
	WRPNULL_CHECK(client)
	WRPPRINT("%s\n", "WrpHmiApp::Attach() Begin");
	client->SetClientId(id);
	m_listOfObservers.push_back(client);
	WRPPRINT("%s\n", "WrpHmiApp::Attach() End");
}

void WrpHmiApp::Detach(WrpHmiAppClient* client)
{
	WRPNULL_CHECK(client)
	WRPPRINT("%s\n", "WrpHmiApp::Detach() Begin");
	std::vector<WrpHmiAppClient*>::iterator it;
	it = std::find(m_listOfObservers.begin(), m_listOfObservers.end(), client);
	if (it != m_listOfObservers.end())
	{
		m_listOfObservers.erase(it);
	}
	WRPPRINT("%s\n", "WrpHmiApp::Detach() End");
}
