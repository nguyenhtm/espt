/********************************************************************************************************
 * @File  : wrpscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpscreen.hpp"
#include "wrplabel.hpp"
#include "wrppopup.hpp"
#include "wrpimage.hpp"
#include "wrpstyle.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpScreen::WrpScreen(const bool bMasterScreen)
: mbMasterScreen(bMasterScreen)
, mpMenuTitle(NULL)
, mpTopPopup(NULL)
, mpBackground(NULL)
, mpAppearance(NULL)
{
   WRPPRINT("%s%d\n", "WrpScreen::WrpScreen() Begin bMasterScreen=", bMasterScreen);
   // screen creation
   if (mbMasterScreen == true)
   {
      // not create new screen, use current loaded screen as a master screen
      mpObjHandle = lv_disp_get_scr_act(NULL);
   }
   else
   {
      // create a new screen
      mpObjHandle = lv_obj_create(NULL, NULL);
   }
   // set screen style before background usage
   mpAppearance = new WrpStyle(mpObjHandle);
   mpAppearance->SetStyle(BUTTON_TGL_RELEASE);
   // set screen background
   //mpBackground = new WrpImage(this);
   //mpBackground->SetSize(320, 240);
   //mpBackground->SetImage(0);
   // set screen top popup
   mpTopPopup = new WrpPopup(this);
   // set screen menu title
   mpMenuTitle = new WrpLabel(this);
   mpMenuTitle->SetPos(WRPSCREEN_MENU_POSX, WRPSCREEN_MENU_POSY);
   WRPPRINT("%s%d\n", "WrpScreen::WrpScreen() End bMasterScreen=", bMasterScreen);
}

WrpScreen::~WrpScreen()
{
   WRPPRINT("%s\n", "WrpScreen::~WrpScreen() Begin");
   delete mpAppearance;
   delete mpBackground;
   delete mpTopPopup;
   delete mpMenuTitle;
   // delete the 'mpObjHandle' screen handle and all its children
   lv_obj_del(mpObjHandle);
   WRPPRINT("%s\n", "WrpScreen::~WrpScreen() End");
}

void WrpScreen::Load()
{
   WRPPRINT("%s\n", "WrpScreen::Load() Begin");
   WRPNULL_CHECK(mpObjHandle)
   mpTopPopup->Hide();
   lv_disp_load_scr(mpObjHandle);
   WRPPRINT("%s\n", "WrpScreen::Load() End");
}

void WrpScreen::SetTitle(const char* text)
{
   WRPPRINT("%s%s\n", "WrpScreen::SetTitle() Begin text=", text);
   WRPNULL_CHECK(mpMenuTitle)
   mpMenuTitle->SetText(text);
   WRPPRINT("%s%s\n", "WrpScreen::SetTitle() End text=", text);
}

void WrpScreen::SetStyle(const WrpStyleType& style)
{
   WRPPRINT("%s%d\n", "WrpScreen::SetStyle() Begin style=", style);
   WRPNULL_CHECK(mpAppearance)
   mpAppearance->SetStyle(style);
   //WrpStyle::SetStyle(m_pTopPopup->m_pHandler, style);
   WRPPRINT("%s%d\n", "WrpScreen::SetStyle() End style=", style);
}

void WrpScreen::ShowPopup(const bool& bShowHide, const char* text)
{
   WRPPRINT("%s%d\n", "WrpScreen::ShowPopup() Begin bShowHide=", bShowHide);
   WRPNULL_CHECK(mpTopPopup)
   if (bShowHide)
   {
      mpTopPopup->SetText(text);
      mpTopPopup->Show();
   }
   else
   {
      mpTopPopup->Hide();
   }
   WRPPRINT("%s%d\n", "WrpScreen::ShowPopup() End bShowHide=", bShowHide);;
}

WrpScreen::WrpScreen()
: mbMasterScreen(false)
, mpMenuTitle(NULL)
, mpTopPopup(NULL)
, mpBackground(NULL)
, mpAppearance(NULL)
{
}

WrpScreen::WrpScreen(const WrpScreen& cp)
: mbMasterScreen(false)
, mpMenuTitle(NULL)
, mpTopPopup(NULL)
, mpBackground(NULL)
, mpAppearance(NULL)
{
}

} /* WrpGui Namespace */
