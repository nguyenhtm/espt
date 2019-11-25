/********************************************************************************************************
 * @File  : wrpstyle.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPGUI_WRPSTYLE_HPP_
#define WRPBASE_WRPGUI_WRPSTYLE_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

enum WrpStyleType
{
	SCREEN_DEFAULT, SCREEN_PLAIN_COLOR, SCREEN_PRETTY, SCREEN_PRETTY_COLOR,
	BUTTON_PRESS, BUTTON_RELEASE, BUTTON_TGL_PRESS, BUTTON_TGL_RELEASE
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpStyle
{
public:
	WrpStyle();
	~WrpStyle();
	void SetStyle(wrpgui_handle_t* handler, WrpStyleType style);
	void SetDefault(wrpgui_handle_t* handler);

protected:

private:
	// methods

	// members
	wrpgui_style_t m_style;
	wrpgui_style_t m_default;
};

} /* Namespace WrpGui */

#endif /* WRPBASE_WRPGUI_WRPSTYLE_HPP_ */
