/********************************************************************************************************
 * @File  : wrpmidwapp.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWAPP_H_
#define WRPMIDW_WRPMIDWAPP_H_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"
#include "wrpmidwappbuilder.hpp"
#include "wrpmidwappfsm.hpp"

using namespace ::WrpSys::Network;
using namespace ::WrpSys::System;

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
enum eWrpMidwAppStatus
{
   MIDWAPP_STATUS_STOP = 0,
   MIDWAPP_STATUS_START,
   MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED,
   MIDWAPP_WSCLIENT_STATUS_DATA_CLEAR
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class WrpServiceManager
{
public:
   WrpServiceManager();
   ~WrpServiceManager();
   void        BuildWrpMidwApp();
   WrpMidwApp* GetWrpMidwAppInstance();

private:
   WrpServiceManager(const WrpServiceManager& cp);
   // members
   WrpMidwAppBuilder* mpBuilder;
};

class WrpMidwAppClient
{
public:
   WrpMidwAppClient();
   virtual ~WrpMidwAppClient();
   virtual void MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length) = 0;

private:
   WrpMidwAppClient(const WrpMidwAppClient& cp);
};

class WrpMidwApp
{
public:
   WrpMidwApp();
   ~WrpMidwApp();
   void                Attach(WrpMidwAppClient* client);
   void                Detach(WrpMidwAppClient* client);
   void                SetState(WrpMidwAppState* state);
   void                ReadConfig();
   eWrpMidwAppStatus   GetMidwAppStatus() const;
   WrpWebSocketClient* GetWSClientHandle() const;

private:
   WrpMidwApp(const WrpMidwApp& cp);
   void                Notify(char* buffer, unsigned int length);
   static void         ThreadWrpMidwApp(void* param);
   // members
   eWrpMidwAppStatus   mMidwAppStatus;
   WrpWebSocketClient* mpWsClientHandle;
   WrpMidwAppState*    mpCurrentState;
   wrpthread_t         mThreadid;

   friend class WrpMidwAppInitState;
   friend class WrpMidwAppDeInitState;
   friend class WrpWsClientNotConnectedState;

   std::vector<WrpMidwAppClient*> m_listOfObservers;
};
#endif /* WRPMIDW_WRPMIDWAPP_H_ */
