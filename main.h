/*
 * main.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "MCAL_Layer/GPIO/GPIO.h"
#include "MCAL_Layer/timer0/timer0.h"
#include "MCAL_Layer/timer1/timer1.h"
#include "MCAL_Layer/ADC/ADC.h"
#include "MCAL_Layer/interrupt/ext_interrupt.h"
#include "MCAL_Layer/interrupt/GIE_interrupt.h"
#include "MCAL_Layer/UART/UART.h"
#include "MCAL_Layer/SPI/SPI.h"
#include "MCAL_Layer/WatchDog/WatchDog.h"
#include "MCAL_Layer/std_types.h"
#include "ECU_Layer/Keypad/keypad.h"
#include "ECU_Layer/SevenSegment/seven_segment.h"
#include "ECU_Layer/lcd/char_lcd.h"
#include "ECU_Layer/LED/LED.h"
#include "ECU_Layer/EEROM/EEPROM.h"
#include "ECU_Layer/RTC/RTC.h"
#include "ECU_Layer/Ultrasonic/Ultrasonic.h"
#include <util/delay.h>

#endif /* MAIN_H_ */
