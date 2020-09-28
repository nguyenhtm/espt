/********************************************************************************************************
 * @File  : wrpnetwork.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPNETWORK_HPP
#define WRPBASE_WRPSYS_WRPNETWORK_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpsys.hpp"
#include "mongoose.h"

namespace WrpSys {
namespace Network {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define NETWORK_STATUS_INIT          (0x00)
#define NETWORK_STATUS_NOTCONNECTED  (0x01)
#define NETWORK_STATUS_CONNECTING    (0x02)
#define NETWORK_STATUS_CONNECTED     (0x03)

enum eWrpWebSocketStatus
{
   WSCLIENT_STATUS_NOTCREATED = 0,
   WSCLIENT_STATUS_CREATED,
   WSCLIENT_STATUS_NOTCONNECTED,
   WSCLIENT_STATUS_CONNECTED
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
extern uint32_t gNetworkStatus;

void InitWifiStation();

void DeInitWifiStation();

// Class WrpWebSocketClient
class WrpWebSocketClient
{
public:
   WrpWebSocketClient();
   ~WrpWebSocketClient();
   bool     Create(const char *serveraddr, const uint16_t serverport);
   void     Close();
   uint32_t Receive(char* buf, int size);
   void     Send(const char* buf, const uint32_t size);
   void     ClearBuffer();

   static eWrpWebSocketStatus m_status;
   static char   mRecvBuffer[255];
   static size_t mRecvBufferLength;
   static char   mSentBuffer[255];
   static size_t mSentBufferLength;

private:
   WrpWebSocketClient(const WrpWebSocketClient& cp);
   //methods
   static void EventHandler(struct mg_connection *nc, int event, void *data);
   //members
   std::string           msURI;
   struct mg_mgr         mEventManager;
   struct mg_connection *mpConnection;
};

} /* Namespace Network */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPNETWORK_HPP */
