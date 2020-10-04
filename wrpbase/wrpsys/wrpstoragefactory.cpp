/********************************************************************************************************
 * @File  : wrpstoragefactory.cpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpstoragefactory.hpp"

namespace WrpSys {
namespace WrpStorage {

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS - WrpNvs
 ********************************************************************************************************/
WrpNvs::WrpNvs()
{
   WRPPRINT("%s\n", "WrpNvs::WrpNvs() Begin");
   WRPPRINT("%s\n", "WrpNvs::WrpNvs() End");
}
WrpNvs::~WrpNvs()
{
   WRPPRINT("%s\n", "WrpNvs::~WrpNvs() Begin");
   WRPPRINT("%s\n", "WrpNvs::~WrpNvs() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpEspNvs
 ********************************************************************************************************/
WrpEspNvs::WrpEspNvs()
{
   WRPPRINT("%s\n", "WrpEspNvs::WrpEspNvs() Begin");
   WRPPRINT("%s\n", "WrpEspNvs::WrpEspNvs() End");
}
WrpEspNvs::~WrpEspNvs()
{
   WRPPRINT("%s\n", "WrpEspNvs::~WrpEspNvs() Begin");
   WRPPRINT("%s\n", "WrpEspNvs::~WrpEspNvs() End");
}
bool WrpEspNvs::Initialize()
{
   WRPPRINT("%s\n", "WrpEspNvs::Initialize() Begin");
#if USE_ESP_IDF
   // A ESP32 Flash contains multiple apps and different kinds of data:
   // a partition table is flashed to 0x8000 in the Flash
   // a data region defined in the partition table with labeled 'nvs' is for storing NVS library partition
   esp_err_t ret = ESP_OK;

   // Initialize the default NVS partition
   ret = nvs_flash_init();
   if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
   {
      // NVS partition was truncated and needs to be erased
      ret = nvs_flash_erase();
      if (ret == ESP_ERR_NOT_FOUND)
      {
         WRPPRINT("%s\n", "WrpEspNvs::Initialize() Not found NVS partition in the partition table!");
         return false;
      }
      // Retry nvs_flash_init
      ret = nvs_flash_init();
      if (ret != ESP_OK)
      {
         WRPPRINT("%s\n", "WrpEspNvs::Initialize() Retry failed!");
         return false;
      }
   }
#endif
   WRPPRINT("%s\n", "WrpEspNvs::Initialize() End");
   return true;
}
bool WrpEspNvs::DeInitialize()
{
   WRPPRINT("%s\n", "WrpEspNvs::DeInitialize() Begin");
#if USE_ESP_IDF
   esp_err_t ret = ESP_OK;

   // Deinitialize the default NVS partition
   ret = nvs_flash_deinit();
   if (ret == ESP_ERR_NVS_NOT_INITIALIZED)
   {
      WRPPRINT("%s\n", "WrpEspNvs::DeInitialize() Not initialized NVS partition!");
      return false;
   }
#endif
   WRPPRINT("%s\n", "WrpEspNvs::DeInitialize() End");
   return true;
}

/********************************************************************************************************
 * FUNCTIONS - WrpSimNvs
 ********************************************************************************************************/
WrpSimNvs::WrpSimNvs()
{
   WRPPRINT("%s\n", "WrpSimNvs::WrpSimNvs() Begin");
   WRPPRINT("%s\n", "WrpSimNvs::WrpSimNvs() End");
}
WrpSimNvs::~WrpSimNvs()
{
   WRPPRINT("%s\n", "WrpSimNvs::~WrpSimNvs() Begin");
   WRPPRINT("%s\n", "WrpSimNvs::~WrpSimNvs() End");
}
bool WrpSimNvs::Initialize()
{
   WRPPRINT("%s\n", "WrpSimNvs::Initialize() Begin");
   WRPPRINT("%s\n", "WrpSimNvs::Initialize() End");
   return true;
}
bool WrpSimNvs::DeInitialize()
{
   WRPPRINT("%s\n", "WrpSimNvs::DeInitialize() Begin");
   WRPPRINT("%s\n", "WrpSimNvs::DeInitialize() End");
   return true;
}

/********************************************************************************************************
 * FUNCTIONS - WrpSpiffs
 ********************************************************************************************************/
WrpSpiffs::WrpSpiffs()
{
   WRPPRINT("%s\n", "WrpSpiffs::WrpSpiffs() Begin");
   WRPPRINT("%s\n", "WrpSpiffs::WrpSpiffs() End");
}
WrpSpiffs::~WrpSpiffs()
{
   WRPPRINT("%s\n", "WrpSpiffs::~WrpSpiffs() Begin");
   WRPPRINT("%s\n", "WrpSpiffs::~WrpSpiffs() End");
}
WrpEspSpiffs::WrpEspSpiffs()
{
   WRPPRINT("%s\n", "WrpEspSpiffs::WrpEspSpiffs() Begin");
   WRPPRINT("%s\n", "WrpEspSpiffs::WrpEspSpiffs() End");
}
WrpEspSpiffs::~WrpEspSpiffs()
{
   WRPPRINT("%s\n", "WrpEspSpiffs::~WrpEspSpiffs() Begin");
   WRPPRINT("%s\n", "WrpEspSpiffs::~WrpEspSpiffs() End");
}
WrpSimSpiffs::WrpSimSpiffs()
{
   WRPPRINT("%s\n", "WrpSimSpiffs::WrpSimSpiffs() Begin");
   WRPPRINT("%s\n", "WrpSimSpiffs::WrpSimSpiffs() End");
}
WrpSimSpiffs::~WrpSimSpiffs()
{
   WRPPRINT("%s\n", "WrpSimSpiffs::~WrpSimSpiffs() Begin");
   WRPPRINT("%s\n", "WrpSimSpiffs::~WrpSimSpiffs() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpSdCard
 ********************************************************************************************************/
WrpSdCard::WrpSdCard()
{
   WRPPRINT("%s\n", "WrpSdCard::WrpSdCard() Begin");
   WRPPRINT("%s\n", "WrpSdCard::WrpSdCard() End");
}
WrpSdCard::~WrpSdCard()
{
   WRPPRINT("%s\n", "WrpSdCard::~WrpSdCard() Begin");
   WRPPRINT("%s\n", "WrpSdCard::~WrpSdCard() End");
}
WrpEspSdCard::WrpEspSdCard()
{
   WRPPRINT("%s\n", "WrpEspSdCard::WrpEspSdCard() Begin");
   WRPPRINT("%s\n", "WrpEspSdCard::WrpEspSdCard() End");
}
WrpEspSdCard::~WrpEspSdCard()
{
   WRPPRINT("%s\n", "WrpEspSdCard::~WrpEspSdCard() Begin");
   WRPPRINT("%s\n", "WrpEspSdCard::~WrpEspSdCard() End");
}
WrpSimSdCard::WrpSimSdCard()
{
   WRPPRINT("%s\n", "WrpSimSdCard::WrpSimSdCard() Begin");
   WRPPRINT("%s\n", "WrpSimSdCard::WrpSimSdCard() End");
}
WrpSimSdCard::~WrpSimSdCard()
{
   WRPPRINT("%s\n", "WrpSimSdCard::~WrpSimSdCard() Begin");
   WRPPRINT("%s\n", "WrpSimSdCard::~WrpSimSdCard() End");
}

/********************************************************************************************************
 * FUNCTIONS - WrpStorageFactory
 ********************************************************************************************************/
WrpStorageFactory::WrpStorageFactory()
{
   WRPPRINT("%s\n", "WrpStorageFactory::WrpStorageFactory() Begin");
   WRPPRINT("%s\n", "WrpStorageFactory::WrpStorageFactory() End");
}
WrpStorageFactory::~WrpStorageFactory()
{
   WRPPRINT("%s\n", "WrpStorageFactory::~WrpStorageFactory() Begin");
   WRPPRINT("%s\n", "WrpStorageFactory::~WrpStorageFactory() End");
}
WrpStorageFactory::WrpStorageFactory(const WrpStorageFactory& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpEspStorage
 ********************************************************************************************************/
WrpEspStorage::WrpEspStorage()
{
   WRPPRINT("%s\n", "WrpEspStorage::WrpEspStorage() Begin");
   WRPPRINT("%s\n", "WrpEspStorage::WrpEspStorage() End");
}
WrpEspStorage::~WrpEspStorage()
{
   WRPPRINT("%s\n", "WrpEspStorage::~WrpEspStorage() Begin");
   WRPPRINT("%s\n", "WrpEspStorage::~WrpEspStorage() End");
}
WrpNvs* WrpEspStorage::CreateWrpNvs() const
{
   return new WrpEspNvs;
}
WrpSpiffs* WrpEspStorage::CreateWrpSpiffs() const
{
   return new WrpEspSpiffs;
}
WrpSdCard* WrpEspStorage::CreateWrpSdCard() const
{
   return new WrpEspSdCard;
}
WrpEspStorage::WrpEspStorage(const WrpEspStorage& cp)
{
}

// Class WrpSimStorage Functions
WrpSimStorage::WrpSimStorage()
{
   WRPPRINT("%s\n", "WrpSimStorage::WrpSimStorage() Begin");
   WRPPRINT("%s\n", "WrpSimStorage::WrpSimStorage() End");
}
WrpSimStorage::~WrpSimStorage()
{
   WRPPRINT("%s\n", "WrpSimStorage::~WrpSimStorage() Begin");
   WRPPRINT("%s\n", "WrpSimStorage::~WrpSimStorage() End");
}
WrpNvs* WrpSimStorage::CreateWrpNvs() const
{
   return new WrpSimNvs;
}
WrpSpiffs* WrpSimStorage::CreateWrpSpiffs() const
{
   return new WrpSimSpiffs;
}
WrpSdCard* WrpSimStorage::CreateWrpSdCard() const
{
   return new WrpSimSdCard;
}
WrpSimStorage::WrpSimStorage(const WrpSimStorage& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpStorage
 ********************************************************************************************************/
WrpStorage::WrpStorage()
{
   WRPPRINT("%s\n", "WrpStorage::WrpStorage() Begin");
   WRPPRINT("%s\n", "WrpStorage::WrpStorage() End");
}
WrpStorage::~WrpStorage()
{
   WRPPRINT("%s\n", "WrpStorage::~WrpStorage() Begin");
   WRPPRINT("%s\n", "WrpStorage::~WrpStorage() End");
}
void WrpStorage::Initialize(WrpSys::WrpStorage::WrpStorageFactory& factory)
{
   WRPPRINT("%s\n", "WrpStorage::Initialize() Begin");
   mpNvs = factory.CreateWrpNvs();
   mpNvs->Initialize();
   mpSpiffs = factory.CreateWrpSpiffs();
   mpSpiffs->Mount();
   mpSdCard = factory.CreateWrpSdCard();
   mpSdCard->Initialize();
   WRPPRINT("%s\n", "WrpStorage::Initialize() End");
}
void WrpStorage::DeInitialize()
{
   WRPPRINT("%s\n", "WrpStorage::DeInitialize() Begin");
   mpNvs->DeInitialize();
   mpSpiffs->Unmount();
   mpSdCard->DeInitialize();
   WRPPRINT("%s\n", "WrpStorage::DeInitialize() End");
}
WrpStorage::WrpStorage(const WrpStorage& cp)
{
}

} /* Namespace WrpStorage */
} /* Namespace WrpSys */
