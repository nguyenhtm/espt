/********************************************************************************************************
 * @File  : wrphmiapp.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPHMI_WRPHMIAPP_H_
#define WRPHMI_WRPHMIAPP_H_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpgui/wrpscreen.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
enum eWrpHmiAppStatus
{
	HMIAPP_STATUS_INIT=0, HMIAPP_STATUS_STARTED, HMIAPP_STATUS_STOPPED
};

enum eWrpHmiAppClientStatus
{
	HMIAPP_CLIENT_UNLOADED=0, HMIAPP_CLIENT_LOADED
};
struct tWrpHmiScreen
{
	WrpGui::WrpScreen* _scrHandler;
	uint16_t _scrId;
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
	void Start();
	void Stop();
	void AddScreen(WrpGui::WrpScreen* handler, const uint16_t id);
	void LoadScreen(const uint16_t id);
	void Attach(WrpHmiAppClient* client, const uint16_t id);
	void Detach(WrpHmiAppClient* client);

protected:

private:
	// methods
	WrpHmiApp();
	static void ThreadWrpHmiApp(void* param);

	// members
	static WrpHmiApp*           m_pInstance;
	eWrpHmiAppStatus            m_status;
	std::vector<tWrpHmiScreen*> m_listOfScreens;
	std::vector<WrpHmiAppClient*> m_listOfObservers;
};

#endif /* WRPHMI_WRPHMIAPP_H_ */
