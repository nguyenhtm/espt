/********************************************************************************************************
 * @File  : wrpdiag.cpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdiag.hpp"
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpdrv/wrptimer.hpp"
#include "wrpbase/wrpdrv/wrpled.hpp"

namespace WrpDrv {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/
WrpDiagPrototype* WrpDiagManager::mDiagTypes[]={new WrpDiagFast, new WrpDiagFull};

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
   else
   {
      // End of chain
   }
   //WRPPRINT("%s\n", "WrpDiagHandler::HandleDiagRequest() End");
}
WrpDiagHandler::WrpDiagHandler(const WrpDiagHandler& cp)
: mpSuccessor(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpDiagPrototype
 ********************************************************************************************************/
WrpDiagPrototype::WrpDiagPrototype()
{
}
WrpDiagPrototype::~WrpDiagPrototype()
{
}
WrpDiagPrototype::WrpDiagPrototype(const WrpDiagPrototype& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpDiagFast
 ********************************************************************************************************/
WrpDiagFast::WrpDiagFast()
{
}
WrpDiagFast::~WrpDiagFast()
{
}
WrpDiagPrototype* WrpDiagFast::Clone() const
{
   return new WrpDiagFast(*this);
}
void WrpDiagFast::DoDiagnosis() const
{
   WRPPRINT("%s\n", "WrpDiagFast::DoDiagnosis() Begin");
   WrpDrv::WrpTimer* timer = new WrpDrv::WrpTimer(NULL);
   WrpDrv::WrpLed* led = new WrpDrv::WrpLed(timer);
   led->HandleDiagRequest();
   delete led;
   delete timer;
   WRPPRINT("%s\n", "WrpDiagFast::DoDiagnosis() End");
}
WrpDiagFast::WrpDiagFast(const WrpDiagFast& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpDiagFull
 ********************************************************************************************************/
WrpDiagFull::WrpDiagFull()
{
}
WrpDiagFull::~WrpDiagFull()
{
}
WrpDiagPrototype* WrpDiagFull::Clone() const
{
   return new WrpDiagFull(*this);
}
void WrpDiagFull::DoDiagnosis() const
{
   WRPPRINT("%s\n", "WrpDiagFull::DoDiagnosis() Begin");
   WRPPRINT("%s\n", "WrpDiagFull::DoDiagnosis() End");
}
WrpDiagFull::WrpDiagFull(const WrpDiagFull& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpDiagManager
 ********************************************************************************************************/
WrpDiagManager::WrpDiagManager()
{
}
WrpDiagManager::~WrpDiagManager()
{
}
WrpDiagPrototype* WrpDiagManager::MakeDriverDiagnosis(enum WrpDrvDiagType choice)
{
   return mDiagTypes[choice]->Clone();
}
WrpDiagManager::WrpDiagManager(const WrpDiagManager& cp)
{
}

} /* WrpDrv Namespace */
