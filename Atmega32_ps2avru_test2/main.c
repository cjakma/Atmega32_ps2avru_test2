
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <string.h>

#include "Functions.h"

//ledfull D4
//led D0 D4 D1
//DAT D3
//D5--ÎÈÑ¹¶þ¼«¹Ü
//row A0,A1,A2,A3,A4 A5 A6 A7 C7 C6 C5 C4 C3 C2 C1 C0 D7
//col B0 B1 B2 B3 B4 B5 B6 B7
uint8_t i,delayval,FN;
uint8_t rowPins[ROWS]={0,1,2,3,4,5,6,7,23,22,21,20,19,18};
uint8_t colPins[COLS]={8,9,10,11,12,13,14,15};
#define ledcount 3
uint8_t ledPins[ledcount]={24,28,25};

uint8_t hexaKeys0[ROWS][COLS] = {
   { KEY_PAUSE,    KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_RCTRL,  KEY_NONE,   KEY_LCTRL,  KEY_F5 },   // ROW0
   { KEY_Q,        KEY_TAB,    KEY_A,      KEY_ESC,    KEY_Z,      KEY_NONE,   KEY_HASH,   KEY_1 },    // ROW1
   { KEY_W,        KEY_CAPS,   KEY_S,      KEY_NONE,   KEY_X,      KEY_NONE,   KEY_F1,     KEY_2 },    // ROW2
   { KEY_E,        KEY_F3,     KEY_D,      KEY_F4,     KEY_C,      KEY_NONE,   KEY_F2,     KEY_3 },    // ROW3
   { KEY_R,        KEY_T,      KEY_F,      KEY_G,      KEY_V,      KEY_B,      KEY_5,      KEY_4 },    // ROW4
   { KEY_U,        KEY_Y,      KEY_J,      KEY_H,      KEY_M,      KEY_N,      KEY_6,      KEY_7 },    // ROW5
   { KEY_I,        KEY_RBR,    KEY_K,      KEY_F6,     KEY_COMMA,  KEY_NONE,   KEY_EQUAL,  KEY_8 },    // ROW6
   { KEY_O,        KEY_F7,     KEY_L,      KEY_NONE,   KEY_DOT,    KEY_FN,     KEY_F8,     KEY_9 },    // ROW7
   { KEY_P,        KEY_LBR,    KEY_COLON,  KEY_QUOTE,  KEY_NONE,   KEY_SLASH,  KEY_MINUS,  KEY_0},     // ROW8
   { KEY_SCRLCK,   KEY_NONE,   KEY_NONE,   KEY_LALT,   KEY_NONE,   KEY_RALT,   KEY_NONE,   KEY_PRNSCR},// ROW9
   { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE},   // ROW10
   { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE}, // ROW11
   { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE}, // ROW12
   { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE}, // ROW13
   { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_UP,     KEY_NONE,   KEY_LEFT,   KEY_HOME,   KEY_END }  // ROW14
};
uint8_t hexaKeys1[ROWS][COLS] = {
	 { KEY_NUMLOCK,  KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_RCTRL,  KEY_NONE,   KEY_LCTRL,  KEY_F5 },   // ROW0
	 { KEY_Q,        KEY_TAB,    KEY_A,      KEY_ESC,    KEY_Z,      KEY_NONE,   KEY_HASH,   KEY_1 },    // ROW1
	 { KEY_W,        KEY_CAPS,   KEY_S,      KEY_NONE,   KEY_X,      KEY_NONE,   KEY_F1,     KEY_2 },    // ROW2
	 { KEY_E,        KEY_F3,     KEY_D,      KEY_F4,     KEY_C,      KEY_NONE,   KEY_F2,     KEY_3 },    // ROW3
	 { KEY_R,        KEY_T,      KEY_F,      KEY_G,      KEY_V,      KEY_B,      KEY_5,      KEY_4 },    // ROW4
	 { KEY_KP_4,     KEY_Y,      KEY_KP_1,   KEY_H,      KEY_KP_0,   KEY_N,      KEY_6,      KEY_KP_7 }, // ROW5
	 { KEY_KP_5,     KEY_RBR,    KEY_KP_2,   KEY_F6,     KEY_KP_0,   KEY_NONE,   KEY_EQUAL,  KEY_KP_8 }, // ROW6
	 { KEY_KP_6,     KEY_F7,     KEY_KP_3,   KEY_NONE,   KEY_KP_DOT, KEY_FN,     KEY_F8,     KEY_KP_9 }, // ROW7
	 { KEY_KP_AST,   KEY_LBR,    KEY_KP_MINUS,KEY_QUOTE, KEY_NONE,   KEY_KP_PLUS,KEY_MINUS,  KEY_KP_SLASH},  // ROW8
	 { KEY_LED,      KEY_NONE,   KEY_NONE,   KEY_LALT,   KEY_NONE,   KEY_RALT,   KEY_NONE,   KEY_PRNSCR},// ROW9
	 { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE},   // ROW10
	 { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE}, // ROW11
	 { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE}, // ROW12
	 { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE,   KEY_NONE}, // ROW13
	 { KEY_NONE,     KEY_NONE,   KEY_NONE,   KEY_UP,     KEY_NONE,   KEY_LEFT,   KEY_HOME,   KEY_END }  // ROW14
};
//keymask_bits:7-press 654-hexatype0 3-press 210-hexatype1
//type: 1-key 2-modifykey 3-mousekey 4-systemkey 5-consumerkey 6-FN 7-consumerkeyAL,8-consumerkeyAC

uint8_t keymask[ROWS][COLS]={
	{0x11,0x00,0x00,0x00,0x22,0x00,0x22,0x11},//ROW0
	{0x11,0x11,0x11,0x11,0x11,0x00,0x11,0x11},//ROW1
	{0x11,0x11,0x11,0x00,0x11,0x00,0x11,0x11},//ROW2
	{0x11,0x11,0x11,0x11,0x11,0x00,0x11,0x11},//ROW3
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},//ROW4
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},
	{0x11,0x11,0x11,0x11,0x11,0x00,0x11,0x11},
	{0x11,0x11,0x11,0x00,0x11,0x11,0x11,0x11},
	{0x11,0x11,0x11,0x11,0x00,0x11,0x11,0x11},
	{0x11,0x00,0x00,0x22,0x00,0x22,0x00,0x11},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x11,0x00,0x11,0x11,0x11},
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
/*
uint8_t LED_caps=2;
uint8_t LED_GPIO1=17;
uint8_t LED_GPIO2=18;
*/
void init_LED(){
	for ( i=0; i<ledcount; i++){
		pinMode(ledPins[i],OUTPUT);
		digitalWrite(ledPins[i],LOW);
	}
}
void LED(){
	for ( i=0; i<ledcount; i++){
		if((keyboard_buffer.keyboard_leds&(1<<i))==(1<<i)){ digitalWrite(ledPins[i],LOW);}
		else{ digitalWrite(ledPins[i],HIGH);}
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
	if(usb_mouse_send_required())delay_before=_delay_before;
	if(delay_after==_delay_after && delay_before==1){
	usb_keyboard_send();usb_mouse_send();}
	if(delay_after==1){
	usb_keyboard_send();usb_mouse_send();}
	if(delay_after>0)delay_after-=1;
	if(delay_before>0)delay_before-=1;
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
	if(keyboard_buffer.enable_pressing==1){
	FaceUMode();
	LED();	
	}	
	}
	return 0;
}
