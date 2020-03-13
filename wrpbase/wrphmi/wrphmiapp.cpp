/********************************************************************************************************
 * @File  : wrphmiapp.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrphmiapp.hpp"
#include "wrpbase/wrpgui/wrpdisplay.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpHmiApp* WrpHmiApp::mpInstance = NULL;

/********************************************************************************************************
 * FUNCTIONS - WrpHmiAppClient
 ********************************************************************************************************/
WrpHmiAppClient::WrpHmiAppClient()
: mpHmiAppClientHandle(NULL)
, mHmiAppClientStatus(HMIAPP_CLIENT_UNLOADED)
, mHmiAppClientId(0)
{
}

WrpHmiAppClient::~WrpHmiAppClient()
{
}
void WrpHmiAppClient::SetId(const uint16_t id)
{
   mHmiAppClientId = id; 
}

uint16_t WrpHmiAppClient::GetId()
{
   return mHmiAppClientId;
}

void WrpHmiAppClient::SetStatus(eWrpHmiAppClientStatus status)
{
   mHmiAppClientStatus = status;
}

eWrpHmiAppClientStatus WrpHmiAppClient::GetStatus()
{
   return mHmiAppClientStatus;
}

WrpGui::WrpScreen* WrpHmiAppClient::GetHandle()
{
   return mpHmiAppClientHandle;
}

WrpHmiAppClient::WrpHmiAppClient(const WrpHmiAppClient& cp)
: mpHmiAppClientHandle(NULL)
, mHmiAppClientStatus(HMIAPP_CLIENT_UNLOADED)
, mHmiAppClientId(0)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpHmiApp
 ********************************************************************************************************/
WrpHmiApp::~WrpHmiApp()
{
   WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() Begin");
   mHmiAppStatus = HMIAPP_STATUS_STOP;
   mListOfObservers.clear();
   WRPPRINT("%s\n", "WrpHmiApp::~WrpHmiApp() End");
}

WrpHmiApp* WrpHmiApp::GetInstance()
{
   WRPPRINT("%s\n", "WrpHmiApp::GetInstance() Begin");
   if (!mpInstance)
   {
      mpInstance = new WrpHmiApp();
   }
   WRPPRINT("%s\n", "WrpHmiApp::GetInstance() End");
   return mpInstance;
}

eWrpHmiAppStatus WrpHmiApp::GetHmiAppStatus()
{
   return mHmiAppStatus;
}

bool WrpHmiApp::Start()
{
   WRPPRINT("%s\n", "WrpHmiApp::Start() Begin");
   mHmiAppStatus = eWrpHmiAppStatus::HMIAPP_STATUS_START;
   mThreadId = WrpSys::System::WrpCreateThread(WrpHmiApp::ThreadWrpHmiApp, "WrpHmiApp", this);
   if (!mThreadId)
   {
      WRPPRINT("%s\n", "WrpHmiApp::Start() WrpCreateThread Failed!");
      mHmiAppStatus = HMIAPP_STATUS_STOP;
      return false;
   }
   WRPPRINT("%s\n", "WrpHmiApp::Start() End");
   return true;
}

void WrpHmiApp::Stop()
{
   mHmiAppStatus = HMIAPP_STATUS_STOP;
}

void WrpHmiApp::LoadScreen(const uint16_t id)
{
   WRPPRINT("%s\n", "WrpHmiApp::LoadScreen() Begin");
   std::vector<WrpHmiAppClient*>::iterator it;
   // destroy and hide the current HmiAppClient
   for (it = mListOfObservers.begin(); it != mListOfObservers.end(); ++it)
   {
      if (((*it)->GetStatus() == HMIAPP_CLIENT_LOADED) && ((*it)->GetId() != id))
      {
         break;
      }
   }
   if (it != mListOfObservers.end())
   {
      (*it)->HideAndDestroy();
      (*it)->SetStatus(HMIAPP_CLIENT_UNLOADED);
   }
   // then create and show the HmiAppClient with id
   for (it = mListOfObservers.begin(); it != mListOfObservers.end(); ++it)
   {
      if ((*it)->GetId() == id)
      {
         break;
      }
   }
   if (it != mListOfObservers.end())
   {
      (*it)->CreateAndShow();
      (*it)->GetHandle()->Load();
      (*it)->SetStatus(HMIAPP_CLIENT_LOADED);
   }
   WRPPRINT("%s\n", "WrpHmiApp::LoadScreen() End");
}

void WrpHmiApp::Attach(WrpHmiAppClient* client, const uint16_t id)
{
   WRPNULL_CHECK(client)
   WRPPRINT("%s\n", "WrpHmiApp::Attach() Begin");
   client->SetId(id);
   mListOfObservers.push_back(client);
   WRPPRINT("%s\n", "WrpHmiApp::Attach() End");
}

void WrpHmiApp::Detach(WrpHmiAppClient* client)
{
   WRPNULL_CHECK(client)
   WRPPRINT("%s\n", "WrpHmiApp::Detach() Begin");
   std::vector<WrpHmiAppClient*>::iterator it;
   it = std::find(mListOfObservers.begin(), mListOfObservers.end(), client);
   if (it != mListOfObservers.end())
   {
      mListOfObservers.erase(it);
   }
   WRPPRINT("%s\n", "WrpHmiApp::Detach() End");
}

WrpHmiApp::WrpHmiApp()
: mHmiAppStatus(HMIAPP_STATUS_STOP)
, mThreadId(0)
{
   WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() Begin");
   mListOfObservers.clear();
   WRPPRINT("%s\n", "WrpHmiApp::WrpHmiApp() End");
}

WrpHmiApp::WrpHmiApp(const WrpHmiApp& cp)
: mHmiAppStatus(HMIAPP_STATUS_STOP)
, mThreadId(0)
{
}

void WrpHmiApp::ThreadWrpHmiApp(void* param)
{
   WRPPRINT("%s\n", "WrpHmiApp::ThreadWrpHmiApp() Begin");
   WrpHmiApp* app = (WrpHmiApp*)param;
   while(app->mHmiAppStatus == HMIAPP_STATUS_START)
   {
      usleep(100*1000); // 100ms
   }
   WRPPRINT("%s\n", "WrpHmiApp::ThreadWrpHmiApp() End");
}
