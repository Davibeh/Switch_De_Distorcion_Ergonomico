/*
 * app_BtnDbnc.h
 *
 *  Created on: 20/10/2017
 *      Author: uidj2522
 */

#ifndef APP_BTNDBNC_H_
#define APP_BTNDBNC_H_

/******************************************
 * Includes
 ******************************************/
#include "stdtypedef.h"

/******************************************
 * Type definitions
 ******************************************/
typedef enum
{
	BUTTON_UNPRESSED,
	BUTTON_PRESSED
}T_BUTTON_STATES;

enum
{
	AUDIO_EFFECT_SEL,
	EMG_CAL_START,
	N_BUTTONS
};

/******************************************
 * Defines
 ******************************************/
/* Confiuration constants for buttons */

#define APP_BTNDBNC_N_BUTTONS				((T_UBYTE)N_BUTTONS)	//Number of buttons to configure

#define APP_BTNDBNC_AUDIOEFF_PIN_NUMBER		((T_UBYTE)9U)	/*Button to change between audio effects*/
#define APP_BTNDBNC_EMG_CAL_PIN_NUMBER		((T_UBYTE)8U)	//Button 1 Pin Number Assignement

#ifdef KINETIS_KL25Z

#define APP_BTNDBNC_AUDIOEFF_PIN_GPIO_BASE	GPIOB	/*Button to change between audio effects*/
#define APP_BTNDBNC_EMG_CAL_PIN_GPIO_BASE	GPIOB	/*Button to Start the EMG Calibration*/

#define APP_BTNDBNC_AUDIOEFF_PIN_PORT_BASE	PORTB	/*Button to change between audio effects*/
#define APP_BTNDBNC_EMG_CAL_PIN_PORT_BASE	PORTB	/*Button to Start the EMG Calibration*/

#define APP_BTNDBNC_AUDIOEFF_PIN_PORT_BASE	PORTB	/*Button to change between audio effects*/
#define APP_BTNDBNC_EMG_CAL_PIN_PORT_BASE	PORTB	/*Button to Start the EMG Calibration*/

#define APP_BTNDBNC_AUDIOEFF_PIN_PORT_CLOCK	kCLOCK_PortB	/*Button to change between audio effects*/
#define APP_BTNDBNC_EMG_CAL_PIN_PORT_CLOCK	kCLOCK_PortB	/*Button to Start the EMG Calibration*/

#endif

#define BUTTON_HW_PRESSED	FALSE
#define BUTTON_HW_UNPRESSED	TRUE

#define AUDIOEFF_DBNC_VALID_COUNT	((T_UWORD)1500U)
#define EMG_CAL_DBNC_VALID_COUNT	((T_UWORD)3000U)



/******************************************
 * Variables
 ******************************************/

/******************************************
 * Prototypes
 ******************************************/
extern void app_BtnDbnc_Init(void);
extern void app_BtnDbnc_TaskMngr(void);

#endif /* APP_BTNDBNC_H_ */
