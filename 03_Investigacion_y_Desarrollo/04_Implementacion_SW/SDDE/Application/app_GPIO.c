/*
 * app_GPIO.c
 *
 *  Created on: 14/10/2017
 *      Author: uidj2522
 */

#include "stdio.h"
#include "MKL25Z4.h"
#include "stdtypedef.h"
#include "app_GPIO.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

void app_GPIO_Init(void)
{
	/* Enable the clock for the modules needed */

	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortD);

	/* PORT Module Configuration */

	port_pin_config_t ls_PinConfig;

	ls_PinConfig.mux = kPORT_MuxAsGpio;
	ls_PinConfig.pullSelect = kPORT_PullUp;

	port_pin_config_t *lps_PinConfig;

	lps_PinConfig = &ls_PinConfig;

	PORT_SetPinConfig(PORTC, 9U, lps_PinConfig);	/*We may need to remove these pins*/
	PORT_SetPinConfig(PORTC, 8U, lps_PinConfig);	/*We may need to remove these pins*/
	PORT_SetPinConfig(PORTB, 18U, lps_PinConfig); /*LED Pin*/
	PORT_SetPinConfig(PORTB, 19U, lps_PinConfig); /*LED Pin*/
	PORT_SetPinConfig(PORTD, 1U, lps_PinConfig);  /*LED Pin*/
	PORT_SetPinConfig(PORTB, 9U, lps_PinConfig);  /*To Change between effects */
	PORT_SetPinConfig(PORTB, 8U, lps_PinConfig);  /*To start Calibration of the EMG movement detection*/

	/* GPIO Configuration for Inputs */

	gpio_pin_config_t ls_GPIOPinConfig;

	ls_GPIOPinConfig.pinDirection = kGPIO_DigitalInput;
	ls_GPIOPinConfig.outputLogic = TRUE;

	gpio_pin_config_t *lps_GPIOPinConfig;

	lps_GPIOPinConfig = &ls_GPIOPinConfig;

	GPIO_PinInit(GPIOC, 9U, lps_GPIOPinConfig); /*We may need to remove these pins*/
	GPIO_PinInit(GPIOC, 8U, lps_GPIOPinConfig);/*We may need to remove these pins*/


	GPIO_PinInit(GPIOB, 9U, lps_GPIOPinConfig); /*To Change between effects */
	GPIO_PinInit(GPIOB, 8U, lps_GPIOPinConfig); /*To start Calibration of the EMG movement detection*/
	/* GPIO Configuration for Outputs */

	ls_GPIOPinConfig.pinDirection = kGPIO_DigitalOutput;
	ls_GPIOPinConfig.outputLogic = TRUE; //LEDs Off
	GPIO_PinInit(GPIOB, 18U, lps_GPIOPinConfig);
	GPIO_PinInit(GPIOB, 19U, lps_GPIOPinConfig);
	GPIO_PinInit(GPIOD, 1U, lps_GPIOPinConfig);

}

T_UBYTE app_GPIO_GetPinValue(GPIO_Type *lps_BaseAddress, T_UBYTE lub_PinNumber)
{
	T_UBYTE lub_PinValue;

	lub_PinValue = (T_UBYTE)GPIO_ReadPinInput(lps_BaseAddress, lub_PinNumber);

	return lub_PinValue;
}
