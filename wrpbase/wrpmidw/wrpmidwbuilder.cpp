/********************************************************************************************************
 * @File  : wrpmidwbuilder.cpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpmidwbuilder.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpMidw
 ********************************************************************************************************/
WrpMidw::WrpMidw()
: mpStorage(NULL)
, mpConnectivity(NULL)
, mpDisplay(NULL)
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
void WrpMidw::SetDisplay(WrpSys::WrpDisplay::WrpDisplay* display)
{
   mpDisplay = display;
}
WrpSys::WrpDisplay::WrpDisplay* WrpMidw::GetDisplay() const
{
   return mpDisplay;
}
void WrpMidw::DeInitialize()
{
   WRPPRINT("%s\n", "WrpMidw::DeInitialize() Begin");
   //WRPNULL_CHECK(mpDisplay)
   //mpDisplay->DeInitialize();
   //delete mpDisplay;

   WRPNULL_CHECK(mpConnectivity)
   mpConnectivity->DeInitialize();
   delete mpConnectivity;

   WRPNULL_CHECK(mpStorage)
   mpStorage->DeInitialize();
   delete mpStorage;
   WRPPRINT("%s\n", "WrpMidw::DeInitialize() End");
}

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
void WrpMidwBuilder::BuildDisplay()
{
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildDisplay() Begin");
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildDisplay() End");
}
void WrpMidwBuilder::BuildSystem()
{
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildSystem() Begin");
   WRPPRINT("%s\n", "WrpMidwBuilder::BuildSystem() End");
}
WrpMidwBuilder::WrpMidwBuilder(const WrpMidwBuilder& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpSimpleMidwBuilder
 ********************************************************************************************************/
WrpSysMidwBuilder::WrpSysMidwBuilder()
: mpMidw(NULL)
{
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::WrpSimpleMidwBuilder() Begin");
   mpMidw = new WrpMidw;
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::WrpSimpleMidwBuilder() End");
}
WrpSysMidwBuilder::~WrpSysMidwBuilder()
{
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::~WrpSimpleMidwBuilder() Begin");
   delete mpMidw;
   WRPPRINT("%s\n", "WrpSimpleMidwBuilder::~WrpSimpleMidwBuilder() End");
}
void WrpSysMidwBuilder::BuildStorage()
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
void WrpSysMidwBuilder::BuildConnectivity()
{
   WRPPRINT("%s\n", "SimpleWrpMidwBuilder::BuildConnectivity() Begin");
   WrpSys::WrpConnectivity::WrpConnectivity* connectivity = new WrpSys::WrpConnectivity::WrpConnectivity;
   connectivity->Initialize();
   mpMidw->SetConnectivity(connectivity);
   WRPPRINT("%s\n", "SimpleWrpMidwBuilder::BuildConnectivity() End");
}
WrpMidw* WrpSysMidwBuilder::GetMidw() const
{
   return mpMidw;
}
WrpSysMidwBuilder::WrpSysMidwBuilder(const WrpSysMidwBuilder& cp)
: mpMidw(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpGuiMidwBuilder
 ********************************************************************************************************/
WrpGuiMidwBuilder::WrpGuiMidwBuilder()
: mpMidw(NULL)
{
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::WrpGuiMidwBuilder() Begin");
   mpMidw = new WrpMidw;
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::WrpGuiMidwBuilder() End");
}
WrpGuiMidwBuilder::~WrpGuiMidwBuilder()
{
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::~WrpGuiMidwBuilder() Begin");
   delete mpMidw;
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::~WrpGuiMidwBuilder() End");
}
void WrpGuiMidwBuilder::BuildStorage()
{
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildStorage() Begin");
#if USE_ESP_IDF
   WrpSys::WrpStorage::WrpEspStorage factory;
#elif LVGL_PC_SIMU
   WrpSys::WrpStorage::WrpSimStorage factory;
#endif
   WrpSys::WrpStorage::WrpStorage* storage = new WrpSys::WrpStorage::WrpStorage;
   storage->Initialize(factory);
   mpMidw->SetStorage(storage);
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildStorage() End");
}
void WrpGuiMidwBuilder::BuildConnectivity()
{
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildConnectivity() Begin");
   WrpSys::WrpConnectivity::WrpConnectivity* connectivity = new WrpSys::WrpConnectivity::WrpConnectivity;
   connectivity->Initialize();
   mpMidw->SetConnectivity(connectivity);
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildConnectivity() End");
}
void WrpGuiMidwBuilder::BuildDisplay()
{
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildDisplay() Begin");
   WrpSys::WrpDisplay::WrpDisplay* display = new WrpSys::WrpDisplay::WrpDisplay;
   display->Initialize();
   mpMidw->SetDisplay(display);
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildDisplay() End");
}
void WrpGuiMidwBuilder::BuildSystem()
{
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildSystem() Begin");
   WRPPRINT("%s\n", "WrpGuiMidwBuilder::BuildSystem() End");
}
WrpMidw* WrpGuiMidwBuilder::GetMidw() const
{
   return mpMidw;
}
WrpGuiMidwBuilder::WrpGuiMidwBuilder(const WrpGuiMidwBuilder& cp)
: mpMidw(NULL)
{
}
