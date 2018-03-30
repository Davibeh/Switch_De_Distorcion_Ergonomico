/*
 * PITDriver.h
 *
 *  Created on: Oct 6, 2016
 *      Author: EdgarArmando
 */

#ifndef PITDRIVER_H_
#define PITDRIVER_H_

#include "derivative.h"
#define NVICPIT    				   (1<<22)
#define FLAG_PIT0_TIMEOUT_ON        0
#define FLAG_PIT1_TIMEOUT_ON        1


void vfnPortConfigurationPIT(unsigned short bTime,unsigned char bChannel);

unsigned char vfnGetTimerFlag (unsigned char bChannel);

void vfnClearTimerFlag (unsigned char bChannel);

#endif /* PITDRIVER_H_ */
