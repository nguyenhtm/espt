/********************************************************************************************************
 * @File  : wrplabel.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrplabel.hpp"
#include "wrpscreen.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpGui {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
WrpLabel::WrpLabel(WrpScreen* parent)
: WrpWidget(NULL)
{
   WRPPRINT("%s\n", "WrpLabel::WrpLabel() Begin");
   mpScreenHandle = parent;
   if (parent)
   {
      mpWidgetHandle = lv_label_create(parent->GetHandle(), NULL);
      lv_obj_set_size(mpWidgetHandle, WRPLABEL_WIDTH, WRPLABEL_HEIGHT);
   }
   WRPPRINT("%s\n", "WrpLabel::WrpLabel() End");
}

WrpLabel::~WrpLabel()
{
   WRPPRINT("%s\n", "WrpLabel::~WrpLabel() Begin");
   WRPNULL_CHECK(mpScreenHandle)
   delete mpWidgetHandle;
   WRPPRINT("%s\n", "WrpLabel::~WrpLabel() End");
}

void WrpLabel::SetText(const char* text)
{
   WRPNULL_CHECK(mpWidgetHandle)
   lv_label_set_text(mpWidgetHandle, text);
}

WrpLabel::WrpLabel()
: WrpWidget(NULL)
{
}

WrpLabel::WrpLabel(const WrpLabel& cp)
: WrpWidget(NULL)
{
}

} /* WrpGui Namespace */
