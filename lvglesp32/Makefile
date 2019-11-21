#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := lvglesp32

# Add new components (source folders)
# Must be before include $(IDF_PATH)/make/project.mk
# $(PROJECT_PATH)/xxx didn't work -> use $(abspath xxx) instead
#EXTRA_COMPONENT_DIRS := $(abspath drv)	$(abspath lvgl) $(abspath lv_examples)

# Build lvgl component in iotprj/packages/lvgl, drv in its own, and wrpbase iotprj/wrpbase
EXTRA_CFLAGS := -DLV_CONF_INCLUDE_SIMPLE
EXTRA_COMPONENT_DIRS := D:/iotprj/packages/lvgl D:/iotprj/lvglesp32/components/drv D:/iotprj/wrpbase D:/iotprj/appsample

# Include lv_conf.h if using main.cpp
EXTRA_CPPFLAGS := -DLV_CONF_INCLUDE_SIMPLE
COMPONENT_EXTRA_INCLUDES := D:/iotprj/packages D:/iotprj/packages/esp32_ili9341/components

CPPFLAGS += -DLVGL_PC_SIMU=0 -DLVGL_ESP32_ILI9341=1 -DUSE_ESP_IDF=1

include $(IDF_PATH)/make/project.mk
