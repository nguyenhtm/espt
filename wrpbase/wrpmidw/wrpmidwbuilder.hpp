/********************************************************************************************************
 * @File  : wrpmidwbuilder.hpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWBUILDER_HPP
#define WRPMIDW_WRPMIDWBUILDER_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpstoragefactory.hpp"
#include "wrpbase/wrpsys/wrpconnectivity.hpp"
#include "wrpbase/wrpsys/wrpdiagnosis.hpp"
#include "wrpbase/wrpsys/wrpdisplay.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Forward classes
//class WrpSys::WrpStorage::WrpNvs;
//class WrpSys::WrpStorage::WrpSpiffs;
//class WrpSys::WrpStorage::WrpSdCard;

// Class WrpMidw
class WrpMidw
{
public:
   WrpMidw();
   ~WrpMidw();
   void SetStorage(WrpSys::WrpStorage::WrpStorage* storage);
   void SetConnectivity(WrpSys::WrpConnectivity::WrpConnectivity* connectivity);
   void SetDisplay(WrpSys::WrpDisplay::WrpDisplay* display);
   WrpSys::WrpStorage::WrpStorage* GetStorage() const;
   WrpSys::WrpConnectivity::WrpConnectivity* GetConnectivity() const;
   WrpSys::WrpDisplay::WrpDisplay* GetDisplay() const;
   void DeInitialize();

private:
   WrpSys::WrpStorage::WrpStorage*           mpStorage;
   WrpSys::WrpConnectivity::WrpConnectivity* mpConnectivity;
   WrpSys::WrpDisplay::WrpDisplay*           mpDisplay;
};

// Class WrpMidwBuilder
class WrpMidwBuilder
{
public:
   WrpMidwBuilder();
   virtual ~WrpMidwBuilder();
   virtual void BuildStorage();
   virtual void BuildConnectivity();
   virtual void BuildDisplay();
   virtual void BuildSystem();
   virtual WrpMidw* GetMidw() const { return 0; }

private:
   WrpMidwBuilder(const WrpMidwBuilder& cp);
};

// Class WrpSysMidwBuilder
class WrpSysMidwBuilder : public WrpMidwBuilder
{
public:
   WrpSysMidwBuilder();
   ~WrpSysMidwBuilder();
   virtual void BuildStorage();
   virtual void BuildConnectivity();
   virtual WrpMidw* GetMidw() const;

private:
   WrpSysMidwBuilder(const WrpSysMidwBuilder& cp);
   // members
   WrpMidw* mpMidw;
};

// Class WrpGuiMidwBuilder
class WrpGuiMidwBuilder : public WrpMidwBuilder
{
public:
   WrpGuiMidwBuilder();
   ~WrpGuiMidwBuilder();
   virtual void BuildStorage();
   virtual void BuildConnectivity();
   virtual void BuildDisplay();
   virtual void BuildSystem();
   virtual WrpMidw* GetMidw() const;

private:
   WrpGuiMidwBuilder(const WrpGuiMidwBuilder& cp);
   // members
   WrpMidw* mpMidw;
};

#endif /* WRPMIDW_WRPMIDWBUILDER_HPP */
