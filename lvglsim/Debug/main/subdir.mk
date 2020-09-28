################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main/main.cpp 

OBJS += \
./main/main.o 

CPP_DEPS += \
./main/main.d 


# Each subdirectory must supply rules for building sources it contributes
main/%.o: ../main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	i686-w64-mingw32-g++ -DLV_CONF_INCLUDE_SIMPLE=1 -DLVGL_PC_SIMU=1 -I"D:\iotprj\espt\lvglsim" -I"D:\iotprj\espt" -I"D:\iotprj\espt\packages" -I"D:\iotprj\espt\packages\mongoose_lib" -I"D:\iotprj\espt\packages\SDL2-2.0.5\i686-w64-mingw32\include" -I"D:\iotprj\espt\packages\pc_simulator_sdl_eclipse" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


