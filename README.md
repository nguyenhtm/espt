Purpose:
Create a tutorial sample app which can be run on ESP32 platform using ESP-WROVER-KIT V3 Kit and on Windows platform using SDL Simulator
Video: https://www.youtube.com/watch?v=6uVoYXjuBhI

Step1
+ Create a folder to contain the sample app like D:\iotprj
+ Enter to D:\iotprj: git clone --recursive https://github.com/nguyenhtm/espt

Step2
Enter to D:\iotprj\buildtools
+ D:\iotprj\buildtools\mingw-w64: download mingw-w64-install.exe at  http://mingw-w64.org/doku.php/download
+ D:\iotprj\buildtools\msys32: download esp32_win32_msys2_environment_and_toolchain-20181001.zip at https://docs.espressif.com/projects/esp-idf/en/stable/get-started/windows-setup.html
+ D:\iotprj\buildtools\eclipse: download eclipse-cpp-2019-03-R-win32-x86_64.zip at https://www.eclipse.org/downloads/packages/file/55067

Step3
Enter to D:\iotprj\packages
+ D:\iotprj\packages\esp-idf: git clone --recursive https://github.com/espressif/esp-idf.git
+ D:\iotprj\packages\lvgl: git clone --recursive https://github.com/littlevgl/lvgl.git
+ D:\iotprj\packages\pc_simulator_sdl_eclipse: git clone --recursive https://github.com/littlevgl/pc_simulator_sdl_eclipse.git
+ D:\iotprj\packages\esp32_ili9341: git clone --recursive https://github.com/littlevgl/esp32_ili9341.git
+ D:\iotprj\packages\SDL2-2.0.5: download the SDL2-devel-2.0.5-mingw.tar.gz file at https://www.libsdl.org/release
+ D:\iotprj\packages\mongoose: git clone https://github.com/cesanta/mongoose
+ Create D:\iotprj\packages\mongoose_lib and copy 2 D:\iotprj\packages\mongoose\mongoose.c and mongoose.h files to it
