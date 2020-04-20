/********************************************************************************************************
 * @File  : wrpscreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPSCREEN_HPP
#define WRPGUI_WRPSCREEN_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpLabel;
//class WrpWidget;
class WrpPopup;
class WrpImage;
class WrpStyle;

// Class WrpScreen
class WrpScreen
{
public:
   WrpScreen(const bool bMasterScreen);
   ~WrpScreen();
   wrpgui_handle_t* GetHandle() { return mpObjHandle; }
   void             Load();
   void             SetTitle(const char* text);
   void             SetStyle(const WrpStyleType& style);
   void             ShowPopup(const bool& bShowHide, const char *text);

private:
   WrpScreen();
   WrpScreen(const WrpScreen& cp);
   // methods

   // members
   wrpgui_handle_t* mpObjHandle;
   bool             mbMasterScreen;
   WrpLabel*        mpMenuTitle;
   WrpPopup*        mpTopPopup;
   WrpImage*        mpBackground;
   WrpStyle*        mpAppearance;

   // friend classes
   friend class WrpWidget;
   friend class WrpLabel;
   friend class WrpImage;
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPSCREEN_HPP */
