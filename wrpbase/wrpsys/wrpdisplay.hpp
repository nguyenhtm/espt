/********************************************************************************************************
 * @File  : wrpdisplay.hpp
 * @Date  : 2020-08-20
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPDISPLAY_HPP
#define WRPBASE_WRPSYS_WRPDISPLAY_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

namespace WrpSys {
namespace WrpDisplay {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpDisplay
{
public:
   WrpDisplay();
   ~WrpDisplay();
   void Initialize();
   void DeInitialize();

private:
   WrpDisplay(const WrpDisplay& cp);
};

} /* Namespace WrpDisplay */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPDISPLAY_HPP */