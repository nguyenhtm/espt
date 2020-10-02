/********************************************************************************************************
 * @File  : wrpguitest.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPTEST_WRPGUITEST_HPP
#define WRPTEST_WRPGUITEST_HPP

#if (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU)

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"

namespace WrpTest {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
extern void GuiTestApp();

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class TestScreen
class TestScreen : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
   TestScreen();
   /*
    * Destructor
    */
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
   void ActiveScreen(const WrpScreen& obj);

private:
   /*
    * Default constructor
    */
   TestScreen(const TestScreen& cp);
   // members
   WrpGui::WrpLabel* mpTestLabel;
   WrpGui::WrpImage* mpTestImage;
};

} /* Namespace WrpTest */

#endif /* (LVGL_ESP32_ILI9341 || LVGL_PC_SIMU) */

#endif /* WRPTEST_WRPGUITEST_HPP */
