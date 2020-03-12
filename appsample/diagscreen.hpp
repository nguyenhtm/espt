/********************************************************************************************************
 * @File  : diagscreen.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_DIAGSCREEN_HPP
#define APPSAMPLE_DIAGSCREEN_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class DiagScreen : public WrpHmiAppClient
                 , public WrpMidwAppClient
                 , public WrpHmiScreen
{
public:
   DiagScreen(WrpHmiApp* app);
   ~DiagScreen();
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
   DiagScreen(const DiagScreen& cp);
   //members
   WrpHmiApp*        mpHmiApp;
   WrpGui::WrpLabel* mpLblBackItem;
};

#endif /* APPSAMPLE_DIAGSCREEN_HPP */
