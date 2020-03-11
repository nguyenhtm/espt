/********************************************************************************************************
 * @File  : sampleapp.cpp
 * @Date  : 2020-02-08
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "sampleapp.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - SampleAppCommand
 ********************************************************************************************************/
SampleAppCommand::SampleAppCommand()
{
}

SampleAppCommand::~SampleAppCommand()
{
}

SampleAppCommand::SampleAppCommand(const SampleAppCommand& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - ScreenManagerOnCommand
 ********************************************************************************************************/
ScreenManagerOnCommand::ScreenManagerOnCommand(WrpScreenManager* pScreenManager)
: mpScreenManager(pScreenManager)
{
}

ScreenManagerOnCommand::~ScreenManagerOnCommand()
{
}

void ScreenManagerOnCommand::Execute() const
{
   mpScreenManager->CreateWrpHmiApp();
}

ScreenManagerOnCommand::ScreenManagerOnCommand()
: mpScreenManager(NULL)
{
}

ScreenManagerOnCommand::ScreenManagerOnCommand(const ScreenManagerOnCommand& cp)
: mpScreenManager(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - ServiceManagerOnCommand
 ********************************************************************************************************/
ServiceManagerOnCommand::ServiceManagerOnCommand(WrpServiceManager* pServiceManager)
: mpServiceManager(pServiceManager)
{
}

ServiceManagerOnCommand::~ServiceManagerOnCommand()
{
}

void ServiceManagerOnCommand::Execute() const
{
   mpServiceManager->BuildWrpMidwApp();
}

ServiceManagerOnCommand::ServiceManagerOnCommand()
: mpServiceManager(NULL)
{
}

ServiceManagerOnCommand::ServiceManagerOnCommand(const ServiceManagerOnCommand& cp)
: mpServiceManager(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - SampleAppInvoker
 ********************************************************************************************************/
SampleAppInvoker::SampleAppInvoker()
: mpCommand(NULL)
{
}

SampleAppInvoker::~SampleAppInvoker()
{
}

void SampleAppInvoker::ExecuteCommand(SampleAppCommand* pCommand)
{
   mpCommand = pCommand;
   mpCommand->Execute();
}

SampleAppInvoker::SampleAppInvoker(const SampleAppInvoker& cp)
: mpCommand(NULL)
{
}
