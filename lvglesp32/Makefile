# ESP32 LVGL AppCluster/AppSample Project Name
PROJECT_NAME := lvglesp32

#For C++ language flags
EXTRA_CPPFLAGS := -DLV_CONF_INCLUDE_SIMPLE -DILI9341_BCKL_ACTIVE_LVL=0

#Use LVGL library and ILI9341 driver
EXTRA_COMPONENT_DIRS := D:/iotprj/espt/packages/lvgl D:/iotprj/espt/packages/esp32_ili9341/components/drv

#Include headers of LVGL library and headers of ILI9341 driver
COMPONENT_EXTRA_INCLUDES := D:/iotprj/espt/packages D:/iotprj/espt/packages/esp32_ili9341/components

#Define macros for wrpbase
CPPFLAGS += -DLVGL_PC_SIMU=0 -DLVGL_ESP32_ILI9341=1 -DUSE_ESP_IDF=1

#Use wrpbase component
EXTRA_COMPONENT_DIRS += D:/iotprj/espt/wrpbase D:/iotprj/espt/wrpbase/wrpdrv D:/iotprj/espt/wrpbase/wrpsys D:/iotprj/espt/wrpbase/wrpgui D:/iotprj/espt/wrpbase/wrpmidw D:/iotprj/espt/wrpbase/wrphmi

#Use wrpres resource for sample app
EXTRA_COMPONENT_DIRS += D:/iotprj/espt/wrpbase/wrpres D:/iotprj/espt/wrpbase/wrptest

#Use appsample component
EXTRA_COMPONENT_DIRS += D:/iotprj/espt/appcluster D:/iotprj/espt/appsample

#esp-idf platform makefile
include $(IDF_PATH)/make/project.mk
