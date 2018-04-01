/*
 * Efectos_De_Sonido.h
 *
 *  Created on: 31/03/2018
 *      Author: David Bellomo
 *Description: This is a wrapper for the pleate Sound effect application
 *
 *
 *
 */

#ifndef EFECTOS_DE_SONIDO_EFECTOS_DE_SONIDO_H_
#define EFECTOS_DE_SONIDO_EFECTOS_DE_SONIDO_H_

/************************Definitions****************/
#define AUDIOEFFECT_ON 0xA5u  /*Activate the Sound Effect*/
#define AUDIOEFFECT_OFF 0x5A  /*De activate the sound effect*/
/*Type definitions*/
typedef enum{
	e_ECHO,
	e_DISTORTION,
	e_VIBRATO

}T_AudioEffect_Selection;

/****************Prototypes************/
extern void ISR_Audio_Sampl_Handler(void); /*This ISR is ment to be placed on the IRQ for the PIT channel corresponding to the Sampling Audio*/
extern void AudioEffect_ActivationCbk(void);
#endif /* EFECTOS_DE_SONIDO_EFECTOS_DE_SONIDO_H_ */
