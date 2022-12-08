################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SW3516.c \
../Core/Src/buck_convertor.c \
../Core/Src/lcd_callback.c \
../Core/Src/lcd_progm.c \
../Core/Src/main.c \
../Core/Src/page_3_callback_imp.c \
../Core/Src/pid.c \
../Core/Src/pid_with_adc_read.c \
../Core/Src/real_time_flow.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/SW3516.o \
./Core/Src/buck_convertor.o \
./Core/Src/lcd_callback.o \
./Core/Src/lcd_progm.o \
./Core/Src/main.o \
./Core/Src/page_3_callback_imp.o \
./Core/Src/pid.o \
./Core/Src/pid_with_adc_read.o \
./Core/Src/real_time_flow.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/SW3516.d \
./Core/Src/buck_convertor.d \
./Core/Src/lcd_callback.d \
./Core/Src/lcd_progm.d \
./Core/Src/main.d \
./Core/Src/page_3_callback_imp.d \
./Core/Src/pid.d \
./Core/Src/pid_with_adc_read.d \
./Core/Src/real_time_flow.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/mkhan/git/power_supply_stm32/lcd_program/ugui/inc" -I"/home/mkhan/git/power_supply_stm32/lcd_program/ugui" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/SW3516.d ./Core/Src/SW3516.o ./Core/Src/SW3516.su ./Core/Src/buck_convertor.d ./Core/Src/buck_convertor.o ./Core/Src/buck_convertor.su ./Core/Src/lcd_callback.d ./Core/Src/lcd_callback.o ./Core/Src/lcd_callback.su ./Core/Src/lcd_progm.d ./Core/Src/lcd_progm.o ./Core/Src/lcd_progm.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/page_3_callback_imp.d ./Core/Src/page_3_callback_imp.o ./Core/Src/page_3_callback_imp.su ./Core/Src/pid.d ./Core/Src/pid.o ./Core/Src/pid.su ./Core/Src/pid_with_adc_read.d ./Core/Src/pid_with_adc_read.o ./Core/Src/pid_with_adc_read.su ./Core/Src/real_time_flow.d ./Core/Src/real_time_flow.o ./Core/Src/real_time_flow.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

