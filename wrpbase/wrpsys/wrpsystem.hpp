/*
 * File  : wrpsys.hpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

#ifndef WRPBASE_WRPSYS_WRPSYS_HPP_
#define WRPBASE_WRPSYS_WRPSYS_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
namespace WrpSys {

enum eWrpSysState
{
	SYS_STATE_INIT = 0,
	SYS_STATE_READY,
	SYS_STATE_SHUTDOWN
};

class IWrpSysStateClient
{
public:
	IWrpSysStateClient(){};
	~IWrpSysStateClient(){};
	virtual void Update() = 0;
};

class IWrpSysState
{
public:
	IWrpSysState();
	virtual ~IWrpSysState();
	virtual void Attach(IWrpSysStateClient* client);
	virtual void Detach(IWrpSysStateClient* client);
	virtual void Notify();

private:
	std::vector<IWrpSysStateClient*> m_listOfObservers;
};

/*
 * Perform software reset of the chip. Execution of the program will stop, both CPUs will be reset
 * Application will be loaded by the boot loader and started again. Peripherals are not reset
 */
void SwReset();

void HwReset();

void PrintChipInfo();

} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPSYS_HPP_ */
