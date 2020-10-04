/********************************************************************************************************
 * @File  : wrpwifistate.cpp
 * @Date  : 2019-12-19
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwfsm.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpMidwState
 ********************************************************************************************************/
WrpMidwState::WrpMidwState(WrpMidwApp* context)
: mpContext(context)
{
}

WrpMidwState::~WrpMidwState()
{
}

WrpMidwState::WrpMidwState()
: mpContext(NULL)
{
}

WrpMidwState::WrpMidwState(const WrpMidwState& cp)
: mpContext(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwInitState
 ********************************************************************************************************/
WrpMidwInitState::WrpMidwInitState(WrpMidwApp* context)
: WrpMidwState(context)
{
}

WrpMidwInitState::~WrpMidwInitState()
{
}

void WrpMidwInitState::Handle()
{
#if 0
   WRPPRINT("%s\n", "WrpMidwInitState::Handle() Begin");
   mpContext->ReadConfig();
   mpContext->mpWsClientHandle = new WrpWebSocketClient;
   bool ret;
#if USE_ESP_IDF
   ret = mpContext->mpWsClientHandle->Create(WRPWS_SERVER_ADDRESS, WRPWS_SERVER_PORT);
#else
   ret = mpContext->mpWsClientHandle->Create("127.0.0.1", WRPWS_SERVER_PORT);
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
#endif
}

WrpMidwInitState::WrpMidwInitState()
{
}

WrpMidwInitState::WrpMidwInitState(const WrpMidwInitState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwDeInitState
 ********************************************************************************************************/
WrpMidwDeInitState::WrpMidwDeInitState(WrpMidwApp* context)
: WrpMidwState(context)
{
}

WrpMidwDeInitState::~WrpMidwDeInitState()
{
}

void WrpMidwDeInitState::Handle()
{
#if 0
   WRPPRINT("%s\n", "WrpMidwAppDeInitState::Handle() Begin");
   mpContext->mMidwAppStatus = MIDWAPP_STATUS_STOP;
   delete mpContext->mpWsClientHandle; //TODO: close before delete
   WRPPRINT("%s\n", "WrpMidwAppDeInitState::Handle() End");
#endif
}

WrpMidwDeInitState::WrpMidwDeInitState()
{
}

WrpMidwDeInitState::WrpMidwDeInitState(const WrpMidwDeInitState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwReadyState
 ********************************************************************************************************/
WrpMidwReadyState::WrpMidwReadyState(WrpMidwApp* context)
: WrpMidwState(context)
{
}

WrpMidwReadyState::~WrpMidwReadyState()
{
}

void WrpMidwReadyState::Handle()
{
   WRPPRINT("%s\n", "WrpMidwReadyState::Handle() Begin");
   WRPPRINT("%s\n", "WrpMidwReadyState::Handle() End");
}

WrpMidwReadyState::WrpMidwReadyState()
{
}

WrpMidwReadyState::WrpMidwReadyState(const WrpMidwReadyState& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpWifiConnectedState
 ********************************************************************************************************/
WrpWifiConnectedState::WrpWifiConnectedState(WrpMidwApp* context)
: WrpMidwState(context)
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
: WrpMidwState(context)
{
}

WrpWifiNotConnectedState::~WrpWifiNotConnectedState()
{
}

void WrpWifiNotConnectedState::Handle()
{
#if 0
   WRPPRINT("%s\n", "WrpWifiNOTConnectedState::Handle() Begin");
   sleep(1);
   WRPPRINT("%s\n", "WrpWifiNOTConnectedState::Handle() End");
   mpContext->SetState(new WrpMidwAppReadyState(mpContext));
#endif
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
: WrpMidwState(context)
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
: WrpMidwState(context)
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
