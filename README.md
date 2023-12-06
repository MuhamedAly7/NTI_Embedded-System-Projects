# NTI_Embedded-System-Projects

# Overview

This repository implements various drivers on the Atmega32 microcontroller, organized into the MCAL (Microcontroller Abstraction Layer) and ECU (Electronic Control Unit) layers. The drivers cover essential functionalities such as timers, interrupts, communication protocols (UART, SPI, I2C), GPIO, ADC, and more.
File Structure

The project is structured into two main layers:

   ## MCAL Layer: Low-level drivers for microcontroller peripherals.
   - Timer1
   - Timer0
   - Interrupt
   - WatchDog
   - UART
   - SPI
   - I2C
   - GPIO
   - ADC

   ## ECU Layer: High-level drivers for Electronic Control Units.
   - LCD
   - Ultrasonic
   - Seven-Segment
   - RTC (Real-Time Clock)
   - LM35 (Temperature Sensor)
   - LED
   - Keypad
   - Fingerprint
   - EEROM
   - DC Motor
   - Button

Build Configuration

The project uses the provided makefile for building. The makefile includes automatic dependency generation based on the source files. The build artifacts include:

    NTI_MohamedAli.elf: Executable file.
    NTI_MohamedAli.hex: Flash image in Intel HEX format.
    NTI_MohamedAli.eep: EEPROM image in Intel HEX format.
    NTI_MohamedAli.lss: Extended listing.
    sizedummy: Display size information.

## Build Instructions

To build the project, run the following command:

bash

make all

To clean the build artifacts, run:

bash

make clean

## Target MCU and Toolchain

The project targets the Atmega32 microcontroller and uses the AVR-GCC toolchain. The build parameters are specified in the makefile.
Additional Information

    The project automatically generates dependency files for each source file.
    Size information is displayed using the avr-size tool.

## Author

This project is authored and maintained by Mohamed Ali.

## LinkedIn
www.linkedin.com/in/mohamedali97/

Feel free to explore and contribute to the project!
