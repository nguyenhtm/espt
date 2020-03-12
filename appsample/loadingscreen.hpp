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
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class LoadingScreen : public WrpHmiAppClient
                    , public WrpMidwAppClient
                    , public WrpHmiScreen
{
public:
   LoadingScreen(WrpHmiApp* app);
   ~LoadingScreen();
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
   LoadingScreen(const LoadingScreen& cp);
   WrpHmiApp*        mpHmiApp;
   WrpGui::WrpLabel* mpLblLoadingStatus;
};

#endif /* APPSAMPLE_LOADINGSCREEN_HPP */
