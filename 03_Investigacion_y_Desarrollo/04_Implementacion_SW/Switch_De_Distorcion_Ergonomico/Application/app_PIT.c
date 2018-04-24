/*
 * app_PIT.c
 *
 *  Created on: 23/10/2017
 *      Author: uidj2522
  *---------------------------------------------------------
 * Change History
 * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description:  Add extra PIT for Audio sampling this PIT must run  100kHz which is a period of 10us
 *				 the system alarm is removed from this code just for now until the complete system is merged
 */


/******************************************
 * Includes
 ******************************************/
#include "MKL25Z4.h"
#include "stdtypedef.h"
#include "Efectos_De_Sonido.h"
#include "app_PIT.h"
#include "fsl_gpio.h"
#include "fsl_pit.h"


/******************************************
 * Defines
 ******************************************/

/******************************************
 * Variables
 ******************************************/
T_UBYTE	rub_PITAlarm;

/******************************************
 * Prototypes
 ******************************************/


/******************************************
 * Code
 ******************************************/
void EMG_MainTsk(void);
/***********************************************
 * Function Name: app_PIT_Init
 * Description: Function that initializes the
 * PIT Module.
 ***********************************************/
void app_PIT_Init(void)
{
	pit_config_t ls_PitConfig;

	/* Get Default Config */
	PIT_GetDefaultConfig(&ls_PitConfig);

	/* PIT Init */
	PIT_Init(PIT, &ls_PitConfig);

	/* PIT Set Period at 1 ms*/
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000,CLOCK_GetFreq(kCLOCK_BusClk))); /*PIT Channel 0 is used for  Scheduler Tick set to 1ms*/
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_1, 240u); 											/*PIT Channel 1 is used for Audio Sampling set to 10us*/

	/* Enable PIT Interrupts */
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	PIT_EnableInterrupts(PIT, kPIT_Chnl_1, kPIT_TimerInterruptEnable);

	/* Enable at the NVIC */
	EnableIRQ(PIT_IRQn);

	/* Start Timer */
	PIT_StartTimer(PIT, kPIT_Chnl_0);
	PIT_StartTimer(PIT, kPIT_Chnl_1); /*This PIT has a very short periodicity be careful! */
}

/***********************************************
 * Function Name: PIT_IRQHandler
 * Description: PIT IRQ Handler
 ***********************************************/

unsigned int popo;
void PIT_IRQHandler(void)
{

	if(PIT_GetStatusFlags(PIT, kPIT_Chnl_0)){
		/* Set PIT Alarm */
		PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
		rub_PITAlarm = TRUE; /*Notify the Scheduler that is time to activate another task*/
		EMG_MainTsk();

		if(popo == 1000){
			GPIO_TogglePinsOutput(GPIOB, 1u<<19u);
			popo =0;
		}else{
	popo++;
		}

	}/*if(PIT_GetStatusFlags(PIT, kPIT_Chnl_0))*/
	else{
		if(PIT_GetStatusFlags(PIT, kPIT_Chnl_1)){
			PIT_ClearStatusFlags(PIT, kPIT_Chnl_1, kPIT_TimerFlag);
			ISR_Audio_Sampl_Handler(); /*Call the ISR for the Audio sampling*/
		}/*if(PIT_GetStatusFlags(PIT, kPIT_Chnl_1))*/
	}

}
