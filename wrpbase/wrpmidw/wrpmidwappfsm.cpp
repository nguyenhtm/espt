/********************************************************************************************************
 * @File  : wrpwifistate.cpp
 * @Date  : 2019-12-19
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwappfsm.hpp"
#include "wrpmidwapp.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppState
 ********************************************************************************************************/
WrpMidwAppState::WrpMidwAppState(WrpMidwApp* context)
: mpContext(context)
{
}

WrpMidwAppState::~WrpMidwAppState()
{
}

WrpMidwAppState::WrpMidwAppState()
: mpContext(NULL)
{
}

WrpMidwAppState::WrpMidwAppState(const WrpMidwAppState& cp)
: mpContext(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppInitState
 ********************************************************************************************************/
WrpMidwAppInitState::WrpMidwAppInitState(WrpMidwApp* context)
: WrpMidwAppState(context)
{
}

WrpMidwAppInitState::~WrpMidwAppInitState()
{
}

void WrpMidwAppInitState::Handle()
{
   WRPPRINT("%s\n", "WrpMidwAppInitState::Handle() Begin");
   mpContext->ReadConfig();
   mpContext->mpWsClientHandle = new WrpWebSocketClient;
#if USE_ESP_IDF
   mpContext->mpWsClientHandle->Create("192.168.1.9", 8000);
#else
   mpContext->mpWsClientHandle->Create("127.0.0.1", 8000);
#endif
   mpContext->mMidwAppStatus = MIDWAPP_STATUS_START;
   mpContext->mThreadId = WrpSys::System::WrpCreateThread(WrpMidwApp::ThreadWrpMidwApp, "WrpMidwApp", mpContext);
   if (!mpContext->mThreadId)
   {
      WRPPRINT("%s\n", "WrpMidwAppInitState::Handle() WrpCreateThread Failed!");
      mpContext->mMidwAppStatus = MIDWAPP_STATUS_STOP;
      return;
   }
   WRPPRINT("%s\n", "WrpMidwAppInitState::Handle() End");
}

WrpMidwAppInitState::WrpMidwAppInitState()
{
}

WrpMidwAppInitState::WrpMidwAppInitState(const WrpMidwAppInitState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppDeInitState
 ********************************************************************************************************/
WrpMidwAppDeInitState::WrpMidwAppDeInitState(WrpMidwApp* context)
: WrpMidwAppState(context)
{
}

WrpMidwAppDeInitState::~WrpMidwAppDeInitState()
{
}

void WrpMidwAppDeInitState::Handle()
{
   WRPPRINT("%s\n", "WrpMidwAppDeInitState::Handle() Begin");
   mpContext->mMidwAppStatus = MIDWAPP_STATUS_STOP;
   delete mpContext->mpWsClientHandle; //TODO: close before delete
   WRPPRINT("%s\n", "WrpMidwAppDeInitState::Handle() End");
}

WrpMidwAppDeInitState::WrpMidwAppDeInitState()
{
}

WrpMidwAppDeInitState::WrpMidwAppDeInitState(const WrpMidwAppDeInitState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppReadyState
 ********************************************************************************************************/
WrpMidwAppReadyState::WrpMidwAppReadyState(WrpMidwApp* context)
: WrpMidwAppState(context)
{
}

WrpMidwAppReadyState::~WrpMidwAppReadyState()
{
}

void WrpMidwAppReadyState::Handle()
{
   WRPPRINT("%s\n", "WrpMidwAppReadyState::Handle() Begin");
   WRPPRINT("%s\n", "WrpMidwAppReadyState::Handle() End");
}

WrpMidwAppReadyState::WrpMidwAppReadyState()
{
}

WrpMidwAppReadyState::WrpMidwAppReadyState(const WrpMidwAppReadyState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpWifiConnectedState
 ********************************************************************************************************/
WrpWifiConnectedState::WrpWifiConnectedState(WrpMidwApp* context)
: WrpMidwAppState(context)
{
}

WrpWifiConnectedState::~WrpWifiConnectedState()
{
}

void WrpWifiConnectedState::Handle()
{
   WRPPRINT("%s\n", "WrpWifiConnectedState::Handle() Begin");
   WRPPRINT("%s\n", "WrpWifiConnectedState::Handle() End");
}

WrpWifiConnectedState::WrpWifiConnectedState()
{
}

WrpWifiConnectedState::WrpWifiConnectedState(const WrpWifiConnectedState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpWifiNotConnectedState
 ********************************************************************************************************/
WrpWifiNotConnectedState::WrpWifiNotConnectedState(WrpMidwApp* context)
: WrpMidwAppState(context)
{
}

WrpWifiNotConnectedState::~WrpWifiNotConnectedState()
{
}

void WrpWifiNotConnectedState::Handle()
{
   WRPPRINT("%s\n", "WrpWifiNOTConnectedState::Handle() Begin");
   sleep(1);
   WRPPRINT("%s\n", "WrpWifiNOTConnectedState::Handle() End");
   mpContext->SetState(new WrpMidwAppReadyState(mpContext));
}

WrpWifiNotConnectedState::WrpWifiNotConnectedState()
{
}

WrpWifiNotConnectedState::WrpWifiNotConnectedState(const WrpWifiNotConnectedState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpWsClientConnectedState
 ********************************************************************************************************/
WrpWsClientConnectedState::WrpWsClientConnectedState(WrpMidwApp* context)
: WrpMidwAppState(context)
{
}

WrpWsClientConnectedState::~WrpWsClientConnectedState()
{
}

void WrpWsClientConnectedState::Handle()
{
   WRPPRINT("%s\n", "WrpWsClientConnectedState::Handle() Begin");
   WRPPRINT("%s\n", "WrpWsClientConnectedState::Handle() End");
}

WrpWsClientConnectedState::WrpWsClientConnectedState()
{
}

WrpWsClientConnectedState::WrpWsClientConnectedState(const WrpWsClientConnectedState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpWsClientNotConnectedState
 ********************************************************************************************************/
WrpWsClientNotConnectedState::WrpWsClientNotConnectedState(WrpMidwApp* context)
: WrpMidwAppState(context)
{
}

WrpWsClientNotConnectedState::~WrpWsClientNotConnectedState()
{
}

void WrpWsClientNotConnectedState::Handle()
{
   WRPPRINT("%s\n", "WrpWsClientNotConnectedState::Handle() Begin");
   //TODO: display icon
   WRPPRINT("%s\n", "WrpWsClientNotConnectedState::Handle() End");
}

WrpWsClientNotConnectedState::WrpWsClientNotConnectedState()
{
}

WrpWsClientNotConnectedState::WrpWsClientNotConnectedState(const WrpWsClientNotConnectedState& cp)
{
}
