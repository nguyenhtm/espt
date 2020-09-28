/********************************************************************************************************
 * @File  : wrpstoragefactory.hpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPSTORAGEFACTORY_HPP
#define WRPBASE_WRPSYS_WRPSTORAGEFACTORY_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

namespace WrpSys {
namespace WrpStorage {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpNvs
// An abstract class defines an abstract product
class WrpNvs
{
public:
   WrpNvs();
   virtual ~WrpNvs();
   virtual bool Initialize() = 0; // pure virtual function makes the WrpNvs class Abstract class
   virtual bool DeInitialize() = 0;
};

// Class WrpEspNvs
class WrpEspNvs : public WrpNvs
{
public:
   WrpEspNvs();
   ~WrpEspNvs();
   bool Initialize();
   bool DeInitialize();
};

// Class WrpSimNvs
class WrpSimNvs : public WrpNvs
{
public:
   WrpSimNvs();
   ~WrpSimNvs();
   bool Initialize();
   bool DeInitialize();
};

// Class WrpSpiffs
// An abstract class defines an abstract product
class WrpSpiffs
{
public:
   WrpSpiffs();
   virtual ~WrpSpiffs();
   virtual bool Mount() = 0;
   virtual bool Unmount() = 0;
};

// Class WrpEspSpiffs
class WrpEspSpiffs : public WrpSpiffs
{
public:
   WrpEspSpiffs();
   ~WrpEspSpiffs();
   bool Mount(){return true;}
   bool Unmount(){return true;}
};

// Class WrpSimSpiffs
class WrpSimSpiffs : public WrpSpiffs
{
public:
   WrpSimSpiffs();
   ~WrpSimSpiffs();
   bool Mount(){return true;}
   bool Unmount(){return true;}
};

// Class WrpSdCard
// An abstract class defines an abstract product
class WrpSdCard
{
public:
   WrpSdCard();
   virtual ~WrpSdCard();
   virtual bool Initialize() = 0;
   virtual bool DeInitialize() = 0;
};

// Class WrpEspSdCard
class WrpEspSdCard : public WrpSdCard
{
public:
   WrpEspSdCard();
   ~WrpEspSdCard();
   bool Initialize(){return true;}
   bool DeInitialize(){return true;}
};

// Class WrpSimSdCard
class WrpSimSdCard : public WrpSdCard
{
public:
   WrpSimSdCard();
   ~WrpSimSdCard();
   bool Initialize(){return true;}
   bool DeInitialize(){return true;}
};

// Class WrpStorageFactory
// An abstract factory only declares an interface for creating products like WrpNvs
class WrpStorageFactory
{
public:
   WrpStorageFactory();
   virtual ~WrpStorageFactory();

   virtual WrpNvs*    CreateWrpNvs() const = 0;
   virtual WrpSpiffs* CreateWrpSpiffs() const = 0;
   virtual WrpSdCard* CreateWrpSdCard() const = 0;

private:
   WrpStorageFactory(const WrpStorageFactory& cp);
};

// Class WrpEspStorage
class WrpEspStorage : public WrpStorageFactory
{
public:
   WrpEspStorage();
   ~WrpEspStorage();

   //collection of factory methods
   virtual WrpNvs*    CreateWrpNvs() const;
   virtual WrpSpiffs* CreateWrpSpiffs() const;
   virtual WrpSdCard* CreateWrpSdCard() const;

private:
   WrpEspStorage(const WrpEspStorage& cp);
};

// Class WrpSimStorage
class WrpSimStorage : public WrpStorageFactory
{
public:
   WrpSimStorage();
   ~WrpSimStorage();

   //collection of factory methods
   virtual WrpNvs*    CreateWrpNvs() const;
   virtual WrpSpiffs* CreateWrpSpiffs() const;
   virtual WrpSdCard* CreateWrpSdCard() const;

private:
   WrpSimStorage(const WrpSimStorage& cp);
};

// Class WrpStorage
class WrpStorage
{
public:
   WrpStorage();
   ~WrpStorage();
   void Initialize(WrpSys::WrpStorage::WrpStorageFactory& factory);
   WrpNvs*    mpNvs;
   WrpSpiffs* mpSpiffs;
   WrpSdCard* mpSdCard;

private:
   WrpStorage(const WrpStorage& cp);
};

} /* Namespace WrpStorage */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPSTORAGEFACTORY_HPP */
