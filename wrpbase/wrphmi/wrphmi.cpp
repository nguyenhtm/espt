/********************************************************************************************************
 * @File  : wrphmi.cpp
 * @Date  : 2020-08-14
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrphmi.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS - WrpHmi
 ********************************************************************************************************/
WrpHmi::WrpHmi()
: mThreadId(NULL)
{
   WRPPRINT("%s\n", "WrpHmi::WrpHmi() Begin");
   mObservers.clear();
   mStatus = WRPHMI_STATUS_STOP;
   WRPPRINT("%s\n", "WrpHmi::WrpHmi() End");
}
WrpHmi::~WrpHmi()
{
   WRPPRINT("%s\n", "WrpHmi::~WrpHmi() Begin");
   mObservers.clear();
   mStatus = WRPHMI_STATUS_STOP;
   WRPPRINT("%s\n", "WrpHmi::~WrpHmi() End");
}
void WrpHmi::Initialize()
{
   WRPPRINT("%s\n", "WrpHmi::Initialize() Begin");
   WRPPRINT("%s\n", "WrpHmi::Initialize() End");
}
void WrpHmi::DeInitialize()
{
   WRPPRINT("%s\n", "WrpHmi::DeInitialize() Begin");
   WRPPRINT("%s\n", "WrpHmi::DeInitialize() End");
}
void WrpHmi::Attach(WrpHmiObserver* obj)
{
   WRPPRINT("%s\n", "WrpHmi::Attach() Begin");
   WRPNULL_CHECK(obj)
   mObservers.push_back(obj);
   WRPPRINT("%s\n", "WrpHmi::Attach() End");
}
void WrpHmi::Detach(WrpHmiObserver* obj)
{
   WRPPRINT("%s\n", "WrpHmi::Detach() Begin");
   WRPNULL_CHECK(obj)
   std::vector<WrpHmiObserver*>::iterator it;
   it = std::find(mObservers.begin(), mObservers.end(), obj);
   if (it != mObservers.end())
   {
      mObservers.erase(it);
   }
   WRPPRINT("%s\n", "WrpHmi::Detach() End");
}
void WrpHmi::LoadScreen(WrpHmiObserver* obj)
{
   WRPPRINT("%s\n", "WrpHmi::LoadScreen() Begin");
   std::vector<WrpHmiObserver*>::iterator it;
   // destroy and hide the current loaded screen
   for (it = mObservers.begin(); it != mObservers.end(); ++it)
   {
      (*it)->HideAndDestroy();
   }
   // then create and show the obj screen
   it = std::find(mObservers.begin(), mObservers.end(), obj);
   if (it != mObservers.end())
   {
      (*it)->CreateAndShow();
   }
   WRPPRINT("%s\n", "WrpHmi::LoadScreen() End");
}
void WrpHmi::ActiveScreen(const WrpHmiObserver& obj)
{
   WRPPRINT("%s\n", "WrpHmi::ActiveScreen() Begin");
   std::vector<WrpHmiObserver*>::iterator it;
   // inform current active screen
   for (it = mObservers.begin(); it != mObservers.end(); ++it)
   {
      (*it)->ActiveScreen(obj);
   }
   WRPPRINT("%s\n", "WrpHmi::ActiveScreen() End");
}
eWrpHmiStatus WrpHmi::GetStatus() const
{
   return mStatus;
}
void WrpHmi::SetStatus(eWrpHmiStatus status)
{
   mStatus = status;
}
WrpHmi::WrpHmi(const WrpHmi& cp)
: mThreadId(NULL)
{
   mObservers.clear();
   mStatus = WRPHMI_STATUS_STOP;
}

/********************************************************************************************************
 * FUNCTIONS - WrpHmiLvgl
 ********************************************************************************************************/
WrpHmiLvgl::WrpHmiLvgl()
{
   WRPPRINT("%s\n", "WrpHmiLvgl::WrpHmiLvgl() Begin");
   WRPPRINT("%s\n", "WrpHmiLvgl::WrpHmiLvgl() End");
}
WrpHmiLvgl::~WrpHmiLvgl()
{
   WRPPRINT("%s\n", "WrpHmiLvgl::~WrpHmiLvgl() Begin");
   WRPPRINT("%s\n", "WrpHmiLvgl::~WrpHmiLvgl() End");
}
void WrpHmiLvgl::Initialize()
{
   WRPPRINT("%s\n", "WrpHmiLvgl::Initialize() Begin");
   mStatus = WRPHMI_STATUS_START;
   mThreadId = WrpSys::System::WrpCreateThread(WrpHmiLvgl::ThreadWrpHmi, "ThreadWrpHmi", this);
   if (!mThreadId)
   {
      mStatus = WRPHMI_STATUS_STOP;
      WRPPRINT("%s\n", "WrpHmiLvgl::Initialize() WrpCreateThread Failed!");
   }
   WRPPRINT("%s\n", "WrpHmiLvgl::Initialize() End");
}
void WrpHmiLvgl::DeInitialize()
{
   WRPPRINT("%s\n", "WrpHmiLvgl::DeInitialize() Begin");
   mStatus = WRPHMI_STATUS_STOP;
   WRPPRINT("%s\n", "WrpHmiLvgl::DeInitialize() End");
}
void WrpHmiLvgl::ThreadWrpHmi(void* param)
{
   WRPPRINT("%s\n", "WrpHmiLvgl::ThreadWrpHmi() Begin");
   WrpHmi* app = (WrpHmi*)param;
   while(app->GetStatus() == WRPHMI_STATUS_START)
   {
      usleep(5*1000); /*Tell LittelvGL that 5 milliseconds were elapsed*/
      lv_task_handler();
#if 0
#if LVGL_PC_SIMU
      SDL_Delay(5);   /*Sleep for 5 millisecond*/
      lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
#elif LVGL_ESP32_ILI9341
      lv_tick_inc(portTICK_RATE_MS);
#endif
#endif
   }
   WRPPRINT("%s\n", "WrpHmiLvgl::ThreadWrpHmi() End");
}
WrpHmiLvgl::WrpHmiLvgl(const WrpHmiLvgl& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpUgfxHmi
 ********************************************************************************************************/
WrpHmiUgfx::WrpHmiUgfx()
{
   WRPPRINT("%s\n", "WrpHmiUgfx::WrpHmiUgfx() Begin");
   WRPPRINT("%s\n", "WrpHmiUgfx::WrpHmiUgfx() End");
}
WrpHmiUgfx::~WrpHmiUgfx()
{
   WRPPRINT("%s\n", "WrpHmiUgfx::~WrpHmiUgfx() Begin");
   WRPPRINT("%s\n", "WrpHmiUgfx::~WrpHmiUgfx() End");
}
void WrpHmiUgfx::Initialize()
{
   WRPPRINT("%s\n", "WrpHmiUgfx::Initialize() Begin");
   WRPPRINT("%s\n", "WrpHmiUgfx::Initialize() End");
}
void WrpHmiUgfx::DeInitialize()
{
   WRPPRINT("%s\n", "WrpHmiUgfx::DeInitialize() Begin");
   mStatus = WRPHMI_STATUS_STOP;
   WRPPRINT("%s\n", "WrpHmiUgfx::DeInitialize() End");
}
WrpHmiUgfx::WrpHmiUgfx(const WrpHmiUgfx& cp)
{
}

/********************************************************************************************************
 * FUNCTIONS - WrpHmiObserver
 ********************************************************************************************************/
WrpHmiObserver::WrpHmiObserver()
{
   WRPPRINT("%s\n", "WrpHmiObserver::WrpHmiObserver() Begin");
   WRPPRINT("%s\n", "WrpHmiObserver::WrpHmiObserver() End");
}
WrpHmiObserver::~WrpHmiObserver()
{
   WRPPRINT("%s\n", "WrpHmiObserver::~WrpHmiObserver() Begin");
   WRPPRINT("%s\n", "WrpHmiObserver::~WrpHmiObserver() End");
}
WrpHmiObserver::WrpHmiObserver(const WrpHmiObserver& cp)
{
}
