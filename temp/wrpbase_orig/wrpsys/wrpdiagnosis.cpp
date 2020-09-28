/********************************************************************************************************
 * @File  : wrpdiagnosis.cpp
 * @Date  : 2020-08-13
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpdiagnosis.hpp"

namespace WrpSys {
namespace WrpDiagnosis {

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
{
   WRPPRINT("%s\n", "WrpDiagnosis::WrpDiagnosis() Begin");
   WRPPRINT("%s\n", "WrpDiagnosis::WrpDiagnosis() End");
}
WrpDiagnosis::~WrpDiagnosis()
{
   WRPPRINT("%s\n", "WrpDiagnosis::~WrpDiagnosis() Begin");
   WRPPRINT("%s\n", "WrpDiagnosis::~WrpDiagnosis() End");
}
void WrpDiagnosis::SelfDiagnosis()
{
   WRPPRINT("%s\n", "WrpDiagnosis::SelfDiagnosis() Begin");

   WRPPRINT("%s\n", "WrpDiagnosis::SelfDiagnosis() End");
}

} /* Namespace WrpDiagnosis */
} /* Namespace WrpSys */
