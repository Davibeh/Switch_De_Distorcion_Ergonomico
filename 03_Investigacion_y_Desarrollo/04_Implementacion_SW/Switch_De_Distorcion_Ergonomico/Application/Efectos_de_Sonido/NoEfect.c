/*
 * NoEfect.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
  *---------------------------------------------------------
 * Change History
 * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description: Alfa variant integration to the Beta variant:
 * 				1- Remove the check for the PIT flag, now this task is executed at interrupt level.
 * 				2- New managed of the ADC conversion, now the conversion is triggered and a wait for complete retains the core
 * 				3- Cleaning the code
 * * --------------------------------------------------------
 */

#include "NoEffect.h"



void NoEffect (void)
{

    	app_ADC_Trigger(APP_ADC_CHANNEL); /*Trigger the ADC channel conversion*/
    	while(ADC_ConvertioCheck(ADC_CHANNEL) != TRUE); /*This might be very dangerous. Need to determine if we may need to implement a timeout strategy*/
		DAC_vfnDisplay(ADC_wfnLecture()); /*Just send the same value*/

}
