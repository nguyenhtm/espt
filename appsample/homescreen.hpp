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
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpgui/wrpanim.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class HomeScreenEx : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
	HomeScreenEx();
   /*
    * Destructor
    */
   ~HomeScreenEx();
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
   HomeScreenEx(const HomeScreenEx& cp);
   // members
   WrpGui::WrpImage* mpLogo;
   WrpGui::WrpImage* mpMenuItem[3];
};

#endif /* APPSAMPLE_HOMESCREEN_HPP */
