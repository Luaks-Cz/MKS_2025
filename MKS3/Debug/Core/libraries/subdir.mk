################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/libraries/basicUtil.c \
../Core/libraries/sct.c 

OBJS += \
./Core/libraries/basicUtil.o \
./Core/libraries/sct.o 

C_DEPS += \
./Core/libraries/basicUtil.d \
./Core/libraries/sct.d 


# Each subdirectory must supply rules for building sources it contributes
Core/libraries/%.o Core/libraries/%.su Core/libraries/%.cyclo: ../Core/libraries/%.c Core/libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030x8 -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Luaks/Documents/GitHub/MKS_2025/MKS3/Core/libraries" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-libraries

clean-Core-2f-libraries:
	-$(RM) ./Core/libraries/basicUtil.cyclo ./Core/libraries/basicUtil.d ./Core/libraries/basicUtil.o ./Core/libraries/basicUtil.su ./Core/libraries/sct.cyclo ./Core/libraries/sct.d ./Core/libraries/sct.o ./Core/libraries/sct.su

.PHONY: clean-Core-2f-libraries

