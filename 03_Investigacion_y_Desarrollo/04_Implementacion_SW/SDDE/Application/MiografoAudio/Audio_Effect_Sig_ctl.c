/* * Audio_Effect_Sig_ctl.c
 *
 *  Created on: 25 mar. 2018
 *      Author: David Bellomo Gomez
 */

#include "stdtypedef.h"
#include "app_DAC.h"
#include "Audio_Effect_Sig_ct.h"

static T_UWORD Sig_Ampl = 0x400;
static T_UWORD Sig_Period_ms = 124;
static T_UWORD OutputSignalState = OUTPUT_OFF;
static T_UWORD SignalCurrentValue = 0x0u;
static T_UWORD Period_Counter = 0x00;
static T_UBYTE SignalGenState = 0x00u;
void app_DAC_SetValue(T_UWORD luw_DacValue);
void NotificationCallback(void){

	if(OUTPUT_OFF == OutputSignalState){
		/*Set the state of the output signal as  on*/
		OutputSignalState = OUTPUT_ON;

	}else{
		/*Set the state of the output signal as off*/
		OutputSignalState = OUTPUT_OFF;
		/*Return to the normal state as soon as possible*/
		app_DAC_SetValue(DEFAULT_VALUE);
		SignalCurrentValue = 0x00u;
	}

}


void SignalGenerator(void){


	if(SignalGenState == 0u){
		/*update the state of the signal*/
		if(Period_Counter < (Sig_Period_ms/2)){
		SignalCurrentValue = SignalCurrentValue + (Sig_Ampl/(Sig_Period_ms/2));
		}else{
			SignalGenState = 0x1u;
		}

	}else{
		/*Update the state of the signal*/
		if(  (Period_Counter >= (Sig_Period_ms/2))  && (Period_Counter < Sig_Period_ms)){
		SignalCurrentValue = SignalCurrentValue - (Sig_Ampl/(Sig_Period_ms/2));
		}else{
			SignalGenState = 0x0u;
			Period_Counter = 0x0u;
			SignalCurrentValue = 0x0u;
		}
	}
	Period_Counter++;
}

void AudioEffectSig_MainFunction(void){
	if(OutputSignalState == OUTPUT_ON){
		/*Output is Active enable the output of the signal*/
		app_DAC_SetValue(SignalCurrentValue);
		SignalGenerator();

	}else{
		/*The output is not active just set a default value*/
		//app_DAC_SetValue(DEFAULT_VALUE);
		//SignalCurrentValue = 0x00u;
		app_DAC_SetValue(SignalCurrentValue);
		SignalGenerator();
	}





}
