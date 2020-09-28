/********************************************************************************************************
 * @File  : loadingscreen.cpp
 * @Date  : 2019-12-09
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appdefines.hpp"
#include "loadingscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - LoadingScreenEx
 ********************************************************************************************************/
LoadingScreenEx::LoadingScreenEx()
: WrpGui::WrpScreen(true)
, mpLblLoadingStatus(NULL)
{
   WRPPRINT("%s\n", "LoadingScreenEx::LoadingScreenEx() Begin");
   WRPPRINT("%s\n", "LoadingScreenEx::LoadingScreenEx() End");
}
LoadingScreenEx::~LoadingScreenEx()
{
   WRPPRINT("%s\n", "LoadingScreenEx::~LoadingScreenEx() Begin");
   WRPPRINT("%s\n", "LoadingScreenEx::~LoadingScreenEx() End");
}
void LoadingScreenEx::CreateAndShow()
{
   WRPPRINT("%s\n", "LoadingScreenEx::CreateAndShow() Begin");
   mpLblLoadingStatus = new WrpGui::WrpLabel(this);
   mpLblLoadingStatus->SetText("Loading...");
   mpLblLoadingStatus->SetPos(50, 90);
   WRPPRINT("%s\n", "LoadingScreenEx::CreateAndShow() End");
}
void LoadingScreenEx::HideAndDestroy()
{
   WRPPRINT("%s\n", "LoadingScreenEx::HideAndDestroy() Begin");
   WRPNULL_CHECK(mpLblLoadingStatus)
   delete mpLblLoadingStatus;
   mpLblLoadingStatus = NULL;
   WRPPRINT("%s\n", "LoadingScreenEx::HideAndDestroy() End");
}
void LoadingScreenEx::ActiveScreen(const WrpScreen& obj)
{
   WRPPRINT("%s%p:%p\n", "TestScreen::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WrpScreen::Load();
   }
   WRPPRINT("%s\n", "TestScreen::ActiveScreen() End");
}
LoadingScreenEx::LoadingScreenEx(const LoadingScreenEx& cp)
: WrpGui::WrpScreen(true)
, mpLblLoadingStatus(NULL)
{
}
