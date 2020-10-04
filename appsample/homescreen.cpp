/********************************************************************************************************
 * @File  : homescreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
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
HomeScreen::HomeScreen()
: WrpGui::WrpScreen(false)
, mpLogo(NULL)
{
   WRPPRINT("%s\n", "HomeScreen::HomeScreen() Begin");
   WRPPRINT("%s\n", "HomeScreen::HomeScreen() End");
}
HomeScreen::~HomeScreen()
{
   WRPPRINT("%s\n", "HomeScreen::~HomeScreen() Begin");
   WRPPRINT("%s\n", "HomeScreen::~HomeScreen() End");
}
void HomeScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "HomeScreen::CreateAndShow() Begin");
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
   WRPPRINT("%s\n", "HomeScreen::CreateAndShow() End");
}
void HomeScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "HomeScreen::HideAndDestroy() Begin");
   WRPNULL_CHECK(mpLogo)
   delete mpLogo; mpLogo = NULL;
   delete [] mpMenuItem; //wrong
   WRPPRINT("%s\n", "HomeScreenEx::HideAndDestroy() End");
}
void HomeScreen::ActiveScreen(const WrpGui::WrpScreen& obj)
{
   WRPPRINT("%s%p:%p\n", "HomeScreen::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WrpScreen::Load();
   }
   WRPPRINT("%s\n", "HomeScreen::ActiveScreen() End");
}
HomeScreen::HomeScreen(const HomeScreen& cp)
: WrpGui::WrpScreen(false)
, mpLogo(NULL)
{
}
