/********************************************************************************************************
 * @File  : wrphmi.hpp
 * @Date  : 2020-08-14
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPHMI_WRPHMI_HPP
#define WRPHMI_WRPHMI_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
enum eWrpHmiStatus
{
   WRPHMI_STATUS_STOP = 0, WRPHMI_STATUS_START
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpHmiObserver
{
public:
   WrpHmiObserver();
   virtual ~WrpHmiObserver();
   virtual void CreateAndShow() = 0;
   virtual void HideAndDestroy() = 0;
   virtual void ActiveScreen(const WrpHmiObserver& obj) = 0;

private:
   WrpHmiObserver(const WrpHmiObserver& cp);
   // methods

   // members
};

class WrpHmi
{
public:
   WrpHmi();
   virtual ~WrpHmi();
   virtual void  Initialize();
   virtual void  DeInitialize();
   void          Attach(WrpHmiObserver* obj);
   void          Detach(WrpHmiObserver* obj);
   void          LoadScreen(WrpHmiObserver* obj);
   void          ActiveScreen(const WrpHmiObserver& obj);
   eWrpHmiStatus GetStatus() const;
   void          SetStatus(eWrpHmiStatus status);

protected:
   // methods

   // members
   WrpSys::System::wrpthread_t  mThreadId;
   eWrpHmiStatus                mStatus;

private:
   WrpHmi(const WrpHmi& cp);
   // methods

   // members
   std::vector<WrpHmiObserver*> mObservers;
};

class WrpHmiLvgl : public WrpHmi
{
public:
   WrpHmiLvgl();
   ~WrpHmiLvgl();
   void Initialize();
   void DeInitialize();

private:
   WrpHmiLvgl(const WrpHmiLvgl& cp);
   // methods
   static void  ThreadWrpHmi(void* param);

   // members
};

class WrpHmiUgfx : public WrpHmi
{
public:
   WrpHmiUgfx();
   ~WrpHmiUgfx();
   void Initialize();
   void DeInitialize();

private:
   WrpHmiUgfx(const WrpHmiUgfx& cp);
   // methods

   // members
};

#endif /* WRPHMI_WRPHMI_HPP */
