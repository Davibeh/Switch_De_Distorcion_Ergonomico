/*
 * app_ADC.c
 *
 *  Created on: 07/03/2018
 *      Author: uidj2522
 *---------------------------------------------------------
 * Change History
 * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 25/03/18
 * Description: Add a public ADC get value interface
 * * --------------------------------------------------------
 *  * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description: Change the APIS in order to manage the Convertions by channels
 * (this applicaction now requires to ADC Channels 1 for Audio Sampling an another for Miograph movement detection
 */

 /******************************************
 * Interfaces
 ******************************************/
#include "stdtypedef.h"
#include "fsl_adc16.h"
#include "app_ADC.h"

 /******************************************
 * Private Macros
 ******************************************/

 /******************************************
 * Private Typedef
 ******************************************/
 
 /******************************************
 * Public Const
 ******************************************/
 
 /******************************************
 * Private Const
 ******************************************/
 
 /******************************************
 * Public Variables
 ******************************************/

 /******************************************
 * Public Prototypes
 ******************************************/

T_UWORD app_GetVal_ADC_IF(void);
void app_ADC_Trigger(T_UBYTE ADC_Channel);
T_UBYTE app_ADC_IsConversionCompleted(void);
T_UWORD app_ADC_GetValue(void);



 /******************************************
 * Private Variables
 ******************************************/
static T_UWORD ruw_ADCValue = 0u;
static T_UBYTE rub_ConversionInProgressFlag = FALSE;
 
 /******************************************
 * Private Prototypes
 ******************************************/

 /******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_ADC_Init
 * Description: Must be call at the beggining of the application boot
 *              this function initialize the ADC as required for the Application.
 *
 *              The requirements for this application are the folloing:
 *              * Convertion Time must be no more than 5us.
 *              * Source Clock must be the  Bus clock Divided by two.
 *              * The CFG2 High Speed Sample must be enabled.
 *              * The convertion resolution must be of 12 bits
 *              * No average functionality.
 *              * High Speed Sample must be configured in CFG1[ADLSMP]
 *              * The Convertion time in ADCK is--> 27ADCK + 5Bus Cucle
 *
 *             The bus cucle for this system is 24MHz
 ***********************************************/
void app_ADC_Init(void)
{
	adc16_config_t ls_ADCConfig;

	//Initialize structure with default values
	ADC16_GetDefaultConfig(&ls_ADCConfig);

	/*Configure ADC0 as required for the application convertion time no longer than 5us*/
	ls_ADCConfig.clockSource = kADC16_ClockSourceAlt0; /*Clock source must be Bus Clock*/
	ls_ADCConfig.enableAsynchronousClock = FALSE; /*Since we are using the Bus clock the asynchrnous clock is not required*/
	ls_ADCConfig.clockDivider= kADC16_ClockDivider2;  /*The division must be of 2*/
	ls_ADCConfig.resolution= kADC16_ResolutionSE12Bit; /*Resolution of 12bits*/
	ls_ADCConfig.longSampleMode= kADC16_LongSampleDisabled;  /* The configuration must be short sample so set it as false*/
	ls_ADCConfig.enableHighSpeed= TRUE;/*Yes, the clock may be faster than allowed for short speed so enable the  high speed sampling*/
	ls_ADCConfig.enableLowPower= FALSE;/*No the ADC must run in high speed*/
	ls_ADCConfig.enableContinuousConversion= FALSE;  /*No it must be single shot*/
	/*The configurations above are expected to give a  2.4us of convertion time*/

	//Init ADC Module
	ADC16_Init(ADC0, &ls_ADCConfig);
	//Disable Hardware Trigger
	ADC16_EnableHardwareTrigger(ADC0, FALSE); /* Make sure the software trigger is used. */
	//Perform Autocalibration
	(void)ADC16_DoAutoCalibration(ADC0);
}

/***********************************************
 * Function Name: app_ADC_Trigger
 * Description: Triggers the Convertion of the specified ADC Channel
 ***********************************************/
 void app_ADC_Trigger(T_UBYTE ADC_Channel)
{
	adc16_channel_config_t ls_ChannelConfig;

	//Channel Selection
	ls_ChannelConfig.channelNumber = ADC_Channel;

	//Disable Interrupt when Conversion is completed
	ls_ChannelConfig.enableInterruptOnConversionCompleted = FALSE;

	//Disable Differential Conversion
	ls_ChannelConfig.enableDifferentialConversion = FALSE;

	ADC16_SetChannelConfig(ADC0, APP_ADC_CHANNEL_GROUP, &ls_ChannelConfig);
}

/***********************************************
 * Function Name: app_ADC_IsConversionCompleted
 * Description: TBD
 ***********************************************/
 T_UBYTE app_ADC_IsConversionCompleted(void)
{
	T_UBYTE lub_Return;

	lub_Return = FALSE;

	//Check if Conversion was completed
	if(kADC16_ChannelConversionDoneFlag &
			ADC16_GetChannelStatusFlags(ADC0, APP_ADC_CHANNEL_GROUP))
	{
		//Conversion Completed
		lub_Return = TRUE;
	}
	else
	{
		//Conversion not completed
		lub_Return = FALSE;
	}

	return lub_Return;
}

/***********************************************
 * Function Name: app_ADC_GetValue
 * Description: TBD
 ***********************************************/
 T_UWORD app_ADC_GetValue(void)
{
	//Return Last Conversion Value
	return ADC16_GetChannelConversionValue(ADC0, APP_ADC_CHANNEL_GROUP);
}

/***********************************************
 * Function Name: app_ADC_Task
 * Description: TBD
 ***********************************************/
void app_ADC_Task(void)
{
	//Check if a conversion is in progress
	if(TRUE == rub_ConversionInProgressFlag)
	{
		//Check if Conversion was completed
		if(TRUE == app_ADC_IsConversionCompleted())
		{
			//Store the ADC Value
			ruw_ADCValue = app_ADC_GetValue();

			//Clear conversion in progress flag
			rub_ConversionInProgressFlag = FALSE;
		}
		else
		{
			/* Do nothing */
		}
	}
	else
	{
		//Trigger the ADC Conversion
		app_ADC_Trigger(APP_ADC_CHANNEL);

		//Set Conversion in progress flag
		rub_ConversionInProgressFlag = TRUE;
	}
}



/***********************************************
 * Function Name: app_GetVal_ADC_IF
 * Description: TBD
 ***********************************************/

T_UWORD app_GetVal_ADC_IF(void){

return ruw_ADCValue;

}
