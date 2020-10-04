/********************************************************************************************************
 * @File  : appsample.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpbase/wrphmi/wrphmi.hpp"
#include "appsample/sampleapp.hpp"
#include "appsample/loadingscreen.hpp"
#include "appsample/homescreen.hpp"
#include "appsample/cflowscreen.hpp"
#include "appsample/speedometer.hpp"

/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
void appsample()
{
   WrpHmiApp app;
   app.Initialize();

   LoadingScreen loadingScreen;
   HomeScreen    homeScreen;
   CFlowScreen   cflowScreen;
   Speedometer   meter;

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
