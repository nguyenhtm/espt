/********************************************************************************************************
 * @File  : wrpdiagnosis.hpp
 * @Date  : 2020-08-13
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPDIAGNOSIS_HPP
#define WRPBASE_WRPSYS_WRPDIAGNOSIS_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpdrv/wrpdiag.hpp"

namespace WrpSys {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpDiagnosis facade
class WrpDiagnosis : public WrpDrv::WrpDiagHandler
{
public:
   static WrpDiagnosis* Instance();
   virtual ~WrpDiagnosis();
   void SelfDiagnosis();

protected:
   WrpDiagnosis();

private:
   static WrpDiagnosis* mpInstance;
   void HandleDiagRequest();
};

} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPDIAGNOSIS_HPP */
