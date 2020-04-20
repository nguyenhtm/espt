/********************************************************************************************************
 * @File  : diagscreen.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "diagscreen.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
DiagScreen::DiagScreen(WrpHmiApp* app)
: mpHmiApp(app)
, mpLblBackItem(NULL)
{
   WRPPRINT("%s\n", "DiagScreen::DiagScreen() Begin");
   mpHmiAppClientHandle = new WrpGui::WrpScreen(false);
   mpHmiAppClientHandle->SetTitle("");
   mpHmiAppClientHandle->SetStyle(WrpGui::BUTTON_TGL_RELEASE);
   //mpLblBackItem = new WrpGui::WrpLabel(mpHmiAppClientHandle);
   //mpLblBackItem->SetPos(260, WRPSCREEN_MENU_POSY);
   //mpLblBackItem->SetText("Back");
   mpBackground = new WrpGui::WrpImage(mpHmiAppClientHandle);
   mpBackground->SetImage(WRPRESIMG_BACKGROUND);
   WRPPRINT("%s\n", "DiagScreen::DiagScreen() End");
}

DiagScreen::~DiagScreen()
{
   WRPPRINT("%s\n", "DiagScreen::~DiagScreen() Begin");
   WRPPRINT("%s\n", "DiagScreen::~DiagScreen() End");
}

void DiagScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "DiagScreen::CreateAndShow() Begin");
   WRPPRINT("%s\n", "DiagScreen::CreateAndShow() End");
}

void DiagScreen::HideAndDestroy()
{
   WRPPRINT("%s", "DiagScreen::HideAndDestroy() Begin");
   //WRPNULL_CHECK(m_pScreenHandle)
   //delete m_pScreenHandle;
   //delete m_pLblBackItem;
   WRPPRINT("%s", "DiagScreen::HideAndDestroy() End");
}

void DiagScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
   WRPPRINT("%s\n", "DiagScreen::MidwAppUpdate() Begin");
   switch(status)
   {
      case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
         {
            if (!strcmp(buffer, "back"))
            {
               mpHmiApp->LoadScreen(HOMESCREEN);
            }
         }
         break;
      default:
         {
            //do nothing
         }
         break;
   }
   WRPPRINT("%s\n", "DiagScreen::MidwAppUpdate() End");
}

DiagScreen::DiagScreen(const DiagScreen& cp)
{
}
