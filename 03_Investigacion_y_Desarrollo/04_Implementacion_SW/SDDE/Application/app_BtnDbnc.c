/*
 * app_BtnDbnc.c
 *
 *  Created on: 20/10/2017
 *      Author: uidj2522
 */

/******************************************
 * Includes
 ******************************************/
#include "MKL25Z4.h"
#include "stdtypedef.h"
#include "app_GPIO.h"
#include "app_BtnDbnc.h"
#include "EMG_Control.h"
#include "Efectos_De_Sonido.h"
#include "app_LED.h"

/******************************************
 * Defines
 ******************************************/

/******************************************
 * Variables
 ******************************************/
const T_UBYTE caub_ButtonPortPinNumber[APP_BTNDBNC_N_BUTTONS] = {
		APP_BTNDBNC_AUDIOEFF_PIN_NUMBER,
		APP_BTNDBNC_EMG_CAL_PIN_NUMBER
};

const GPIO_Type *cpub_ButtonGPIOBase[APP_BTNDBNC_N_BUTTONS] = {
		APP_BTNDBNC_AUDIOEFF_PIN_GPIO_BASE,
		APP_BTNDBNC_EMG_CAL_PIN_GPIO_BASE
};

const T_UWORD cauw_ButtonValidCounts[APP_BTNDBNC_N_BUTTONS] ={
		AUDIOEFF_DBNC_VALID_COUNT,
		EMG_CAL_DBNC_VALID_COUNT
};


T_UWORD	raub_ButtonDbncCounters[APP_BTNDBNC_N_BUTTONS];
T_BUTTON_STATES rae_ButtonsState[APP_BTNDBNC_N_BUTTONS];

/******************************************
 * Prototypes
 ******************************************/
static void app_BtnDbnc_CheckButtonsState(void);
static void app_BtnDbnc_IncreaseDbncCounter(T_UBYTE lub_ButtonNumber);
static void app_BtnDbnc_ClearDbncCounter(T_UBYTE lub_ButtonNumber);
static void app_BtnDbnc_Actions();

/******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_BtnDbnc_Init
 * Description: TBD
 ***********************************************/
void app_BtnDbnc_Init(void)
{
	T_UBYTE lub_i;
	/* Clear all the counters and states*/
	for(lub_i = 0U; lub_i < APP_BTNDBNC_N_BUTTONS; lub_i++)
	{
		raub_ButtonDbncCounters[lub_i] = 0U; //Clear counter
		rae_ButtonsState[lub_i] = BUTTON_UNPRESSED; //Clear press state
	}
}

/***********************************************
 * Function Name: app_BtnDbnc_TaskMngr
 * Description: TBD
 ***********************************************/
void app_BtnDbnc_TaskMngr(void)
{
	/* Check the state for all buttons */
	app_BtnDbnc_CheckButtonsState();
	/* Perform the corresponding action depending the buttons state */
	app_BtnDbnc_Actions();
}

/***********************************************
 * Function Name: app_BtnDbnc_CheckButtonsState
 * Description: TBD
 ***********************************************/
static void app_BtnDbnc_CheckButtonsState(void)
{
	T_UBYTE lub_i;
	/* Check the buttons state */
	for(lub_i = 0; lub_i < APP_BTNDBNC_N_BUTTONS;lub_i++)
	{//Check for each button
		if(app_GPIO_GetPinValue((GPIO_Type *)cpub_ButtonGPIOBase[lub_i], caub_ButtonPortPinNumber[lub_i]) == BUTTON_HW_PRESSED)
		{//Button pressed in HW
			app_BtnDbnc_IncreaseDbncCounter(lub_i);
		}
		else
		{//Button unpressed in SW
			app_BtnDbnc_ClearDbncCounter(lub_i);
		}
	}
}

/***********************************************
 * Function Name: app_BtnDbnc_IncreaseDbncCounter
 * Description: TBD
 ***********************************************/
static void app_BtnDbnc_IncreaseDbncCounter(T_UBYTE lub_ButtonNumber)
{
	/* Check if the counter hasn't reached its max limit */
	if(raub_ButtonDbncCounters[lub_ButtonNumber] >= cauw_ButtonValidCounts[lub_ButtonNumber])
	{//Counter is in the limit
		/* Valid State */
		rae_ButtonsState[lub_ButtonNumber] = BUTTON_PRESSED;
	}
	else
	{//Counter has not reached a valid value
		raub_ButtonDbncCounters[lub_ButtonNumber]++;
	}
}

/***********************************************
 * Function Name: app_BtnDbnc_ClearDbncCounter
 * Description: TBD
 ***********************************************/
static void app_BtnDbnc_ClearDbncCounter(T_UBYTE lub_ButtonNumber)
{
	/* Clear debounce counter */
	raub_ButtonDbncCounters[lub_ButtonNumber] = 0U;
	/* Clear button state */
	rae_ButtonsState[lub_ButtonNumber] = BUTTON_UNPRESSED;
}

/***********************************************
 * Function Name: app_BtnDbnc_ClearDbncCounter
 * Description: TBD
 ***********************************************/
static void app_BtnDbnc_Actions(void)
{
	T_UBYTE lub_i;
	/* Check internal button states */
	for(lub_i = 0; lub_i < APP_BTNDBNC_N_BUTTONS; lub_i++)
	{
		/* If button has a valid press, then perform the corresponding actions*/
		if(rae_ButtonsState[lub_i] == BUTTON_PRESSED)
		{
			switch(lub_i)
			{
			/*Actions for AUDIO_EFFECT_SEL*/
			case AUDIO_EFFECT_SEL:
			{
				AudioEffect_Select();/*Change the state of the sound effect*/
			}break;
			/*Actions for EMG_CAL_START*/
			case EMG_CAL_START:
			{
				EMG_MGN_CHNAGE_TOCAL();/*Change the state of the EMG to Cal*/
			}break;
			/*Actions for not valid BUTTON*/
			default:
			{
				/* Do Nothing */
			}break;
			}
		}
		else
		{//Button is not pressed, perform the corresponding action

		}
	}
}
