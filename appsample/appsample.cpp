/********************************************************************************************************
 * @File  : appsample.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include <appsample/speedometer.hpp>
#include "appdefines.hpp"
#include "wrpbase/wrphmi/wrphmiapp.hpp"
#include "wrpbase/wrphmi/wrphmiscreen.hpp"
#include "wrpbase/wrpmidw/wrpmidwapp.hpp"
#include "wrpbase/wrpmidw/wrpmidwappfsm.hpp"
#include "homescreen.hpp"
#include "loadingscreen.hpp"
#include "cflowscreen.hpp"

#include "wrpbase/wrpbaseapp.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/

void appsample()
{
   WrpGuiApp app;
   app.Initialize();

   LoadingScreenEx loadingScreen;
   HomeScreenEx    homeScreen;
   CFlowScreenEx   cflowScreen;
   Speedometer     meter;

   app.GetHmiInstance()->Attach(&loadingScreen);
   app.GetHmiInstance()->Attach(&homeScreen);
   app.GetHmiInstance()->Attach(&cflowScreen);
   app.GetHmiInstance()->Attach(&meter);

   app.GetHmiInstance()->LoadScreen(&loadingScreen);
   sleep(3);
   //app.GetHmiInstance()->LoadScreen(&homeScreen);
   //sleep(3);
   //app.GetHmiInstance()->LoadScreen(&cflowScreen);
   //sleep(5);
   app.GetHmiInstance()->LoadScreen(&meter);
   meter.RunSpeedMeter(360);
   meter.RunSpeedMeter(20);
#ifndef USE_ESP_IDF
   SDL_Event e;
   while(1)
   {
      if (SDL_WaitEvent(&e)) {
         if (e.type == SDL_QUIT)
            break;
      }
   }
#else
   while(1){}
#endif
}
