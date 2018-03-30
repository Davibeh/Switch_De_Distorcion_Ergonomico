/*
 * ADC_Driver.h
 *
 *  Created on: Oct 4, 2016
 *      Author: mac
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

/*!
 \def      ADC0_SC3_CAL_MASK
 \brief    Mask to activate the calibration mode
 */
#define ADC0_SC3_CAL_MASK	(1<<7)

/*!
 \def      ADC_12BITS_RES
 \brief    Mask to set the ADC resolution to 12 bits
 */
#define ADC_12BITS_RES  (1<<2)

/*!
 \def      ADC_MODE
 \brief    The port is assigned as an adc  mode
 */
#define ADC_MODE               	0

/*!
 \def      ADC_CHANNEL
 \brief    Channel is assigned
 */
#define ADC_CHANNEL            	0
/*!
 \def      TURN_OFF_CHANNELS
 \brief    mask used to turn off all the all the ADC channel
 */
#define TURN_OFF_CHANNELS      0x1F

/*!
 \fn       ADC_vfnDriverInit
 \brief    inicial adc registers assignments  
 */
void  ADC_vfnDriverInit(void);

/*!
 \fn      unsigned short ADC_wfnRead(unsigned char);
 \param   bChannel which channel are using in the ADC
 \return  gbCococFlag 
 \brief   Channel assignation 
 */
unsigned short ADC_ConvertioCheck(unsigned char );

/*!
 \fn      ADC_wfnLecture
 \return  This function return the value of the ADC 
 \brief   This function return the value of the ADC
 */
unsigned short ADC_wfnLecture(void);


#endif /* ADC_DRIVER_H_ */
