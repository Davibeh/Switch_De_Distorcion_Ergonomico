/*
 * ADC_Driver.c
 *
 *  Created on: Oct 4, 2016
 *      Author: mac
 */


#include "derivative.h"
#include "ADC_Driver.h"

unsigned char bADCOCOFlag;

void  ADC_vfnDriverInit()
{
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	
	PORTE_PCR20 |= PORT_PCR_MUX(ADC_MODE);
	
	PORTE_PCR22 |= PORT_PCR_MUX(ADC_MODE);
	
	ADC0_CFG1 |= ADC_12BITS_RES;
	
	ADC0_SC3 |= ADC0_SC3_CAL_MASK;

	ADC0_SC1A = 0;
}

unsigned short ADC_ConvertioCheck(unsigned char bChannel)
{
	bADCOCOFlag = 0;
	
	ADC0_SC1A &= ~(TURN_OFF_CHANNELS);

	ADC0_SC1A |= ADC_SC1_ADCH(bChannel);
	
	if(!(ADC0_SC1A & ADC_SC1_COCO_MASK))
	{	
		bADCOCOFlag  = 1;	
	}
	
	
	return bADCOCOFlag;
}

unsigned short ADC_wfnLecture(void)
{
	volatile unsigned short wData;
	
	wData = ADC0_RA;
	

	ADC0_SC1A &= ~(ADC_SC1_COCO_MASK);

	ADC0_SC1A &= ~ADC_SC1_ADCH_MASK;
	
	
	return wData;
}


