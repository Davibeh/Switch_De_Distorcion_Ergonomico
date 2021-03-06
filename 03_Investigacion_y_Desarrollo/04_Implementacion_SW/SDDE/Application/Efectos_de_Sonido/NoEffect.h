/*
 * NoEfect.h
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
  * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description: Change the application to work with the ADC interface. The headers were replaced  a new type def
 *              file was added. And wrappers as definition were made in order to reduce the impact in the original code.
 */

#ifndef NOEFECT_H_
#define NOEFECT_H_





#include "stdtypedef.h"
#include "app_ADC.h"
#include "app_DAC.h"



/*Wrapper definitions in order to reduce the code impact*/
#define ADC_ConvertioCheck(x) app_ADC_IsConversionCompleted()
#define ADC_wfnLecture() app_ADC_GetValue()
#define DAC_vfnDisplay(x) app_DAC_SetValue(x)


extern void NoEffect (void);


#endif /* NOEFECT_H_ */
