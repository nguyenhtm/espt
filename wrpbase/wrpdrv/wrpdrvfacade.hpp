/********************************************************************************************************
 * @File  : wrpdrvfacade.hpp
 * @Date  : 2020-09-21
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPDRV_WRPDRVFACADE_HPP
#define WRPBASE_WRPDRV_WRPDRVFACADE_HPP

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
// Class WrpDrvFacade
class WrpDrvFacade
{
public:
   static WrpDrvFacade* Instance();
   virtual ~WrpDrvFacade();
   void DoFastDiagnosis();

private:
   WrpDrvFacade();
   WrpDrvFacade(const WrpDrvFacade& cp);
   // members
   static WrpDrvFacade* mpInstance;
};

} /* Namespace WrpDrv */

#endif /* WRPBASE_WRPDRV_WRPDRVFACADE_HPP */
