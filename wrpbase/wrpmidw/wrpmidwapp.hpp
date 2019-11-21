/********************************************************************************************************
 * @File  : wrpmidwapp.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@yahoo.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWAPP_H_
#define WRPMIDW_WRPMIDWAPP_H_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
enum eWrpMidwAppStatus
{
	MIDWAPP_STATUS_INIT = 0,
	MIDWAPP_STATUS_STARTED,
	MIDWAPP_STATUS_STOPPED,
	MIDWAPP_STATUS_SHUTDOWN,
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
	~WrpMidwApp();
	static WrpMidwApp* GetInstance();
	eWrpMidwAppStatus GetStatus();
	void Attach(WrpMidwAppClient* client);
	void Detach(WrpMidwAppClient* client);
	void Start();
	void Stop();

protected:

private:
	WrpMidwApp();
	static std::vector<WrpMidwAppClient*> m_listOfObservers;
	static eWrpMidwAppStatus m_status;
	WrpSys::WrpSysNetwork::WrpWebSocketClient* m_wsClient;
#if LVGL_PC_SIMU
	static int ThreadWrpMidwApp(void* param);
#elif LVGL_ESP32_ILI9341
	static void ThreadWrpMidwApp(void* param);
#endif
	static void Notify(char* buffer, unsigned int length);

	static WrpMidwApp* m_pInstance;
};

#endif /* WRPMIDW_WRPMIDWAPP_H_ */
