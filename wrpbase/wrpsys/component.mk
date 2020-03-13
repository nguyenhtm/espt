#wrpsys
#for mongoose websocket need to build as part of wrpsys -> add this source here
COMPONENT_SRCDIRS := . \
                     ../../packages/mongoose_lib

#for include headers: current source dir, and wrbase.hpp in previous dir
COMPONENT_ADD_INCLUDEDIRS := $(COMPONENT_SRCDIRS) ../../
