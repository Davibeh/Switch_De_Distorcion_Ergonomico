/*
 * Efectos_De_Sonido.c
 *
 *  Created on: 31/03/2018
 *      Author: uidv7995
 * Description: This file contains the main functionality for the the Sound effects
 */


/*********************************Includes**********************************************/
#include "Echo.h"  /* Echo interface*/
#include "Distorcion.h" /*Distorción interface*/
#include "Vibrato.h" /*Vibrato interface*/
#include "NoEffect.h" /*No effect interface*/
#include "Efectos_De_Sonido.h"


/*********************************Private Variables*************************************/
static T_AudioEffect_Selection AudioEffect_Selection = e_ECHO; /*We may need a button selector and button manager*/
static T_UBYTE AudioEFfect_ActiveSate = AUDIOEFFECT_OFF; /*This is the interface with the Electromigoraph*/


/*********************************Public Prototypes************************************/
void ISR_Audio_Sampl_Handler(void);
void AudioEffect_ActivationCbk(void);


/***********************************************
 * Function Name: ISR_Audio_Sampl_Handler
 * Description: CAlled by the configured PIT channel
 ***********************************************/
void ISR_Audio_Sampl_Handler(void){

	if(AudioEFfect_ActiveSate == AUDIOEFFECT_ON){
		 switch(AudioEffect_Selection){
		  		case e_ECHO:
		  			vfnEcho();
		 		break;
		  		case e_DISTORTION:
		  			vfnDistorcion();
		 		break;
		  		case e_VIBRATO:
		  			vfnVibrato();
		 		break;
		       default:

		       break;
		  }
	}else{
		/*Just sample the sound with no effect*/
		NoEffect();
	}
}

/***********************************************
 * Function Name: ISR_Audio_Sampl_Handler
 * Description:  This callback is called when a change
 * on the activation of the sound effect status is required
 ***********************************************/

void AudioEffect_ActivationCbk(void){ /*Added to the Beta code of the electromiograph*/
/*TODO: Check if is plausible to use just a bitwise NOT operation*/
	if(AudioEFfect_ActiveSate == AUDIOEFFECT_OFF){
		/*The audio effect is not active, just activated*/
		AudioEFfect_ActiveSate = AUDIOEFFECT_ON;
	}else{
		/*The audio effect is Active, just deactivated*/
		AudioEFfect_ActiveSate = AUDIOEFFECT_OFF;
	}


}












