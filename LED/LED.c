/*
 * LED.h
 *
 * Created: 11/30/2021 7:49:41 AM
 *  Author: Administrator
 */ 



#include "LED.h"


void LED0_Init(void)
{
	DIO_SetPinDir(DIO_PORTC, DIO_PIN2 , DIO_PIN_OUTPUT);
}

void LED0_ON(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_HIGH);
}

void LED0_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_LOW);
}

void LED0_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN2);
}

