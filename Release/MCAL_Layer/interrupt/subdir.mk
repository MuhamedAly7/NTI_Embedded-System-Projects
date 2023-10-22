################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_Layer/interrupt/ext_interrupt.c 

OBJS += \
./MCAL_Layer/interrupt/ext_interrupt.o 

C_DEPS += \
./MCAL_Layer/interrupt/ext_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_Layer/interrupt/%.o: ../MCAL_Layer/interrupt/%.c MCAL_Layer/interrupt/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


