/*
 * WatchDog.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_WATCHDOG_WATCHDOG_H_
#define MCAL_LAYER_WATCHDOG_WATCHDOG_H_

#include "WatchDog_cfg.h"
#include "WatchDog_Priv.h"

/* --------------------------------------------- Macros objects ------------------------------- */
#define WDT_TIMEOUT_16MS        0
#define WDT_TIMEOUT_32MS        1
#define WDT_TIMEOUT_65MS        2
#define WDT_TIMEOUT_01S         3
#define WDT_TIMEOUT_026S        4
#define WDT_TIMEOUT_052S        5
#define WDT_TIMEOUT_1S          6
#define WDT_TIMEOUT_2S          7


#define WDTOE_POS               4
#define WDE_POS                 3

/* --------------------------------------------- APIs ----------------------------------------- */
void WDT_Enable(void);
void WDT_Disable(void);
void WDT_sleep(u8 sleepTime);
void WDT_refresh(void);


#endif /* MCAL_LAYER_WATCHDOG_WATCHDOG_H_ */
