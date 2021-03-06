/*
 * Vibrato.h
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
  * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description: Change the application to work with the ADC interface. The headers were replaced  a new type def
 *              file was added. And wrappers as definitions were made in order to reduce the impact in the original code.
 */

#ifndef VIBRATO_H_
#define VIBRATO_H_

#include "stdtypedef.h" /*Type def of the system*/
#include "app_ADC.h" /*ADC interface header*/
#include "app_DAC.h" /*ADC interface header*/

/*Wrapper definitions in order to reduce the code impact*/
#define ADC_ConvertioCheck(x) app_ADC_IsConversionCompleted() /*To check if the conversion was completed*/
#define ADC_wfnLecture() app_ADC_GetValue() /*To get the converted value*/
#define DAC_vfnDisplay(x) app_DAC_SetValue(x) /*To ser the value to the DAC*/

/*******Public header for the main function********************/
void vfnVibrato (void); 
#endif /* VIBRATO_H_ */
