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
#include "../../PRIV/Atmega32.h"
#include "GPIO_cfg.h"

/*----------------------------------------- Macros objects ------------------------------------*/

#define NUM_PORTS 4

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

/* this struct to configure my GPIO per one pin */
typedef struct{
    u8 port       : 3; // receive numbers from  Port_index_t
    u8 pin        : 3; // receive numbers from  Pin_index_t
    u8 direction  : 1; // receive numbers from  Direction_type
    u8 logic      : 1; // receive numbers from  Logic_t
}GPIO_CFG_T;


/*------------------------------------------API's------------------------------------------------*/
PROGRAM_STATUS_T DIO_SetPinDirection(const GPIO_CFG_T *obj);
PROGRAM_STATUS_T DIO_SetPinValue(const GPIO_CFG_T *obj, Logic_t logic);
PROGRAM_STATUS_T DIO_GetPinValue(const GPIO_CFG_T *obj, u8 *pin_value);
PROGRAM_STATUS_T DIO_SetPortDirection(Port_index_t port_index, u8 directions);
PROGRAM_STATUS_T DIO_SetPortValues(Port_index_t port_index, u8 values);
PROGRAM_STATUS_T DIO_GetPortValues(Port_index_t port_index, u8 *port_value);

#endif /* MCAL_LAYER_GPIO_GPIO_H_ */
