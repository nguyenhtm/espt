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
	virtual void BuildStorage() = 0;
	virtual void BuildDisplay() = 0;
	virtual void BuildNetwork() = 0;
	virtual void BuildSystem() = 0;
	virtual WrpMidwApp* GetWrpMidwApp() = 0;
};

class WrpMidwAppESP32 : public WrpMidwAppBuilder
{
public:
	WrpMidwAppESP32();
	~WrpMidwAppESP32();
	void BuildStorage();
	void BuildDisplay();
	void BuildNetwork();
	void BuildSystem();
	WrpMidwApp* GetWrpMidwApp();

private:
	WrpMidwApp* m_pMidwApp;
};

class WrpMidwAppSIM : public WrpMidwAppBuilder
{
public:
	WrpMidwAppSIM();
	~WrpMidwAppSIM();
	void BuildStorage();
	void BuildDisplay();
	void BuildNetwork();
	void BuildSystem();
	WrpMidwApp* GetWrpMidwApp();

private:
	WrpMidwApp* m_pMidwApp;
};



#endif /* WRPMIDW_WRPMIDWAPPBUILDER_HPP */
