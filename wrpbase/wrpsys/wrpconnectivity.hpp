/********************************************************************************************************
 * @File  : wrpconnectivity.hpp
 * @Date  : 2020-08-05
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPCONNECTIVITY_HPP
#define WRPBASE_WRPSYS_WRPCONNECTIVITY_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpsys.hpp"
#include "mongoose.h"

namespace WrpSys {
namespace WrpConnectivity {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpConnection
class WrpConnection
{
public:
   WrpConnection(){};
   virtual ~WrpConnection(){};
   virtual void Connect(){};
   virtual void Add(WrpConnection* pItem){};
   virtual void Remove(){};
};

// Class WrpWifiStation
class WrpWifiStation : public WrpConnection
{
public:
   WrpWifiStation();
   virtual ~WrpWifiStation();
   void Connect();
};

// Class WrpWsClient
class WrpWsClient : public WrpConnection
{
public:
   WrpWsClient();
   virtual ~WrpWsClient();
   void Connect();
   void Add(WrpConnection* pItem);

private:
   WrpWsClient(const WrpWsClient& cp);
};

// Class WrpWsServer
class WrpWsServer : public WrpConnection
{
public:
   WrpWsServer();
   virtual ~WrpWsServer();
   void Add(WrpConnection* pItem);

private:
   WrpWsServer(const WrpWsServer& cp);
};

// Class WrpConnectivity
class WrpConnectivity
{
public:
   WrpConnectivity();
   ~WrpConnectivity();
   void Initialize();
   void DeInitialize();
   WrpWsClient* GetWsClient();

private:
   WrpWsClient* mpWsClient;
   WrpWsServer* mpWsServer;
};


} /* Namespace WrpConnectivity */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPCONNECTIVITY_HPP */
