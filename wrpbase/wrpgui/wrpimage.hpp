/********************************************************************************************************
 * @File  : wrpimage.hpp
 * @Date  : 2020-01-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPIMAGE_HPP
#define WRPGUI_WRPIMAGE_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpwidget.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPRESIMG_BACKGROUND     0x00 //def01background
#define WRPRESIMG_DEF01HOME      0x01 //def01home
#define WRPRESIMG_DEF01APP       0x02 //def01app
#define WRPRESIMG_DEF01SETTING   0x03 //def01setting
#define WRPRESIMG_DEF01DIAGNOSIS 0x04 //def01diagnosis
#define WRPRESIMG_DEF01AUTOTEST  0x05 //def01autotest
#define WRPRESIMG_DEF01WIFI0     0x10 //def01wifi0
#define WRPRESIMG_DEF01WIFI1     0x11 //def01wifi1
#define WRPRESIMG_DEF01WIFI2     0x12 //def01wifi2
#define WRPRESIMG_DEF01LOGO      0x13 //def01logo
#define WRPRESIMG_DEF01MENUITEM1 0x14 //def01menuitem1
#define WRPRESIMG_DEF01MENUITEM2 0x15 //def01menuitem2
#define WRPRESIMG_DEF01MENUITEM3 0x16 //def01menuitem3
#define WRPRESIMG_DEF01MENUITEM4 0x17 //def01menuitem4
#define WRPRESIMG_DEF01MENUITEM5 0x18 //def01menuitem5
#define WRPRESIMG_DEF01METER     0x19 //def01meter
#define WRPRESIMG_DEF01NEEDLE    0x1A //def01needle

#define WRPRESIMG_METER_NEEDLE1 0x1B
#define WRPRESIMG_METER1_0      0x1C
#define WRPRESIMG_METER1_1      0x1D
#define WRPRESIMG_METER1_2      0x1E
#define WRPRESIMG_METER1_3      0x1F


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpScreen;

// Class WrpImage
class WrpImage : public WrpWidget
{
public:
   WrpImage(WrpScreen* parent);
   ~WrpImage();
   bool LoadImageFromFile(const char* path);
   bool SetImage(const uint16_t imgid);
   void SetHide();
   void SetShow();
   void SetTop();

private:
   WrpImage();
   WrpImage(const WrpImage& cp);
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPIMAGE_HPP */
