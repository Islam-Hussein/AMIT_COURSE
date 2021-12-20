#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"


void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteData(uint8 data);

void LCD_GoTo(uint8 Row, Uint8 Col);

void LCD_WriteString (uint8* str);

void LCD_Clear(void);


#endif