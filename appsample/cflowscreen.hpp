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
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
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
class CFlowScreenEx : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
	CFlowScreenEx();
   /*
    * Destructor
    */
   ~CFlowScreenEx();
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
   CFlowScreenEx(const CFlowScreenEx& cp);
   // members
   WrpGui::WrpAnim   mAnim;
   WrpGui::WrpImage* mpMenuItem[MENUITEMS_MAX];
   WrpGui::WrpImage* mpAnimItem[ANIMITEMS_MAX];
};

#endif /* APPSAMPLE_CFLOWSCREEN_HPP */
