/********************************************************************************************************
 * @File  : wrpmidwbuilder.cpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidw.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpMidw
 ********************************************************************************************************/
WrpMidw::WrpMidw()
: mpStorage(NULL)
, mpConnectivity(NULL)
{
   WRPPRINT("%s\n", "WrpMidw::WrpMidw() Begin");
   WRPPRINT("%s\n", "WrpMidw::WrpMidw() End");
}
WrpMidw::~WrpMidw()
{
   WRPPRINT("%s\n", "WrpMidw::~WrpMidw() Begin");
   WRPPRINT("%s\n", "WrpMidw::~WrpMidw() End");
}
void WrpMidw::SetStorage(WrpSys::WrpStorage::WrpStorage* storage)
{
   mpStorage = storage;
}
WrpSys::WrpStorage::WrpStorage* WrpMidw::GetStorage() const
{
   return mpStorage;
}
void WrpMidw::SetConnectivity(WrpSys::WrpConnectivity::WrpConnectivity* connectivity)
{
   mpConnectivity = connectivity;
}
WrpSys::WrpConnectivity::WrpConnectivity* WrpMidw::GetConnectivity() const
{
   return mpConnectivity;
}

