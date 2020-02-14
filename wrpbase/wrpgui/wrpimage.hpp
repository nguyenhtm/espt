/********************************************************************************************************
 * @File  : wrpimage.hpp
 * @Date  : 2020-01-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPIMAGE_HPP_
#define WRPGUI_WRPIMAGE_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpwidget.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPRESIMG_BACKGROUND  0x00 //def01background
#define WRPRESIMG_HOME        0x01 //def01home
#define WRPRESIMG_APP         0x02 //def01app
#define WRPRESIMG_SETTING     0x03 //def01setting
#define WRPRESIMG_DIAGNOSIS   0x04 //def01diagnosis
#define WRPRESIMG_AUTOTEST    0x05 //def01autotest
#define WRPRESIMG_WIFI0       0x10 //def01wifi0
#define WRPRESIMG_WIFI1       0x11 //def01wifi1
#define WRPRESIMG_WIFI2       0x12 //def01wifi2
#define WRPRESIMG_LOGO        0x13 //def01logo
#define WRPRESIMG_CFLOWITEM1  0x14 //menuitem1
#define WRPRESIMG_CFLOWITEM2  0x15 //menuitem2
#define WRPRESIMG_CFLOWITEM3  0x16 //menuitem3
#define WRPRESIMG_CFLOWITEM4  0x17 //menuitem4

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpScreen;

// Class WrpImage
class WrpImage : public WrpWidget
{
public:
	WrpImage(WrpScreen* parent=NULL);
	~WrpImage();
	bool LoadImageFromFile(const char* path);
	bool SetImage(const uint16_t imgid);

protected:

private:
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPIMAGE_HPP_ */
