/********************************************************************************************************
 * @File  : wrplabel.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrplabel.hpp"
#include "wrpscreen.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

// WrpLabel Class Methods

WrpLabel::WrpLabel(WrpScreen* parent)
: m_pHandler(NULL)
, m_pParentScreen(parent)
{
	WRPPRINT("%s", "WrpLabel::WrpLabel() Begin\n");
	if (parent)
	{
		m_pHandler = lv_label_create(m_pParentScreen->GetProperty()._pHandler, NULL);
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
	// screen m_parent will destroy all its members
}

wrp_pos_t WrpLabel::GetX()
{
	//WRPCHECK_NULL(m_pHandler)
	return lv_obj_get_x(m_pHandler);
}

wrp_pos_t WrpLabel::GetY()
{
	//WRPCHECK_NULL(m_pHandler)
	return lv_obj_get_y(m_pHandler);
}

wrp_pos_t WrpLabel::GetW()
{
	//WRPCHECK_NULL(m_pHandler)
	return lv_obj_get_width(m_pHandler);
}

wrp_pos_t WrpLabel::GetH()
{
	//WRPCHECK_NULL(m_pHandler)
	return lv_obj_get_height(m_pHandler);
}

void WrpLabel::SetX(const wrp_pos_t x)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_x(m_pHandler, x);
}

void WrpLabel::SetY(const wrp_pos_t y)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_y(m_pHandler, y);
}

void WrpLabel::SetW(const wrp_pos_t w)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_width(m_pHandler, w);
}

void WrpLabel::SetH(const wrp_pos_t h)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_height(m_pHandler, h);
}

void WrpLabel::SetPos(const wrp_pos_t x, const wrp_pos_t y)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_pos(m_pHandler, x, y);
}

void WrpLabel::SetSize(const wrp_pos_t w, const wrp_pos_t h)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_size(m_pHandler, w, h);
}

void WrpLabel::SetText(const char* text)
{
	WRPNULL_CHECK(m_pHandler)
	lv_label_set_text(m_pHandler, text);
}

} /* WrpGui Namespace */
