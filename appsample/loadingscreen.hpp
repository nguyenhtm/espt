/********************************************************************************************************
 * @File  : loadingscreen.hpp
 * @Date  : 2019-12-09
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_LOADINGSCREEN_HPP_
#define APPSAMPLE_LOADINGSCREEN_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class LoadingScreen : public WrpHmiAppClient
                    , public WrpMidwAppClient
{
public:
	/*
	 * Constructor
	 */
	LoadingScreen(WrpHmiApp* app);
	/*
	 * Destructor
	 */
	~LoadingScreen();
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
	void MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length);

protected:

private:
	WrpHmiApp* m_pHmiApp;
	WrpGui::WrpLabel* m_pLblLoadingStatus;
};

#endif /* APPSAMPLE_LOADINGSCREEN_HPP_ */
