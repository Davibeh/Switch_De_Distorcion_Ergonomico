/*
 * OS_Sched_Tasks.c
 *
 *  Created on: 17/11/2017
 *      Author: uidj2522
 */

/******************************************
 * Interfaces
 ******************************************/
#include "OS_Sched_Tasks.h"
#include "app_ADC.h"

void  EMG_MainTsk(void);
void AudioEffectSig_MainFunction(void);
void EMG_SampleADC(void);
/******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_OS_Sched_Task_64tk
 * Description: TBD
 ***********************************************/
void app_OS_Sched_Task_1tk(void)
{
	//Every 64 ms
	//app_LED_Task();

	/* Functions Executed Every Loop */
	//app_BtnDbnc_TaskMngr();

	/* DAC Task */
	//app_DAC_TaskMngr();

	app_ADC_Task();
	EMG_SampleADC();
	EMG_MainTsk();
	AudioEffectSig_MainFunction();
	//AudioEffectSig_MainFunction();
}
