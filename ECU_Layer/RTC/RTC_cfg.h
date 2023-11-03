/*
 * RTC_cfg.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_RTC_RTC_CFG_H_
#define ECU_LAYER_RTC_RTC_CFG_H_

#define RTC_24HR_SYSTEM     0
#define RTC_12HR_SYSTEM		1

/*
 * Choose from above configurations
 * RTC_24HR_SYSTEM : To deal with 24-hour system
 * RTC_12HR_SYSTEM : To deal with 12-hour system
 * */
#define RTC_TIME_SYSTEM        RTC_12HR_SYSTEM


#endif /* ECU_LAYER_RTC_RTC_CFG_H_ */
