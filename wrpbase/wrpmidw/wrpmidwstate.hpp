/********************************************************************************************************
 * @File  : wrpmidwstate.hpp
 * @Date  : 2019-12-19
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWSTATE_H_
#define WRPMIDW_WRPMIDWSTATE_H_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

using namespace ::WrpSys::Network;
using namespace ::WrpSys::System;

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward class
class WrpMidwApp;

// Class WrpMidwState
class WrpMidwState
{
public:
	WrpMidwState(WrpMidwApp* context) : m_context(context){}
	virtual ~WrpMidwState(){};
	virtual void Handle() = 0;

protected:
	WrpMidwApp* m_context;

private:

};

class WrpMidwInitState : public WrpMidwState
{
public:
	WrpMidwInitState(WrpMidwApp* context) : WrpMidwState(context){};
	~WrpMidwInitState(){};
	void Handle();

protected:

private:

};

class WrpMidwDeInitState : public WrpMidwState
{
public:
	WrpMidwDeInitState(WrpMidwApp* context) : WrpMidwState(context){};
	~WrpMidwDeInitState(){};
	void Handle();

protected:

private:

};

class WrpMidwReadyState : public WrpMidwState
{
public:
	WrpMidwReadyState(WrpMidwApp* context) : WrpMidwState(context){};
	~WrpMidwReadyState(){};
	void Handle();

protected:

private:

};

class WrpWifiConnectedState : public WrpMidwState
{
public:
	WrpWifiConnectedState(WrpMidwApp* context) : WrpMidwState(context){};
	~WrpWifiConnectedState(){};
	void Handle();

protected:

private:

};

class WrpWifiNotConnectedState : public WrpMidwState
{
public:
	WrpWifiNotConnectedState(WrpMidwApp* context) : WrpMidwState(context){};
	~WrpWifiNotConnectedState(){};
	void Handle();

protected:

private:

};

class WrpMidwWsConnectedState : public WrpMidwState
{
public:
	WrpMidwWsConnectedState(WrpMidwApp* context) : WrpMidwState(context){};
	~WrpMidwWsConnectedState(){};
	void Handle();

protected:

private:

};

class WrpMidwWsNotConnectedState : public WrpMidwState
{
public:
	WrpMidwWsNotConnectedState(WrpMidwApp* context) : WrpMidwState(context){};
	~WrpMidwWsNotConnectedState(){};
	void Handle();

protected:

private:

};

#endif /* WRPMIDW_WRPMIDWSTATE_H_ */
