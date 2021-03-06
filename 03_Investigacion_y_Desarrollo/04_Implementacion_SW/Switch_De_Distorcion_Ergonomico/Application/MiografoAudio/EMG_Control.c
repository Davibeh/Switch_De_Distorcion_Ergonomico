/*
 * EMG_Control.c
 *
 *  Created on: 25 mar. 2018
 *      Author: David Bellomo Gomez
  *
  *---------------------------------------------------------
 * Change History
 * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 *Description:  Change the ADC reads now the ADC is read directly from the synchronous trigger of the ADC conversion.
 *              The interrupts are now disabled during the ADC conversion of this channel to avoid any interfireance with the
 *              Audio sampling. A new callback is privisioned in the configuration.
 */

#include "EMG_Control.h"
#include "Efectos_De_Sonido.h"
#include "fsl_common.h" /*This is to include disable or enable the ADC interrupt*/
void NotificationCallback(void);/*TODO Place this in the proper header*/
void EMG_MNG_sample_pulse(void);
void EMG_MNG_waitpulse(void);
 /******************************************
 * Private Const
 ******************************************/
/*Calibration structure declaration for the EMG manager*/

static  T_EMG_MNG_CAL EMG_MNG_CAL = {
		1700u, /*Value of the ADC Threshold 1.3mV*/
		100u, /*Value of the Pulse activation time aprox 1s*/
		1,/*Value of the time base for the EMG manager 1ms aprox*/
};


/******************************************
* Private Variables
******************************************/

static T_EMG_MNG_CTL EMG_MNG;


/******************************************************************
 * Name: EMG_MNG_Init
 * Return: Void
 * Parameter: Void
 * DEscription Initialization function for the EMG Manager, this functions
 * sets the initial state.
 *
 * ****************************************************************/
void EMG_MNG_Init (void){

	EMG_MNG.EMG_STATE = WAIT_FOR_PULSE; /* Start with wait pulse*/
	EMG_MNG.PULSE_COUNT = 0u; /* Start with 0*/
	EMG_MNG.Callback_ptr = AudioEffect_ActivationCbk; /*Call callback for the SWC */
}


/******************************************************************
 * EMG_SampleADC
 * Return: Void
 * Parameter: Void
 * Description: TBD
 * ****************************************************************/

//void EMG_SampleADC(void){
//
///*Get the Sample value of the ADC value and sum up*/
//	ADC_SAMPLE_SUM =   app_GetVal_ADC_IF();
//}
/******************************************************************
 * Get_ADCSample_lowPass
 * Return: T_UWORD
 * Parameter: Void
 * Description: TBD
 * ****************************************************************/
//T_UWORD Get_ADCSample_lowPass(void){
//
//	return ADC_SAMPLE_SUM ; /*Sample divided by 8*/
//
//}

/******************************************************************
 * Name:ReadAndSetCal
 * Return: Void
 * Parameter: Void
 * Description: This is the main task for the EMG
 * ****************************************************************/

void  EMG_MainTsk(void){

switch(EMG_MNG.EMG_STATE){
case WAIT_FOR_PULSE:
/*Call the Wait for Pulse main function*/
	EMG_MNG_waitpulse();
break;
case  SAMPLE_PULSE_TIME:
/*Call the sample pulse main function*/
	EMG_MNG_sample_pulse();
break;

default:
	/*OOPS! Something horrible occurred*/
	/*TODO: If needed create a fatal erro log*/
	break;

}


}

/******************************************************************
 * EMG_MNG_IsPulseActive
 * Return: T_UBYTE
 * Parameter: Void
 * Description: TBD
 * ****************************************************************/
T_UBYTE EMG_MNG_IsPulseActive(void){
	T_UWORD luw_obtained_ADC_Value;
	uint32_t primask; /*This is use for store the mask*/

	//primask =DisableGlobalIRQ();/*Disable the interrupts so the ADC is not interrupted*/

		/*Read the ADC current value*/
		app_ADC_Trigger(EMG_ADC_CHANNEL); /*Trigger the ADC channel conversion*/
		while(app_ADC_IsConversionCompleted() != TRUE); /*This might be very dangerous. Need to determine if we may need to implement a timeout strategy*/
		luw_obtained_ADC_Value = app_ADC_GetValue(); /*Read the ADC value*/

//	EnableGlobalIRQ(primask); /*Enable the interrupts again*/

	if( EMG_MNG_CAL.ADC_VAL_THRESHOLD  <=luw_obtained_ADC_Value){
		return TRUE;
	}else{
		return FALSE;
	}
}

/******************************************************************
 * EMG_MNG_waitpulse
 * Return: void
 * Parameter: Void
 * Description: TBD
 * ****************************************************************/

void EMG_MNG_waitpulse(void){

if( TRUE == EMG_MNG_IsPulseActive()){
	/*Wow a pulse is present, now evaluate it by measuring the pulse lenght*/
	EMG_MNG.EMG_STATE = SAMPLE_PULSE_TIME; /*Lest go to check the pulse lenght*/
	/*TODO: Need to review if there is need to increase the counter by 1 here*/
}else{
	/*Do nothing, the pulse is not present*/

}

}
/******************************************************************
 * EMG_MNG_sample_pulse
 * Return: void
 * Parameter: Void
 * Description: TBD
 * ****************************************************************/


void EMG_MNG_sample_pulse(void){
	T_UWORD Calculated_PULSE_TIME_ms = 0;
	if( TRUE == EMG_MNG_IsPulseActive()){
	/*Pulse is still there increment the count*/
		EMG_MNG.PULSE_COUNT++; /*Just increment the pulse*/
	}else{
	/*Pulse is over, lets see if it is a valid activation pulse*/
		Calculated_PULSE_TIME_ms =  EMG_MNG.PULSE_COUNT * EMG_MNG_CAL.MAIN_TASK_TIME_BASE_ms; /*Pulse_Time =  Count * EMG_TimeBase*/
		if(EMG_MNG_CAL.PULSE_TIME_THRESHOLD <= Calculated_PULSE_TIME_ms){
			/*Pulse is valid*/
			(*EMG_MNG.Callback_ptr)(); /*Call the Callback to notify the event to the external manager*/
		}else{
		/*Do nothing the pulse was not valid*/
		}
		EMG_MNG.EMG_STATE = WAIT_FOR_PULSE; /*Return to Wait for a pulse*/
		EMG_MNG.PULSE_COUNT = 0u; /*Erase counter of the previous pulse*/
	}
}





