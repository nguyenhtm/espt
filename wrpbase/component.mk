# for mongoose websocket need to build as part of wrpbase -> add this source here
COMPONENT_SRCDIRS := . \
    wrpdrv             \
    wrpgui             \
    wrpsys             \
    wrphmi             \
    wrpmidw            \
    wrptest            \
    wrpres             \
    ../packages/mongoose_lib

COMPONENT_ADD_INCLUDEDIRS := $(COMPONENT_SRCDIRS) ..
