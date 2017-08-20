#include "Functions.h"
#include "ws2812.h"
#ifdef ps2avrGB
//ps2avrGB rev_SJZZ
//col A0,A1,A2,A3,A4 A5 A6 A7 C7 C6 C5 C4 C3 C2 D7
//row B3 B4 B5 B6 B7
//usbdrv D5
//led D0 D1 D6
//full led  D4 RGB C1
uint8_t i,FN;
uint8_t rowPins[ROWS]={11,12,13,14,15};
uint8_t colPins[COLS]={0,1,2,3,4,5,6,7,23,22,21,20,19,18,31};
#define ledcount 2
uint8_t ledPins[ledcount]={24,25};
void init_cols(){
	for ( i=0; i<COLS; i++){
		pinMode(colPins[i],INPUT);
		digitalWrite(colPins[i],HIGH);
	}
}
void init_rows(){
	DDRB=0;
	PORTB=1;
}
void matrix_set_row_status(uint8_t row) {
    row+=3;
	DDRB = (1 << row);
	PORTB = ~(1 << row);
}
uint8_t hexaKeys0[ROWS][COLS] = {
  {KEY_ESC,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_0,KEY_MINUS,KEY_EQUAL,0x00,KEY_BACKSPACE},
  {KEY_TAB,KEY_Q,KEY_W,KEY_E,KEY_R,KEY_T,KEY_Y,KEY_U,KEY_I,KEY_O,KEY_P,KEY_LEFT_BRACE,KEY_RIGHT_BRACE,KEY_BACKSLASH,0x00},
  {KEY_CAPS_LOCK,KEY_A,KEY_S,KEY_D,KEY_F,KEY_G,KEY_H,KEY_J,KEY_K,KEY_L,KEY_SEMICOLON,KEY_QUOTE,0x00,KEY_ENTER,0x00},
  {KEY_LEFT_SHIFT,0x00,KEY_Z,KEY_X,KEY_C,KEY_V,KEY_B,KEY_N,KEY_M,KEY_COMMA,KEY_PERIOD,KEY_SLASH, KEY_RIGHT_SHIFT,KEY_UP,0x00},
  {KEY_LEFT_CTRL,KEY_FN,KEY_LEFT_ALT,0x00,0x00,0x00,0x00,KEY_SPACE,0x00,KEY_FN,KEY_RIGHT_ALT,KEY_LEFT,KEY_DOWN, KEY_RIGHT,0x00}
};
uint8_t hexaKeys1[ROWS][COLS] = {
	{KEY_TILDE,KEY_F1,KEY_F2,KEY_F3,KEY_F4,KEY_F5,KEY_F6,KEY_F7,KEY_F8,KEY_F9,KEY_F10,KEY_F11,KEY_F12,0x00,KEY_DELETE},
	{KEY_TAB,KEYPAD_1,KEYPAD_2,KEYPAD_3,KEYPAD_4,KEYPAD_5,KEYPAD_6,KEYPAD_7,KEYPAD_8,KEYPAD_9,KEYPAD_0,KEYPAD_MINUS,KEYPAD_PLUS,KEY_BACKSLASH,0x00},
	{KEY_CAPS_LOCK, MOUSE_LEFT,MOUSE_MID,MOUSE_RIGHT,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,KEY_ENTER,0x00},
	{KEY_LEFT_SHIFT,0x00,KEY_NUM_LOCK ,KEY_SCROLL_LOCK,KEY_INSERT,KEY_PRINTSCREEN,0x00,0x00,0x00,AUDIO_VOL_DOWN,AUDIO_VOL_UP,AUDIO_MUTE,KEY_RIGHT_SHIFT,KEY_UP,0x00},
	{KEY_LEFT_CTRL,KEY_FN,KEY_LEFT_ALT,0x00,0x00,0x00,0x00,KEY_SPACE,0x00,KEY_FN,KEY_RIGHT_ALT,KEY_LEFT,KEY_DOWN,KEY_RIGHT,0x00}
};
//keymask_bits:7-press 654-hexatype0 3-press 210-hexatype1
//type: 1-key 2-modifykey 3-mousekey 4-systemkey 5-consumerkey 6-FN 7-consumerkeyAL,8-consumerkeyAC
uint8_t keymask[ROWS][COLS] = {
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x00},
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x00},
	{0x11,0x13,0x13,0x13,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x11,0x00},
	{0x22,0x00,0x11,0x11,0x11,0x11,0x10,0x10,0x10,0x15,0x15,0x15,0x22,0x11,0x00},
	{0x22,0x66,0x22,0x00,0x00,0x00,0x00,0x11,0x00,0x66,0x22,0x11,0x11,0x11,0x00}
};
/////////////////////////////////////////////////////////////////////
void Open_LED(){
	for ( i=0; i<ledcount; i++){
		digitalWrite(ledPins[i],HIGH);
	}
}
void Close_LED(){

	for ( i=0; i<ledcount; i++){
		digitalWrite(ledPins[i],LOW);
	}
}
uint16_t delayval;
void init_LED(){
	for ( i=0; i<ledcount; i++){
		pinMode(ledPins[i],OUTPUT);
		digitalWrite(ledPins[i],HIGH);
	}
		WS2812Setup();delayval=Maxdelay;
		WS2812Clear();
		WS2812Send();
}
uint16_t cindex[WS2812_COUNT]={0,34,68,102,136,170};
void LED(){
	for ( i=0; i<ledcount; i++){
		if((keyboard_buffer.keyboard_leds&(1<<i))==(1<<i)){ digitalWrite(ledPins[i],HIGH);}
		else{ digitalWrite(ledPins[i],LOW);}
	}
	if(delayval>=Maxdelay){
		if((keyboard_buffer.keyboard_leds&(1<<2))==(1<<2)){
			for(uint8_t i=0;i<WS2812_COUNT;i++){
				uint8_t r=pgm_read_byte(Rcolors+cindex[i]);
				uint8_t g=pgm_read_byte(Gcolors+cindex[i]);
				uint8_t b=pgm_read_byte(Bcolors+cindex[i]);
				WS2812SetRGB(i,r,g,b);
				cindex[i]++;
				if(cindex[i]>=WS2812ColorCount) cindex[i]=0;
			}
			}else{
			WS2812Clear();
		}
		delayval--;
		WS2812Send();
		}else{
		if(delayval){delayval--;}
		else {delayval=Maxdelay;}
	}
}
/////////////////////////////////////////////////////////////////////
uint8_t r,c;
uint8_t delay_after=0;
uint8_t delay_before=0;
void BfaceMod(){
	FN=0xF0;
	for (r = 0; r < ROWS; r++) {
		matrix_set_row_status(r);
		_delay_us(5);
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
	if(delay_after==_delay_after && delay_before==1){usb_keyboard_send();usb_mouse_send();}
	if(delay_after==1){usb_keyboard_send();usb_mouse_send();}
	if(delay_after>0)delay_after--;
	if(delay_before>0)delay_before--;
}
int init_main(void) {
	usb_init();
	////////////////////////////////////////////////
	init_cols();
	init_rows();
	while (1) {
		init_LED();
		keyboard_buffer.enable_pressing=1;
		releaseAllkeyboardkeys();
		releaseAllmousekeys();
		ResetMatrixFormEEP();
		_delay_ms(500);
		usb_keyboard_send();
		while (1) {
			usb_update();
			if(keyboard_buffer.enable_pressing==2){
				break;
			}
			else if(keyboard_buffer.enable_pressing==1){
				if (usbConfiguration && usbInterruptIsReady())BfaceMod();
				//LED();
			}
		}
	}
	return 0;
}
#endif