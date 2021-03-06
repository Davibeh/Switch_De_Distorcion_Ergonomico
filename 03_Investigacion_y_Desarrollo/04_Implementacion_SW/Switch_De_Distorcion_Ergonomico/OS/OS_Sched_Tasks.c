/*
 * OS_Sched_Tasks.c
 *
 *  Created on: 17/11/2017
 *      Author: uidj2522
  *---------------------------------------------------------
 * Change History
 * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description:  Removed the ADC task since now the ADC read is performed in a synchronous fashion
 * 				Also the EMG_SampleADC() is removed since is not providing any bennefit right now
 */

/******************************************
 * Interfaces
 ******************************************/
#include "OS_Sched_Tasks.h"
#include "app_ADC.h"


void  EMG_MainTsk(void);
void AudioEffectSig_MainFunction(void);
/******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_OS_Sched_Task_64tk
 * Description: TBD
 ***********************************************/



void app_OS_Sched_Task_1tk(void)
{
/*Task executed every 1ms*/
	/* Functions Executed Every Loop */
	//app_BtnDbnc_TaskMngr();
	EMG_MainTsk();


	/*AudioEffectSig_MainFunction();*/
	//AudioEffectSig_MainFunction();
}

