/*
 * app_ADC.h
 *
 *  Created on: 07/03/2018
 *      Author: uidj2522
 */

#ifndef APP_ADC_H_
#define APP_ADC_H_

#define APP_ADC_CHANNEL 		0u
#define APP_ADC_CHANNEL_GROUP 	0u


#include "stdtypedef.h"

 /******************************************
 * Public Macros
 ******************************************/
 
 /******************************************
 * Public Typedef
 ******************************************/
 
 /******************************************
 * Public Const
 ******************************************/
 
 /******************************************
 * Public Variables
 ******************************************/
 
 /******************************************
 * Public Prototypes
 ******************************************/
extern void app_ADC_Init(void);
extern void app_ADC_Task(void);
extern T_UBYTE app_ADC_IsConversionCompleted(void);
extern T_UWORD app_ADC_GetValue(void);
extern void app_DAC_SetValue(T_UWORD luw_DacValue);
extern void app_ADC_Trigger(T_UBYTE ADC_Channel);

#endif /* APP_ADC_H_ */
