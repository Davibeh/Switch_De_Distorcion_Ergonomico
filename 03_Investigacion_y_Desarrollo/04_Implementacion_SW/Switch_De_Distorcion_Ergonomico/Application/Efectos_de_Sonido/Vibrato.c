/*
 * Vibrato.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
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

	if (vfnGetTimerFlag(0))
	{
		vfnLedToggle(PORTB,18);
		
		if (ADC_ConvertioCheck(ADC_CHANNEL))
		{
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



		vfnClearTimerFlag(0);
	}
}
