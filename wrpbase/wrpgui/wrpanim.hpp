/********************************************************************************************************
 * @File  : wrpanim.hpp
 * @Date  : 2019-12-03
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPANIM_HPP_
#define WRPGUI_WRPANIM_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"
#include "wrpwidget.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpAnim
{
public:
	WrpAnim();
	~WrpAnim();
	void SetWidgets(WrpWidget* pListOfWidgets[], uint16_t size);
	void Barcelona();
	void RealMadrid();
	void Liverpool();
	void Chealse();
	void Messi();

	void FadeIn(const WrpWidget* widget, const uint16_t duration);
	void FadeOut(const WrpWidget* widget, const uint16_t duration);
	void MoveX(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t x2, const uint16_t duration, const bool playback);
	void MoveY(const WrpWidget* widget, const wrpgui_pos_t y1, const wrpgui_pos_t y2, const uint16_t duration, const bool playback);
    void MoveXY(const WrpWidget* widget, const wrpgui_pos_t x1, const wrpgui_pos_t y1, const wrpgui_pos_t x2, const wrpgui_pos_t y2, const uint16_t duration, const bool playback);

protected:

private:
	// members
	WrpWidget** m_pListOfWidgets;
	uint16_t m_NumOfWidgets;
	int32_t  m_x;
	int32_t  m_y;
	uint8_t  m_selected;//0: liverpool, 1: barcelona, 2: real madrid
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPANIM_HPP_ */
