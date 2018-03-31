/*
 * Electromiografo.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */

#include "Electromiografo.h"

#define NUMBER_OF_SAMPLES  250

unsigned char vfnElectromiografo (void)
{
	static unsigned char TreshHold = 0;
	static unsigned char EfectState = 0;
	static unsigned long dwSignalAverage = 0;
	static unsigned char bAmountOfData = 0;
	
	if(vfnGetTimerFlag(1))
	{
		if (ADC_ConvertioCheck(3))
		{
			dwSignalAverage += ADC_wfnLecture();
			bAmountOfData++;
		}


		if (bAmountOfData == NUMBER_OF_SAMPLES)
		{
			dwSignalAverage = dwSignalAverage/NUMBER_OF_SAMPLES;

			if ( dwSignalAverage > 1300)
			{
				TreshHold = 1;
			}
			else
			{
				TreshHold = 0;
			}
			dwSignalAverage = 0;
			bAmountOfData = 0;

		}

		if (TreshHold)
		{
			if (!EfectState)
			{
				EfectState = 1;
			}
		}
		else
		{
			if (EfectState)
			{
				EfectState = 0;
			}
		}
		vfnClearTimerFlag(1);
	}
	return EfectState;
}
