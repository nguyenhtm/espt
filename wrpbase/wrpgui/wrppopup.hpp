/********************************************************************************************************
 * @File  : wrppopup.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPPOPUP_HPP_
#define WRPGUI_WRPPOPUP_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpScreen;
class WrpLabel;

// Class WrpPopup
class WrpPopup : public WrpGui
{
public:
	WrpPopup(WrpScreen* parent);
	~WrpPopup();

	void Show();
	void Hide();
	void SetText(const char* text);

protected:

private:
	wrpgui_handle_t *m_pPopupText;
	void EnableAnimation();
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPPOPUP_HPP_ */
