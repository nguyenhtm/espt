/********************************************************************************************************
 * @File  : wrptimer.hpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPDRV_WRPTIMER_HPP
#define WRPBASE_WRPDRV_WRPTIMER_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpdiag.hpp"

namespace WrpDrv {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class WrpTimer : public WrpDiagHandler
{
public:
   WrpTimer(WrpDiagHandler* p);
   virtual ~WrpTimer();
   void HandleDiagRequest();

private:
   WrpTimer(const WrpTimer& cp);
};

} /* Namespace WrpDrv */

#endif /* WRPBASE_WRPDRV_WRPTIMER_HPP */
