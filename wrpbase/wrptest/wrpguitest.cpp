/********************************************************************************************************
 * @File  : wrpguitest.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrptest.hpp"
#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpdisplay.hpp"
#include "wrpbase/wrpsys/wrpstorage.hpp"
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

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
void wrpguitest(void)
{
	WrpSys::System::PrintChipInfo();
	WrpSys::Storage::InitNVS(); // must 1st initialization
	WrpSys::Network::InitWifiStation();
	WrpSys::InitLvglLib();

	WrpGui::WrpScreen* masterScreen = new WrpGui::WrpScreen(true); // loaded by default
	WrpGui::WrpScreen* homeScreen   = new WrpGui::WrpScreen();

	masterScreen->SetTitle("Master Screen");
	homeScreen->SetTitle("Home Screen");

	masterScreen->Load();
	usleep(5000*1000);
	homeScreen->Load();

	usleep(2000*1000);
	delete homeScreen;
	delete masterScreen;
}

} /* Namespace WrpTest */
