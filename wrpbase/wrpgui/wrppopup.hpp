/********************************************************************************************************
 * @File  : wrppopup.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPGUI_WRPPOPUP_HPP_
#define WRPBASE_WRPGUI_WRPPOPUP_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrplabel.hpp"
#include "wrpstyle.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPPOPUP_WIDTH  320
#define WRPPOPUP_HEIGHT 80

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// forward classes
class WrpScreen;

class WrpPopup : public WrpLabel, public WrpStyle
{
public:
	WrpPopup(WrpScreen* parent);
	~WrpPopup();

	void Show();
	void Hide();

protected:

private:
	void EnableAnimation();
};

} /* Namespace WrpGui */

#endif /* WRPBASE_WRPGUI_WRPPOPUP_HPP_ */
