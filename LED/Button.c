/*
 * Button.c
 *
 * Created: 11/30/2021 8:39:38 AM
 *  Author: Administrator
 */ 

#include "Button.h"
#define F_CPU 16000000
#include <util/delay.h>

void Button0_Init(void)
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN0, DIO_PIN_INPUT);	
}

uint8 Button0_GetValue(void)
{
	uint8 Value = 0;
	
	Value = GET_BIT(PINB,0);
	
	while(GET_BIT(PINB,0));
	
	_delay_ms(20);
	
	return Value;
}


