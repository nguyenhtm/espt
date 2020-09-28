/********************************************************************************************************
 * @File  : wrpdrvfacade.cpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdrvfacade.hpp"
#include "wrpdiag.hpp"

namespace WrpDrv {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpDrvFacade* WrpDrvFacade::mpInstance = NULL;

/********************************************************************************************************
 * FUNCTIONS - WrpDrvFacade
 ********************************************************************************************************/
WrpDrvFacade* WrpDrvFacade::Instance()
{
   if (mpInstance == NULL)
   {
      mpInstance = new WrpDrvFacade;
   }
   return mpInstance;
}
WrpDrvFacade::WrpDrvFacade()
{
   WRPPRINT("%s\n", "WrpDrvFacade::WrpDrvFacade() Begin");
   WRPPRINT("%s\n", "WrpDrvFacade::WrpDrvFacade() End");
}
WrpDrvFacade::~WrpDrvFacade()
{
   WRPPRINT("%s\n", "WrpDrvFacade::~WrpDrvFacade() Begin");
   WRPPRINT("%s\n", "WrpDrvFacade::~WrpDrvFacade() End");
}
void WrpDrvFacade::DoFastDiagnosis()
{
   WRPPRINT("%s\n", "WrpDrvFacade::DoFastDiagnosis() Begin");
   WrpDiagPrototype* diag = WrpDiagManager::MakeDriverDiagnosis(DIAGTYPE_FAST);
   diag->DoDiagnosis();
   delete diag;
   WRPPRINT("%s\n", "WrpDrvFacade::DoFastDiagnosis() End");
}
WrpDrvFacade::WrpDrvFacade(const WrpDrvFacade& cp)
{
}

} /* WrpDrv Namespace */
