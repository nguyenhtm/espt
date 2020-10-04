/********************************************************************************************************
 * @File  : wrpmidwbuilder.cpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwbuilder.hpp"
#include "wrpbase/wrpsys/wrpstoragefactory.hpp"
#include "wrpbase/wrpsys/wrpconnectivity.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpMidwBuilder
 ********************************************************************************************************/
WrpMidwBuilder::WrpMidwBuilder()
{
   WRPPRINT("%s\n", "WrpMidwBuilder::WrpMidwBuilder() Begin");
   WRPPRINT("%s\n", "WrpMidwBuilder::WrpMidwBuilder() End");
}
WrpMidwBuilder::~WrpMidwBuilder()
{
   WRPPRINT("%s\n", "WrpMidwBuilder::~WrpMidwBuilder() Begin");
   WRPPRINT("%s\n", "WrpMidwBuilder::~WrpMidwBuilder() End");
}
void WrpMidwBuilder::BuildStorage()
{
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildStorage() Begin");
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildStorage() End");
}
void WrpMidwBuilder::BuildConnectivity()
{
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildConnectivity() Begin");
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildConnectivity() End");
}
void WrpMidwBuilder::BuildSystem()
{
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildSystem() Begin");
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildSystem() End");
}
WrpMidw* WrpMidwBuilder::GetMidw() const
{
   return NULL;
}
WrpMidwBuilder::WrpMidwBuilder(const WrpMidwBuilder& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpSimpleMidwBuilder
 ********************************************************************************************************/
WrpSimpleMidwBuilder::WrpSimpleMidwBuilder()
: WrpMidwBuilder()
, mpMidw(NULL)
{
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::WrpSimpleMidwBuilder() Begin");
   mpMidw = new WrpMidw;
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::WrpSimpleMidwBuilder() End");
}
WrpSimpleMidwBuilder::~WrpSimpleMidwBuilder()
{
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::~WrpSimpleMidwBuilder() Begin");
   delete mpMidw;
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::~WrpSimpleMidwBuilder() End");
}
void WrpSimpleMidwBuilder::BuildStorage()
{
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::BuildStorage() Begin");
#if USE_ESP_IDF
   WrpSys::WrpStorage::WrpEspStorage factory;
#elif LVGL_PC_SIMU
   WrpSys::WrpStorage::WrpSimStorage factory;
#endif
   WrpSys::WrpStorage::WrpStorage* storage = new WrpSys::WrpStorage::WrpStorage;
   storage->Initialize(factory);
   mpMidw->SetStorage(storage);
   WRPPRINT("%s\n", "SimpleWrpMidwBuilder::BuildStorage() End");
}
void WrpSimpleMidwBuilder::BuildConnectivity()
{
   WRPPRINT("%s\n", "SimpleWrpMidwBuilder::BuildConnectivity() Begin");
   WrpSys::WrpConnectivity::WrpConnectivity* connectivity = new WrpSys::WrpConnectivity::WrpConnectivity;
   connectivity->Initialize();
   mpMidw->SetConnectivity(connectivity);
   WRPPRINT("%s\n", "SimpleWrpMidwBuilder::BuildConnectivity() End");
}
WrpMidw* WrpSimpleMidwBuilder::GetMidw() const
{
   return mpMidw;
}
WrpSimpleMidwBuilder::WrpSimpleMidwBuilder(const WrpSimpleMidwBuilder& cp)
: WrpMidwBuilder()
, mpMidw(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpStandardMidwBuilder
 ********************************************************************************************************/
WrpStandardMidwBuilder::WrpStandardMidwBuilder()
: WrpMidwBuilder()
, mpMidw(NULL)
{
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::WrpStandardMidwBuilder() Begin");
   mpMidw = new WrpMidw;
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::WrpStandardMidwBuilder() End");
}
WrpStandardMidwBuilder::~WrpStandardMidwBuilder()
{
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::~WrpGuiMidwBuilder() Begin");
   delete mpMidw;
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::~WrpGuiMidwBuilder() End");
}
void WrpStandardMidwBuilder::BuildStorage()
{
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::BuildStorage() Begin");
#if USE_ESP_IDF
   WrpSys::WrpStorage::WrpEspStorage factory;
#elif LVGL_PC_SIMU
   WrpSys::WrpStorage::WrpSimStorage factory;
#endif
   WrpSys::WrpStorage::WrpStorage* storage = new WrpSys::WrpStorage::WrpStorage;
   storage->Initialize(factory);
   mpMidw->SetStorage(storage);
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::BuildStorage() End");
}
void WrpStandardMidwBuilder::BuildConnectivity()
{
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::BuildConnectivity() Begin");
   WrpSys::WrpConnectivity::WrpConnectivity* connectivity = new WrpSys::WrpConnectivity::WrpConnectivity;
   connectivity->Initialize();
   mpMidw->SetConnectivity(connectivity);
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildConnectivity() End");
}
void WrpStandardMidwBuilder::BuildSystem()
{
   WRPPRINT("%s\n", "WrpStandardMidwBuilder::BuildSystem() Begin");
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildSystem() End");
}
WrpMidw* WrpStandardMidwBuilder::GetMidw() const
{
   return mpMidw;
}
WrpStandardMidwBuilder::WrpStandardMidwBuilder(const WrpStandardMidwBuilder& cp)
: WrpMidwBuilder()
, mpMidw(NULL)
{
}
