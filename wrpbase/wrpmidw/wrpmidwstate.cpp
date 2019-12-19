/********************************************************************************************************
 * @File  : wrpwifistate.cpp
 * @Date  : 2019-12-19
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwstate.hpp"
#include "wrpmidwbuilder.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpMidwInit::WrpMidwInit(WrpMidw* context)
: m_context(context)
{

}

WrpMidwInit::~WrpMidwInit()
{

}

void WrpMidwInit::Handle()
{

}

WrpWifiConnectedState::WrpWifiConnectedState(WrpMidw* context)
: m_context(context)
{

}

WrpWifiConnectedState::~WrpWifiConnectedState()
{

}

void WrpWifiConnectedState::Handle()
{
	//m_context->m_pWsClient->Create()
}

WrpWifiDisConnectedState::WrpWifiDisConnectedState(WrpMidw* context)
: m_context(context)
{

}

WrpWifiDisConnectedState::~WrpWifiDisConnectedState()
{

}

void WrpWifiDisConnectedState::Handle()
{
	//m_context->m_pWsClient->Close();
}
