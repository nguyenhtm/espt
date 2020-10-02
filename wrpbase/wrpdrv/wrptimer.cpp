/********************************************************************************************************
 * @File  : wrptimer.cpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrptimer.hpp"
#include "wrpbase/wrpbase.hpp"

namespace WrpDrv {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpTimer
 ********************************************************************************************************/
WrpTimer::WrpTimer(WrpDiagHandler* p)
: WrpDiagHandler(p)
{
   WRPPRINT("%s\n", "WrpTimer::WrpTimer() Begin");
   WRPPRINT("%s\n", "WrpTimer::WrpTimer() End");
}

WrpTimer::~WrpTimer()
{
   WRPPRINT("%s\n", "WrpTimer::~WrpTimer() Begin");
   WRPPRINT("%s\n", "WrpTimer::~WrpTimer() End");
}

void WrpTimer::HandleDiagRequest()
{
   WRPPRINT("%s\n", "WrpTimer::HandleDiagRequest() Begin");
   // handle a diag request for timer
   WRPPRINT("%s\n", "WrpTimer::HandleDiagRequest() End");
   // then forwards to successor
   WrpDiagHandler::HandleDiagRequest();
}

WrpTimer::WrpTimer(const WrpTimer& cp)
: WrpDiagHandler(NULL)
{
}

} /* WrpDrv Namespace */
