/*
 * EMG_Control.h
 *
 *  Created on: 25 mar. 2018
 *      Author: David Bellomo
 */

#ifndef MIOGRAFOAUDIO_EMG_CONTROL_H_
#define MIOGRAFOAUDIO_EMG_CONTROL_H_

#include "stdtypedef.h"
#include "app_ADC.h"


/*Enumeration that represents the state of the EMG manager*/
typedef enum{
	NO_STATE,
	WAIT_FOR_PULSE,
	SAMPLE_PULSE_TIME,
	CAL_STATE
}T_EMG_MNG_ST;

typedef enum{
	NO_CAL_STATE,
	ANNOUNCE_START,
	START_LOW_SENSING,
	REQUEST_MOVEMENT,
}T_EMG_MNG_CAL_ST;

/*Structure Type that holds the calibration parameters for the EMG Manager*/
typedef struct{
T_UWORD ADC_VAL_THRESHOLD;  /*Threshold which marks the presence of a pulse*/
T_UWORD PULSE_TIME_THRESHOLD; /*Threshold which marks the time for an activation pulse*/
T_UBYTE MAIN_TASK_TIME_BASE_ms; /* Value of the time base fo rthe main task ms*/
}T_EMG_MNG_CAL;



/*Structure that holds the main control variables for the EMG manager*/
typedef struct{
T_EMG_MNG_ST EMG_STATE; /*Stores the state of the EMG Manager*/
T_UWORD  PULSE_COUNT; /*Stores the current Value for the pulse count to be used for pulse lenght calculation*/
void (* Callback_ptr)(void);  /*Configurable callback */
}T_EMG_MNG_CTL;


typedef struct{
	T_EMG_MNG_CAL_ST EMG_CAL_STATE;
	T_UWORD PULSE_CAL_COUNT;
	T_UWORD STATE_TIME_CONTROL;
	unsigned long CAL_THRESHOLD;
	unsigned long CAL_LOWTHRES;
}T_CAL_EMG_CTL;


extern void EMG_MGN_CHNAGE_TOCAL(void);
#endif /* MIOGRAFOAUDIO_EMG_CONTROL_H_ */
