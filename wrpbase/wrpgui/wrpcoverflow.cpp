/********************************************************************************************************
 * @File  : wrpcoverflow.cpp
 * @Date  : 2019-12-03
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpcoverflow.hpp"
#include "wrpbase/wrpbase.hpp"
#include <math.h>

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

WrpCoverFlow::WrpCoverFlow()
{
	WRPPRINT("%s\n", "WrpCoverFlow::WrpCoverFlow() Begin");
	m_x = 140;
	m_y = 20;
	m_w = 30;
	m_h = 30;
	m_xI = 140;
	m_yI = 100;

    WRPPRINT("%s\n", "WrpCoverFlow::WrpCoverFlow() End");
}

WrpCoverFlow::~WrpCoverFlow()
{
	WRPPRINT("%s\n", "WrpCoverFlow::~WrpCoverFlow() Begin");
	WRPPRINT("%s\n", "WrpCoverFlow::~WrpCoverFlow() End");
}

void WrpCoverFlow::SetWidgets(WrpWidget* pListOfWidgets[], uint16_t size)
{
	m_pListOfWidgets = pListOfWidgets;
	m_NumOfWidgets = size;
}

void WrpCoverFlow::Select2()
{
	WRPPRINT("%s\n", "WrpCoverFlow::Select2() Begin");

	m_x = 140;
	m_y = 60;
	m_w = 30;
	m_h = 30;
	m_xI = 140;
	m_yI = 120;

	m_pListOfWidgets[0]->SetPos(m_x, m_y);
	m_pListOfWidgets[0]->SetSize(m_w, m_h);

	for (int i = 1; i < m_NumOfWidgets; i++)
	{
		float alpha = ((2 * 3.14159 * i)/m_NumOfWidgets);
		int32_t x = m_xI + (m_x - m_xI)*cos(alpha) - (m_y - m_yI)*sin(alpha);
		int32_t y = m_yI + (m_x - m_xI)*sin(alpha) + (m_y - m_yI)*cos(alpha);
		m_pListOfWidgets[i]->SetPos(x, y);
		m_pListOfWidgets[i]->SetSize(m_w, m_h);

	}
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		if (i != m_NumOfWidgets-1)
		{
			EnableAnimation2(m_pListOfWidgets[i], m_pListOfWidgets[i+1]);
		}
		else
		{
			EnableAnimation2(m_pListOfWidgets[m_NumOfWidgets-1], m_pListOfWidgets[0]);
		}

	}

    WRPPRINT("%s\n", "WrpCoverFlow::Select2() End");
}

void WrpCoverFlow::Select()
{
	WRPPRINT("%s\n", "WrpCoverFlow::Select() Begin");

	m_x = 10;
	m_y = 40;
	m_w = 30;
	m_h = 30;

	m_pListOfWidgets[0]->SetPos(m_x, m_y);
	m_pListOfWidgets[0]->SetSize(m_w, m_h);

	for (int i = 1; i < m_NumOfWidgets; i++)
	{
		m_pListOfWidgets[i]->SetPos(m_x, m_pListOfWidgets[i-1]->GetY() + m_h + 10);
		m_pListOfWidgets[i]->SetSize(m_w, m_h);
	}

	for (int i = 0; i < m_NumOfWidgets; i++)
	{
		EnableAnimation(m_pListOfWidgets[i],NULL);
		usleep(350*1000);
	}

    WRPPRINT("%s\n", "WrpCoverFlow::Select() End");
}

void WrpCoverFlow::FadeInOut(WrpWidget* widget)
{
	WRPPRINT("%s\n", "WrpCoverFlow::FadeInOut() Begin");
	lv_obj_set_opa_scale_enable(widget->m_pHandler, true);

	lv_anim_t a;
	lv_anim_init(&a);
	lv_anim_set_time(&a, 2000, 0);
	lv_anim_set_values(&a, LV_OPA_TRANSP, LV_OPA_COVER);
	lv_anim_set_exec_cb(&a, widget->m_pHandler, (lv_anim_exec_xcb_t)lv_obj_set_opa_scale);
	lv_anim_create(&a);

	WRPPRINT("%s\n", "WrpCoverFlow::FadeInOut() End");
}

void WrpCoverFlow::Eclipse()
{
	WRPPRINT("%s\n", "WrpCoverFlow::Select2() Begin");

	m_x = 40;
	m_y = 60;

	m_pListOfWidgets[0]->SetPos(m_x, m_y);

	for (int i = 1; i < m_NumOfWidgets; i++)
	{
		m_pListOfWidgets[i]->SetPos(m_x*i, m_y);
	}
	for (int i = 0; i < m_NumOfWidgets; i++)
	{
/*
		if (i != m_NumOfWidgets-1)
		{
			EnableAnimation3(m_pListOfWidgets[i], m_pListOfWidgets[i+1]);
		}
		else
		{

			EnableAnimation3(m_pListOfWidgets[m_NumOfWidgets-1], m_pListOfWidgets[0]);
		}
*/
		EnableAnimation3(m_pListOfWidgets[i]);

	}

    WRPPRINT("%s\n", "WrpCoverFlow::Select2() End");
}

void WrpCoverFlow::EnableAnimation(WrpWidget* cur, WrpWidget* next)
{
	lv_anim_t a;

	// object need to be animated
	a.var = cur->m_pHandler;
	// func to execute anim y
	a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_x;
	a.path_cb = lv_anim_path_linear;
	a.ready_cb = NULL;
	// set start/end value
	a.start = cur->GetX();
	a.end = cur->GetX()+10;
    a.time = 300;
    // make delay
    a.act_time = 0;
    // no play back
    a.playback = 1;
    a.playback_pause = 0;
    // no repeat
    a.repeat = 0;
    a.repeat_pause = 0;
    lv_anim_create(&a);
}

void WrpCoverFlow::EnableAnimation2(WrpWidget* cur, WrpWidget* next)
{
	lv_anim_t a;

	// object need to be animated
	a.var = cur->m_pHandler;
	// func to execute anim y
	a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_x;
	a.path_cb = lv_anim_path_linear;
	a.ready_cb = NULL;
	// set start/end value
	a.start = cur->GetX();
	a.end = next->GetX();
    a.time = 400;
    // make delay
    a.act_time = -600;
    // no play back
    a.playback = 0;
    a.playback_pause = 0;
    // no repeat
    a.repeat = 0;
    a.repeat_pause = 0;
    lv_anim_create(&a);

	a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_y;
	a.start = cur->GetY();
	a.end = next->GetY();
    lv_anim_create(&a);
}


void WrpCoverFlow::EnableAnimation3(WrpWidget* cur)
{
	lv_anim_t a;

	// object need to be animated
	a.var = cur->m_pHandler;
	// func to execute anim y
	a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_x;
	a.path_cb = lv_anim_path_linear;
	a.ready_cb = NULL;
	// set start/end value
	a.start = cur->GetX();
	a.end = cur->GetX()+10;
    a.time = 300;
    // make delay
    a.act_time = 0;
    // no play back
    a.playback = 0;
    a.playback_pause = 0;
    // no repeat
    a.repeat = 0;
    a.repeat_pause = 0;
    lv_anim_create(&a);
}

} /* WrpGui Namespace */
