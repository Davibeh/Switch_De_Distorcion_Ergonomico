/*
 * Echo.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 *
 *---------------------------------------------------------
 * Change History
 * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description: Alfa variant integration to the Beta variant:
 * 				1- Remove the check for the PIT flag, now this task is executed at interrupt level.
 * 				2- New managed of the ADC conversion, now the conversion is triggered and a wait for complete retains the core
 * 				3- Cleaning the code
 * 				4- Correct the division by to with just a right shift by 1
 * * --------------------------------------------------------
 */

#include "Echo.h"

#define RESET                                 0

#define MAX_NUMBER     						  4090
	

static unsigned short wOffsetDAC = MAX_NUMBER;

static unsigned short wOffsetADC = RESET;

static unsigned short wArray[4096] = {0};

static unsigned short *PtrArray = wArray;

static unsigned short wAdcData;

unsigned char ADC_Inconverstion = 0x00u;




void vfnEcho (void)
{


	    app_ADC_Trigger(APP_ADC_CHANNEL); /*Trigger the ADC channel conversion*/
	    while(ADC_ConvertioCheck(ADC_CHANNEL) != TRUE); /*This might be very dangerous. Need to determine if we may need to implement a timeout strategy*/
		wAdcData = ADC_wfnLecture(); /*Get the converted value*/

		*(PtrArray+wOffsetADC) = wAdcData; /*This value must be place in the output buffer, in the ADC sampling locator*/

		DAC_vfnDisplay((wAdcData + *(PtrArray+wOffsetDAC))>>2); /*Add to the current Value of the signal the delayed signal to produce the ECHO effect
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	note that the resulting value  is divided by two to avoid  a saturation*/

		if (wOffsetADC == RESET )
		{
			/*We are in the lower limit just set it to the max value*/
			/*TODO: This can be solved with a modulus operation*/
			wOffsetADC = MAX_NUMBER;
		}

		else
		{
			/*Decrease the ADC buffer*/
			wOffsetADC--;
		}
		if (wOffsetDAC == RESET )
		{
			/*We reached the lower index just set the indext to the maximum index value.*/
			wOffsetDAC = MAX_NUMBER;
		}
		else
		{
			/*Decrease the index value*/
			wOffsetDAC--;
		}

}
