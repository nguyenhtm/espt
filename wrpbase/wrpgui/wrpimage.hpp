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

protected:

private:

};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPIMAGE_HPP_ */
