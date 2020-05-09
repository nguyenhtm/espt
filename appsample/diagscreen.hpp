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
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Forward classes
class WrpGui::WrpLabel;
class WrpGui::WrpImage;

// Class DiagScreen
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
   void RunSpeedMeter(const uint16_t km);
   //members
   WrpHmiApp*        mpHmiApp;
   WrpGui::WrpImage* mpMeter;
   WrpGui::WrpImage* mpNeedle;
   WrpGui::WrpLabel* mpLblBackItem;
   int16_t mCurrentSpeed;
   lv_obj_t* mpCanvas;
   lv_color_t *mpCanvasBuf;
   uint16_t mCanvasBufSize;
};

#endif /* APPSAMPLE_DIAGSCREEN_HPP */
