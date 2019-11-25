/********************************************************************************************************
 * @File  : wrpgui.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpGui::WrpGui()
: m_pHandler(NULL)
{
}

WrpGui::~WrpGui()
{
}

wrpgui_pos_t WrpGui::GetX()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_x(m_pHandler);
}

wrpgui_pos_t WrpGui::GetY()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_y(m_pHandler);
}

wrpgui_size_t WrpGui::GetW()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_width(m_pHandler);
}

wrpgui_size_t WrpGui::GetH()
{
	WRPNULL_CHECKRET(m_pHandler)
	return lv_obj_get_height(m_pHandler);
}

void WrpGui::SetX(const wrpgui_pos_t x)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_x(m_pHandler, x);
}

void WrpGui::SetY(const wrpgui_pos_t y)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_y(m_pHandler, y);
}

void WrpGui::SetW(const wrpgui_size_t w)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_width(m_pHandler, w);
}

void WrpGui::SetH(const wrpgui_size_t h)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_height(m_pHandler, h);
}

void WrpGui::SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_pos(m_pHandler, x, y);
}

void WrpGui::SetSize(const wrpgui_size_t w, const wrpgui_size_t h)
{
	WRPNULL_CHECK(m_pHandler)
	lv_obj_set_size(m_pHandler, w, h);
}

} /* WrpGui Namespace */
