################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_Layer/SevenSegment/seven_segment.c 

OBJS += \
./ECU_Layer/SevenSegment/seven_segment.o 

C_DEPS += \
./ECU_Layer/SevenSegment/seven_segment.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_Layer/SevenSegment/%.o: ../ECU_Layer/SevenSegment/%.c ECU_Layer/SevenSegment/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


