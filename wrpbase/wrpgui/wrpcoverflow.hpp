/********************************************************************************************************
 * @File  : wrpcoverflow.hpp
 * @Date  : 2019-12-03
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPCOVERFLOW_HPP_
#define WRPGUI_WRPCOVERFLOW_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpwidget.hpp"
#include "wrpstyle.hpp"
#include <vector>

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpCoverFlow : public WrpStyle
{
public:
	WrpCoverFlow();
	~WrpCoverFlow();
	void SetWidgets(WrpWidget* pListOfWidgets[]);
	void Select();

protected:

private:
	// methods
	void EnableAnimation(WrpWidget* cur, WrpWidget* next);

	// members
	WrpWidget** m_pListOfWidgets;
	int32_t m_x;
	int32_t m_y;
	int32_t m_w;
	int32_t m_h;
	int32_t m_xI;
	int32_t m_yI;
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPCOVERFLOW_HPP_ */
