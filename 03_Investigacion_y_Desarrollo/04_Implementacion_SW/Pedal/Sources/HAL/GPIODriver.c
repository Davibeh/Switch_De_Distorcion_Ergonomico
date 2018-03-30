/*
 * GPIODriver.c
 *
 *  Created on: Oct 6, 2016
 *      Author: EdgarArmando
 */

#include "GPIOdriver.h"
static const PORT_MemMapPtr port[5]= PORT_BASE_PTRS;
	
static const GPIO_MemMapPtr Led [5] = GPIO_BASE_PTRS;

void vfnGPIOInit (unsigned char bPort, unsigned char bPin, unsigned char bDirection)
{
	
	SIM_SCGC5 |= (1<<(SIM_SCGC5_PORTA_SHIFT+bPort));
	
	PORT_PCR_REG(port[bPort],bPin) = PORT_PCR_MUX(MUX_GPIO);
	
	if (bDirection)
	{
		GPIO_PDDR_REG(Led[bPort]) |= (1<<bPin);
	}
	else
	{
		GPIO_PDDR_REG(Led[bPort]) &= ~(1<<bPin);
	}
	
	
}
void vfnLedToggle (unsigned char bPort, unsigned char bPin)
{
	GPIO_PTOR_REG(Led[bPort]) |= (1<<bPin);
}
unsigned char vfnPinStatus (unsigned char bPort, unsigned char bPin)
{
	return ((GPIO_PDIR_REG(Led[bPort]) >>(bPin)) & 1);
}
