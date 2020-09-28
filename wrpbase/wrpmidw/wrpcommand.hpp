/********************************************************************************************************
 * @File  : wrpcommand.hpp
 * @Date  : 2020-09-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPCOMMAND_HPP
#define WRPMIDW_WRPCOMMAND_HPP

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
// Forward classes
class WrpHmi;
class WrpMidw;

// Class WrpCommand
class WrpCommand
{
public:
   virtual ~WrpCommand();
   virtual void Execute() = 0;

protected:
   WrpCommand();
};

// Class StartWrpHmiCmd
class StartWrpHmiCmd : public WrpCommand
{
public:
   StartWrpHmiCmd(WrpHmi* receiver);
   virtual ~StartWrpHmiCmd();
   void Execute();

private:
   StartWrpHmiCmd(const StartWrpHmiCmd& cp);
   //members
   WrpHmi* mpReceiver;
};

// Class StopWrpHmiCmd
class StopWrpHmiCmd : public WrpCommand
{
public:
   StopWrpHmiCmd(WrpHmi* receiver);
   virtual ~StopWrpHmiCmd();
   void Execute();

private:
   StopWrpHmiCmd(const StopWrpHmiCmd& cp);
   //members
   WrpHmi* mpReceiver;
};

// Class DiagnosisCmd
class DiagnosisCmd : public WrpCommand
{
public:
   DiagnosisCmd(WrpMidw* receiver);
   virtual ~DiagnosisCmd();
   void Execute();

private:
   DiagnosisCmd(const DiagnosisCmd& cp);
   //members
   WrpMidw* mpReceiver;
};

#endif /* WRPMIDW_WRPCOMMAND_HPP */
