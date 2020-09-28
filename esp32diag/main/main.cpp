/********************************************************************************************************
 * @File  : main.cpp
 * @Date  : 2020-03-12
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbase/wrptest/wrptest.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
extern "C" void app_main();

void app_main()
{
   WrpTest::WrpTestApp app;
   app.Construct();

   //WrpTest::WrpSysTest();
}
