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
 * FUNCTIONS - WrpServiceManager
 ********************************************************************************************************/
WrpServiceManager::WrpServiceManager()
: mpBuilder(NULL)
{
   WRPPRINT("%s\n", "WrpServiceManager::WrpServiceManager() Begin");
#if USE_ESP_IDF
   mpBuilder = new WrpMidwAppESP32;
#else
   mpBuilder = new WrpMidwAppSIM;
#endif
   WRPPRINT("%s\n", "WrpServiceManager::WrpServiceManager() End");
}

WrpServiceManager::~WrpServiceManager()
{
   WRPPRINT("%s\n", "WrpServiceManager::~WrpServiceManager() Begin");
   delete mpBuilder;
   WRPPRINT("%s\n", "WrpServiceManager::~WrpServiceManager() End");
}

void WrpServiceManager::BuildWrpMidwApp()
{
   WRPPRINT("%s\n", "WrpServiceManager::BuildWrpMidwApp() Begin");
   // must 1st initialization
   mpBuilder->BuildStorage();
   // and driver, display, network, system...
   mpBuilder->BuildDisplay();
   mpBuilder->BuildNetwork();
   mpBuilder->BuildSystem();
   // completely build a WrpMidw app then start it up
   WrpMidwApp* midwApp = mpBuilder->GetWrpMidwApp();
   midwApp->SetState(new WrpMidwAppInitState(midwApp));
   WRPPRINT("%s\n", "WrpServiceManager::BuildWrpMidwApp() End");
}

WrpMidwApp* WrpServiceManager::GetWrpMidwAppInstance()
{
   return mpBuilder->GetWrpMidwApp();
}

WrpServiceManager::WrpServiceManager(const WrpServiceManager& cp)
: mpBuilder(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwAppClient
 ********************************************************************************************************/
WrpMidwAppClient::WrpMidwAppClient()
{
}

WrpMidwAppClient::~WrpMidwAppClient()
{
}

WrpMidwAppClient::WrpMidwAppClient(const WrpMidwAppClient& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpMidwApp
 ********************************************************************************************************/
WrpMidwApp::WrpMidwApp()
: mMidwAppStatus(MIDWAPP_STATUS_STOP)
, mpWsClientHandle(NULL)
, mpCurrentState(NULL)
, mThreadid(0)
{
   WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() Begin");
   m_listOfObservers.clear();
   WRPPRINT("%s\n", "WrpMidwApp::WrpMidwApp() End");
}

WrpMidwApp::~WrpMidwApp()
{
   WRPPRINT("%s\n", "WrpMidwApp::~WrpMidwApp() Begin");
   mMidwAppStatus = MIDWAPP_STATUS_STOP;
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

void WrpMidwApp::SetState(WrpMidwAppState* state)
{
   WRPPRINT("%s\n", "WrpMidwApp::SetState() Begin");
   if(mpCurrentState)
   {
      delete mpCurrentState;
   }
   mpCurrentState = state;
   mpCurrentState->Handle();
   WRPPRINT("%s\n", "WrpMidwApp::SetState() End");
}

void WrpMidwApp::ReadConfig()
{
   WRPPRINT("%s\n", "WrpMidwApp::ReadConfig() Begin");
   if (WrpSys::Storage::m_uStorageStatus && STORAGE_STATUS_INITSPIFFS)
   {
   }
   WRPPRINT("%s\n", "WrpMidwApp::ReadConfig() End");
}

eWrpMidwAppStatus WrpMidwApp::GetMidwAppStatus() const
{
   return mMidwAppStatus;
}

WrpWebSocketClient* WrpMidwApp::GetWSClientHandle() const
{
   return mpWsClientHandle;
}

WrpMidwApp::WrpMidwApp(const WrpMidwApp& cp)
: mMidwAppStatus(MIDWAPP_STATUS_STOP)
, mpWsClientHandle(NULL)
, mpCurrentState(NULL)
, mThreadid(0)
{
}

void WrpMidwApp::Notify(char* buffer, unsigned int length)
{
   WRPPRINT("%s\n", "WrpMidwApp::Notify() Begin");
   size_t numOfElements = m_listOfObservers.size();
   for (size_t i = 0; i < numOfElements; i++)
   {
      m_listOfObservers[i]->MidwAppUpdate(mMidwAppStatus, buffer, length);
   }
   WRPPRINT("%s\n", "WrpMidwApp::Notify() End");
}

void WrpMidwApp::ThreadWrpMidwApp(void* param)
{
   WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() Begin");
   char buf[255]={0};
   uint32_t len=0;

   eWrpWebSocketStatus wsPreStatus = WSCLIENT_STATUS_NOTCREATED;
   WrpMidwApp*         midwApp = (WrpMidwApp*)param;
   midwApp->SetState(new WrpMidwAppReadyState(midwApp));

   usleep(100*1000); //TODO: race condition prevent
   while(midwApp->mMidwAppStatus != MIDWAPP_STATUS_STOP)
   {
      // MidwApp WebSocket client polling incoming data of web socket client in 100ms
      len = midwApp->mpWsClientHandle->Receive(buf, sizeof(buf));
      if (len > 0 )
      {
         WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED");
         midwApp->mMidwAppStatus = MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED;
         midwApp->Notify(buf, len);
         usleep(100*1000);
         midwApp->mMidwAppStatus = MIDWAPP_WSCLIENT_STATUS_DATA_CLEAR;
         midwApp->mpWsClientHandle->ClearBuffer();
      }

      // MidwApp State Context handling state based on ws server, wifi,...status
      // for wifi connection
      if (WrpSys::Network::m_uNetworkStatus != NETWORK_STATUS_CONNECTED)
      {
         //TODO: display no wifi icon
      }
      // for websocket server connection
      if (wsPreStatus == midwApp->GetWSClientHandle()->m_status)
      {
         continue;
      }
      wsPreStatus = midwApp->GetWSClientHandle()->m_status;
      switch(midwApp->GetWSClientHandle()->m_status)
      {
         case WSCLIENT_STATUS_NOTCONNECTED:
            {
               midwApp->SetState(new WrpWsClientNotConnectedState(midwApp));
            }
            break;
         case WSCLIENT_STATUS_CONNECTED:
            {
              midwApp->SetState(new WrpMidwAppReadyState(midwApp));
            }
            break;
         default:
            {
            // fall through
            }
            break;
      }
   }
   WRPPRINT("%s\n", "WrpMidwApp::ThreadWrpMidwApp() End");
}
