/*
 * GPIO.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_GPIO_GPIO_H_
#define MCAL_LAYER_GPIO_GPIO_H_

/*------------------------------------------ Includes -----------------------------------------*/
#include "./../std_types.h"
#include "./../std_libraries.h"
#include "GPIO_Priv.h"
#include "GPIO_cfg.h"
#include "../../math.h"

/*----------------------------------------- Macros objects ------------------------------------*/

#define NUM_PORTS 4
#define NUM_PINS  8

/*----------------------------------------- Macros functions ----------------------------------*/


/*----------------------------------------- User types -----------------------------------------*/

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX
}Port_index_t;

typedef enum{
    PIN0_INDEX,
    PIN1_INDEX,
    PIN2_INDEX,
    PIN3_INDEX,
    PIN4_INDEX,
    PIN5_INDEX,
    PIN6_INDEX,
    PIN7_INDEX
}Pin_index_t;

typedef enum{
    GPIO_DIRECTION_INPUT = 0,
    GPIO_DIRECTION_OUTPUT = 1
}Direction_type;

typedef enum{
    GPIO_LOW,
    GPIO_HIGH
}Logic_t;


/*------------------------------------------API's------------------------------------------------*/
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,  u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);
void DIO_voidTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);
void DIO_voidSetPortDirection(u8 Copy_u8PortId,  u8 Copy_u8Direction);
void DIO_voidSetPortValues(u8 Copy_u8PortId, u8 Copy_u8Value);
u8 DIO_u8GetPortValues(u8 Copy_u8PortId);

#endif /* MCAL_LAYER_GPIO_GPIO_H_ */
