/*
 * interruptExternal.cpp
 *
 * Created: 12/12/2022 11.25.19
 *  Author: fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "interruptExternal.hpp"

void interruptExternalInit(Pin pin,Mode mode)
{
	
	if(pin == pinINT0){
		DDRD &= ~(1<<2);
		PORTD |= (1<<2);
		GICR |= (1<<INT0);
		
		if(mode == activeWhen0To1){
			MCUCR |= (1<<ISC01)|(1<<ISC00);
		}else if(mode == activeWhen1To0){
			MCUCR |= (1<<ISC01);
		}
		
	}else if(pin == pinINT1){
		DDRD &= ~(1<<3);
		PORTD |= (1<<3);
		GICR |= (1<<INT1);
		
		if(mode == activeWhen0To1){
			MCUCR |= (1<<ISC11)|(1<<ISC10);
		}else if(mode == activeWhen1To0){
			MCUCR |= (1<<ISC11);
		}	
	}
}