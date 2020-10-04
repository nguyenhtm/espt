/********************************************************************************************************
 * @File  : wrpmidwfsm.hpp
 * @Date  : 2019-12-19
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWFSM_HPP
#define WRPMIDW_WRPMIDWFSM_HPP

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

class WrpMidwState
{
public:
   WrpMidwState(WrpMidwApp* context);
   virtual ~WrpMidwState();
   virtual void Handle() = 0;
   WrpMidwState();

protected:
   // members
   WrpMidwApp* mpContext;

private:
   WrpMidwState(const WrpMidwState& cp);
};

class WrpMidwInitState : public WrpMidwState
{
public:
   WrpMidwInitState(WrpMidwApp* context);
   ~WrpMidwInitState();
   void Handle();

private:
   WrpMidwInitState();
   WrpMidwInitState(const WrpMidwInitState& cp);
};

class WrpMidwDeInitState : public WrpMidwState
{
public:
	WrpMidwDeInitState(WrpMidwApp* context);
   ~WrpMidwDeInitState();
   void Handle();

private:
   WrpMidwDeInitState();
   WrpMidwDeInitState(const WrpMidwDeInitState& cp);
};

class WrpMidwReadyState : public WrpMidwState
{
public:
	WrpMidwReadyState(WrpMidwApp* context);
   ~WrpMidwReadyState();
   void Handle();

private:
   WrpMidwReadyState();
   WrpMidwReadyState(const WrpMidwReadyState& cp);
};

class WrpWifiConnectedState : public WrpMidwState
{
public:
	WrpWifiConnectedState(WrpMidwApp* context);
   ~WrpWifiConnectedState();
   void Handle();

private:
   WrpWifiConnectedState();
   WrpWifiConnectedState(const WrpWifiConnectedState& cp);
};

class WrpWifiNotConnectedState : public WrpMidwState
{
public:
	WrpWifiNotConnectedState(WrpMidwApp* context);
   ~WrpWifiNotConnectedState();
   void Handle();

private:
   WrpWifiNotConnectedState();
   WrpWifiNotConnectedState(const WrpWifiNotConnectedState& cp);
};

class WrpWsClientConnectedState : public WrpMidwState
{
public:
	WrpWsClientConnectedState(WrpMidwApp* context);
   ~WrpWsClientConnectedState();
   void Handle();

private:
   WrpWsClientConnectedState();
   WrpWsClientConnectedState(const WrpWsClientConnectedState& cp);
};

class WrpWsClientNotConnectedState : public WrpMidwState
{
public:
   WrpWsClientNotConnectedState(WrpMidwApp* context);
   ~WrpWsClientNotConnectedState();
   void Handle();

private:
   WrpWsClientNotConnectedState();
   WrpWsClientNotConnectedState(const WrpWsClientNotConnectedState& cp);
};

#endif /* WRPMIDW_WRPMIDWFSM_HPP */
