/*
 * Inicializacion.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */

#include "Inicializacion.h"

#define ADC_CHANNEL             0

#define	TIME_EFECT				490// 20kHz

#define TIME_ELECTROMIOGRAFO	4200

void vfnEfectinit (void)
{
	ADC_vfnDriverInit();
		
	DAC_vfnInit();
	
	vfnGPIOInit(PORTB,18,1);
	
	vfnGPIOInit(PORTD,0,0);
	
	vfnGPIOInit(PORTD,1,0);
	
	vfnGPIOInit(PORTD,2,0);

	vfnPortConfigurationPIT(TIME_EFECT,0);
	
	vfnPortConfigurationPIT(TIME_ELECTROMIOGRAFO,1);

}
