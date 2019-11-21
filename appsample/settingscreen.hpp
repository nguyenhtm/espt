/********************************************************************************************************
 * @File  : settingscreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@yahoo.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_SETTINGSCREEN_HPP_
#define APPSAMPLE_SETTINGSCREEN_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// forward classes
//class WrpGui::WrpScreen;
//class WrpGui::WrpLabel;

class SettingScreen : public WrpMidwAppClient
{
public:
	SettingScreen(WrpHmiApp* app);
	~SettingScreen();
	// data binding
	WrpGui::WrpScreen* m_pScrHandler;
	void Update(eWrpMidwAppStatus, char* buffer, unsigned int length);

protected:

private:
	WrpHmiApp* m_pHmiApp;
	WrpGui::WrpLabel*  m_pLblBackItem;
	void EnableAnimation();
};

#endif /* APPSAMPLE_SETTINGSCREEN_HPP_ */
