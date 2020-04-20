/********************************************************************************************************
 * @File  : homescreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "homescreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
HomeScreen::HomeScreen(WrpHmiApp* app)
: mpHmiApp(app)
{
   WRPPRINT("%s\n", "HomeScreen::HomeScreen() Begin");
   // homescreen is a master screen
   mpHmiAppClientHandle = new WrpGui::WrpScreen(true);
   mpHmiAppClientHandle->SetTitle("");
   mpHmiAppClientHandle->SetStyle(WrpGui::BUTTON_TGL_RELEASE);
   mpMenuItem[0] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMenuItem[0]->SetImage(WRPRESIMG_SETTING);
   mpMenuItem[0]->SetPos(WRPSCREEN_WIDTH-30, WRPSCREEN_MENU_POSY);
   mpMenuItem[1] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMenuItem[1]->SetImage(WRPRESIMG_AUTOTEST);
   mpMenuItem[1]->SetPos(WRPSCREEN_WIDTH-60, WRPSCREEN_MENU_POSY);
   mpMenuItem[2] = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpMenuItem[2]->SetImage(WRPRESIMG_DIAGNOSIS);
   mpMenuItem[2]->SetPos(WRPSCREEN_WIDTH-90, WRPSCREEN_MENU_POSY);
   // homescreen has a logo
   mpLogo = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpLogo->SetImage(WRPRESIMG_LOGO);
   mpLogo->SetPos(WRPSCREEN_MENU_POSX+120, WRPSCREEN_MENU_POSY+80);
   WRPPRINT("%s\n", "HomeScreen::HomeScreen() End");
}

HomeScreen::~HomeScreen()
{
   WRPPRINT("%s\n", "HomeScreen::~HomeScreen() Begin");
   delete [] mpMenuItem;
   delete mpLogo;
   WRPPRINT("%s\n", "HomeScreen::~HomeScreen() End");
}

void HomeScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "HomeScreen::CreateAndShow() Begin");
   // homescreen is a master screen, must create in constructor
   mAnim.FadeIn((WrpGui::WrpWidget*)mpLogo, 2000);
   WRPPRINT("%s\n", "HomeScreen::CreateAndShow() End");
}

void HomeScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "HomeScreen::HideAndDestroy() Begin");
   // homescreen is a master screen, must not delete it
   WRPPRINT("%s\n", "HomeScreen::HideAndDestroy() End");
}

void HomeScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
   WRPPRINT("%s\n", "HomeScreen::MidwAppUpdate() Begin");
   switch(status)
   {
      case MIDWAPP_STATUS_START:
      case MIDWAPP_STATUS_STOP:
         {
         }
         break;
      case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
         {
            if (!strcmp(buffer, "diagnosis"))
            {
               mpHmiApp->LoadScreen(SETTINGSCREEN);
            }
            else if (!strcmp(buffer, "cflow"))
            {
               mpHmiApp->LoadScreen(CFLOWSCREEN);
            }
            else if (!strcmp(buffer, "shutdown"))
            {
               mpHmiAppClientHandle->ShowPopup(true, "Shutting Down!");
            }
            else if(!strcmp(buffer, "SCREEN_PLAIN_COLOR"))
            {
               mpHmiAppClientHandle->SetStyle(WrpGui::SCREEN_PLAIN_COLOR);
            }
            else if(!strcmp(buffer, "SCREEN_PRETTY"))
            {
               mpHmiAppClientHandle->SetStyle(WrpGui::SCREEN_PRETTY);
            }
            else if(!strcmp(buffer, "SCREEN_PRETTY_COLOR"))
            {
               mpHmiAppClientHandle->SetStyle(WrpGui::SCREEN_PRETTY_COLOR);
            }
            else if(!strcmp(buffer, "BUTTON_PRESS"))
            {
               mpHmiAppClientHandle->SetStyle(WrpGui::BUTTON_PRESS);
            }
            else if(!strcmp(buffer, "BUTTON_RELEASE"))
            {
               mpHmiAppClientHandle->SetStyle(WrpGui::BUTTON_RELEASE);
            }
            else if(!strcmp(buffer, "BUTTON_TGL_RELEASE"))
            {
               mpHmiAppClientHandle->SetStyle(WrpGui::BUTTON_TGL_RELEASE);
            }
            else if(!strcmp(buffer, "BUTTON_TGL_PRESS"))
            {
               mpHmiAppClientHandle->SetStyle(WrpGui::BUTTON_TGL_PRESS);
            }
         }
         break;
      default:
         {
            //do nothing
         }
         break;
   }
   WRPPRINT("%s\n", "HomeScreen::MidwAppUpdate() End");
}

HomeScreen::HomeScreen(const HomeScreen& cp)
{
}
