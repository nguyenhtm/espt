/********************************************************************************************************
 * @File  : wrptesthmi.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPTEST_WRPTESTHMI_HPP
#define WRPTEST_WRPTESTHMI_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpgui/wrpscreen.hpp"

namespace WrpTest {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
extern void WrpTestHmi();

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Forward Classes
class WrpLabel;
class WrpImage;

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

#endif /* WRPTEST_WRPGUITEST_HPP */
