/********************************************************************************************************
 * @File  : homescreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@yahoo.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_HOMESCREEN_HPP_
#define APPSAMPLE_HOMESCREEN_HPP_

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

class HomeScreen : public WrpMidwAppClient
{
public:
	HomeScreen(WrpHmiApp* app);
	~HomeScreen();
	// data binding
	WrpGui::WrpScreen* m_pScrHandler;
	WrpGui::WrpLabel*  m_pLblProgramStatus;
	WrpGui::WrpLabel*  m_pLblSettingItem;
	void Update(eWrpMidwAppStatus status, char* buffer, unsigned int length);

protected:

private:
	WrpHmiApp* m_pHmiApp;

	static int ThreadHomeScreen(void* param);
};

#endif /* APPSAMPLE_HOMESCREEN_HPP_ */
