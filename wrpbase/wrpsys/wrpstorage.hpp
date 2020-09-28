/********************************************************************************************************
 * @File  : wrpstorage.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPSTORAGE_HPP_
#define WRPBASE_WRPSYS_WRPSTORAGE_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

namespace WrpSys {
namespace Storage {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define STORAGE_STATUS_INIT       (0x00)
#define STORAGE_STATUS_INITNVS    (0x01)
#define STORAGE_STATUS_INITSPIFFS (0x02)
#define STORAGE_STATUS_INITSDCARD (0x04)

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
extern uint32_t gStorageStatus;

bool InitNVS();

int32_t GetRestartCounter();

void ResetRestartCounter();

void DeInitNVS();

bool InitSPIFFS();

void DeInitSPIFFS();

bool InitSDCard();

void DeInitSDCard();

} /* Namespace Storage */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPSTORAGE_HPP_ */
