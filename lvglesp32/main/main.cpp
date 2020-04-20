/********************************************************************************************************
 * @File  : main.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "appsample/appdefines.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
extern "C" void app_main();

void app_main()
{
	/*
	 * This function is for ESP32 Wrover V3.0 which includes LCD
	 */
	appsample();
}
