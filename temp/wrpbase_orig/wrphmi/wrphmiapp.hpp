/********************************************************************************************************
 * @File  : wrphmiapp.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPHMI_WRPHMIAPP_HPP
#define WRPHMI_WRPHMIAPP_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"
#include "wrpbase/wrpgui/wrpscreen.hpp"

using namespace WrpSys::System;

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
enum eWrpHmiAppStatus
{
   HMIAPP_STATUS_STOP = 0, HMIAPP_STATUS_START
};

enum eWrpHmiAppClientStatus
{
   HMIAPP_CLIENT_UNLOADED = 0, HMIAPP_CLIENT_LOADED
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class WrpHmiAppClient
{
public:
   WrpHmiAppClient();
   virtual ~WrpHmiAppClient();
   virtual void           CreateAndShow() = 0;
   virtual void           HideAndDestroy() = 0;
   void                   SetId(const uint16_t id);
   uint16_t               GetId();
   void                   SetStatus(eWrpHmiAppClientStatus status);
   eWrpHmiAppClientStatus GetStatus();
   WrpGui::WrpScreen*     GetHandle();

protected:
   WrpGui::WrpScreen*     mpHmiAppClientHandle;

private:
   WrpHmiAppClient(const WrpHmiAppClient& cp);
   // members
   eWrpHmiAppClientStatus mHmiAppClientStatus;
   uint16_t               mHmiAppClientId;
};

class WrpHmiApp
{
public:
   ~WrpHmiApp();
   static WrpHmiApp* GetInstance();
   eWrpHmiAppStatus  GetHmiAppStatus();
   bool              Start();
   void              Stop();
   void              LoadScreen(const uint16_t id);
   void              Attach(WrpHmiAppClient* client, const uint16_t id);
   void              Detach(WrpHmiAppClient* client);

private:
   WrpHmiApp();
   WrpHmiApp(const WrpHmiApp& cp);
   static void       ThreadWrpHmiApp(void* param);

   // members
   static WrpHmiApp*             mpInstance;
   eWrpHmiAppStatus              mHmiAppStatus;
   wrpthread_t                   mThreadId;
   std::vector<WrpHmiAppClient*> mListOfObservers;
};

#endif /* WRPHMI_WRPHMIAPP_HPP */
