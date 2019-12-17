/********************************************************************************************************
 * @File  : wrpwidget.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpwidget.hpp"
#include "wrpscreen.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpWidget::WrpWidget(WrpScreen* parent)
: m_pHandler(NULL)
, m_pParentScreen(parent)
{
	if (parent)
	{
		m_pHandler = lv_obj_create(parent->m_pHandler, NULL);
	}

	m_style.SetStyle(m_pHandler, BUTTON_TGL_RELEASE);
}

WrpWidget::~WrpWidget()
{
}

wrpgui_pos_t WrpWidget::GetX()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_x(m_pHandler);
}

wrpgui_pos_t WrpWidget::GetY()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_y(m_pHandler);
}

wrpgui_size_t WrpWidget::GetW()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_width(m_pHandler);
}

wrpgui_size_t WrpWidget::GetH()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_height(m_pHandler);
}

void WrpWidget::SetX(const wrpgui_pos_t x)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_x(m_pHandler, x);
}

void WrpWidget::SetY(const wrpgui_pos_t y)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_y(m_pHandler, y);
}

void WrpWidget::SetW(const wrpgui_size_t w)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_width(m_pHandler, w);
}

void WrpWidget::SetH(const wrpgui_size_t h)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_height(m_pHandler, h);
}

void WrpWidget::SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_pos(m_pHandler, x, y);
}

void WrpWidget::SetSize(const wrpgui_size_t w, const wrpgui_size_t h)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_size(m_pHandler, w, h);
}

} /* WrpGui Namespace */
