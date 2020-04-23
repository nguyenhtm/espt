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
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"
#include "wrpbase/wrpgui/wrpanim.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class CFlowScreen : public WrpHmiAppClient
                  , public WrpMidwAppClient
                  , public WrpHmiScreen
{
public:
   CFlowScreen(WrpHmiApp* app);
   ~CFlowScreen();
   /*
    * Call back function called on a WrpHmiClient screen creation
    */
   void CreateAndShow();
   /*
    * Call back function called on a WrpHmiClient screen destroy
    */
   void HideAndDestroy();
   /*
    * Call back function called on a WrpMidwAppClient events update
    */
   void MidwAppUpdate(eWrpMidwAppStatus status, char* buffer, unsigned int length);
   /*
    * Call back function called on a WrpHmiScreen config loading
    */
   void          LoadConfig(){};
   void          Add(WrpHmiScreen* pHmiScreen){};
   void          Remove(WrpHmiScreen* pHmiScreen){};
   WrpHmiScreen* GetChild(const uint8_t id) const { return NULL; };

private:
   CFlowScreen(const CFlowScreen& cp);
   /** Holds the handle of */
   WrpHmiApp*        mpHmiApp;
   WrpGui::WrpAnim   mAnim;
   WrpGui::WrpImage* mpMenuItem[5];
   WrpGui::WrpImage* mpAnimItem[6];
};

#endif /* APPSAMPLE_CFLOWSCREEN_HPP */
