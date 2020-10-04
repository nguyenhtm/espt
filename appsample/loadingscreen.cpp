/********************************************************************************************************
 * @File  : loadingscreen.cpp
 * @Date  : 2019-12-09
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "loadingscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - LoadingScreenEx
 ********************************************************************************************************/
LoadingScreen::LoadingScreen()
: WrpGui::WrpScreen(true)
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
   mpLblLoadingStatus = new WrpGui::WrpLabel(this);
   mpLblLoadingStatus->SetText("Loading...");
   mpLblLoadingStatus->SetPos(50, 90);
   WRPPRINT("%s\n", "LoadingScreen::CreateAndShow() End");
}
void LoadingScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "LoadingScreen::HideAndDestroy() Begin");
   WRPNULL_CHECK(mpLblLoadingStatus)
   delete mpLblLoadingStatus;
   mpLblLoadingStatus = NULL;
   WRPPRINT("%s\n", "LoadingScreen::HideAndDestroy() End");
}
void LoadingScreen::ActiveScreen(const WrpGui::WrpScreen& obj)
{
   WRPPRINT("%s%p:%p\n", "LoadingScreen::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WrpScreen::Load();
   }
   WRPPRINT("%s\n", "LoadingScreen::ActiveScreen() End");
}
LoadingScreen::LoadingScreen(const LoadingScreen& cp)
: WrpGui::WrpScreen(true)
, mpLblLoadingStatus(NULL)
{
}
