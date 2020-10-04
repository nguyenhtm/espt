/********************************************************************************************************
 * @File  : speedometer.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_SPEEDOMETER_HPP
#define APPSAMPLE_SPEEDOMETER_HPP

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
// Forward classes
//class WrpGui::WrpLabel;
//class WrpGui::WrpImage;

class Speedometer : public WrpGui::WrpScreen
{
public:
   /*
    * Constructor
    */
	Speedometer();
   /*
    * Destructor
    */
   ~Speedometer();
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
   void RunSpeedMeter(const uint16_t km);
private:
   /*
    * Default constructor
    */
   Speedometer(const Speedometer& cp);

   // members
   WrpGui::WrpImage* mpMeter;
   WrpGui::WrpImage* mpNeedle;
   WrpGui::WrpLabel* mpLblBackItem;
   int16_t mCurrentSpeed;
   lv_obj_t* mpCanvas;
   lv_color_t *mpCanvasBuf;
   uint16_t mCanvasBufSize;
};

#endif /* APPSAMPLE_SPEEDOMETER_HPP */
