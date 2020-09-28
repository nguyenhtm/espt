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
#include "wrpbase/wrpgui/wrpscreen.hpp"

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
class WrpHmi
{
public:
   WrpHmi();
   virtual ~WrpHmi();
   virtual void  Initialize();
   virtual void  DeInitialize();
   void          Attach(WrpGui::WrpScreen* obj);
   void          Detach(WrpGui::WrpScreen* obj);
   void          LoadScreen(WrpGui::WrpScreen* obj);
   void          ActiveScreen(const WrpGui::WrpScreen& obj);
   eWrpHmiStatus GetStatus() const;
   void          SetStatus(eWrpHmiStatus status);

protected:
   // methods

   // members
   WrpSys::System::wrpthread_t mThreadId;
   eWrpHmiStatus               mStatus;

private:
   WrpHmi(const WrpHmi& cp);
   // methods

   // members
   std::vector<WrpGui::WrpScreen*> mpObservers;
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
