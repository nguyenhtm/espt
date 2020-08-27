/********************************************************************************************************
 * @File  : wrpdiagnosis.cpp
 * @Date  : 2020-08-13
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdiagnosis.hpp"
#include "wrpbase/wrpdrv/wrptimer.hpp"
#include "wrpbase/wrpdrv/wrpled.hpp"

namespace WrpSys {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpDiagnosis* WrpDiagnosis::mpInstance = NULL;

/********************************************************************************************************
 * FUNCTIONS - WrpDiagnosis
 ********************************************************************************************************/
WrpDiagnosis* WrpDiagnosis::Instance()
{
   if (mpInstance == NULL)
   {
      mpInstance = new WrpDiagnosis;
   }
   return mpInstance;
}
WrpDiagnosis::WrpDiagnosis()
: WrpDiagHandler(NULL)
{
   WRPPRINT("%s\n", "WrpDiagnosis::WrpDiagnosis() Begin");
   WRPPRINT("%s\n", "WrpDiagnosis::WrpDiagnosis() End");
}
WrpDiagnosis::~WrpDiagnosis()
{
   WRPPRINT("%s\n", "WrpDiagnosis::~WrpDiagnosis() Begin");
   WRPPRINT("%s\n", "WrpDiagnosis::~WrpDiagnosis() End");
}
void WrpDiagnosis::HandleDiagRequest()
{
   WRPPRINT("%s\n", "WrpDiagnosis::HandleDiagRequest() Begin");
   // End of diag request chain
   WRPPRINT("%s\n", "WrpDiagnosis::HandleDiagRequest() End");
}
void WrpDiagnosis::SelfDiagnosis()
{
   WRPPRINT("%s\n", "WrpDiagnosis::SelfDiagnosis() Begin");
   WrpDrv::WrpTimer* timer = new WrpDrv::WrpTimer(mpInstance);
   WrpDrv::WrpLed* led = new WrpDrv::WrpLed(timer);
   led->HandleDiagRequest();
   delete led;
   delete timer;
   WRPPRINT("%s\n", "WrpDiagnosis::SelfDiagnosis() End");
}

} /* Namespace WrpSys */
