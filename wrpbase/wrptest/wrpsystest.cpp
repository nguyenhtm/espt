/********************************************************************************************************
 * @File  : wrpsystest.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"
#include "wrpbase/wrpmidw/wrpmidwbuilder.hpp"
#include "wrpbase/wrpmidw/wrpmidwstate.hpp"
#include "wrptest.hpp"

namespace WrpTest {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

void wrpsystest(void)
{
	WrpSys::System::PrintChipInfo();
	WrpSys::Storage::InitNVS(); // must 1st initialization
	WrpSys::Network::InitWifiStation();

	//websocket test
	usleep(3000*1000); //wait until wifi done
	int count = 5;

	WrpSys::Network::WrpWebSocketClient ws;
#if LVGL_PC_SIMU
	ws.Create("127.0.0.1", 8000);
#elif LVGL_ESP32_ILI9341
	ws.Create("172.20.10.5", 8000);
#endif

	while (--count)
	{
		usleep(1000*1000);
	}

	WrpMidwBuilder *midwAppBuilder = new WrpMidwESP32();
	WrpMidwDirector *ctr = new WrpMidwDirector(midwAppBuilder);
	ctr->BuildWrpMidwApp();
	WrpMidw* p = ctr->GetMidwApp();
	p->SetState(new WrpMidwInit(p));
}

} /* Namespace WrpTest */
