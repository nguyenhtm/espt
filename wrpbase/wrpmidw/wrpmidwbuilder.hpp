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
#include "wrpbase/wrpsys/wrpnetwork.hpp"
#include "wrpbase/wrpsys/wrpsystem.hpp"

using namespace ::WrpSys::Network;
using namespace ::WrpSys::System;

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

class WrpMidw
{
public:
	WrpMidw();
	~WrpMidw();

	void buildDisplay();
	void buildNetwork();
	void buildStorage();
	void buildSystem();

protected:

private:
	WrpWebSocketClient* m_pWsClient;
};

class WrpMidwBuilder
{
public:
	WrpMidwBuilder(){};
	virtual ~WrpMidwBuilder(){};
	virtual void BuildDisplay() = 0;
	virtual void BuildNetwork() = 0;
	virtual void BuildStorage() = 0;
	virtual void BuildSystem() = 0;
	virtual WrpMidw* GetMidwApp() = 0;
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
	WrpMidw* GetMidwApp();

protected:

private:
	WrpMidw* m_pMidwApp;
};

class WrpMidwSIM : public WrpMidwBuilder
{
public:
	WrpMidwSIM();
	~WrpMidwSIM();

	void BuildDisplay();
	void BuildNetwork();
	void BuildStorage();
	void BuildSystem();
	WrpMidw* GetMidwApp();

protected:

private:
	WrpMidw* m_pMidwApp;
};

class WrpMidwDirector
{
public:
	WrpMidwDirector(WrpMidwBuilder *builder);
	~WrpMidwDirector();
	void BuildWrpMidwApp();
	WrpMidw* GetMidwApp();

protected:

private:
	WrpMidwBuilder *m_pMidwAppBuilder;
};

#endif /* WRPMIDW_WRPMIDWBUILDER_H_ */
