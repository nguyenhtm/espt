/********************************************************************************************************
 * @File  : wrpmidw.hpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDW_HPP
#define WRPMIDW_WRPMIDW_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpstoragefactory.hpp"
#include "wrpbase/wrpsys/wrpconnectivity.hpp"
#include "wrpbase/wrpdrv/wrpdiag.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpMidw
class WrpMidw
{
public:
   WrpMidw();
   ~WrpMidw();
   void                                      SetStorage(WrpSys::WrpStorage::WrpStorage* storage);
   void                                      SetConnectivity(WrpSys::WrpConnectivity::WrpConnectivity* connectivity);
   WrpSys::WrpStorage::WrpStorage*           GetStorage() const;
   WrpSys::WrpConnectivity::WrpConnectivity* GetConnectivity() const;

private:
   WrpSys::WrpStorage::WrpStorage*           mpStorage;
   WrpSys::WrpConnectivity::WrpConnectivity* mpConnectivity;
};

#endif /* WRPMIDW_WRPMIDW_HPP */
