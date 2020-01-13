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
#include "wrpbase/wrpgui/wrpimage.hpp"
#include "wrpbase/wrpgui/wrpcoverflow.hpp"
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
	/*
	 * Constructor
	 */
	HomeScreen(WrpHmiApp* app);
	/*
	 * Destructor
	 */
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

protected:

private:
	WrpHmiApp* m_pHmiApp;
	WrpGui::WrpCoverFlow m_anim;
	WrpGui::WrpImage* m_pMenuImage[5];
	static int ThreadHomeScreen(void* param);
};

#endif /* APPSAMPLE_HOMESCREEN_HPP_ */
