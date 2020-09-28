/********************************************************************************************************
 * @File  : wrpwidget.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPGUI_WRPWIDGET_HPP
#define WRPGUI_WRPWIDGET_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpgui.hpp"

namespace WrpGui {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward Classes
class WrpScreen;
class WrpStyle;

// Class WrpWidget
class WrpWidget
{
public:
   WrpWidget(WrpScreen* parent);
   virtual ~WrpWidget();
   wrpgui_pos_t  GetX();
   wrpgui_pos_t  GetY();
   wrpgui_size_t GetW();
   wrpgui_size_t GetH();
   void          SetX(const wrpgui_pos_t x);
   void          SetY(const wrpgui_pos_t y);
   void          SetW(const wrpgui_size_t w);
   void          SetH(const wrpgui_size_t h);
   void          SetSize(const wrpgui_size_t w, const wrpgui_size_t h);
   virtual void  SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y);

   WrpScreen*       mpScreenHandle;
   WrpStyle*        mpAppearance;
   wrpgui_handle_t* mpWidgetHandle;

protected:
   WrpWidget();

private:
   WrpWidget(const WrpWidget& cp);
};

// Class WrpDecorator
class WrpDecorator : public WrpWidget
{
public:
   WrpDecorator(WrpWidget*);
   virtual ~WrpDecorator();
   virtual void SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y);
   virtual void MoveX(const wrpgui_pos_t x1, const wrpgui_pos_t x2) const = 0;
   virtual void MoveY(const wrpgui_pos_t y1, const wrpgui_pos_t y2) const = 0;

protected:
   WrpWidget* mpComponent;

private:
   WrpDecorator(const WrpDecorator& cp);
   //members
};

// Class WrpAnimEx
class WrpAnimEx : public WrpDecorator
{
public:
   WrpAnimEx(WrpWidget* component, uint16_t duration);
   ~WrpAnimEx();
   void SetPos(const wrpgui_pos_t x, const wrpgui_pos_t y);
   void MoveX(const wrpgui_pos_t x1, const wrpgui_pos_t x2) const;
   void MoveY(const wrpgui_pos_t y1, const wrpgui_pos_t y2) const;

private:
   WrpAnimEx(const WrpAnimEx& cp);
   // methods

   // members
   uint16_t mDuration;
};

} /* Namespace WrpGui */

#endif /* WRPGUI_WRPWIDGET_HPP */
