/********************************************************************************************************
 * @File  : cflowscreen.hpp
 * @Date  : 2020-02-08
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_CFLOWSCREEN_HPP
#define APPSAMPLE_CFLOWSCREEN_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrpanim.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define MENUITEMS_MAX 5
#define ANIMITEMS_MAX 6

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
//
class CFlowScreen : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
   CFlowScreen();
   /*
    * Destructor
    */
   ~CFlowScreen();
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
   CFlowScreen(const CFlowScreen& cp);
   // members
   WrpGui::WrpAnim  mAnim;
   WrpGui::WrpImage* mpMenuItem[MENUITEMS_MAX];
   WrpGui::WrpImage* mpAnimItem[ANIMITEMS_MAX];
};

#endif /* APPSAMPLE_CFLOWSCREEN_HPP */
