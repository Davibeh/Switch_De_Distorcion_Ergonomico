/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*David Bellomo 30/03/18: Add a ifdef and define  in order to enable and disable the Beta variant code*/
#define DISABLE_BETA

/**
 * @file    MKL25Z128xxx4_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"

/* TODO: insert other include files here. */
#include "app_Init.h"
#include "app_PIT.h"
#include "app_BtnDbnc.h"
#include "app_LED.h"
#include "fsl_gpio.h"
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

/*David Bellomo just for now ;)*/
#ifdef DISABLE_BETA
unsigned char estado;
void vfnEcho (void);
void NoEffect (void);
#endif


int main(void)
{
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_BootClockRUN();
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();


#ifndef DISABLE_BETA
	/* Initialization App */
	printf("BETA CODE IS ENABLED\n");
	app_Init_BETA();

	//Infinite Loop
	for(;;)
	{
		OS_Sched_Core_Loop();
	}
#else
	printf("ALFA CODE IS ENABLED\n");
	app_Init_ALFA();
	for(;;);
#endif
	return 0 ;
}
