/********************************************************************************************************
 * @File  : wrpsystest.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPTEST_WRPTEST_HPP
#define WRPTEST_WRPTEST_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpmidw/wrpmidwbuilder.hpp"
#include "wrpbase/wrpsys/wrpstoragefactory.hpp"
#include "wrpbase/wrphmi/wrphmi.hpp"

#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"

namespace WrpTest {

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
extern void WrpSysTest(void);

#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)
extern void WrpGuiScreenCreationTest(void);
extern void WrpGuiTest(void);
#endif

class WrpSysTestApp
{
public:
   WrpSysTestApp();
   ~WrpSysTestApp();

private:
   WrpSysMidwBuilder mMidwBuilder;
   WrpMidw* mpMidw;
};

class WrpGuiTestApp
{
public:
   WrpGuiTestApp();
   ~WrpGuiTestApp();

   //create a midw instance
   void ConstructMidw();
   // delete created midw obj
   void DestructMidw();
   //factory method to create a hmi instance
   void ConstructHmi(uint8_t productid=0);
   //get instances
   WrpHmi* GetHmiInstance() { return mpHmi; }
   WrpMidw* GetMidwInstance() { return mpMidw; }

private:
   WrpGuiMidwBuilder mMidwBuilder;
   WrpMidw* mpMidw;
   WrpHmi* mpHmi;
};

class TestScreen : public WrpHmiObserver
{
public:
   TestScreen();
   ~TestScreen();
   /*
    * Call back function called on a WrpHmiObserver screen creation
    */
   void CreateAndShow();
   /*
    * Call back function called on a WrpHmiObserver screen destroy
    */
   void HideAndDestroy();
   /*
    * Call back function called on a WrpHmiObserver screen active
    */
   void ActiveScreen(const WrpHmiObserver& obj);

private:
   TestScreen(const TestScreen& cp);
   WrpGui::WrpScreen* mpScreen;
   WrpGui::WrpLabel*  mpLabel;
};

} /* Namespace WrpTest */

#endif /* WRPTEST_WRPTEST_HPP */
