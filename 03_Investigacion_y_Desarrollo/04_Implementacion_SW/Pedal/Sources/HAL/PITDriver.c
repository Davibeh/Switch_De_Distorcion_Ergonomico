/*
 * PITDriver.c
 *
 *  Created on: Oct 6, 2016
 *      Author: EdgarArmando
 */

#include "PITDriver.h"



static volatile short gwTimeOutReached ;

void vfnPortConfigurationPIT(unsigned short bTime, unsigned char bChannel)
{
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	
	NVIC_ISER |= NVICPIT;
	
	PIT_MCR &= ~PIT_MCR_MDIS_MASK;
	
	PIT_MCR |=PIT_MCR_FRZ_MASK;
	
	PIT_LDVAL_REG(PIT_BASE_PTR,bChannel) = bTime;
	
	PIT_TCTRL_REG(PIT_BASE_PTR,bChannel) |= PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK;
	
}
void PIT_IRQHandler (void)
{	 
	
	if (PIT_TFLG_REG(PIT_BASE_PTR,0) & PIT_TFLG_TIF_MASK)
	{
		PIT_TFLG0 |= PIT_TFLG_TIF_MASK;
		gwTimeOutReached = (1<<FLAG_PIT0_TIMEOUT_ON);
	}
	if (PIT_TFLG_REG(PIT_BASE_PTR,1) & PIT_TFLG_TIF_MASK)
	{
		PIT_TFLG0 |= PIT_TFLG_TIF_MASK;
		gwTimeOutReached = (1<<FLAG_PIT1_TIMEOUT_ON);
	}
	
	
	
}
unsigned char vfnGetTimerFlag (unsigned char bChannel)
{
	
	return ((gwTimeOutReached>>bChannel)&1);
}
void vfnClearTimerFlag (unsigned char bChannel)
{
	gwTimeOutReached &= ~(1<<bChannel);
}
