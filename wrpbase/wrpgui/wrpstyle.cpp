/*
 * File  : wrpstyle.cpp
 * Date  : 2019-10-06
 * Author: nguyenhtm - htminhnguyen@yahoo.com
 */

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpstyle.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpGui
{

WrpStyle::WrpStyle()
{
	WRPPRINT("%s\n", "WrpStyle::WrpStyle() Begin");
	lv_style_copy(&m_style, &lv_style_scr);
	lv_style_copy(&m_default, &lv_style_scr);
    WRPPRINT("%s\n", "WrpScreen::WrpScreen() End");
}

WrpStyle::~WrpStyle()
{
	WRPPRINT("%s\n", "WrpStyle::~WrpStyle() Begin");
	WRPPRINT("%s\n", "WrpStyle::~WrpStyle() End");
}

void WrpStyle::SetStyle(wrp_handler_t* handler, WrpStyleType style)
{
	WRPNULL_CHECK(handler)
	switch(style)
	{
		case SCREEN_DEFAULT:
		{
			lv_style_copy(&m_style, &lv_style_scr);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		case SCREEN_PLAIN_COLOR:
		{
			lv_style_copy(&m_style, &lv_style_plain_color);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		case SCREEN_PRETTY:
		{
			lv_style_copy(&m_style, &lv_style_pretty);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		case SCREEN_PRETTY_COLOR:
		{
			lv_style_copy(&m_style, &lv_style_pretty_color);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		case BUTTON_PRESS:
		{
			lv_style_copy(&m_style, &lv_style_btn_pr);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		case BUTTON_RELEASE:
		{
			lv_style_copy(&m_style, &lv_style_btn_rel);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		case BUTTON_TGL_PRESS:
		{
			lv_style_copy(&m_style, &lv_style_btn_tgl_pr);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		case BUTTON_TGL_RELEASE:
		{
			lv_style_copy(&m_style, &lv_style_btn_tgl_rel);
			lv_obj_set_style(handler, &m_style);
		}
		break;
		default:
		{
			lv_obj_set_style(handler, &m_default);
		}
	}
}

void WrpStyle::SetDefault(wrp_handler_t* handler)
{
	WRPNULL_CHECK(handler)
	lv_obj_set_style(handler, &m_default);
}

} /* WrpGui Namespace */