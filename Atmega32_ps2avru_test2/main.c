
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <string.h>

#include "Functions.h"

//ledfull D4
//led D0 D4 D1
//DAT D3
//D5--ÎÈÑ¹¶þ¼«¹Ü
//col A0,A1,A2,A3,A4 A5 A6 A7 C7 C6 C5 C4 C3 C2 C1 C0 D7
//row B0 B1 B2 B3 B4 B5 B6 B7
//jump A1 B0
uint8_t i,delayval,FN;
uint8_t rowPins[ROWS]={8,9,10,11,12,13,14,15};
uint8_t colPins[COLS]={1,2,3,4,5,6,7,23,22,21};
//                     2 3 4 5 6 7 8  9  10 11
#define ledcount 3
uint8_t ledPins[ledcount]={24,25,28};

uint8_t hexaKeys0[ROWS][COLS] = {
	{KEY_Q,KEY_W,KEY_E,KEY_R,KEY_U,KEY_I,KEY_O,KEY_P,KEY_CTRL,KEY_GUI},//ROW0
	{KEY_TAB,KEY_CAPS,0x00,KEY_T,KEY_Y,KEY_RIGHT_BRACE,KEY_TILDE,KEY_LEFT_BRACE,KEY_SHIFT,0x00},//ROW1
	{KEY_A,KEY_S,KEY_D,KEY_F,KEY_J,KEY_K,KEY_L,KEY_SEMICOLON,KEY_RIGHT_CTRL,KEY_BACKSLASH},//ROW2
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW3
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW4
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW5
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW6
	{KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_0},//ROW7
};
uint8_t hexaKeys1[ROWS][COLS] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW0
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW1
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW2
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW3
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW4
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW5
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW6
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//ROW7
};
//keymask_bits:7-press 654-hexatype0 3-press 210-hexatype1
//type: 1-key 2-modifykey 3-mousekey 4-systemkey 5-consumerkey 6-FN 7-consumerkeyAL,8-consumerkeyAC

uint8_t keymask[ROWS][COLS]={
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW0
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW1
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW2
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW3
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW4
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW5
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW6
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW7
};

void init_cols(){
	for ( i=0; i<COLS; i++){
		pinMode(colPins[i],INPUT);
		digitalWrite(colPins[i],HIGH);
	}
}
void init_rows(){
	for ( i=0; i<ROWS; i++){
		pinMode(rowPins[i],INPUT);
		digitalWrite(rowPins[i],HIGH);
	}
}
/////////////////////////////////////////////////////////////////////

void Open_LED(){
	for ( i=0; i<ledcount; i++){
		digitalWrite(ledPins[i],LOW);
	}
}
void Close_LED(){

	for ( i=0; i<ledcount; i++){
		digitalWrite(ledPins[i],HIGH);
	}
}
void init_LED(){
	for ( i=0; i<ledcount; i++){
		pinMode(ledPins[i],OUTPUT);
		digitalWrite(ledPins[i],LOW);
	}
}
void LED(){
	for ( i=0; i<ledcount; i++){
		if((keyboard_buffer.keyboard_leds&(1<<i))==(1<<i)){ digitalWrite(ledPins[i],HIGH);}
		else{ digitalWrite(ledPins[i],LOW);}
	}
}


/////////////////////////////////////////////////////////////////////
uint8_t r,c;
uint8_t delay_after=0;
uint8_t delay_before=0;
void FaceUMode(){
	FN=0xF0;
	for (r = 0; r < ROWS; r++) {
		pinMode(rowPins[r],OUTPUT);
		digitalWrite(rowPins[r],LOW);
		for (c = 0; c < COLS; c++) {
			if (digitalRead(colPins[c])) {keymask[r][c]&= ~0x88;}
			else {keymask[r][c]|= 0x88;delay_after=_delay_after;}
			if(keymask[r][c]==0xEE )FN=0x0F;
		}
		init_rows();
	}
	releaseAllkeyboardkeys();
	releaseAllmousekeys();
	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLS; c++) {
			switch(keymask[r][c]&FN){
				case 0x90:
				presskey(hexaKeys0[r][c]);
				break;
				case 0xA0:
				pressModifierKeys(hexaKeys0[r][c]);
				break;
				case 0xB0:
				pressmousekey(hexaKeys0[r][c]);
				break;
				case 0xC0:
				presssystemkey(hexaKeys0[r][c]);
				break;
				case 0xD0:
				pressconsumerkey(hexaKeys0[r][c]);
				break;
				case 0x09:
				presskey(hexaKeys1[r][c]);
				break;
				case 0x0A:
				pressModifierKeys(hexaKeys1[r][c]);
				break;
				case 0x0B:
				pressmousekey(hexaKeys1[r][c]);
				break;
				case 0x0C:
				presssystemkey(hexaKeys1[r][c]);
				break;
				case 0x0D:
				pressconsumerkey(hexaKeys1[r][c]);
				break;
			}
		}
	}
	if(usb_keyboard_send_required())delay_before=_delay_before;
	//if(usb_mouse_send_required())delay_before=_delay_before;
	if(delay_after==_delay_after && delay_before==1){
	usb_keyboard_send();
	//usb_mouse_send();
	}
	if(delay_after==1){
	usb_keyboard_send();
	//usb_mouse_send();
	}
	if(delay_after>0)delay_after--;
	if(delay_before>0)delay_before--;
	usb_update();
}
int main(void) {
	usb_init();	
	////////////////////////////////////////////////
	init_cols();
	init_rows();
    init_LED();
	releaseAllkeyboardkeys();
	releaseAllmousekeys();
	//ResetMatrixFormEEP();
	while (1) {
	//if(keyboard_buffer.enable_pressing==1){
	FaceUMode();
	LED();	
	//}	
	}
	return 0;
}
