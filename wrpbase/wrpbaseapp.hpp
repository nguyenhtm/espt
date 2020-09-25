/********************************************************************************************************
 * @File  : wrpbaseapp.hpp
 * @Date  : 2020-09-23
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPBASEAPP_HPP
#define WRPBASE_WRPBASEAPP_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpmidw/wrpmidwbuilder.hpp"
#include "wrpbase/wrpsys/wrpstoragefactory.hpp"
#include "wrpbase/wrphmi/wrphmi.hpp"

#include "wrpbase/wrpgui/wrpscreen.hpp"
#include "wrpbase/wrpgui/wrplabel.hpp"
#include "wrpbase/wrpgui/wrpimage.hpp"

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpSysTestApp
class WrpSysTestApp
{
public:
   WrpSysTestApp();
   ~WrpSysTestApp();

private:
   WrpSysTestApp(const WrpSysTestApp& cp);
   // methods

   // members
   WrpSysMidwBuilder* mpMidwBuilder;
   WrpMidw*           mpMidw;
};

// Class WrpGuiApp
class WrpGuiApp
{
public:
   WrpGuiApp();
   ~WrpGuiApp();
   //create a midw and hmi instances
   void Initialize();
   //delete created midw and hmi instances
   void DeInitialize();
   //get instances
   WrpHmi* GetHmiInstance() { return mpHmi; }
   WrpMidw* GetMidwInstance() { return mpMidw; }

private:
   WrpGuiApp(const WrpGuiApp& cp);
   // methods

   // members
   WrpGuiMidwBuilder* mpMidwBuilder;
   WrpMidw* mpMidw;
   WrpHmi* mpHmi;
};

#endif /* WRPBASE_WRPBASEAPP_HPP */
