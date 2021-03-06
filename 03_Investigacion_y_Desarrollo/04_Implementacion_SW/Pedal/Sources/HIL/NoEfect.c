/*
 * NoEfect.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */

#include "NoEffect.h"

void NoEffect (void)
{
	if (vfnGetTimerFlag(0))
	{
		vfnLedToggle(PORTB,18);
		
		if (ADC_ConvertioCheck(ADC_CHANNEL))
		{
			DAC_vfnDisplay(ADC_wfnLecture());
		}

		vfnClearTimerFlag(0);
	}
}
