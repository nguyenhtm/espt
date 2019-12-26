/********************************************************************************************************
 * @File  : homescreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
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

class HomeScreen : public WrpHmiAppClient
                 , public WrpMidwAppClient
{
public:
	HomeScreen(WrpHmiApp* app);
	~HomeScreen();

	/*
	 * Call back function called on a screen creation
	 */
	void CreateAndShow();
	/*
	 * Call back function called on a screen destroy
	 */
	void HideAndDestroy();
	/*
	 * Call back function called on midw events update
	 */
	void Update(eWrpMidwAppStatus status, char* buffer, unsigned int length);
	// data binding
	WrpGui::WrpLabel*  m_pLblProgramStatus;
	WrpGui::WrpLabel*  m_pLblSettingItem;


protected:

private:
	WrpHmiApp* m_pHmiApp;

	static int ThreadHomeScreen(void* param);
};

#endif /* APPSAMPLE_HOMESCREEN_HPP_ */
