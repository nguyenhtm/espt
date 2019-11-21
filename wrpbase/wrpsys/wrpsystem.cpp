/*
 * File  : wrpsys.cpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpsystem.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
namespace WrpSys
{

// IWrpSysState
IWrpSysState::IWrpSysState()
{
	m_listOfObservers.clear();
}

IWrpSysState::~IWrpSysState()
{
	m_listOfObservers.clear();
}

void IWrpSysState::Attach(IWrpSysStateClient* client)
{
	m_listOfObservers.push_back(client);
}

void IWrpSysState::Detach(IWrpSysStateClient* client)
{
	std::vector<IWrpSysStateClient*>::iterator it;
	it = std::find(m_listOfObservers.begin(), m_listOfObservers.end(), client);
	if (it != m_listOfObservers.end())
	{
		m_listOfObservers.erase(it);
	}
}

void IWrpSysState::Notify()
{
	size_t numOfElements = m_listOfObservers.size();
	for (int i = 0; i < numOfElements; i++)
	{
		m_listOfObservers[i]->Update();
	}
}

void SwReset()
{

}

void HwReset()
{

}

void PrintChipInfo()
{
	WRPPRINT("%s\n", "PrintChipInfo() Begin");
#if USE_ESP_IDF
	esp_chip_info_t chipInfo;

    esp_chip_info(&chipInfo);
    WRPPRINT("This is ESP32 chip with %d CPU cores, WiFi%s%s, ", chipInfo.cores, (chipInfo.features & CHIP_FEATURE_BT) ? "/BT" : "", (chipInfo.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    WRPPRINT("silicon revision %d, ", chipInfo.revision);
    WRPPRINT("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024), (chipInfo.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
#endif
	WRPPRINT("%s\n", "PrintChipInfo() End");
}

} /* Namespace WrpSys */
