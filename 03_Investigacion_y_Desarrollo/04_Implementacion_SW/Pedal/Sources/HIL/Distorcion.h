/*
 * Distorcion.h
 *
 *  Created on: Mar 24, 2018
 *      Author: Edgar Padilla Chung
 */

#ifndef DISTORCION_H_
#define DISTORCION_H_

#include "ADC_Driver.h"
#include "DACDriver.h"
#include "PITDriver.h"
#include "GPIODriver.h"

void vfnDistorcionInit (void);
void vfnDistorcion (void);

#endif /* DISTORCION_H_ */
