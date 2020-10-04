/********************************************************************************************************
 * @File  : loadingscreen.hpp
 * @Date  : 2019-12-09
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_LOADINGSCREEN_HPP
#define APPSAMPLE_LOADINGSCREEN_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpgui/wrpscreen.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class LoadingScreen : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
	LoadingScreen();
   /*
    * Destructor
    */
   ~LoadingScreen();
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
   LoadingScreen(const LoadingScreen& cp);
   // members
   WrpGui::WrpLabel* mpLblLoadingStatus;
};

#endif /* APPSAMPLE_LOADINGSCREEN_HPP */
