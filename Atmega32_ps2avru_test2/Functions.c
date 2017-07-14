
#include "Functions.h"
#ifdef _AVR_ATMEGA32A_H_INCLUDED
void pinMode(uint8_t IO,uint8_t value){
	switch(IO){
		case 0: if(value){DDRA|= (1<<0);}else{DDRA &= ~(1<<0);}break;
		case 1: if(value){DDRA|= (1<<1);}else{DDRA &= ~(1<<1);}break;
		case 2: if(value){DDRA|= (1<<2);}else{DDRA &= ~(1<<2);}break;
		case 3: if(value){DDRA|= (1<<3);}else{DDRA &= ~(1<<3);}break;
		case 4: if(value){DDRA|= (1<<4);}else{DDRA &= ~(1<<4);}break;
		case 5: if(value){DDRA|= (1<<5);}else{DDRA &= ~(1<<5);}break;
		case 6: if(value){DDRA|= (1<<6);}else{DDRA &= ~(1<<6);}break;
		case 7: if(value){DDRA|= (1<<7);}else{DDRA &= ~(1<<7);}break;

		case 8:  if(value){DDRB|= (1<<0);}else{DDRB &= ~(1<<0);}break;
		case 9:  if(value){DDRB|= (1<<1);}else{DDRB &= ~(1<<1);}break;
		case 10: if(value){DDRB|= (1<<2);}else{DDRB &= ~(1<<2);}break;
		case 11: if(value){DDRB|= (1<<3);}else{DDRB &= ~(1<<3);}break;
		case 12: if(value){DDRB|= (1<<4);}else{DDRB &= ~(1<<4);}break;
		case 13: if(value){DDRB|= (1<<5);}else{DDRB &= ~(1<<5);}break;
		case 14: if(value){DDRB|= (1<<6);}else{DDRB &= ~(1<<6);}break;
		case 15: if(value){DDRB|= (1<<7);}else{DDRB &= ~(1<<7);}break;

		case 16: if(value){DDRC|= (1<<0);}else{DDRC &= ~(1<<0);}break;
		case 17: if(value){DDRC|= (1<<1);}else{DDRC &= ~(1<<1);}break;
		case 18: if(value){DDRC|= (1<<2);}else{DDRC &= ~(1<<2);}break;
		case 19: if(value){DDRC|= (1<<3);}else{DDRC &= ~(1<<3);}break;
		case 20: if(value){DDRC|= (1<<4);}else{DDRC &= ~(1<<4);}break;
		case 21: if(value){DDRC|= (1<<5);}else{DDRC &= ~(1<<5);}break;
		case 22: if(value){DDRC|= (1<<6);}else{DDRC &= ~(1<<6);}break;
		case 23: if(value){DDRC|= (1<<7);}else{DDRC &= ~(1<<7);}break;

		case 24: if(value){DDRD|= (1<<0);}else{DDRD &= ~(1<<0);}break;
		case 25: if(value){DDRD|= (1<<1);}else{DDRD &= ~(1<<1);}break;
		case 26: if(value){DDRD|= (1<<2);}else{DDRD &= ~(1<<2);}break;
		case 27: if(value){DDRD|= (1<<3);}else{DDRD &= ~(1<<3);}break;
		case 28: if(value){DDRD|= (1<<4);}else{DDRD &= ~(1<<4);}break;
		case 29: if(value){DDRD|= (1<<5);}else{DDRD &= ~(1<<5);}break;
		case 30: if(value){DDRD|= (1<<6);}else{DDRD &= ~(1<<6);}break;
		case 31: if(value){DDRD|= (1<<7);}else{DDRD &= ~(1<<7);}break;
	}
}
void digitalWrite(uint8_t IO,uint8_t value){
	switch(IO){
		case 0: if(value){PORTA|= (1<<0);}else{PORTA &= ~(1<<0);}break;
		case 1: if(value){PORTA|= (1<<1);}else{PORTA &= ~(1<<1);}break;
		case 2: if(value){PORTA|= (1<<2);}else{PORTA &= ~(1<<2);}break;
		case 3: if(value){PORTA|= (1<<3);}else{PORTA &= ~(1<<3);}break;
		case 4: if(value){PORTA|= (1<<4);}else{PORTA &= ~(1<<4);}break;
		case 5: if(value){PORTA|= (1<<5);}else{PORTA &= ~(1<<5);}break;
		case 6: if(value){PORTA|= (1<<6);}else{PORTA &= ~(1<<6);}break;
		case 7: if(value){PORTA|= (1<<7);}else{PORTA &= ~(1<<7);}break;

		case 8: if(value){PORTB|= (1<<0);}else{PORTB &= ~(1<<0);}break;
		case 9: if(value){PORTB|= (1<<1);}else{PORTB &= ~(1<<1);}break;
		case 10: if(value){PORTB|= (1<<2);}else{PORTB &= ~(1<<2);}break;
		case 11: if(value){PORTB|= (1<<3);}else{PORTB &= ~(1<<3);}break;
		case 12: if(value){PORTB|= (1<<4);}else{PORTB &= ~(1<<4);}break;
		case 13: if(value){PORTB|= (1<<5);}else{PORTB &= ~(1<<5);}break;
		case 14: if(value){PORTB|= (1<<6);}else{PORTB &= ~(1<<6);}break;
		case 15: if(value){PORTB|= (1<<7);}else{PORTB &= ~(1<<7);}break;

		case 16: if(value){PORTC|= (1<<0);}else{PORTC &= ~(1<<0);}break;
		case 17: if(value){PORTC|= (1<<1);}else{PORTC &= ~(1<<1);}break;
		case 18: if(value){PORTC|= (1<<2);}else{PORTC &= ~(1<<2);}break;
		case 19: if(value){PORTC|= (1<<3);}else{PORTC &= ~(1<<3);}break;
		case 20: if(value){PORTC|= (1<<4);}else{PORTC &= ~(1<<4);}break;
		case 21: if(value){PORTC|= (1<<5);}else{PORTC &= ~(1<<5);}break;
		case 22: if(value){PORTC|= (1<<6);}else{PORTC &= ~(1<<6);}break;
		case 23: if(value){PORTC|= (1<<7);}else{PORTC &= ~(1<<7);}break;

		case 24: if(value){PORTD|= (1<<0);}else{PORTD &= ~(1<<0);}break;
		case 25: if(value){PORTD|= (1<<1);}else{PORTD &= ~(1<<1);}break;
		case 26: if(value){PORTD|= (1<<2);}else{PORTD &= ~(1<<2);}break;
		case 27: if(value){PORTD|= (1<<3);}else{PORTD &= ~(1<<3);}break;
		case 28: if(value){PORTD|= (1<<4);}else{PORTD &= ~(1<<4);}break;
		case 29: if(value){PORTD|= (1<<5);}else{PORTD &= ~(1<<5);}break;
		case 30: if(value){PORTD|= (1<<6);}else{PORTD &= ~(1<<6);}break;
		case 31: if(value){PORTD|= (1<<7);}else{PORTD &= ~(1<<7);}break;

	}
}
uint8_t digitalRead(uint8_t IO){
	uint8_t value=0;
	switch(IO){
		case 0:  value= PINA& (1<<0) ;break;
		case 1:  value= PINA& (1<<1) ;break;
		case 2:  value= PINA& (1<<2) ;break;
		case 3:  value= PINA& (1<<3) ;break;
		case 4:  value= PINA& (1<<4) ;break;
		case 5:  value= PINA& (1<<5) ;break;
		case 6:  value= PINA& (1<<6) ;break;
		case 7:  value= PINA& (1<<7) ;break;

		case 8:  value= PINB& (1<<0) ;break;
		case 9:  value= PINB& (1<<1) ;break;
		case 10:  value= PINB& (1<<2) ;break;
		case 11:  value= PINB& (1<<3) ;break;
		case 12:  value= PINB& (1<<4) ;break;
		case 13:  value= PINB& (1<<5) ;break;
		case 14:  value= PINB& (1<<6) ;break;
		case 15:  value= PINB& (1<<7) ;break;

		case 16:  value= PINC& (1<<0) ;break;
		case 17:  value= PINC& (1<<1) ;break;
		case 18:  value= PINC& (1<<2) ;break;
		case 19:  value= PINC& (1<<3) ;break;
		case 20:  value= PINC& (1<<4) ;break;
		case 21:  value= PINC& (1<<5) ;break;
		case 22:  value= PINC& (1<<6) ;break;
		case 23:  value= PINC& (1<<7) ;break;

		case 24:  value= PIND& (1<<0) ;break;
		case 25:  value= PIND& (1<<1) ;break;
		case 26:  value= PIND& (1<<2) ;break;
		case 27:  value= PIND& (1<<3) ;break;
		case 28:  value= PIND& (1<<4) ;break;
		case 29:  value= PIND& (1<<5) ;break;
		case 30:  value= PIND& (1<<6) ;break;
		case 31:  value= PIND& (1<<7) ;break;
	}
	return value;
}
#endif

