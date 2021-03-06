/*
 * app_Init.c
 *
 *  Created on: 23/10/2017
 *      Author: uidj2522
  *---------------------------------------------------------
 * Change History
 * --------------------------------------------------------
 * Name: David Roberto Bellomo Gomez
 * Date: 31/03/18
 * Description: Add Two initialization one called for Beta Variant and the second one called Alfa.
 * 				Also the PIT initialization was moved to the end of the app_init in both variants
 * 				since the PIT channel 1 is now very fast (10us) and we do not want a nasty interrupt
 * 				being executed while we are initializating.
 */

/******************************************
 * Includes
 ******************************************/
#include "app_Init.h"
#include "app_GPIO.h"
#include "app_BtnDbnc.h"
#include "app_PIT.h"
#include "app_DAC.h"
#include "app_ADC.h"

/******************************************
 * Defines
 ******************************************/

/******************************************
 * Variables
 ******************************************/

/******************************************
 * Prototypes
 ******************************************/
void EMG_MNG_Init (void);
/******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_Init
 * Description: TBD
 ***********************************************/
void app_Init_BETA(void)
{


    /* GPIO Module Init */
    app_GPIO_Init();

    /* DAC Module Init */
    app_DAC_Init();

    /* ADC Module Init */
    app_ADC_Init();

    /* Button Debounce App Init */
    app_BtnDbnc_Init();

    EMG_MNG_Init ();
    /* PIT Module Init */
    app_PIT_Init(); /*TODO: Find the interface to globally disable the interrupts*/

}


void app_Init_ALFA(void)
{
    /* GPIO Module Init */
    app_GPIO_Init();

    /* DAC Module Init */
    app_DAC_Init();

    /* ADC Module Init */
    app_ADC_Init();

    /* PIT Module Init */
    app_PIT_Init();/*TODO: Find the interface to globally disable the interrupts*/
    //EMG_MNG_Init ();

}
