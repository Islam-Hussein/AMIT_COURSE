#ifndef ATMEGA32_REGISTER_H_
#define ATMEGA32_REGISTER_H_

#include "STD.h"

/****************************** PORTA **************************************/

#define DDRA       (*(volatile uint8*)(0x3A))
#define PORTA      (*(volatile uint8*)(0x3B))
#define PINA       (*(volatile uint8*)(0x39))

/****************************** PORTB **************************************/

#define DDRB       (*(volatile uint8*)(0x37))
#define PORTB      (*(volatile uint8*)(0x38))
#define PINB       (*(volatile uint8*)(0x36))

/****************************** PORTC **************************************/

#define DDRC       (*(volatile uint8*)(0x34))
#define PORTC      (*(volatile uint8*)(0x35))
#define PINC       (*(volatile uint8*)(0x33))

/****************************** PORTD **************************************/

#define DDRD       (*(volatile uint8*)(0x32))
#define PORTD      (*(volatile uint8*)(0x33))
#define PIND       (*(volatile uint8*)(0x31))







#endif 