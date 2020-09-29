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
#include "wrpbase/wrpgui/wrpimage.hpp"

namespace WrpTest {

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
extern void SysTestApp();
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

#endif /* WRPTEST_WRPTEST_HPP */
