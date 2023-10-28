/*
 * char_lcd_cfg.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_LCD_CHAR_LCD_CFG_H_
#define ECU_LAYER_LCD_CHAR_LCD_CFG_H_

// to select lcd mode
#define LCD_4_BIT_MODE_SELECT       0
#define LCD_8_BIT_MODE_SELECT       1
#define LCD_MODE_SELECT             LCD_4_BIT_MODE_SELECT

// lcd port configurations
#define LCD_PORTA_POS               0
#define LCD_PORTB_POS               1
#define LCD_PORTC_POS               2
#define LCD_PORTD_POS               3

// lcd pin configurations
#define LCD_PIN0_POS                0
#define LCD_PIN1_POS                1
#define LCD_PIN2_POS                2
#define LCD_PIN3_POS                3
#define LCD_PIN4_POS                4
#define LCD_PIN5_POS                5
#define LCD_PIN6_POS                6
#define LCD_PIN7_POS                7



#if LCD_MODE_SELECT == LCD_4_BIT_MODE_SELECT

// LCD ports configurations
#define LCD_4BIT_RS_PIN_PORT      LCD_PORTA_POS
#define LCD_4BIT_EN_PIN_PORT      LCD_PORTA_POS
#define LCD_4BIT_D7_PIN_PORT      LCD_PORTB_POS
#define LCD_4BIT_D6_PIN_PORT      LCD_PORTB_POS
#define LCD_4BIT_D5_PIN_PORT      LCD_PORTB_POS
#define LCD_4BIT_D4_PIN_PORT      LCD_PORTB_POS

// LCD pins configurations
#define LCD_4BIT_RS_PIN           LCD_PIN3_POS
#define LCD_4BIT_EN_PIN           LCD_PIN2_POS
#define LCD_4_BIT_D7_PIN          LCD_PIN0_POS
#define LCD_4_BIT_D6_PIN          LCD_PIN1_POS
#define LCD_4_BIT_D5_PIN          LCD_PIN2_POS
#define LCD_4_BIT_D4_PIN          LCD_PIN4_POS

#elif LCD_MODE_SELECT == LCD_8_BIT_MODE_SELECT
#define LCD_8BIT_RS_PIN
#define LCD_8BIT_EN_PIN
#define LCD_8_BIT_D7_PIN
#define LCD_8_BIT_D6_PIN
#define LCD_8_BIT_D5_PIN
#define LCD_8_BIT_D4_PIN
#define LCD_8_BIT_D3_PIN
#define LCD_8_BIT_D2_PIN
#define LCD_8_BIT_D1_PIN
#define LCD_8_BIT_D0_PIN

#else
#error "Mode is not defined"
#endif




#endif /* ECU_LAYER_LCD_CHAR_LCD_CFG_H_ */
