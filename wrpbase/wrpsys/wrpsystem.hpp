/********************************************************************************************************
 * @File  : wrpsystem.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPSYS_HPP_
#define WRPBASE_WRPSYS_WRPSYS_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

namespace WrpSys {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/


/*
 * Perform software reset of the chip. Execution of the program will stop, both CPUs will be reset
 * Application will be loaded by the boot loader and started again. Peripherals are not reset
 */
void SwReset();

void HwReset();

void PrintChipInfo();

} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPSYS_HPP_ */
