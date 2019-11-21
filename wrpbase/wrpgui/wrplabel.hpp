/*
 * File  : wrplabel.hpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

#ifndef WRPBASE_WRPGUI_WRPLABEL_HPP_
#define WRPBASE_WRPGUI_WRPLABEL_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPLABEL_WIDTH  100
#define WRPLABEL_HEIGHT 66

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
namespace WrpGui {

class WrpScreen;

class WrpLabel
{
public:
	WrpLabel(WrpScreen* parent=NULL);
	~WrpLabel();

	wrp_pos_t GetX();
	wrp_pos_t GetY();
	wrp_pos_t GetW();
	wrp_pos_t GetH();
	void SetX(const wrp_pos_t x);
	void SetY(const wrp_pos_t y);
	void SetW(const wrp_pos_t w);
	void SetH(const wrp_pos_t h);
	void SetPos(const wrp_pos_t x, const wrp_pos_t y);
	void SetSize(const wrp_pos_t w, const wrp_pos_t h);
	void SetText(const char* text);

protected:
	wrp_handler_t* m_pHandler;

private:
	WrpScreen*     m_pParentScreen;
};

} /* Namespace WrpGui */

#endif /* WRPBASE_WRPGUI_WRPLABEL_HPP_ */
