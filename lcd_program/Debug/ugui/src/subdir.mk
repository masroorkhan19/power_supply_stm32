################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ugui/src/ugui.c \
../ugui/src/ugui_ST7789.c 

OBJS += \
./ugui/src/ugui.o \
./ugui/src/ugui_ST7789.o 

C_DEPS += \
./ugui/src/ugui.d \
./ugui/src/ugui_ST7789.d 


# Each subdirectory must supply rules for building sources it contributes
ugui/src/%.o ugui/src/%.su: ../ugui/src/%.c ugui/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Syed Mir Hamza/git/power_supply_stm32/lcd_program/ugui/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ugui-2f-src

clean-ugui-2f-src:
	-$(RM) ./ugui/src/ugui.d ./ugui/src/ugui.o ./ugui/src/ugui.su ./ugui/src/ugui_ST7789.d ./ugui/src/ugui_ST7789.o ./ugui/src/ugui_ST7789.su

.PHONY: clean-ugui-2f-src

