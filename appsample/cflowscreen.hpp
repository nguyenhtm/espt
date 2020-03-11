/********************************************************************************************************
 * @File  : cflowscreen.hpp
 * @Date  : 2020-02-08
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_CFLOWSCREEN_HPP_
#define APPSAMPLE_CFLOWSCREEN_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"
#include "wrpbase/wrpgui/wrpanim.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class CFlowScreen : public WrpHmiAppClient
                  , public WrpMidwAppClient
{
public:
	/**
	 * Constructor for the class
	 */
	CFlowScreen(WrpHmiApp* app);
	/**
	 * Destructor for the class
	 */
	~CFlowScreen();
	/*
	 * Description: call back function called on a screen creation
	 * @param[in] : none
	 * @param[out]: none
	 */
	void CreateAndShow();
	/*
	 * DESCRIPTION: call back function called on a screen destroy
	 * @param[in] : none
	 * @param[out]: none
	 */
	void HideAndDestroy();
	/*
	 * Call back function called on midw events update
	 */
	void MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length);

protected:

private:
	/** Holds the handle of */
	WrpHmiApp* m_pHmiApp;
	WrpGui::WrpAnim m_anim;
	WrpGui::WrpImage* m_pMenuItem[4];
	WrpGui::WrpImage* m_pAnimItem[6];
};

#endif /* APPSAMPLE_HOMESCREEN_HPP_ */
