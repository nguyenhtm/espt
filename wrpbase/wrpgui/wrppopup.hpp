/********************************************************************************************************
 * @File  : wrppopup.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPPOPUP_HPP
#define WRPGUI_WRPPOPUP_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpwidget.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpScreen;

// Class WrpPopup
class WrpPopup : public WrpWidget
{
public:
   WrpPopup(WrpScreen* parent);
   ~WrpPopup();
   void Show();
   void Hide();
   void SetText(const char* text);

private:
   WrpPopup();
   WrpPopup(const WrpPopup& cp);
   //methods
   void EnableAnimation();
   //members
   wrpgui_handle_t *mpPopupText;
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPPOPUP_HPP */
