/*
 * DACDriver.c

 *
 *  Created on: Jan 24, 2017
 *      Author: EdgarArmando
 */
#include "derivative.h"
#include "DACDriver.h"

void DAC_vfnInit (void)
{
	SIM_SCGC6 |= SIM_SCGC6_DAC0_MASK;
	
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		
	PORTE_PCR30 |= PORT_PCR_MUX(DAC_MODE);
	
	DAC0_C0 |= DAC_C0_DACEN_MASK;
	
	
}
void DAC_vfnDisplay (unsigned short wData)
{

	
	DAC0_DAT0L = (unsigned char)wData;	
	DAC0_DAT0H = (wData>>8);
	
}
