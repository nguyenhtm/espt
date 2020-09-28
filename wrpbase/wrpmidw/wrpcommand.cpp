/********************************************************************************************************
 * @File  : wrpcommand.cpp
 * @Date  : 2020-09-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpcommand.hpp"
#include "wrpbase/wrphmi/wrphmi.hpp"
#include "wrpbase/wrpmidw/wrpmidwbuilder.hpp"
#include "wrpbase/wrpdrv/wrpdrvfacade.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpCommand
 ********************************************************************************************************/
WrpCommand::WrpCommand()
{
   WRPPRINT("%s\n", "WrpCommand::WrpCommand() Begin");
   WRPPRINT("%s\n", "WrpCommand::WrpCommand() End");
}
WrpCommand::~WrpCommand()
{
   WRPPRINT("%s\n", "WrpCommand::~WrpCommand() Begin");
   WRPPRINT("%s\n", "WrpCommand::~WrpCommand() End");
}

/********************************************************************************************************
 * FUNCTIONS - StartWrpHmiCmd
 ********************************************************************************************************/
StartWrpHmiCmd::StartWrpHmiCmd(WrpHmi* receiver)
: mpReceiver(receiver)
{
   WRPPRINT("%s\n", "StartWrpHmiCmd::StartWrpHmiCmd() Begin");
   WRPPRINT("%s\n", "StartWrpHmiCmd::StartWrpHmiCmd() End");
}
StartWrpHmiCmd::~StartWrpHmiCmd()
{
   WRPPRINT("%s\n", "StartWrpHmiCmd::~StartWrpHmiCmd() Begin");
   WRPPRINT("%s\n", "StartWrpHmiCmd::~StartWrpHmiCmd() End");
}
void StartWrpHmiCmd::Execute()
{
   WRPPRINT("%s\n", "StartWrpHmiCmd::Execute() Begin");
   mpReceiver->Initialize();
   WRPPRINT("%s\n", "StartWrpHmiCmd::Execute() End");
}
StartWrpHmiCmd::StartWrpHmiCmd(const StartWrpHmiCmd& cp)
: mpReceiver(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - StopWrpHmiCmd
 ********************************************************************************************************/
StopWrpHmiCmd::StopWrpHmiCmd(WrpHmi* receiver)
: mpReceiver(receiver)
{
   WRPPRINT("%s\n", "StopWrpHmiCmd::StopWrpHmiCmd() Begin");
   WRPPRINT("%s\n", "StopWrpHmiCmd::StopWrpHmiCmd() End");
}
StopWrpHmiCmd::~StopWrpHmiCmd()
{
   WRPPRINT("%s\n", "StopWrpHmiCmd::~StopWrpHmiCmd() Begin");
   WRPPRINT("%s\n", "StopWrpHmiCmd::~StopWrpHmiCmd() End");
}
void StopWrpHmiCmd::Execute()
{
   WRPPRINT("%s\n", "StopWrpHmiCmd::Execute() Begin");
   mpReceiver->DeInitialize();
   WRPPRINT("%s\n", "StopWrpHmiCmd::Execute() End");
}
StopWrpHmiCmd::StopWrpHmiCmd(const StopWrpHmiCmd& cp)
: mpReceiver(NULL)
{
}

/********************************************************************************************************
 * FUNCTIONS - DiagnosisCmd
 ********************************************************************************************************/
DiagnosisCmd::DiagnosisCmd(WrpMidw* receiver)
: mpReceiver(receiver)
{
   WRPPRINT("%s\n", "DiagnosisCmd::DiagnosisCmd() Begin");
   WRPPRINT("%s\n", "DiagnosisCmd::DiagnosisCmd() End");
}
DiagnosisCmd::~DiagnosisCmd()
{
   WRPPRINT("%s\n", "DiagnosisCmd::~DiagnosisCmd() Begin");
   WRPPRINT("%s\n", "DiagnosisCmd::~DiagnosisCmd() End");
}
void DiagnosisCmd::Execute()
{
   WRPPRINT("%s\n", "DiagnosisCmd::Execute() Begin");
   WrpDrv::WrpDrvFacade::Instance()->DoFastDiagnosis();
   WRPPRINT("%s\n", "DiagnosisCmd::Execute() End");
}
DiagnosisCmd::DiagnosisCmd(const DiagnosisCmd& cp)
: mpReceiver(NULL)
{
}
