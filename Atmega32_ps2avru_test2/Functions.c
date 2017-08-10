
#include "Functions.h"

uint8_t usb_mouse_send_required(){
	uint8_t send_required_t=0;
	if(mouse_report.mouse.buttons!=mouse_buffer.mouse_keys)
	{
		mouse_report.mouse.buttons=mouse_buffer.mouse_keys;
		send_required_t=REPORT_ID_MOUSE;
	}
	if(mouse_report.system_keys.usage!=mouse_buffer.system_keys)
	{
		mouse_report.system_keys.usage=mouse_buffer.system_keys;
		send_required_t=REPORT_ID_SYSTEM;
	}
	if(mouse_report.consumer_keys.usage!=mouse_buffer.consumer_keys)
	{
		mouse_report.consumer_keys.usage=mouse_buffer.consumer_keys;
		send_required_t=REPORT_ID_CONSUMER;
	}
	if(send_required_t){
		mouse_buffer.Send_Required=send_required_t;
	}
	return send_required_t;
}
uint8_t usb_keyboard_send_required(){
	uint8_t send_required_t=0;
	if(keyboard_report.modifier!=keyboard_buffer.keyboard_modifier_keys)
	{keyboard_report.modifier = keyboard_buffer.keyboard_modifier_keys;send_required_t=1;}
	if(keyboard_report.keycode[0]!=keyboard_buffer.keyboard_keys[0])
	{keyboard_report.keycode[0]=keyboard_buffer.keyboard_keys[0];send_required_t=1;}
	if(keyboard_report.keycode[1]!=keyboard_buffer.keyboard_keys[1])
	{keyboard_report.keycode[1]=keyboard_buffer.keyboard_keys[1];send_required_t=1;}
	if(keyboard_report.keycode[2]!=keyboard_buffer.keyboard_keys[2])
	{keyboard_report.keycode[2]=keyboard_buffer.keyboard_keys[2];send_required_t=1;}
	if(keyboard_report.keycode[3]!=keyboard_buffer.keyboard_keys[3])
	{keyboard_report.keycode[3]=keyboard_buffer.keyboard_keys[3];send_required_t=1;}
	if(keyboard_report.keycode[4]!=keyboard_buffer.keyboard_keys[4])
	{keyboard_report.keycode[4]=keyboard_buffer.keyboard_keys[4];send_required_t=1;}
	if(keyboard_report.keycode[5]!=keyboard_buffer.keyboard_keys[5])
	{keyboard_report.keycode[5]=keyboard_buffer.keyboard_keys[5];send_required_t=1;}
	if(send_required_t)keyboard_buffer.Send_Required=send_required_t;
	return send_required_t;
}
uint8_t i1=0;
uint8_t i2=0;
uint8_t usb_mouse_send(){
	if(mouse_buffer.Send_Required==0)return 0;
	i1=0;
	while(++i1<50){
		usbPoll();
		if (usbConfiguration &&usbInterruptIsReady3()){
			if(mouse_buffer.Send_Required==REPORT_ID_MOUSE){
				usbSetInterrupt3((void *)&mouse_report.mouse, sizeof(report_mouse0_t));
				mouse_buffer.Send_Required=0;
			}
			else if(mouse_buffer.Send_Required==REPORT_ID_SYSTEM){
				usbSetInterrupt3((void *)&mouse_report.system_keys, sizeof(report_extra_t));
				mouse_buffer.Send_Required=0;
			}
			else if(mouse_buffer.Send_Required==REPORT_ID_CONSUMER){
				usbSetInterrupt3((void *)&mouse_report.consumer_keys, sizeof(report_extra_t));
				mouse_buffer.Send_Required=0;
			}
			return 1;
		}
	}
	return 0;
}
uint8_t usb_keyboard_send(){
	if(keyboard_buffer.Send_Required==0)return 0;
	i2=0;
	while(++i2<50){
		usbPoll();
		if (usbConfiguration &&usbInterruptIsReady()){
			if(keyboard_buffer.Send_Required){
				usbSetInterrupt((void *)&keyboard_report, sizeof(report_keyboard_t));
				keyboard_buffer.Send_Required=0;
			}
			return 1;
		}
	}
	return 0;
}
void usb_update(){
	usbPoll();
}
///////////////////////////////////////////////////////////////////////
uint8_t presskey(uint8_t key)
{
	uint8_t i;
	for ( i=0; i < 6; i++) {
		if (keyboard_buffer.keyboard_keys[i] == key) {
			return 1;
		}
	}
	for ( i=0; i < 6; i++) {
		if (keyboard_buffer.keyboard_keys[i] == 0) {
			keyboard_buffer.keyboard_keys[i] = key;
			return 1;
		}
	}
	return 0;
}
void pressModifierKeys(uint8_t key)
{
	keyboard_buffer.keyboard_modifier_keys|=key;
}
void pressmousekey(uint8_t key){
	mouse_buffer.mouse_keys|=key;
}
void presssystemkey(uint8_t key){
	mouse_buffer.system_keys=(uint16_t)key;
}
void pressconsumerkey(uint8_t key){
	mouse_buffer.consumer_keys=(uint16_t)key;
}
void releaseAllmousekeys(){
	mouse_buffer.mouse_keys=0;
	mouse_buffer.system_keys=0;
	mouse_buffer.consumer_keys=0;
}
void releaseAllkeyboardkeys()
{
	uint8_t i;
	for ( i=0; i < 6; i++) {
		keyboard_buffer.keyboard_keys[i] = 0;
	}
	keyboard_buffer.keyboard_modifier_keys=0;
}
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

