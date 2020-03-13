/********************************************************************************************************
 * @File  : wrpwidget.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPWIDGET_HPP
#define WRPGUI_WRPWIDGET_HPP

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
class WrpScreen;

// Class WrpWidget
class WrpWidget
{
public:
	WrpWidget(WrpScreen* parent=NULL);
	~WrpWidget();
	wrpgui_pos_t  GetX();
	wrpgui_pos_t  GetY();
	wrpgui_size_t GetW();
	wrpgui_size_t GetH();
	void SetX(const wrpgui_pos_t x);
	void SetY(const wrpgui_pos_t y);
	void SetW(const wrpgui_size_t w);
	void SetH(const wrpgui_size_t h);
	void SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y);
	void SetSize(const wrpgui_size_t w, const wrpgui_size_t h);

	wrpgui_handle_t* m_pHandler;
	WrpScreen* m_pParentScreen;
	WrpStyle m_style;

protected:

private:

};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPWIDGET_HPP_ */
