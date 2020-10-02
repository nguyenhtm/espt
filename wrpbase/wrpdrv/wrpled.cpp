/********************************************************************************************************
 * @File  : wrpled.cpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpled.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpDrv {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpLed
 ********************************************************************************************************/
WrpLed::WrpLed(WrpDiagHandler* p)
: WrpDiagHandler(p)
{
   WRPPRINT("%s\n", "WrpLed::WrpLed() Begin");
   WRPPRINT("%s\n", "WrpLed::WrpLed() End");
}
WrpLed::~WrpLed()
{
   WRPPRINT("%s\n", "WrpLed::~WrpLed() Begin");
   WRPPRINT("%s\n", "WrpLed::~WrpLed() End");
}
void WrpLed::HandleDiagRequest()
{
   WRPPRINT("%s\n", "WrpLed::HandleDiagRequest() Begin");
   // handle a diag request for led

   WRPPRINT("%s\n", "WrpLed::HandleDiagRequest() End");
   // then forwards to successor
   WrpDiagHandler::HandleDiagRequest();
}
WrpLed::WrpLed(const WrpLed& cp)
: WrpDiagHandler(NULL)
{
}

} /* WrpDrv Namespace */
