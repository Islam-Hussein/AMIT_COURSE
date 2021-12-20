
#include "LCD.h"
#define F_CPU 16000000
#include <util/delay.h>

void LCD_Init(void)
{
    #if LCD_MODE == 8
    

    DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_OUTPUT);

    DIO_SetPortDir(LCD_8BIT_DATA_PORT, DIO_PORT_OUTPUT);

    _delay_ms(100);


    #elif LCD_MODE == 4

    DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_E_PIN , DIO_PIN_OUTPUT);

    DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_D4 , DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_D5 , DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_D6 , DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_D7 , DIO_PIN_OUTPUT);

    _delay_ms(100);



    #endif
}

void LCD_WriteCommand(uint8 cmd)
{
    DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_RS_PIN , DIO_PIN_LOW);
    DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_RW_PIN , DIO_PIN_LOW);
    DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN  , DIO_PIN_LOW);

    
}

void LCD_WriteData(uint8 data);

void LCD_GoTo(uint8 Row, Uint8 Col);

void LCD_WriteString (uint8* str);

void LCD_Clear(void);
