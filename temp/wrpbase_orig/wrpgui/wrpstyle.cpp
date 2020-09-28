/********************************************************************************************************
 * @File  : wrpstyle.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpstyle.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpStyle::WrpStyle(wrpgui_handle_t* obj)
: mpObjHandle(obj)
{
   WRPPRINT("%s\n", "WrpStyle::WrpStyle(obj) Begin");
   mCurrentStyle = SCREEN_DEFAULT;
   lv_style_copy(&m_style, &lv_style_scr);
   WRPPRINT("%s\n", "WrpStyle::WrpStyle(obj) End");
}

WrpStyle::~WrpStyle()
{
   WRPPRINT("%s\n", "WrpStyle::~WrpStyle() Begin");
   WRPPRINT("%s\n", "WrpStyle::~WrpStyle() End");
}

void WrpStyle::SetStyle(const WrpStyleType& style)
{
   WRPNULL_CHECK(mpObjHandle)
   WRPPRINT("%s%d\n", "WrpStyle::SetStyle() Begin style=", style);
   switch(style)
   {
      case SCREEN_DEFAULT:
      {
         lv_style_copy(&m_style, &lv_style_btn_tgl_rel);
         m_style.body.main_color = LV_COLOR_BLACK;
         m_style.body.grad_color = LV_COLOR_BLACK;
         m_style.body.radius = 0;
         m_style.text.color = LV_COLOR_WHITE;
         break;
      }
      case SCREEN_PLAIN_COLOR:  lv_style_copy(&m_style, &lv_style_plain_color); break;
      case SCREEN_PRETTY:       lv_style_copy(&m_style, &lv_style_pretty); break;
      case SCREEN_PRETTY_COLOR: lv_style_copy(&m_style, &lv_style_pretty_color); break;
      case BUTTON_PRESS:        lv_style_copy(&m_style, &lv_style_btn_pr); break;
      case BUTTON_RELEASE:      lv_style_copy(&m_style, &lv_style_btn_rel); break;
      case BUTTON_TGL_PRESS:    lv_style_copy(&m_style, &lv_style_btn_tgl_pr); break;
      case BUTTON_TGL_RELEASE:  lv_style_copy(&m_style, &lv_style_btn_tgl_rel); break;
      default:                  lv_style_copy(&m_style, &lv_style_scr); break;
   }
   lv_obj_set_style(mpObjHandle, &m_style);
   mCurrentStyle = style;
   WRPPRINT("%s%d\n", "WrpStyle::SetStyle() End style=", style);
}

void WrpStyle::SetDefaultStyle()
{
   WRPNULL_CHECK(mpObjHandle)
   WRPPRINT("%s\n", "WrpStyle::SetDefaultStyle() Begin");
   SetStyle(SCREEN_DEFAULT);
   WRPPRINT("%s\n", "WrpStyle::SetDefaultStyle() End");
}

WrpStyle::WrpStyle()
: mpObjHandle(NULL)
, mCurrentStyle(SCREEN_DEFAULT)
{
}

WrpStyle::WrpStyle(const WrpStyle& cp)
: mpObjHandle(NULL)
, mCurrentStyle(SCREEN_DEFAULT)
{
}

} /* WrpGui Namespace */
