/********************************************************************************************************
 * @File  : wrphmiapp.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPHMI_WRPHMIAPP_HPP
#define WRPHMI_WRPHMIAPP_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"
#include "wrpbase/wrpgui/wrpscreen.hpp"

using namespace WrpSys::System;

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
enum eWrpHmiAppStatus
{
	HMIAPP_STATUS_STOP=0, HMIAPP_STATUS_START
};

enum eWrpHmiAppClientStatus
{
	HMIAPP_CLIENT_UNLOADED=0, HMIAPP_CLIENT_LOADED
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class WrpHmiAppClient
{
public:
	WrpHmiAppClient();
	virtual ~WrpHmiAppClient();
	virtual void CreateAndShow() = 0;
	virtual void HideAndDestroy() = 0;
	void SetClientId(const uint16_t id) { m_ScreenId = id; }
	uint16_t GetClientId() { return m_ScreenId; }
	void SetScreenStatus(eWrpHmiAppClientStatus status) { m_status = status; }
	eWrpHmiAppClientStatus GetScreenStatus() { return m_status; }
	WrpGui::WrpScreen* GetScreenHandle() { return m_pScreenHandle; }

protected:
	WrpGui::WrpScreen*     m_pScreenHandle;

private:
	uint16_t               m_ScreenId;
	eWrpHmiAppClientStatus m_status;
};

class WrpHmiApp
{
public:
	~WrpHmiApp();
	static WrpHmiApp* GetInstance();
	eWrpHmiAppStatus GetStatus();
	bool Start();
	void Stop();
	void LoadScreen(const uint16_t id);
	void Attach(WrpHmiAppClient* client, const uint16_t id);
	void Detach(WrpHmiAppClient* client);

protected:

private:
	// methods
	WrpHmiApp();
	static void ThreadWrpHmiApp(void* param);

	// members
	static WrpHmiApp* m_pInstance;
	eWrpHmiAppStatus  m_status;
	wrpthread_t       m_threadid;
	std::vector<WrpHmiAppClient*> m_listOfObservers;
};

#endif /* WRPHMI_WRPHMIAPP_HPP */
