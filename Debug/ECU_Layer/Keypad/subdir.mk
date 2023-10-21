################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_Layer/Keypad/keypad.c 

OBJS += \
./ECU_Layer/Keypad/keypad.o 

C_DEPS += \
./ECU_Layer/Keypad/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_Layer/Keypad/%.o: ../ECU_Layer/Keypad/%.c ECU_Layer/Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


