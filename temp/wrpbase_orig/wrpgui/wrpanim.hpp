/********************************************************************************************************
 * @File  : wrpanim.hpp
 * @Date  : 2019-12-03
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPANIM_HPP
#define WRPGUI_WRPANIM_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpWidget;

// Class WrpAnim
class WrpAnim
{
public:
   WrpAnim();
   ~WrpAnim();
   void SetWidgets(WrpWidget* widgets[], const uint16_t size);
   void Barcelona();
   void RealMadrid();
   void Liverpool();
   void Chealse();
   void Messi();

   void FadeIn(const WrpWidget* widget, const uint16_t duration);
   void FadeOut(const WrpWidget* widget, const uint16_t duration);
   void MoveX(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t x2, const uint16_t duration, const bool playback);
   void MoveY(const WrpWidget* widget, const wrpgui_pos_t y1, const wrpgui_pos_t y2, const uint16_t duration, const bool playback);
   void MoveXY(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t y1, const wrpgui_pos_t x2, const wrpgui_pos_t y2, const uint16_t duration, const bool playback);

private:
   WrpAnim(const WrpAnim& cp);
   // members
   WrpWidget** mpListOfWidgets;
   uint16_t mNumOfWidgets;
   int32_t  mPosX;
   int32_t  mPosY;
   uint8_t  mSelected;//0: liverpool, 1: barcelona, 2: real madrid
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPANIM_HPP */
