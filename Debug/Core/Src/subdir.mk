################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/beep.c \
../Core/Src/burst.c \
../Core/Src/delay.c \
../Core/Src/distanceProc.c \
../Core/Src/ds18b20.c \
../Core/Src/font.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/iwdg.c \
../Core/Src/lightbar.c \
../Core/Src/main.c \
../Core/Src/oled.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tim.c 

OBJS += \
./Core/Src/beep.o \
./Core/Src/burst.o \
./Core/Src/delay.o \
./Core/Src/distanceProc.o \
./Core/Src/ds18b20.o \
./Core/Src/font.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/iwdg.o \
./Core/Src/lightbar.o \
./Core/Src/main.o \
./Core/Src/oled.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tim.o 

C_DEPS += \
./Core/Src/beep.d \
./Core/Src/burst.d \
./Core/Src/delay.d \
./Core/Src/distanceProc.d \
./Core/Src/ds18b20.d \
./Core/Src/font.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/iwdg.d \
./Core/Src/lightbar.d \
./Core/Src/main.d \
./Core/Src/oled.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/beep.cyclo ./Core/Src/beep.d ./Core/Src/beep.o ./Core/Src/beep.su ./Core/Src/burst.cyclo ./Core/Src/burst.d ./Core/Src/burst.o ./Core/Src/burst.su ./Core/Src/delay.cyclo ./Core/Src/delay.d ./Core/Src/delay.o ./Core/Src/delay.su ./Core/Src/distanceProc.cyclo ./Core/Src/distanceProc.d ./Core/Src/distanceProc.o ./Core/Src/distanceProc.su ./Core/Src/ds18b20.cyclo ./Core/Src/ds18b20.d ./Core/Src/ds18b20.o ./Core/Src/ds18b20.su ./Core/Src/font.cyclo ./Core/Src/font.d ./Core/Src/font.o ./Core/Src/font.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/iwdg.cyclo ./Core/Src/iwdg.d ./Core/Src/iwdg.o ./Core/Src/iwdg.su ./Core/Src/lightbar.cyclo ./Core/Src/lightbar.d ./Core/Src/lightbar.o ./Core/Src/lightbar.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/oled.cyclo ./Core/Src/oled.d ./Core/Src/oled.o ./Core/Src/oled.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su

.PHONY: clean-Core-2f-Src

