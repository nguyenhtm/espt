/********************************************************************************************************
 * @File  : cflowscreen.cpp
 * @Date  : 2020-02-08
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "cflowscreen.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
CFlowScreenEx::CFlowScreenEx()
: WrpGui::WrpScreen(false)
, mpMenuItem() // initialize array of pointers to null
, mpAnimItem()
{
   WRPPRINT("%s\n", "CFlowScreenEx::CFlowScreenEx() Begin");
   WRPPRINT("%s\n", "CFlowScreenEx::CFlowScreenEx() End");
}
CFlowScreenEx::~CFlowScreenEx()
{
   WRPPRINT("%s\n", "CFlowScreenEx::~CFlowScreenEx() Begin");
   WRPPRINT("%s\n", "CFlowScreenEx::~CFlowScreenEx() End");
}
void CFlowScreenEx::CreateAndShow()
{
   WRPPRINT("%s\n", "CFlowScreenEx::CreateAndShow() Begin");

   // cflowscreen has a list of menu items to select each kind of cover flow
   mpMenuItem[0] = new WrpGui::WrpImage(this);
   mpMenuItem[0]->SetImage(WRPRESIMG_DEF01MENUITEM1);
   mpMenuItem[0]->SetPos(WRPSCREEN_WIDTH-60, WRPSCREEN_MENU_POSY);
   mpMenuItem[1] = new WrpGui::WrpImage(this);
   mpMenuItem[1]->SetImage(WRPRESIMG_DEF01MENUITEM2);
   mpMenuItem[1]->SetPos(WRPSCREEN_WIDTH-120, WRPSCREEN_MENU_POSY);
   mpMenuItem[2] = new WrpGui::WrpImage(this);
   mpMenuItem[2]->SetImage(WRPRESIMG_DEF01MENUITEM3);
   mpMenuItem[2]->SetPos(WRPSCREEN_WIDTH-180, WRPSCREEN_MENU_POSY);
   mpMenuItem[3] = new WrpGui::WrpImage(this);
   mpMenuItem[3]->SetImage(WRPRESIMG_DEF01MENUITEM4);
   mpMenuItem[3]->SetPos(WRPSCREEN_WIDTH-240, WRPSCREEN_MENU_POSY);
   mpMenuItem[4] = new WrpGui::WrpImage(this);
   mpMenuItem[4]->SetImage(WRPRESIMG_DEF01MENUITEM5);
   mpMenuItem[4]->SetPos(WRPSCREEN_WIDTH-300, WRPSCREEN_MENU_POSY);

   // cflowscreen has items to demo many kinds of coverflow
   mpAnimItem[0] = new WrpGui::WrpImage(this);
   mpAnimItem[0]->SetImage(WRPRESIMG_DEF01APP);
   mpAnimItem[1] = new WrpGui::WrpImage(this);
   mpAnimItem[1]->SetImage(WRPRESIMG_DEF01SETTING);
   mpAnimItem[2] = new WrpGui::WrpImage(this);
   mpAnimItem[2]->SetImage(WRPRESIMG_DEF01DIAGNOSIS);
   mpAnimItem[3] = new WrpGui::WrpImage(this);
   mpAnimItem[3]->SetImage(WRPRESIMG_DEF01AUTOTEST);
   mpAnimItem[4] = new WrpGui::WrpImage(this);
   mpAnimItem[4]->SetImage(WRPRESIMG_DEF01WIFI2);
   mpAnimItem[5] = new WrpGui::WrpImage(this);
   mpAnimItem[5]->SetImage(WRPRESIMG_DEF01HOME);
   mAnim.SetWidgets((WrpGui::WrpWidget**)mpAnimItem, 6);

   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[0], 2000);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[1], 2000);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[2], 2000);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[3], 2000);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[4], 2000);

   mAnim.Liverpool();

   WRPPRINT("%s\n", "CFlowScreenEx::CreateAndShow() End");
}
void CFlowScreenEx::HideAndDestroy()
{
   WRPPRINT("%s\n", "CFlowScreenEx::HideAndDestroy() Begin");
   WRPNULL_CHECK(mpMenuItem[0])
   int i = 0;
   for (i = 0; i < MENUITEMS_MAX; i++) {
      delete mpMenuItem[i];
      mpMenuItem[i] = NULL;
   }
   for (i = 0; i < ANIMITEMS_MAX; i++) {
      delete mpAnimItem[i];
      mpAnimItem[i] = NULL;
   }
   WRPPRINT("%s\n", "CFlowScreenEx::HideAndDestroy() End");
}
void CFlowScreenEx::ActiveScreen(const WrpScreen& obj)
{
   WRPPRINT("%s%p:%p\n", "CFlowScreenEx::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WrpScreen::Load();
   }
   WRPPRINT("%s\n", "CFlowScreenEx::ActiveScreen() End");
}
CFlowScreenEx::CFlowScreenEx(const CFlowScreenEx& cp)
: WrpGui::WrpScreen(false)
{
}
