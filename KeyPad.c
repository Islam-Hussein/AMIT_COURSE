#include "KeyPad.h"
#include <util/delay.h>

#define COL_INIT   0 
#define COL_FINAL  3

#define ROW_INIT   4
#define ROW_FINAL  7

const uint8 KeyPad_Value[4][4] = {	{'7','8','9','/'},
									{'4','5','6','*'},
									{'1','2','3','-'}, 
									{'c','0','=','+'}  };


void KeyPad_init(void)
{
	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_COLOUM_0 , DIO_PIN_OUTPUT);
	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_COLOUM_1 , DIO_PIN_OUTPUT);
	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_COLOUM_2 , DIO_PIN_OUTPUT);
	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_COLOUM_3 , DIO_PIN_OUTPUT);

	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_ROW_0 , DIO_PIN_OUTPUT);
	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_ROW_1 , DIO_PIN_OUTPUT);
	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_ROW_2 , DIO_PIN_OUTPUT);
	DIO_SetPintDir(KEYPAD_PORT , KEYPAD_ROW_3 , DIO_PIN_OUTPUT);

	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_0);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_1);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_2);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_3 );
	
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_0, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_1, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_2, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_3, DIO_PIN_HIGH);
}

uint8 KeyPad_GetValue(void)
{
	uint8 LOC_Coloum = 0;
	uint8 LOC_Row    = 0;
	uint8 value      = 0;
	uint8 Temp       = 0;
	
	
	for (LOC_Coloum = COL_INIT ; LOC_Coloum <= COL_FINAL  ; LOC_Coloum++)
	{
		DIO_SetPinValue(KEYPAD_PORT, LOC_Coloum , DIO_PIN_LOW);
		
		for (LOC_Row = ROW_INIT; LOC_Row <= ROW_FINAL ; LOC_Row++)
		{
			DIO_ReadPin(KEYPAD_PORT, LOC_Row , &Temp);
			
			if(!Temp)
			{
				value = KeyPad_Value[LOC_Row - ROW_INIT][LOC_Coloum - COL_INIT];
				
				while(!Temp)
				{
					DIO_ReadPin(KEYPAD_PORT, LOC_Row , &Temp);
				}
				_delay_ms(10);      //debouncing of Button
			}
		}
		
		DIO_SetPinValue(KEYPAD_PORT, LOC_Coloum , DIO_PIN_HIGH);
	}
	
	return value;
	
}






















