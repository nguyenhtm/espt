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

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpLabel;
class WrpPopup;
class WrpImage;
class WrpStyle;

// Class WrpScreen
class WrpScreen
{
public:
   WrpScreen(const bool bMasterScreen=false);
   virtual ~WrpScreen();
   wrpgui_handle_t* GetHandle() { return mpObjHandle; }
   void             Load();
   void             SetTitle(const char* text);
   void             SetStyle(const WrpStyleType& style);
   void             ShowPopup(const bool& bShowHide, const char *text);
   virtual void     CreateAndShow() = 0;
   virtual void     HideAndDestroy() = 0;
   virtual void     ActiveScreen(const WrpScreen& obj) = 0;

protected:
   // members
   wrpgui_handle_t* mpObjHandle;

private:
   WrpScreen();
   WrpScreen(const WrpScreen& cp);
   // methods

   // members
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
