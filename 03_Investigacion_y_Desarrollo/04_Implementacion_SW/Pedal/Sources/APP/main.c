/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

#include "Distorcion.h"

#include "Electromiografo.h"

#include "Echo.h"

#include "Vibrato.h"

#include "NoEffect.h"

int main(void)
{
	int counter = 0;
	
	static unsigned char Mioelectrico = 0;
	
	
	for(;;) {	  
		
		Mioelectrico = vfnElectromiografo();
		
		if (Mioelectrico)
		{
			if (vfnPinStatus(PORTD,0))
			{
				vfnDistorcion();
			}
			else if(vfnPinStatus(PORTD,1))
			{
				vfnEcho();
			}
			else if(vfnPinStatus(PORTD,2))
			{
				vfnVibrato();
			}
		}
		else
		{
			NoEffect();
		}
		
		
		
		
	   	counter++;
	}
	
	return 0;
}
