/********************************************************************************************************
 * @File  : homescreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "homescreen.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
/********************************************************************************************************
 * FUNCTIONS - HomeScreenEx
 ********************************************************************************************************/
HomeScreenEx::HomeScreenEx()
: WrpGui::WrpScreen(false)
, mpLogo(NULL)
{
   WRPPRINT("%s\n", "HomeScreenEx::HomeScreenEx() Begin");
   WRPPRINT("%s\n", "HomeScreenEx::HomeScreenEx() End");
}
HomeScreenEx::~HomeScreenEx()
{
   WRPPRINT("%s\n", "HomeScreenEx::~HomeScreenEx() Begin");
   WRPPRINT("%s\n", "HomeScreenEx::~HomeScreenEx() End");
}
void HomeScreenEx::CreateAndShow()
{
   WRPPRINT("%s\n", "HomeScreenEx::CreateAndShow() Begin");
   // homescreen has a logo
   mpLogo = new WrpGui::WrpImage(this);
   mpLogo->SetImage(WRPRESIMG_DEF01LOGO);
   mpLogo->SetPos(WRPSCREEN_MENU_POSX+130, WRPSCREEN_MENU_POSY+90);
   // and a menu items
   mpMenuItem[0] = new WrpGui::WrpImage(this);
   mpMenuItem[0]->SetImage(WRPRESIMG_DEF01SETTING);
   mpMenuItem[0]->SetPos(WRPSCREEN_WIDTH-30, WRPSCREEN_MENU_POSY);
   mpMenuItem[1] = new WrpGui::WrpImage(this);
   mpMenuItem[1]->SetImage(WRPRESIMG_DEF01AUTOTEST);
   mpMenuItem[1]->SetPos(WRPSCREEN_WIDTH-60, WRPSCREEN_MENU_POSY);
   mpMenuItem[2] = new WrpGui::WrpImage(this);
   mpMenuItem[2]->SetImage(WRPRESIMG_DEF01DIAGNOSIS);
   mpMenuItem[2]->SetPos(WRPSCREEN_WIDTH-90, WRPSCREEN_MENU_POSY);
   WRPPRINT("%s\n", "HomeScreenEx::CreateAndShow() End");
}
void HomeScreenEx::HideAndDestroy()
{
   WRPPRINT("%s\n", "HomeScreenEx::HideAndDestroy() Begin");
   WRPNULL_CHECK(mpLogo)
   delete mpLogo; mpLogo = NULL;
   delete [] mpMenuItem;
   WRPPRINT("%s\n", "HomeScreenEx::HideAndDestroy() End");
}
void HomeScreenEx::ActiveScreen(const WrpScreen& obj)
{
   WRPPRINT("%s%p:%p\n", "HomeScreenEx::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WrpScreen::Load();
   }
   WRPPRINT("%s\n", "HomeScreenEx::ActiveScreen() End");
}
HomeScreenEx::HomeScreenEx(const HomeScreenEx& cp)
: WrpGui::WrpScreen(false)
, mpLogo(NULL)
{
}
