/********************************************************************************************************
 * @File  : wrplabel.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrplabel.hpp"
#include "wrpscreen.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpLabel::WrpLabel(WrpScreen* parent)
: m_pParentScreen(parent)
{
	WRPPRINT("%s", "WrpLabel::WrpLabel() Begin\n");
	if (parent)
	{
		m_pHandler = lv_label_create(parent->m_pHandler, NULL);
	}
	else
	{
		// this label is a child of current loaded screen
		m_pHandler = lv_label_create(lv_disp_get_scr_act(NULL), NULL);
	}
	lv_obj_set_size(m_pHandler, WRPLABEL_WIDTH, WRPLABEL_HEIGHT);
	WRPPRINT("%s", "WrpLabel::WrpLabel() End\n");
}

WrpLabel::~WrpLabel()
{
	// m_pHandler shall be deleted by its parent
}

void WrpLabel::SetText(const char* text)
{
	WRPNULL_CHECK(m_pHandler)
	lv_label_set_text(m_pHandler, text);
}

} /* WrpGui Namespace */
