/********************************************************************************************************
 * @File  : sampleapp.hpp
 * @Date  : 2020-02-08
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef APPSAMPLE_SAMPLEAPP_HPP
#define APPSAMPLE_SAMPLEAPP_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class SampleAppCommand
{
public:
   SampleAppCommand();
   virtual ~SampleAppCommand();
   virtual void Execute() const = 0;

private:
   SampleAppCommand(const SampleAppCommand& cp);
};

class ScreenManagerOnCommand : public SampleAppCommand
{
public:
   ScreenManagerOnCommand(WrpScreenManager* pScreenManager);
   ~ScreenManagerOnCommand();
   void Execute() const;

private:
   ScreenManagerOnCommand();
   ScreenManagerOnCommand(const ScreenManagerOnCommand& cp);
   // members
   WrpScreenManager* mpScreenManager;
};

class ServiceManagerOnCommand : public SampleAppCommand
{
public:
   ServiceManagerOnCommand(WrpServiceManager* pServiceManager);
   ~ServiceManagerOnCommand();
   void Execute() const;

private:
   ServiceManagerOnCommand();
   ServiceManagerOnCommand(const ServiceManagerOnCommand& cp);
   // members
   WrpServiceManager* mpServiceManager;
};

class SampleAppInvoker
{
public:
   SampleAppInvoker();
   ~SampleAppInvoker();
   void ExecuteCommand(SampleAppCommand* pCommand);

private:
   SampleAppInvoker(const SampleAppInvoker& cp);
   //members
   SampleAppCommand* mpCommand;
};

#endif /* APPSAMPLE_SAMPLEAPP_HPP */
