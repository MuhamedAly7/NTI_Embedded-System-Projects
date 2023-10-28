/*
 * seven_segment_cfg.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_SEVENSEGMENT_SEVEN_SEGMENT_CFG_H_
#define ECU_LAYER_SEVENSEGMENT_SEVEN_SEGMENT_CFG_H_


// port configurations
#define POTRA_POS   0
#define PORTB_POS   1
#define PORTC_POS   2
#define PORTD_POS   3

#define SEVEN_SEGMENT_PIN0      0
#define SEVEN_SEGMENT_PIN1      1
#define SEVEN_SEGMENT_PIN2      2
#define SEVEN_SEGMENT_PIN3      3
#define SEVEN_SEGMENT_PIN4      4
#define SEVEN_SEGMENT_PIN5      5
#define SEVEN_SEGMENT_PIN6      6
#define SEVEN_SEGMENT_PIN7      7

// pins configurations
#define SEGMENT_PIN0_POS    SEVEN_SEGMENT_PIN0
#define SEGMENT_PIN1_POS    SEVEN_SEGMENT_PIN1
#define SEGMENT_PIN2_POS    SEVEN_SEGMENT_PIN2
#define SEGMENT_PIN3_POS    SEVEN_SEGMENT_PIN4



// seven segments pins
#define SEGMENT_PIN0      SEGMENT_PIN0_POS
#define SEGMENT_PIN1      SEGMENT_PIN1_POS
#define SEGMENT_PIN2      SEGMENT_PIN2_POS
#define SEGMENT_PIN3      SEGMENT_PIN3_POS

// seven segments ports per pins
#define SEGMENT_PIN0_PORT PORTB_POS
#define SEGMENT_PIN1_PORT PORTB_POS
#define SEGMENT_PIN2_PORT PORTB_POS
#define SEGMENT_PIN3_PORT PORTB_POS


#endif /* ECU_LAYER_SEVENSEGMENT_SEVEN_SEGMENT_CFG_H_ */
