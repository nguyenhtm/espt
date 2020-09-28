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

namespace WrpSys {
namespace WrpDiagnosis {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpDiagnosis facade
class WrpDiagnosis
{
public:
   static WrpDiagnosis* Instance();
   virtual ~WrpDiagnosis();
   void SelfDiagnosis();

protected:
   WrpDiagnosis();

private:
   static WrpDiagnosis* mpInstance;
};


} /* Namespace WrpDiagnosis */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPDIAGNOSIS_HPP */
