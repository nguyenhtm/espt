/********************************************************************************************************
 * @File  : main.cpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
//#include "appsample/appdefines.hpp"
//#include "appcluster/clusterapp.hpp"
#include "wrpbase/wrptest/wrptest.hpp"


/********************************************************************************************************
 * VARIABLES
 ********************************************************************************************************/

/********************************************************************************************************
 * FUNCTIONS
 ********************************************************************************************************/
int main(int argc, char** argv)
{
   //appsample();
   //appcluster();
   //WrpTest::WrpSysTestApp app;
   WrpTest::WrpGuiTestApp app;
   app.Initialize();

   WrpTest::TestScreen testscreen;
   app.GetHmiInstance()->Attach(&testscreen);
   app.GetHmiInstance()->LoadScreen(&testscreen);

   SDL_Event e;
   while(1)
   {
      if (SDL_WaitEvent(&e)) {
         if (e.type == SDL_QUIT)
        	 break;
      }
   }
   app.DeInitialize();

   return 0;
}
