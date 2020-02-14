/********************************************************************************************************
 * @File  : wrpwifistate.cpp
 * @Date  : 2019-12-19
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwstate.hpp"
#include "wrpmidwbuilder.hpp"
#include "wrpmidwapp.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS - WrpMidwInitState
 ********************************************************************************************************/
void WrpMidwInitState::Handle()
{
	WRPPRINT("%s\n", "WrpMidwInitState::Handle() Begin");
	m_context->ReadConfig();
	m_context->m_pWsClient = new WrpWebSocketClient;
#if LVGL_PC_SIMU
	m_context->GetWSClient()->Create("127.0.0.1", 8000);
#elif LVGL_ESP32_ILI9341
	m_context->GetWSClient()->Create("192.168.1.7", 8000);
#endif
	m_context->m_status = MIDWAPP_STATUS_START;
	m_context->m_threadid = WrpSys::System::WrpCreateThread(WrpMidwApp::ThreadWrpMidwApp, "WrpMidwApp", m_context);
	if (!m_context->m_threadid)
	{
		WRPPRINT("%s\n", "WrpMidwInitState::Handle() WrpCreateThread Failed!");
		m_context->m_status = MIDWAPP_STATUS_STOP;
		return;
	}
	WRPPRINT("%s\n", "WrpMidwInitState::Handle() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwDeInitState
 ********************************************************************************************************/
void WrpMidwDeInitState::Handle()
{
	WRPPRINT("%s\n", "WrpMidwDeInitState::Handle() Begin");
	m_context->m_status = MIDWAPP_STATUS_STOP;
	delete m_context->m_pWsClient;
	WRPPRINT("%s\n", "WrpMidwDeInitState::Handle() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwReadyState
 ********************************************************************************************************/
void WrpMidwReadyState::Handle()
{
	WRPPRINT("%s\n", "WrpMidwReadyState::Handle() Begin");
	WRPPRINT("%s\n", "WrpMidwReadyState::Handle() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpWifiConnectedState
 ********************************************************************************************************/
void WrpWifiConnectedState::Handle()
{
	WRPPRINT("%s\n", "WrpWifiConnectedState::Handle() Begin");
	WRPPRINT("%s\n", "WrpWifiConnectedState::Handle() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpWifiNotConnectedState
 ********************************************************************************************************/
void WrpWifiNotConnectedState::Handle()
{
	WRPPRINT("%s\n", "WrpWifiNOTConnectedState::Handle() Begin");
	sleep(1);
	WRPPRINT("%s\n", "WrpWifiNOTConnectedState::Handle() End");
	m_context->SetState(new WrpMidwReadyState(m_context));
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwWsConnectedState
 ********************************************************************************************************/
void WrpMidwWsConnectedState::Handle()
{
	WRPPRINT("%s\n", "WrpMidwWsConnectedState::Handle() Begin");

	WRPPRINT("%s\n", "WrpMidwWsConnectedState::Handle() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwWsNotConnectedState
 ********************************************************************************************************/
void WrpMidwWsNotConnectedState::Handle()
{
	WRPPRINT("%s\n", "WrpMidwWsNotConnectedState::Handle() Begin");
	//TODO: display icon
	WRPPRINT("%s\n", "WrpMidwWsNotConnectedState::Handle() End");
}

