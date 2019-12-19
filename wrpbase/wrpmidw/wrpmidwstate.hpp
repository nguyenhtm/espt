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
class WrpMidw;

class WrpMidwState
{
public:
	WrpMidwState(){};
	~WrpMidwState(){};
	virtual void Handle() = 0;

protected:

private:

};

class WrpMidwInit : public WrpMidwState
{
public:
	WrpMidwInit(WrpMidw* context);
	virtual ~WrpMidwInit();
	void Handle();

protected:

private:
	WrpMidw* m_context;
};

class WrpWifiConnectedState : public WrpMidwState
{
public:
	WrpWifiConnectedState(WrpMidw* context);
	virtual ~WrpWifiConnectedState();
	void Handle();

protected:

private:
	WrpMidw* m_context;
};

class WrpWifiDisConnectedState : public WrpMidwState
{
public:
	WrpWifiDisConnectedState(WrpMidw* context);
	virtual ~WrpWifiDisConnectedState();
	void Handle();

protected:

private:
	WrpMidw* m_context;
};

#endif /* WRPMIDW_WRPMIDWSTATE_H_ */
