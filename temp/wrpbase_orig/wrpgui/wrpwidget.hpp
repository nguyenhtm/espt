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

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpScreen;
class WrpStyle;

// Class WrpWidget
class WrpWidget
{
public:
   WrpWidget(WrpScreen* parent);
   ~WrpWidget();
   wrpgui_pos_t  GetX();
   wrpgui_pos_t  GetY();
   wrpgui_size_t GetW();
   wrpgui_size_t GetH();
   void          SetX(const wrpgui_pos_t x);
   void          SetY(const wrpgui_pos_t y);
   void          SetW(const wrpgui_size_t w);
   void          SetH(const wrpgui_size_t h);
   void          SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y);
   void          SetSize(const wrpgui_size_t w, const wrpgui_size_t h);

   WrpScreen*       mpScreenHandle;
   WrpStyle*        mpAppearance;
   wrpgui_handle_t* mpWidgetHandle;

private:
   WrpWidget();
   WrpWidget(const WrpWidget& cp);
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPWIDGET_HPP */
