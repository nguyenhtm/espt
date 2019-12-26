/********************************************************************************************************
 * @File  : wrpscreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPSCREEN_HPP_
#define WRPGUI_WRPSCREEN_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpstyle.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpLabel;
class WrpWidget;
class WrpPopup;

// Class WrpScreen
class WrpScreen : public WrpStyle
{
public:
	WrpScreen(const bool bMasterScreen=false);
	~WrpScreen();

	void Load();
	void SetTitle(const char* text);
	void SetStyle(const WrpStyleType style);
	void ShowPopup(const bool bShowHide, const char *text);

protected:

private:
	// methods
	wrpgui_handle_t* m_pHandler;
	friend class WrpWidget;
	friend class WrpLabel;

	// members
	bool      m_bMasterScreen;
	WrpLabel* m_pMenuTitle;
	WrpPopup* m_pTopPopup;
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPSCREEN_HPP_ */
