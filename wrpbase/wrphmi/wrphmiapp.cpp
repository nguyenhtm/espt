/********************************************************************************************************
 * @File  : wrphmiapp.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrphmiapp.hpp"
#include "wrpbase/wrpsys/wrpdisplay.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpHmiApp* WrpHmiApp::m_pInstance = NULL;

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
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
: m_status(eWrpHmiAppStatus::HMIAPP_STATUS_INIT)
{
	WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() Begin");
	m_listOfScreens.clear();
	WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() End");
}

WrpHmiApp::~WrpHmiApp()
{
	WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() Begin");
	m_listOfScreens.clear();
	WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() End");
}

eWrpHmiAppStatus WrpHmiApp::GetStatus()
{
	return m_status;
}

void WrpHmiApp::Start()
{
	WRPPRINT("%s\n", "WrpHmiApp::Start() Begin");

	WrpSys::InitLvglLib();

	m_status = eWrpHmiAppStatus::HMIAPP_STATUS_STARTED;
#if LVGL_PC_SIMU
	SDL_CreateThread(WrpHmiApp::ThreadWrpHmiApp, "ThreadWrpHmiApp", this);
#elif LVGL_ESP32_ILI9341
	xTaskCreate(&WrpHmiApp::ThreadWrpHmiApp, "ThreadWrpHmiApp", 4096, this, 5, NULL);
#endif
}

void WrpHmiApp::Stop()
{
	m_status = eWrpHmiAppStatus::HMIAPP_STATUS_STOPPED;
}

#if LVGL_PC_SIMU
int WrpHmiApp::ThreadWrpHmiApp(void* param)
#elif LVGL_ESP32_ILI9341
void WrpHmiApp::ThreadWrpHmiApp(void* param)
#endif
{
	WRPPRINT("%s\n", "WrpHmiApp::ThreadWrpHmiApp() Begin");

	WrpHmiApp* app = (WrpHmiApp*)param;
	while(app->m_status == eWrpHmiAppStatus::HMIAPP_STATUS_STARTED)
	{
		usleep(500*1000);
	}

	WRPPRINT("%s\n", "WrpHmiApp::ThreadWrpHmiApp() End");
#if LVGL_PC_SIMU
	return 0;
#endif
}

void WrpHmiApp::AddScreen(WrpGui::WrpScreen* handler, const uint16_t id)
{
	tWrpHmiScreen *tmp = new tWrpHmiScreen;
	tmp->_scrHandler = handler;
	tmp->_scrId = id;
	m_listOfScreens.push_back(tmp);
}

void WrpHmiApp::LoadScreen(const uint16_t id)
{
	std::vector<tWrpHmiScreen*>::iterator it;
	for (it = m_listOfScreens.begin(); it != m_listOfScreens.end(); ++it)
	{
		if ((*it)->_scrId == id)
		{
			break;
		}
	}
	if (it != m_listOfScreens.end())
	{
		(*it)->_scrHandler->Load();
	}
}
