/*
 * WatchDog_Priv.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_WATCHDOG_WATCHDOG_PRIV_H_
#define MCAL_LAYER_WATCHDOG_WATCHDOG_PRIV_H_

#include "../std_types.h"

#define WATCHDOG_BASE        0x41

typedef struct {
	u8 WDP_BITS   : 3;
	u8 WDE_BIT    : 1;
	u8 WDTOE_BIT  : 1;
	u8 RESERVED   : 3;
}WDTCR_R;

#define WDTCR_REG        (*((volatile u8 *)WATCHDOG_BASE))
#define WATCHDOG_CONTROL ((volatile WDTCR_R *)WATCHDOG_BASE)

#endif /* MCAL_LAYER_WATCHDOG_WATCHDOG_PRIV_H_ */
