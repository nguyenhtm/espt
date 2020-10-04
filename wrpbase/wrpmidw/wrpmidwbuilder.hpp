/********************************************************************************************************
 * @File  : wrpmidwbuilder.hpp
 * @Date  : 2020-08-04
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWBUILDER_HPP
#define WRPMIDW_WRPMIDWBUILDER_HPP

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrpmidw/wrpmidw.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
// Class WrpMidwBuilder
class WrpMidwBuilder
{
public:
   WrpMidwBuilder();
   virtual ~WrpMidwBuilder();
   virtual void BuildStorage();
   virtual void BuildConnectivity();
   virtual void BuildSystem();
   virtual WrpMidw* GetMidw() const;

protected:
   WrpMidwBuilder(const WrpMidwBuilder& cp);
};

// Class WrpSimpleMidwBuilder
class WrpSimpleMidwBuilder : public WrpMidwBuilder
{
public:
   WrpSimpleMidwBuilder();
   ~WrpSimpleMidwBuilder();
   void BuildStorage();
   void BuildConnectivity();
   WrpMidw* GetMidw() const;

private:
   WrpSimpleMidwBuilder(const WrpSimpleMidwBuilder& cp);
   // members
   WrpMidw* mpMidw;
};

// Class WrpStandardMidwBuilder
class WrpStandardMidwBuilder : public WrpMidwBuilder
{
public:
   WrpStandardMidwBuilder();
   ~WrpStandardMidwBuilder();
   void BuildStorage();
   void BuildConnectivity();
   void BuildSystem();
   WrpMidw* GetMidw() const;

private:
   WrpStandardMidwBuilder(const WrpStandardMidwBuilder& cp);
   // members
   WrpMidw* mpMidw;
};

#endif /* WRPMIDW_WRPMIDWBUILDER_HPP */
