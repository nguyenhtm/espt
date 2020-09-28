/********************************************************************************************************
 * @File  : wrpmidwappfsm.hpp
 * @Date  : 2019-12-19
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWAPPFSM_HPP
#define WRPMIDW_WRPMIDWAPPFSM_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward class
class WrpMidwApp;

class WrpMidwAppState
{
public:
   WrpMidwAppState(WrpMidwApp* context);
   virtual ~WrpMidwAppState();
   virtual void Handle() = 0;
   WrpMidwAppState();
   WrpMidwAppState(const WrpMidwAppState& cp);
protected:
   // members
   WrpMidwApp* mpContext;

private:

};

class WrpMidwAppInitState : public WrpMidwAppState
{
public:
   WrpMidwAppInitState(WrpMidwApp* context);
   ~WrpMidwAppInitState();
   void Handle();

private:
   WrpMidwAppInitState();
   WrpMidwAppInitState(const WrpMidwAppInitState& cp);
};

class WrpMidwAppDeInitState : public WrpMidwAppState
{
public:
   WrpMidwAppDeInitState(WrpMidwApp* context);
   ~WrpMidwAppDeInitState();
   void Handle();

private:
   WrpMidwAppDeInitState();
   WrpMidwAppDeInitState(const WrpMidwAppDeInitState& cp);
};

class WrpMidwAppReadyState : public WrpMidwAppState
{
public:
   WrpMidwAppReadyState(WrpMidwApp* context);
   ~WrpMidwAppReadyState();
   void Handle();

private:
   WrpMidwAppReadyState();
   WrpMidwAppReadyState(const WrpMidwAppReadyState& cp);
};

class WrpWifiConnectedState : public WrpMidwAppState
{
public:
   WrpWifiConnectedState(WrpMidwApp* context);
   ~WrpWifiConnectedState();
   void Handle();

private:
   WrpWifiConnectedState();
   WrpWifiConnectedState(const WrpWifiConnectedState& cp);
};

class WrpWifiNotConnectedState : public WrpMidwAppState
{
public:
   WrpWifiNotConnectedState(WrpMidwApp* context);
   ~WrpWifiNotConnectedState();
   void Handle();

private:
   WrpWifiNotConnectedState();
   WrpWifiNotConnectedState(const WrpWifiNotConnectedState& cp);
};

class WrpWsClientConnectedState : public WrpMidwAppState
{
public:
   WrpWsClientConnectedState(WrpMidwApp* context);
   ~WrpWsClientConnectedState();
   void Handle();

private:
   WrpWsClientConnectedState();
   WrpWsClientConnectedState(const WrpWsClientConnectedState& cp);
};

class WrpWsClientNotConnectedState : public WrpMidwAppState
{
public:
   WrpWsClientNotConnectedState(WrpMidwApp* context);
   ~WrpWsClientNotConnectedState();
   void Handle();

private:
   WrpWsClientNotConnectedState();
   WrpWsClientNotConnectedState(const WrpWsClientNotConnectedState& cp);
};

#endif /* WRPMIDW_WRPMIDWAPPFSM_HPP */
