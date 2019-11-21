/*
 * File  : wrpsystest.cpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrptest.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
//#define WRPESP_WIFI_SSID           "Sankalp004_2"
//#define WRPESP_WIFI_PASS           "9845447464"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpTest {

void wrpsystest(void)
{
	WrpSys::PrintChipInfo();
	WrpSys::WrpSysStorage::InitNVS(); // must 1st initialization
	WrpSys::WrpSysNetwork::InitWifiStation();

	//websocket test
	usleep(3000*1000); //wait until wifi done
	int count = 5;

	WrpSys::WrpSysNetwork::WrpWebSocketClient ws;
	while (--count)
	{
		usleep(1000*1000);
	}

}

} /* Namespace WrpTest */
