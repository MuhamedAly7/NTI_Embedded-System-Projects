/*
 * ADC.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_ADC_ADC_H_
#define MCAL_LAYER_ADC_ADC_H_

/* --------------------------- Includes Start ------------------------- */
#include "ADC_cfg.h"
#include "../../PRIV/Atmega32.h"
#include "../std_types.h"
#include "../std_libraries.h"
#include "../GPIO/GPIO.h"


/* ----------------------- Macro Declarations Start ------------------- */

// select Single ended channels
#define ADC0_CHANNEL_SE_SELECT          0
#define ADC1_CHANNEL_SE_SELECT          1
#define ADC2_CHANNEL_SE_SELECT          2
#define ADC3_CHANNEL_SE_SELECT          3
#define ADC4_CHANNEL_SE_SELECT          4
#define ADC5_CHANNEL_SE_SELECT          5
#define ADC6_CHANNEL_SE_SELECT          6
#define ADC7_CHANNEL_SE_SELECT          7

// To select adjustfication
#define ADC_LEFT_ADJUSTED               1
#define ADC_RIGHT_ADJUSTED              0

// to select voltage reference
#define ADC_INTERNAL_VREF_TURNED_OFF    0
#define ADC_AVCC_EXTERNAL_AT_AREF       1
#define ADC_INTERNAL_VREF_AT_AREF       3


// To select prescaler
#define ADC_PRESCALER_DIV_2             0
#define ACD_PRESCALER_DIV_4             2
#define ADC_PRESCALER_DIV_8             3
#define ADC_PRESCALER_DIV_16            4
#define ADC_PRESCALER_DIV_32            5
#define ADC_PRESCALER_DIV_64            6
#define ADC_PRESCALER_DIV_128           7

// to write on the trigger bit
#define ADC_AUTO_TRIGGER_ENABLE         1
#define ADC_AUTO_TRIGGER_DISABLE        0

// to start conversion
#define ADC_START_CONVERSION            1

// To enable or disable trigger source
#define ADC_ENABLE                      1
#define ADC_DISABLE                     0


// To select trigger source
#define ADC_SELECT_TRIGGER_FREE_SOURCE                0
#define ADC_SELECT_TRIGGER_ANALOG_COMPARATOR          1
#define ADC_SELECT_TRIGGER_EXTERNAL_INTERRUPT_REQ_0   2
#define ADC_SELECT_TRIGGER_TIMER0_COMPARE_MATCH       3
#define ADC_SELECT_TRIGGER_TIMER0_OVERFLOW            4
#define ADC_SELECT_TRIGGER_TIMER0_COMPARE_MATCH_B     5
#define ADC_SELECT_TRIGGER_TIMER1_OVERFLOW            6
#define ADC_SELECT_TRIGGER_TIMER1_CAPTURE_EVENT       7

/* ------------------ Macro Function Declarations Start --------------- */

// To Enable or Disable ADC
#define ADC_ENABLE_CFG()                          (ADC_MAP->ADCSRA_REG.ADEN = ADC_ENABLE)
#define ADC_DISABLE_CFG()                         (ADC_MAP->ADCSRA_REG.ADEN = ADC_DISABLE)
// To start conversion
#define ADC_START_CONVERSION_CFG()                (ADC_MAP->ADCSRA_REG.ADSC = ADC_START_CONVERSION)
// To enable or disable auto trigger
#define ADC_AUTO_TRIGGER_ENABLE_CONFIG()          (ADC_MAP->ADCSRA_REG.ADATE = ADC_AUTO_TRIGGER_ENABLE)
#define ADC_AUTO_TRIGGER_DISABLE_CONFIG()         (ADC_MAP->ADCSRA_REG.ADATE = ADC_AUTO_TRIGGER_DISABLE)
// to select trigger source
#define ADC_SELECT_TRIGGER_SOURCE_EVENT(SOURCE)   (ADC_MAP->SFIOR_REG.ADTS = SOURCE)
// To select voltage reference
#define ADC_SELECT_VOLTAGE_REF_CFG(REF)           (ADC_MAP->ADMUX_REG.REFS = REF)
// To select channels
#define ADC_SELECT_CHANNEL_CFG(CHANNEL)           (ADC_MAP->ADMUX_REG.MUX = CHANNEL)
// To select adjustification
#define ADC_SELECT_ADJUSTTFICATION(ADJUST)        (ADC_MAP->ADMUX_REG.ADLAR = ADJUST)
// To select prescaler
#define ADC_SELECT_PRESCALER(PRESCALER)           (ADC_MAP->ADCSRA_REG.ADPS = PRESCALER)



/* -------------------- Data Type Declarations Start ------------------ */


typedef struct{
	//u8 select_channel           : 5;
	u8 select_trigger_source    : 3;
	u8 voltage_reference_select : 2;
	u8 adjustification_select   : 1;
	u8 prescaler_select         : 1;
	u8 reserved                 : 1;
}ADC_cfg_t;

/* --------------- Software Interfaces Declarations Start ------------- */
void ADC_voidInit(const ADC_cfg_t *ADC_obj);
void ADC_getDigitalValueSynchNonBlocking(u8 Copy_u8Channel);
#endif /* MCAL_LAYER_ADC_ADC_H_ */
