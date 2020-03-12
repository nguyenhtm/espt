/********************************************************************************************************
 * @File  : loadingscreen.cpp
 * @Date  : 2019-12-09
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "loadingscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
LoadingScreen::LoadingScreen(WrpHmiApp* app)
: mpHmiApp(app)
, mpLblLoadingStatus(NULL)
{
   WRPPRINT("%s\n", "LoadingScreen::LoadingScreen() Begin");
   WRPPRINT("%s\n", "LoadingScreen::LoadingScreen() End");
}

LoadingScreen::~LoadingScreen()
{
   WRPPRINT("%s\n", "LoadingScreen::~LoadingScreen() Begin");
   WRPPRINT("%s\n", "LoadingScreen::~LoadingScreen() End");
}

void LoadingScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "LoadingScreen::CreateAndShow() Begin");
   mpHmiAppClientHandle = new WrpGui::WrpScreen(false);
   mpHmiAppClientHandle->SetTitle("");
   mpLblLoadingStatus = new WrpGui::WrpLabel(mpHmiAppClientHandle);
   mpLblLoadingStatus->SetPos(100, 90);
   mpLblLoadingStatus->SetText("Loading......0%");
   WRPPRINT("%s\n", "LoadingScreen::CreateAndShow() End");
}

void LoadingScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "LoadingScreen::HideAndDestroy() Begin");
   //WRPNULL_CHECK(m_pScreenHandle)
   //delete m_pScreenHandle;
   //delete m_pLblLoadingStatus;
   WRPPRINT("%s\n", "LoadingScreen::HideAndDestroy() End");
}

void LoadingScreen::MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length)
{
   WRPPRINT("%s\n", "LoadingScreen::MidwAppUpdate() Begin");
   switch(status)
   {
      case MIDWAPP_WSCLIENT_STATUS_DATA_RECEIVED:
         {
         //TODO
         if (!strcmp(buffer, "go"))
			{
				for(int i = 1; i <= 10; i++)
				{
					char str[100] = {0};
					sprintf(str, "Loading.......%d%%", i*10);
					mpLblLoadingStatus->SetText(str);
					usleep(500*1000);
				}
				mpHmiApp->LoadScreen(HOMESCREEN);
			}
		}
		break;
		default:
		{

		}
		break;
	}

   WRPPRINT("%s\n", "LoadingScreen::MidwAppUpdate() End");
}

LoadingScreen::LoadingScreen(const LoadingScreen& cp)
{
}
