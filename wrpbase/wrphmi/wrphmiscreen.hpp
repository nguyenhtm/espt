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
	virtual void LoadConfig() = 0;
	virtual void Add(WrpHmiScreen* pHmiScreen) = 0;
	virtual void Remove(WrpHmiScreen* pHmiScreen) = 0;
	virtual WrpHmiScreen* GetChild(uint8_t id) = 0;
};

class WrpScreenManager : public WrpHmiScreen
{
public:
	WrpScreenManager();
	~WrpScreenManager();
	void LoadConfig();
	void Add(WrpHmiScreen* pHmiScreen);
	void Remove(WrpHmiScreen* pHmiScreen);
	WrpHmiScreen* GetChild(uint8_t id);
	void CreateWrpHmiApp();
	WrpHmiApp* GetWrpHmiAppInstance();

private:
	std::vector<WrpHmiScreen*> m_listOfScreens;
	WrpHmiApp* m_pHmiApp;
};

#endif /* WRPHMI_WRPHMISCREEN_HPP */
