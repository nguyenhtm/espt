/********************************************************************************************************
 * @File  : wrpdiag.cpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdiag.hpp"

namespace WrpDrv {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpDiagHandler
 ********************************************************************************************************/
WrpDiagHandler::WrpDiagHandler(WrpDiagHandler* successor)
: mpSuccessor(successor)
{
   WRPPRINT("%s\n", "WrpDiagHandler::WrpDiagHandler() Begin");
   WRPPRINT("%s\n", "WrpDiagHandler::WrpDiagHandler() End");
}

WrpDiagHandler::~WrpDiagHandler()
{
   WRPPRINT("%s\n", "WrpDiagHandler::~WrpDiagHandler() Begin");
   WRPPRINT("%s\n", "WrpDiagHandler::~WrpDiagHandler() End");
}
void WrpDiagHandler::HandleDiagRequest()
{
   //WRPPRINT("%s\n", "WrpDiagHandler::HandleDiagRequest() Begin");
   if (mpSuccessor)
   {
      mpSuccessor->HandleDiagRequest();
   }
   //WRPPRINT("%s\n", "WrpDiagHandler::HandleDiagRequest() End");
}
WrpDiagHandler::WrpDiagHandler(const WrpDiagHandler& cp)
: mpSuccessor(NULL)
{
}

} /* WrpDrv Namespace */
