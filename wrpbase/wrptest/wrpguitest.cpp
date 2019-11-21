/*
 * File  : wrpguitest.cpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "../wrpgui/wrpscreen.hpp"
#include "../wrpgui/wrplabel.hpp"
#include "../wrpsys/wrpdisplay.hpp"
#include "wrptest.hpp"
#include "../wrpsys/wrpstorage.hpp"
#include "../wrpsys/wrpnetwork.hpp"
#include "../wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpTest {

void wrpguitest(void)
{
	WrpSys::PrintChipInfo();
	WrpSys::WrpSysStorage::InitNVS(); // must 1st initialization
	WrpSys::WrpSysNetwork::InitWifiStation();
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
