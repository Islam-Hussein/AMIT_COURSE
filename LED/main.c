/*
 * LED.c
 *
 * Created: 11/30/2021 6:32:17 AM
 * Author : Administrator
 */ 
#include "LED.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "Button.h"


int main(void)
{
	
	uint8 Button_Value = 0;
	
	Button0_Init();
	LED0_Init();
	
	LED0_ON();
	
    /* Replace with your application code */
    while (1) 
    {
		Button_Value = Button0_GetValue();
		
		if (Button_Value == 1)
		{
			LED0_Toggle();
		}
    }
}

