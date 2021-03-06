/*
 * Echo.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */

#include "Echo.h"

#define AUIDIO_SIGNAL_ADC_CHANNEL             0

#define POT_ADC_CHANNEL                       0x03

#define	TIME				                  490// 20kHz

#define RED_LED_MASK  						 (1<<18)

#define TOGGLE_RED_LED                        GPIOB_PTOR |= RED_LED_MASK;

#define RESET                                 0

#define MAX_NUMBER     						  4090
	

static unsigned short wOffsetDAC = MAX_NUMBER;

static unsigned short wOffsetADC = RESET;

static unsigned short wArray[4096] = {0};

static unsigned short *PtrArray = wArray;

static unsigned short wAdcData;

void vfnEcho (void)
{
	
	if (vfnGetTimerFlag(0))
	{
		vfnLedToggle(PORTB,18);

		if (ADC_ConvertioCheck(ADC_CHANNEL))
		{
			wAdcData = ADC_wfnLecture();

			*(PtrArray+wOffsetADC) = wAdcData;

			DAC_vfnDisplay((wAdcData + *(PtrArray+wOffsetDAC))/2);

			if (wOffsetADC == RESET )
			{
				wOffsetADC = MAX_NUMBER;
			}

			else
			{
				wOffsetADC--;
			}
			if (wOffsetDAC == RESET )
			{
				wOffsetDAC = MAX_NUMBER;
			}
			else
			{
				wOffsetDAC--;
			}

		}		
		vfnClearTimerFlag(0);
	}
}
