/********************************************************************************************************
 * @File  : wrphmiscreen.hpp
 * @Date  : 2020-03-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPHMI_WRPHMISCREEN_HPP
#define WRPHMI_WRPHMISCREEN_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
class WrpHmiScreen
{
public:
   WrpHmiScreen();
   virtual ~WrpHmiScreen();
   virtual void          LoadConfig() = 0;
   virtual void          Add(WrpHmiScreen* pHmiScreen) = 0;
   virtual void          Remove(WrpHmiScreen* pHmiScreen) = 0;
   virtual WrpHmiScreen* GetChild(const uint8_t id) const = 0;

private:
   WrpHmiScreen(const WrpHmiScreen& cp);
};

class WrpScreenManager : public WrpHmiScreen
{
public:
   WrpScreenManager();
   ~WrpScreenManager();
   void          LoadConfig();
   void          Add(WrpHmiScreen* pHmiScreen);
   void          Remove(WrpHmiScreen* pHmiScreen);
   WrpHmiScreen* GetChild(uint8_t id) const;
   void          CreateWrpHmiApp();
   WrpHmiApp*    GetWrpHmiAppInstance();

private:
   WrpScreenManager(const WrpScreenManager& cp);
   // members
   std::vector<WrpHmiScreen*> m_listOfScreens;
   WrpHmiApp*                 mpHmiApp;
};

#endif /* WRPHMI_WRPHMISCREEN_HPP */
