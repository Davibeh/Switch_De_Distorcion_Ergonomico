/*
 * Vibrato.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 * Description: Alfa variant integration to the Beta variant:
 * 				1- Remove the check for the PIT flag, now this task is executed at interrupt level.
 * 				2- New managed of the ADC conversion, now the conversion is triggered and a wait for complete retains the core
 * 				3- Cleaning the code
 */

#include "Vibrato.h"

#define ADC_CHANNEL             0

#define POT_ADC_CHANNEL         3

#define	TIME				    490// 20kHz

#define RED_LED_MASK   (1<<18)

static unsigned long wVibrato = 1;

static unsigned short wStep = 1000;

static unsigned short wData;

static unsigned short wData1;

static unsigned long  dwcorrimiento;

static unsigned short wCounterUPDown = 0;

void vfnVibrato (void)
{
			app_ADC_Trigger(APP_ADC_CHANNEL); /*Trigger the ADC channel conversion*/
			while(ADC_ConvertioCheck(ADC_CHANNEL) != TRUE); /*This might be very dangerous. Need to determine if we may need to implement a timeout strategy*/

			wData1 = ADC_wfnLecture();
			wData = ((wData1*wVibrato)>>20);

			if (wVibrato >= 1000000)
			{
				wCounterUPDown = 1;
			}

			if (wCounterUPDown) 
			{
				wVibrato = wVibrato - wStep;

				if (wVibrato <= 1)
				{
					wCounterUPDown = 0;
				}
			}
			else
			{
				wVibrato = wVibrato + wStep;
			}

			DAC_vfnDisplay(wData);
}
