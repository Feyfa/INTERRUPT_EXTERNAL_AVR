/*
 * GccApplication1.cpp
 *
 * Created: 25/12/2022 14.53.27
 * Author : fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "interruptExternal.hpp"

ISR(INT0_vect){
	PORTB |= (1<<0);
	_delay_ms(1000);
}
ISR(INT1_vect){
	PORTB |= (1<<1);
	_delay_ms(1000);
}
int main(void)
{
	DDRB = (1<<0)|(1<<1);
	interruptExternalInit(pinINT0,activeWhen0To1);//using the INT0 pin, the interrupt fires when 0 goes to 1
	interruptExternalInit(pinINT1,activeWhen1To0);//using the INT1 pin, the interrupt fires when 1 goes to 0
	sei();
    
	while (1) 
    {
		PORTB &= ~((1<<0)|(1<<1));
    }
}

