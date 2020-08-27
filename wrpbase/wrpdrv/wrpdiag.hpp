/********************************************************************************************************
 * @File  : wrpdiag.hpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPDRV_WRPDIAG_HPP
#define WRPBASE_WRPDRV_WRPDIAG_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

namespace WrpDrv {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpDiagHandler represents a chain of responsibility
class WrpDiagHandler
{
public:
   WrpDiagHandler(WrpDiagHandler* successor);
   virtual ~WrpDiagHandler();
   virtual void HandleDiagRequest();

private:
   WrpDiagHandler(const WrpDiagHandler& cp);
   WrpDiagHandler* mpSuccessor;
};

} /* Namespace WrpDrv */

#endif /* WRPBASE_WRPDRV_WRPTIMER_HPP */
