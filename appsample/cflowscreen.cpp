/********************************************************************************************************
 * @File  : cflowscreen.cpp
 * @Date  : 2020-02-08
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "cflowscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
CFlowScreen::CFlowScreen(WrpHmiApp* app)
: mpHmiApp(app)
{
   WRPPRINT("%s\n", "CFlowScreen::CFlowScreen() Begin");
   // cflowscreen is a normal screen
   mpHmiAppClientHandle = new WrpGui::WrpScreen(false);
   mpHmiAppClientHandle->SetTitle("");
   mpHmiAppClientHandle->SetStyle(WrpGui::BUTTON_TGL_RELEASE);
   // cflowscreen has a main menu
   mpMenuItem[0] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMenuItem[0]->SetImage(WRPRESIMG_CFLOWITEM1);
   mpMenuItem[0]->SetPos(WRPSCREEN_WIDTH-60, WRPSCREEN_MENU_POSY);
   mpMenuItem[1] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMenuItem[1]->SetImage(WRPRESIMG_CFLOWITEM2);
   mpMenuItem[1]->SetPos(WRPSCREEN_WIDTH-120, WRPSCREEN_MENU_POSY);
   mpMenuItem[2] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMenuItem[2]->SetImage(WRPRESIMG_CFLOWITEM3);
   mpMenuItem[2]->SetPos(WRPSCREEN_WIDTH-180, WRPSCREEN_MENU_POSY);
   mpMenuItem[3] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMenuItem[3]->SetImage(WRPRESIMG_CFLOWITEM4);
   mpMenuItem[3]->SetPos(WRPSCREEN_WIDTH-240, WRPSCREEN_MENU_POSY);
   // cflowscreen has items to demo many kinds of coverflow
   mpAnimItem[0] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpAnimItem[0]->SetImage(WRPRESIMG_APP);
   mpAnimItem[1] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpAnimItem[1]->SetImage(WRPRESIMG_SETTING);
   mpAnimItem[2] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpAnimItem[2]->SetImage(WRPRESIMG_DIAGNOSIS);
   mpAnimItem[3] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpAnimItem[3]->SetImage(WRPRESIMG_AUTOTEST);
   mpAnimItem[4] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpAnimItem[4]->SetImage(WRPRESIMG_WIFI2);
   mpAnimItem[5] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpAnimItem[5]->SetImage(WRPRESIMG_HOME);
   mAnim.SetWidgets((WrpGui::WrpWidget**)mpAnimItem, 6);
   WRPPRINT("%s\n", "CFlowScreen::CFlowScreen() End");
}

CFlowScreen::~CFlowScreen()
{
   WRPPRINT("%s\n", "CFlowScreen::~CFlowScreen() Begin");
   WRPPRINT("%s\n", "CFlowScreen::~CFlowScreen() End");
}

void CFlowScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "CFlowScreen::CreateAndShow() Begin");
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[0], 2000);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[1], 2000);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[2], 2000);
   mAnim.FadeIn((WrpGui::WrpWidget*)mpMenuItem[3], 2000);
   mAnim.Liverpool();
   WRPPRINT("%s\n", "CFlowScreen::CreateAndShow() End");
}

void CFlowScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "CFlowScreen::HideAndDestroy() Begin");
   WRPPRINT("%s\n", "CFlowScreen::HideAndDestroy() End");
}

void CFlowScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
   WRPPRINT("%s\n", "CFlowScreen::MidwAppUpdate() Begin");
   switch(status)
   {
      case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
         {
            if (!strcmp(buffer, "home"))
            {
               mpHmiApp->LoadScreen(HOMESCREEN);
            }
            else if (!strcmp(buffer, "cflow1"))
            {
               mpAnimItem[5]->SetPos(0,0); // unhide it
               mAnim.SetWidgets((WrpGui::WrpWidget**)mpAnimItem, 6);
               mAnim.Liverpool();
            }
            else if (!strcmp(buffer, "cflow2"))
            {
               mpAnimItem[5]->SetPos(0,-30); // hide it
               mAnim.SetWidgets((WrpGui::WrpWidget**)mpAnimItem, 5);
               mAnim.Barcelona();
            }
            else if (!strcmp(buffer, "cflow3"))
            {
               mpAnimItem[5]->SetPos(0,0);  // unhide it
               mAnim.SetWidgets((WrpGui::WrpWidget**)mpAnimItem, 6);
               mAnim.RealMadrid();
            }
            else if (!strcmp(buffer, "cflow4"))
            {
               mpAnimItem[5]->SetPos(0,0);  // unhide it
               mAnim.SetWidgets((WrpGui::WrpWidget**)mpAnimItem, 6);
               mAnim.Chealse();
            }
            else if (!strcmp(buffer, "cflow5"))
            {
               mpAnimItem[5]->SetPos(0,0);  // unhide it
               mAnim.SetWidgets((WrpGui::WrpWidget**)mpAnimItem, 6);
               mAnim.Messi();
            }
         }
         break;
      default:
         break;
   }
   WRPPRINT("%s", "CFlowScreen::Update() End\n");
}

CFlowScreen::CFlowScreen(const CFlowScreen& cp)
{
}
