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
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"
#include "wrpbase/wrpgui/wrpstyle.hpp"
#include "wrpbase/wrpgui/wrpcoverflow.hpp"
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
	/*
	 * Constructor
	 */
	CFlowScreen(WrpHmiApp* app);
	/*
	 * Destructor
	 */
	~CFlowScreen();
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
	WrpGui::WrpImage* m_pMenuItem[4];
	WrpGui::WrpImage* m_pAnimItem[6];
};

#endif /* APPSAMPLE_HOMESCREEN_HPP_ */
