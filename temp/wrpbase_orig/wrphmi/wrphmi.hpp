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

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpHmiObserver
{
public:
   WrpHmiObserver();
   virtual ~WrpHmiObserver();
   virtual void           CreateAndShow() = 0;
   virtual void           HideAndDestroy() = 0;

protected:

private:
   WrpHmiObserver(const WrpHmiObserver& cp);
   // members
   uint16_t               mHmiAppClientId;
};

class WrpHmi
{
public:
   WrpHmi();
   virtual ~WrpHmi();
   virtual void Initialize();
   void Attach(WrpHmiObserver* obj, const uint16_t id){};
   void Detach(WrpHmiObserver* obj){};

private:
   WrpHmi(const WrpHmi& cp);
};

class WrpLvglHmi : public WrpHmi
{
public:
   WrpLvglHmi();
   ~WrpLvglHmi();
   void Initialize();

private:
   WrpLvglHmi(const WrpLvglHmi& cp);
};

class WrpUgfxHmi : public WrpHmi
{
public:
   WrpUgfxHmi();
   ~WrpUgfxHmi();
   void Initialize();

private:
   WrpUgfxHmi(const WrpUgfxHmi& cp);
};

#endif /* WRPHMI_WRPHMI_HPP */
