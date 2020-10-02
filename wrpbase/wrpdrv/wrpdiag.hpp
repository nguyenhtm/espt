/********************************************************************************************************
 * @File  : wrpdiag.hpp
 * @Date  : 2020-08-27
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPDRV_WRPDIAG_HPP
#define WRPBASE_WRPDRV_WRPDIAG_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/

namespace WrpDrv {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
// driver diagnosis types
enum WrpDrvDiagType
{
   DIAGTYPE_FAST = 0,
   DIAGTYPE_FULL,
   DIAGTYPE_MAX
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpDiagHandler represents a chain of responsibility
class WrpDiagHandler
{
public:
   WrpDiagHandler(WrpDiagHandler* successor);
   virtual ~WrpDiagHandler();
   virtual void HandleDiagRequest();

private:
   WrpDiagHandler(const WrpDiagHandler& cp);
   WrpDiagHandler* mpSuccessor;
};

// Class WrpDiagPrototype declares interfaces for cloning itself
class WrpDiagPrototype
{
public:
   WrpDiagPrototype();
   virtual ~WrpDiagPrototype();
   virtual WrpDiagPrototype* Clone() const = 0;
   virtual void DoDiagnosis() const = 0;

private:
   WrpDiagPrototype(const WrpDiagPrototype& cp);
};

class WrpDiagFast : public WrpDiagPrototype
{
public:
   WrpDiagFast();
   ~WrpDiagFast();
   WrpDiagPrototype* Clone() const;
   void DoDiagnosis() const;

private:
   WrpDiagFast(const WrpDiagFast& cp);
};

class WrpDiagFull : public WrpDiagPrototype
{
public:
   WrpDiagFull();
   ~WrpDiagFull();
   WrpDiagPrototype* Clone() const;
   void DoDiagnosis() const;

private:
   WrpDiagFull(const WrpDiagFull& cp);
};

// Class WrpDiagManager is a prototype manager
class WrpDiagManager
{
public:
   static WrpDiagPrototype* MakeDriverDiagnosis(const WrpDrvDiagType choice);
   virtual ~WrpDiagManager();

private:
   WrpDiagManager();
   WrpDiagManager(const WrpDiagManager& cp);
   static WrpDiagPrototype* mDiagTypes[DIAGTYPE_MAX];
};

} /* Namespace WrpDrv */

#endif /* WRPBASE_WRPDRV_WRPTIMER_HPP */
