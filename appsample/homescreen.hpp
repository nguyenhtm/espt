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
#include "wrpbase/wrpgui/wrpimage.hpp"
#include "wrpbase/wrpgui/wrpanim.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class HomeScreen : public WrpHmiAppClient
                 , public WrpMidwAppClient
                 , public WrpHmiScreen
{
public:
   HomeScreen(WrpHmiApp* app);
   ~HomeScreen();
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
   HomeScreen(const HomeScreen& cp);
   WrpHmiApp*        mpHmiApp;
   WrpGui::WrpAnim   mAnim;
   WrpGui::WrpImage* mpMenuItem[3];
   WrpGui::WrpImage* mpLogo;
};

#endif /* APPSAMPLE_HOMESCREEN_HPP */
