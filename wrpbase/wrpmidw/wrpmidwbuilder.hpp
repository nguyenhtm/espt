/********************************************************************************************************
 * @File  : wrpmidwbuilder.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPMIDW_WRPMIDWBUILDER_H_
#define WRPMIDW_WRPMIDWBUILDER_H_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
//#include "wrpbase/wrpsys/wrpnetwork.hpp"
//#include "wrpbase/wrpsys/wrpsystem.hpp"

//using namespace ::WrpSys::Network;
//using namespace ::WrpSys::System;

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

// Forward class
class WrpMidwApp;

// WrpMidwBuilder Class
class WrpMidwBuilder
{
public:
	WrpMidwBuilder(){};
	virtual ~WrpMidwBuilder(){};
	virtual void BuildStorage() = 0;
	virtual void BuildDisplay() = 0;
	virtual void BuildNetwork() = 0;
	virtual void BuildSystem() = 0;
	virtual WrpMidwApp* GetMidwApp() = 0;

protected:

private:

};

class WrpMidwESP32 : public WrpMidwBuilder
{
public:
	WrpMidwESP32();
	~WrpMidwESP32();

	void BuildStorage();
	void BuildDisplay();
	void BuildNetwork();
	void BuildSystem();
	WrpMidwApp* GetMidwApp();

protected:

private:
	WrpMidwApp* m_pMidwApp;
};

class WrpMidwSIM : public WrpMidwBuilder
{
public:
	WrpMidwSIM();
	~WrpMidwSIM();

	void BuildStorage();
	void BuildDisplay();
	void BuildNetwork();
	void BuildSystem();
	WrpMidwApp* GetMidwApp();

protected:

private:
	WrpMidwApp* m_pMidwApp;
};

class WrpMidwDirector
{
public:
	WrpMidwDirector(WrpMidwBuilder *builder);
	~WrpMidwDirector();
	void BuildWrpMidwApp();
	WrpMidwApp* GetMidwApp();

protected:

private:
	WrpMidwBuilder *m_pMidwAppBuilder;
};

#endif /* WRPMIDW_WRPMIDWBUILDER_H_ */
