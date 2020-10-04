/********************************************************************************************************
 * @File  : wrptesthmi.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrphmi/wrphmi.hpp"
#include "wrptesthmi.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"

namespace WrpTest {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - TestScreen
 ********************************************************************************************************/
TestScreen::TestScreen()
: WrpGui::WrpScreen(true)
, mpTestLabel(NULL)
, mpTestImage(NULL)
{
   WRPPRINT("%s\n", "TestScreen::TestScreen() Begin");
   WRPPRINT("%s\n", "TestScreen::TestScreen() End");
}
TestScreen::~TestScreen()
{
   WRPPRINT("%s\n", "TestScreen::~TestScreen() Begin");
   WRPPRINT("%s\n", "TestScreen::~TestScreen() End");
}
void TestScreen::CreateAndShow()
{
   WRPPRINT("%s\n", "TestScreen::CreateAndShow() Begin");
   mpTestLabel = new WrpGui::WrpLabel(this);
   mpTestLabel->SetText("Test Label");
   mpTestLabel->SetPos(50, 90);
   mpTestImage = new WrpGui::WrpImage(this);
   mpTestImage->SetImage(WRPRESIMG_DEF01HOME);
   // decorator
   WrpGui::WrpDecorator *decor1 = new WrpGui::WrpAnimEx(mpTestImage, 1000);
   WrpGui::WrpDecorator *decor2 = new WrpGui::WrpAnimEx(mpTestLabel, 2000);
   decor1->SetPos(50, 50);
   decor1->MoveX(50, 200);
   decor2->MoveY(90, 160);
   delete decor1;
   delete decor2;
   WRPPRINT("%s\n", "TestScreen::CreateAndShow() End");
}
void TestScreen::HideAndDestroy()
{
   WRPPRINT("%s\n", "TestScreen::HideAndDestroy() Begin");
   WRPNULL_CHECK(mpTestLabel)
   delete mpTestLabel;
   delete mpTestImage;
   WRPPRINT("%s\n", "TestScreen::HideAndDestroy() End");
}
void TestScreen::ActiveScreen(const WrpScreen& obj)
{
   WRPPRINT("%s%p:%p\n", "TestScreen::ActiveScreen() Begin ", &obj, this);
   if (this == &obj)
   {
      WrpScreen::Load();
   }
   WRPPRINT("%s\n", "TestScreen::ActiveScreen() End");
}
TestScreen::TestScreen(const TestScreen& cp)
: WrpGui::WrpScreen(true)
, mpTestLabel(NULL)
, mpTestImage(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpTestHmi
 ********************************************************************************************************/
void WrpTestHmi()
{
   WrpHmiApp app;
   app.Initialize();

   WrpTest::TestScreen testscreen;
   app.GetHmiInstance()->Attach(&testscreen);
   app.GetHmiInstance()->LoadScreen(&testscreen);

#ifndef USE_ESP_IDF
   SDL_Event e;
   while(1)
   {
      if (SDL_WaitEvent(&e)) {
         if (e.type == SDL_QUIT) break;
      }
   }
#else
   while(1)
   {
	      vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
#endif
   app.DeInitialize();
}

} /* Namespace WrpTest */
