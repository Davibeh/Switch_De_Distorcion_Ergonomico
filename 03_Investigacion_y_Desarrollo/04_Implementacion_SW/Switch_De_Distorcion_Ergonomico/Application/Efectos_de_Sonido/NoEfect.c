/*
 * NoEfect.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */

#include "NoEffect.h"
unsigned  char  covnersion_ongoing = 0;
unsigned short  adc_readings[200];
unsigned int indice = 0u;
void app_ADC_Trigger(void);
void NoEffect (void)
{
	if (vfnGetTimerFlag(0))
	{
		/*vfnLedToggle(PORTB,18);*/
		if(covnersion_ongoing == 0x01){
		if (ADC_ConvertioCheck(ADC_CHANNEL))
		{
			adc_readings[indice] = ADC_wfnLecture();
			DAC_vfnDisplay(adc_readings[indice]);
			covnersion_ongoing = 0x0;
			indice = (indice+1)%200;
		}
		}else{
			app_ADC_Trigger();
			covnersion_ongoing = 0x1;
		}



		vfnClearTimerFlag(0);
	}
}