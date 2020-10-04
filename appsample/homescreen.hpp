/********************************************************************************************************
 * @File  : homescreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_HOMESCREEN_HPP
#define APPSAMPLE_HOMESCREEN_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrpanim.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class HomeScreen : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
	HomeScreen();
   /*
    * Destructor
    */
   ~HomeScreen();
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
   void ActiveScreen(const WrpGui::WrpScreen& obj);

private:
   /*
    * Default constructor
    */
   HomeScreen(const HomeScreen& cp);
   // members
   WrpGui::WrpImage* mpLogo;
   WrpGui::WrpImage* mpMenuItem[3];
};

#endif /* APPSAMPLE_HOMESCREEN_HPP */
