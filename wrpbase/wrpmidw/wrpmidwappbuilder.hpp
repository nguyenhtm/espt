/********************************************************************************************************
 * @File  : wrpmidwappbuilder.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWAPPBUILDER_HPP
#define WRPMIDW_WRPMIDWAPPBUILDER_HPP

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

// Forward class
class WrpMidwApp;

class WrpMidwAppBuilder
{
public:
   WrpMidwAppBuilder();
   virtual ~WrpMidwAppBuilder();
   virtual void BuildStorage() const = 0;
   virtual void BuildDisplay() const = 0;
   virtual void BuildNetwork() const = 0;
   virtual void BuildSystem() const = 0;
   virtual WrpMidwApp* GetWrpMidwApp() const = 0;

private:
   WrpMidwAppBuilder(const WrpMidwAppBuilder& cp);
};

class WrpMidwAppESP32 : public WrpMidwAppBuilder
{
public:
   WrpMidwAppESP32();
   ~WrpMidwAppESP32();
   void BuildStorage() const;
   void BuildDisplay() const;
   void BuildNetwork() const;
   void BuildSystem() const;
   WrpMidwApp* GetWrpMidwApp() const;

private:
   WrpMidwAppESP32(const WrpMidwAppESP32& cp);
   // members
   WrpMidwApp* mpMidwApp;
};

class WrpMidwAppSIM : public WrpMidwAppBuilder
{
public:
   WrpMidwAppSIM();
   ~WrpMidwAppSIM();
   void BuildStorage() const;
   void BuildDisplay() const;
   void BuildNetwork() const;
   void BuildSystem() const;
   WrpMidwApp* GetWrpMidwApp() const;

private:
   WrpMidwAppSIM(const WrpMidwAppSIM& cp);
   // members
   WrpMidwApp* mpMidwApp;
};

#endif /* WRPMIDW_WRPMIDWAPPBUILDER_HPP */
