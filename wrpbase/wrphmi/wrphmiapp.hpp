/********************************************************************************************************
 * @File  : wrphmiapp.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@yahoo.com
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

struct tWrpHmiScreen
{
	WrpGui::WrpScreen* _scrHandler;
	uint16_t _scrId;
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
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

protected:

private:
	WrpHmiApp();
#if LVGL_PC_SIMU
	static int ThreadWrpHmiApp(void* param);
#elif LVGL_ESP32_ILI9341
	static void ThreadWrpHmiApp(void* param);
#endif
	static WrpHmiApp*           m_pInstance;
	eWrpHmiAppStatus            m_status;
	std::vector<tWrpHmiScreen*> m_listOfScreens;
};

#endif /* WRPHMI_WRPHMIAPP_H_ */
