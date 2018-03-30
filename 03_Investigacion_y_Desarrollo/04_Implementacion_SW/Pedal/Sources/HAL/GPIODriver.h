/*
 * GPIODriver.h
 *
 *  Created on: Oct 6, 2016
 *      Author: EdgarArmando
 */

#ifndef GPIODRIVER_H_
#define GPIODRIVER_H_

#include "derivative.h"

#define MUX_GPIO 	  1

enum
{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE
};



void vfnGPIOInit (unsigned char bPort, unsigned char bPin, unsigned char bDirection);
void vfnLedToggle (unsigned char bPort, unsigned char bPin);
unsigned char vfnPinStatus (unsigned char bPort, unsigned char bPin);

#endif /* GPIODRIVER_H_ */
