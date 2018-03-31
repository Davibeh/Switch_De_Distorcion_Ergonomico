/*
 * Distorcion.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */
#include "Distorcion.h"

static unsigned short wMaxParameter = 500;

static unsigned short wDataToDAC;

void vfnDistorcion (void)
{
	if (vfnGetTimerFlag(0))
	{
		vfnLedToggle(PORTB,18);
		
		if (ADC_ConvertioCheck(ADC_CHANNEL))
		{

			if (4096 - wMaxParameter <= ADC_wfnLecture())
			{
				wDataToDAC = 4096;
			}
			else
			{
				wDataToDAC = ADC_wfnLecture();
			}
			if (wMaxParameter >= ADC_wfnLecture())
			{
				wDataToDAC = 0;
			}
			else
			{
				wDataToDAC = ADC_wfnLecture();
			}
			DAC_vfnDisplay(wDataToDAC);
		}

		vfnClearTimerFlag(0);
	}
}
