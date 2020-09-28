# ESP32 LVGL SampleApp Project Name
PROJECT_NAME := lvglesp32

#For C++ language flags
EXTRA_CPPFLAGS := -DLV_CONF_INCLUDE_SIMPLE -DILI9341_BCKL_ACTIVE_LVL=0

#Use LVGL library and ILI9341 driver
EXTRA_COMPONENT_DIRS := D:/iotprj/packages/lvgl D:/iotprj/packages/esp32_ili9341/components/drv

#Include headers of LVGL library and headers of ILI9341 driver
COMPONENT_EXTRA_INCLUDES := D:/iotprj/packages D:/iotprj/packages/esp32_ili9341/components

#Define macros for wrpbase
CPPFLAGS += -DLVGL_PC_SIMU=0 -DLVGL_ESP32_ILI9341=1 -DUSE_ESP_IDF=1
#Use wrpbase component
EXTRA_COMPONENT_DIRS += D:/iotprj/wrpbase/wrpdrv D:/iotprj/wrpbase/wrpsys D:/iotprj/wrpbase/wrpgui D:/iotprj/wrpbase/wrpmidw D:/iotprj/wrpbase/wrphmi D:/iotprj/wrpbase/wrpres

#Use appsample component
EXTRA_COMPONENT_DIRS += D:/iotprj/appsample

#esp-idf platform makefile
include $(IDF_PATH)/make/project.mk


