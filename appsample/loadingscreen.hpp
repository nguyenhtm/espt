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
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpgui/wrpscreen.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class LoadingScreenEx : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
   LoadingScreenEx();
   /*
    * Destructor
    */
   ~LoadingScreenEx();
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
   LoadingScreenEx(const LoadingScreenEx& cp);
   // members
   WrpGui::WrpLabel* mpLblLoadingStatus;
};

#endif /* APPSAMPLE_LOADINGSCREEN_HPP */
