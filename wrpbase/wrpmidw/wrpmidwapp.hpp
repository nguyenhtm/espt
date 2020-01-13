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
#include "wrpmidwbuilder.hpp"
#include "wrpmidwstate.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

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
class WrpMidwAppClient
{
public:
	WrpMidwAppClient(){};
	virtual ~WrpMidwAppClient(){};
	virtual void Update(eWrpMidwAppStatus status, char* buffer, unsigned int length) = 0;
};

class WrpMidwApp
{
public:
	WrpMidwApp();
	~WrpMidwApp();
	void Attach(WrpMidwAppClient* client);
	void Detach(WrpMidwAppClient* client);

	void SetState(WrpMidwState* state);
	void ReadConfig();
	WrpWebSocketClient* GetWSClient() { return m_pWsClient; }
	eWrpMidwAppStatus GetStatus() { return m_status; }

protected:

private:
	// methods
	void Notify(char* buffer, unsigned int length);
	static void ThreadWrpMidwApp(void* param);

	// members
	WrpWebSocketClient* m_pWsClient;
	eWrpMidwAppStatus   m_status;
	wrpthread_t         m_threadid;

	friend class WrpMidwInitState;
	friend class WrpMidwDeInitState;
	friend class WrpMidwWsNotConnectedState;
	WrpMidwState* m_pCurrentState;
	std::vector<WrpMidwAppClient*> m_listOfObservers;
};

#endif /* WRPMIDW_WRPMIDWAPP_H_ */
