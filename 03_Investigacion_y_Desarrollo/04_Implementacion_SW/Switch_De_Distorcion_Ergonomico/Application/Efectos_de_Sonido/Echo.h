/*
 * Echo.h
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */

#ifndef ECHO_H_
#define ECHO_H_
/*David bellomo Commented just for now*/
//#include "ADC_Driver.h"
//#include "DACDriver.h"
//#include "PITDriver.h"
//#include "GPIODriver.h"

/*David Bellomo just for now because I need to  check if it works*/
#include "stdtypedef.h"
#include "app_ADC.h"
#include "app_DAC.h"
extern T_UBYTE	rub_PITAlarm;
extern T_UBYTE app_ADC_IsConversionCompleted(void);
extern T_UWORD app_ADC_GetValue(void);
extern   void app_DAC_SetValue(T_UWORD luw_DacValue);

#define vfnGetTimerFlag(x) rub_PITAlarm
#define vfnClearTimerFlag(x)  rub_PITAlarm = 0u
#define ADC_ConvertioCheck(x) app_ADC_IsConversionCompleted()
#define ADC_wfnLecture() app_ADC_GetValue()
#define DAC_vfnDisplay(x) app_DAC_SetValue(x)
void vfnEcho (void);


#endif /* ECHO_H_ */