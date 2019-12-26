/********************************************************************************************************
 * @File  : settingscreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
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
#include "wrpbase/wrpgui/wrpcoverflow.hpp"

#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class SettingScreen : public WrpHmiAppClient
                    , public WrpMidwAppClient
{
public:
	SettingScreen(WrpHmiApp* app);
	~SettingScreen();
	/*
	 * Call back function called on a screen creation
	 */
	void CreateAndShow();
	/*
	 * Call back function called on a screen destroy
	 */
	void HideAndDestroy();
	// data binding

	WrpGui::WrpWidget* m_pMenuItem[5];
	void Update(eWrpMidwAppStatus, char* buffer, unsigned int length);

protected:

private:
	WrpHmiApp* m_pHmiApp;
	WrpGui::WrpLabel*  m_pLblBackItem;
	WrpGui::WrpCoverFlow m_anim;
};

#endif /* APPSAMPLE_SETTINGSCREEN_HPP_ */
