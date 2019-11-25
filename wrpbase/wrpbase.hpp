/********************************************************************************************************
 * @File  : wrpbase.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPDEFINE_HPP_
#define WRPBASE_WRPDEFINE_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpgui/wrpgui.hpp"
#include "wrpbase/wrpsys/wrpsys.hpp"


// c/c++ standard lib INCLUDES
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <vector>
#include <string>
#include <algorithm>

#include <cstdint>

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPNULL_CHECK(p)    if(!p) return;
#define WRPNULL_CHECKRET(p) if(!p) return 0;
#define WRPPRINT(fmt, ...)  fprintf(stderr, fmt, __VA_ARGS__)
#define WRPPRINT2(fmt, ...) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__)

#endif /* WRPBASE_WRPDEFINE_HPP_ */
