/********************************************************************************************************
 * @File  : wrpsystem.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPSYSTEM_HPP
#define WRPBASE_WRPSYS_WRPSYSTEM_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

namespace WrpSys {
namespace System {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

// Thread Handling
#if LVGL_PC_SIMU
typedef SDL_Thread*  wrpthread_t;
#elif USE_ESP_IDF
typedef TaskHandle_t wrpthread_t;
#endif
typedef void (*wrpthread_handler_t)(void *param);

/********************************************************************************************************
 * PROTOTYPES
 ********************************************************************************************************/
extern wrpthread_t WrpCreateThread(wrpthread_handler_t taskfunc, const char* taskname, void* arg);

/*
 * Perform software reset of the chip. Execution of the program will stop, both CPUs will be reset
 * Application will be loaded by the boot loader and started again. Peripherals are not reset
 */
void SwReset();

void HwReset();

void PrintChipInfo();

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

} /* Namespace System */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPSYSTEM_HPP */
