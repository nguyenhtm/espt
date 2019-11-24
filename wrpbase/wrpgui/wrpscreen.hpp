/********************************************************************************************************
 * @File  : wrpscreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPGUI_WRPSCREEN_HPP_
#define WRPBASE_WRPGUI_WRPSCREEN_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrppopup.hpp"
#include "wrpstyle.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
struct WrpScreenProperty
{
	bool            _bMaster;
	wrp_handler_t*  _pHandler;
	wrp_handler_t*  _pTitle;
	wrp_handler_t*  _pBackground;
	wrp_pos_t       _width;
	wrp_pos_t       _height;
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Class WrpScreen
class WrpScreen : public WrpStyle
{
public:
	WrpScreen(const bool bMaster=false);
	~WrpScreen();

	void Load();
	void SetTitle(const char* text);
	void SetStyle(const WrpStyleType style);
	WrpScreenProperty GetProperty() { return m_property; }
	void ShowPopup(bool bEnable, const char *text);

protected:

private:
	// methods

	// members
	wrp_handler_t*    m_pHandler;
	wrp_style_t       m_style;
	WrpScreenProperty m_property;
	WrpPopup*    m_popup;
};

} /* Namespace WrpGui */

#endif /* WRPBASE_WRPGUI_WRPSCREEN_HPP_ */
