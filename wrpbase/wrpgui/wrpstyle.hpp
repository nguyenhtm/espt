/********************************************************************************************************
 * @File  : wrpstyle.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPSTYLE_HPP
#define WRPGUI_WRPSTYLE_HPP

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

// Class WrpStyle
class WrpStyle
{
public:
   WrpStyle(wrpgui_handle_t* obj);
   ~WrpStyle();
   void SetStyle(const WrpStyleType& style);
   void SetDefaultStyle();

private:
   WrpStyle();
   WrpStyle(const WrpStyle& cp);
   // members
   wrpgui_handle_t* mpObjHandle;
   wrpgui_style_t   m_style;
   wrpgui_style_t   m_default;
   WrpStyleType     mCurrentStyle;
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPSTYLE_HPP */
