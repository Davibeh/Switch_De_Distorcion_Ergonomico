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
	
	/*Activate the Clock sources*/
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK; /* Set Bit 27 from SIM_SCG6 to activate the peripheral Clock */
	
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK; /*Set Bit 12  form SIM_SCGC5 to enable the clock of the PORTE peripheral*/
	
	PORTE_PCR20 |= PORT_PCR_MUX(ADC_MODE);  /*Set the MUX bit fiel 10-8 from PORTE_PCR20 to b000 in order to enable the Analog input */
	
	PORTE_PCR22 |= PORT_PCR_MUX(ADC_MODE); /*Set the MUX bit fiel 10-8 from PORTE_PCR22 to b000 in order to enable the Analog input */
	
	ADC0_CFG1 |= ADC_12BITS_RES; /*Set the Resolution to 12bit only if DIFF = 0 other wise 13bit*/
	
	ADC0_SC3 |= ADC0_SC3_CAL_MASK; /*Start the calibration of the ADC   Not sure if we need to wait until calibration ends
									This is not doing anything the calibrated Gain output must be written on PG register*/

ADC0_SC1A = 0; /* Con interrupt in conversion ended, single ended (DIFF = 0) , No channel selected*/
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


