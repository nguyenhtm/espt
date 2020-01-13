/********************************************************************************************************
 * @File  : wrpwidget.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpimage.hpp"
#include "wrpscreen.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpImage::WrpImage(WrpScreen* parent)
: WrpWidget(NULL)
{
	WRPPRINT("%s", "WrpLabel::WrpImage() Begin\n");
	m_pParentScreen = parent;
	if (parent)
	{
		m_pHandler = lv_img_create(parent->m_pHandler, NULL);
	}
	WRPPRINT("%s", "WrpLabel::WrpImage() End\n");
}

WrpImage::~WrpImage()
{
	// m_pHandler shall be deleted by its parent
}

bool WrpImage::LoadImageFromFile(const char* path)
{
    lv_obj_t * img_bin = lv_img_create(m_pHandler, NULL);
    //#if LV_COLOR_DEPTH == 16; Letter=D
    char tmp[255] = {0};
    sprintf(tmp, "D:iotprj/wrpbase/resources/%s", path);
    lv_img_set_src(img_bin, tmp);
    lv_obj_set_drag(img_bin, true);

   return true;
}

} /* WrpGui Namespace */
