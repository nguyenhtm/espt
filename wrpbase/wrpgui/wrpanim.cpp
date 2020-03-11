/********************************************************************************************************
 * @File  : wrpanim.cpp
 * @Date  : 2019-12-03
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpanim.hpp"
#include "wrpbase/wrpbase.hpp"
#include <math.h>

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpAnim::WrpAnim()
: m_selected(0)
{
	WRPPRINT("%s\n", "WrpAnim::WrpAnim() Begin");

    WRPPRINT("%s\n", "WrpAnim::WrpAnim() End");
}

WrpAnim::~WrpAnim()
{
	WRPPRINT("%s\n", "WrpAnim::~WrpAnim() Begin");

	WRPPRINT("%s\n", "WrpAnim::~WrpAnim() End");
}

void WrpAnim::SetWidgets(WrpWidget* pListOfWidgets[], uint16_t size)
{
	m_pListOfWidgets = pListOfWidgets;
	m_NumOfWidgets = size;
}

void WrpAnim::Liverpool()
{
	WRPPRINT("%s\n", "WrpAnim::Liverpool() Begin");
	static int flag = 0;
	m_x = 140; m_y = 60;
	wrpgui_pos_t _xI = 140;
	wrpgui_pos_t _yI = 120;
	if (m_selected)
	{
		m_pListOfWidgets[0]->SetPos(m_x, m_y);
	}
	else if (!flag)
	{
		m_pListOfWidgets[0]->SetPos(m_x, m_y);
		flag = ~flag;
	}

	for (int i = 1; i < m_NumOfWidgets; i++)
	{
		float alpha = ((2 * 3.14159 * i)/m_NumOfWidgets);
		int32_t x = _xI + (m_pListOfWidgets[0]->GetX() - _xI)*cos(alpha) - (m_pListOfWidgets[0]->GetY() - _yI)*sin(alpha);
		int32_t y = _yI + (m_pListOfWidgets[0]->GetX() - _xI)*sin(alpha) + (m_pListOfWidgets[0]->GetY() - _yI)*cos(alpha);
		m_pListOfWidgets[i]->SetPos(x, y);
	}
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		if (i != m_NumOfWidgets-1)
		{
			MoveXY(m_pListOfWidgets[i], m_pListOfWidgets[i]->GetX(), m_pListOfWidgets[i]->GetY(), m_pListOfWidgets[i+1]->GetX(), m_pListOfWidgets[i+1]->GetY(), 400, false);
		}
		else
		{
			MoveXY(m_pListOfWidgets[m_NumOfWidgets-1], m_pListOfWidgets[m_NumOfWidgets-1]->GetX(), m_pListOfWidgets[m_NumOfWidgets-1]->GetY(), m_pListOfWidgets[0]->GetX(), m_pListOfWidgets[0]->GetY(), 400, false);
		}
	}

	WrpWidget* tmp = m_pListOfWidgets[0];
	for (int i = 0; i < m_NumOfWidgets-1; i++)
	{
		m_pListOfWidgets[i] = m_pListOfWidgets[i+1];
	}
	m_pListOfWidgets[m_NumOfWidgets-1] = tmp;

	m_selected = 0;
    WRPPRINT("%s\n", "WrpCoverFlow::Liverpool() End");
}

void WrpAnim::Barcelona()
{
	WRPPRINT("%s\n", "WrpAnim::Barcelona() Begin");
    // set start position of list of widgets
	m_x = 10; m_y = 40;
	m_pListOfWidgets[0]->SetPos(m_x, m_y);
	for (int i = 1; i < m_NumOfWidgets; i++)
	{
		m_pListOfWidgets[i]->SetPos(m_x, m_pListOfWidgets[i-1]->GetY() + 40);
	}
    // do Barcelona animation type
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		MoveX(m_pListOfWidgets[i], m_pListOfWidgets[i]->GetX(), m_pListOfWidgets[i]->GetX() + 10, 300, true);
		usleep(350*1000);
	}
	m_selected = 1;
    WRPPRINT("%s\n", "WrpAnim::Barcelona() End");
}

void WrpAnim::RealMadrid()
{
	WRPPRINT("%s\n", "WrpAnim::RealMadrid() Begin");
	// set start position of list of widgets
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		m_pListOfWidgets[i]->SetPos((320/m_NumOfWidgets)*i + 10, m_y + 20);
	}
	// do Real Madrid animation type
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		MoveY(m_pListOfWidgets[i], m_pListOfWidgets[i]->GetY(), m_pListOfWidgets[i]->GetY()+80, 1000, true);
		usleep(350*1000);
	}
	m_selected = 2;
    WRPPRINT("%s\n", "WrpAnim::RealMadrid() End");
}

void WrpAnim::Chealse()
{
	WRPPRINT("%s\n", "WrpAnim::Chealse() Begin");
	// set start position of list of widgets
	m_x = 40; m_y = 80;
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		m_pListOfWidgets[i]->SetPos(m_x, m_y);
	}
	// do Chealse animation type
	for (int i = m_NumOfWidgets-1; i > 0; i--)
	{
		MoveX(m_pListOfWidgets[i], m_pListOfWidgets[0]->GetX(), m_pListOfWidgets[0]->GetX() + 40*i, 150*i, false);
		usleep(350*1000);
	}
	m_selected = 3;
    WRPPRINT("%s\n", "WrpAnim::Chealse() End");
}

void WrpAnim::Messi()
{
	WRPPRINT("%s\n", "WrpAnim::Messi() Begin");
	m_x = 140; m_y = 60;
	wrpgui_pos_t _xI = 140, _yI = 120;

	// move to circle positions
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		m_pListOfWidgets[i]->SetPos(_xI, _yI);
	}
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		float alpha = ((2 * 3.14159 * i)/m_NumOfWidgets);
		int32_t x = _xI + (m_x - _xI)*cos(alpha) - (m_y - _yI)*sin(alpha);
		int32_t y = _yI + (m_x - _xI)*sin(alpha) + (m_y - _yI)*cos(alpha);
		MoveXY(m_pListOfWidgets[i], m_pListOfWidgets[i]->GetX(), m_pListOfWidgets[i]->GetY(), x, y, 500, false);
	}
	usleep(2000*1000);

	// rotate
	Liverpool();
	usleep(2000*1000);
	Liverpool();
	usleep(2000*1000);

	// move to center
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		MoveXY(m_pListOfWidgets[i], m_pListOfWidgets[i]->GetX(), m_pListOfWidgets[i]->GetY(), _xI, _yI, 500, false);
	}
	usleep(2000*1000);

	// move to RealMadrid
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		MoveXY(m_pListOfWidgets[i], m_pListOfWidgets[i]->GetX(), m_pListOfWidgets[i]->GetY(), (320/m_NumOfWidgets)*i + 10, 80, 500, false);
	}
	usleep(2000*1000);
	RealMadrid();

	m_selected = 4;
    WRPPRINT("%s\n", "WrpAnim::Messi() End");
}

void WrpAnim::FadeIn(const WrpWidget* widget, const uint16_t duration)
{
	WRPPRINT("%s\n", "WrpAnim::FadeIn() Begin");
	lv_obj_set_opa_scale_enable(widget->m_pHandler, true);
	lv_anim_t anim;
	lv_anim_init(&anim);
	lv_anim_set_time(&anim, duration, 0);
	lv_anim_set_values(&anim, LV_OPA_TRANSP, LV_OPA_COVER);
	lv_anim_set_exec_cb(&anim, widget->m_pHandler, (lv_anim_exec_xcb_t)lv_obj_set_opa_scale);
	lv_anim_create(&anim);
	WRPPRINT("%s\n", "WrpAnim::FadeIn() End");
}

void WrpAnim::FadeOut(const WrpWidget* widget, const uint16_t duration)
{
	WRPPRINT("%s\n", "WrpAnim::FadeOut() Begin");
	lv_obj_set_opa_scale_enable(widget->m_pHandler, true);
	lv_anim_t anim;
	lv_anim_init(&anim);
	lv_anim_set_time(&anim, duration, 0);
	lv_anim_set_values(&anim, LV_OPA_TRANSP, LV_OPA_COVER);
	lv_anim_set_exec_cb(&anim, widget->m_pHandler, (lv_anim_exec_xcb_t)lv_obj_set_opa_scale);
	lv_anim_create(&anim);
	WRPPRINT("%s\n", "WrpAnim::FadeOut() End");
}

void WrpAnim::MoveX(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t x2, const uint16_t duration, const bool playback)
{
	WRPPRINT("%s\n", "WrpAnim::MoveX() Begin");
	lv_anim_t anim;
	lv_anim_init(&anim);
	lv_anim_set_time(&anim, duration, 0);
	lv_anim_set_playback(&anim, 0);
	lv_anim_set_values(&anim, x1, x2);
	lv_anim_set_exec_cb(&anim, widget->m_pHandler, (lv_anim_exec_xcb_t)lv_obj_set_x);
	playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
	lv_anim_create(&anim);
	WRPPRINT("%s\n", "WrpAnim::MoveX() End");
}

void WrpAnim::MoveY(const WrpWidget* widget, const wrpgui_pos_t y1, const wrpgui_pos_t y2, const uint16_t duration, const bool playback)
{
	WRPPRINT("%s\n", "WrpAnim::MoveY() Begin");
	lv_anim_t anim;
	lv_anim_init(&anim);
	lv_anim_set_time(&anim, duration, 0);
	lv_anim_set_values(&anim, y1, y2);
	lv_anim_set_exec_cb(&anim, widget->m_pHandler, (lv_anim_exec_xcb_t)lv_obj_set_y);
	playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
	lv_anim_create(&anim);
	WRPPRINT("%s\n", "WrpAnim::MoveY() End");
}

void WrpAnim::MoveXY(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t y1, const wrpgui_pos_t x2, const wrpgui_pos_t y2, const uint16_t duration, const bool playback)
{
	WRPPRINT("%s\n", "WrpAnim::MoveXY() Begin");
	lv_anim_t anim;
	lv_anim_init(&anim);
	lv_anim_set_time(&anim, duration, 0);

	lv_anim_set_values(&anim, x1, x2);
	lv_anim_set_exec_cb(&anim, widget->m_pHandler, (lv_anim_exec_xcb_t)lv_obj_set_x);
	lv_anim_create(&anim);

	lv_anim_set_values(&anim, y1, y2);
	lv_anim_set_exec_cb(&anim, widget->m_pHandler, (lv_anim_exec_xcb_t)lv_obj_set_y);
	lv_anim_create(&anim);

	playback == true ? lv_anim_set_playback(&anim, 0) : lv_anim_clear_playback(&anim);
	lv_anim_create(&anim);
	WRPPRINT("%s\n", "WrpAnim::MoveXY() End");
}

} /* WrpGui Namespace */
