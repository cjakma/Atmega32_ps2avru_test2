#include "usbdevice.h"

#define KBUF_SIZE 8
static report_keyboard_t kbuf[KBUF_SIZE];
static uint8_t kbuf_head = 0;
static uint8_t kbuf_tail = 0;

static void vusb_transfer_keyboard()
{
	if (usbInterruptIsReady()) {
		if (kbuf_head != kbuf_tail) {
			usbSetInterrupt((void *)&kbuf[kbuf_tail], sizeof(report_keyboard_t));
			kbuf_tail = (kbuf_tail + 1) % KBUF_SIZE;
		}
	}
}
static void send_keyboard(report_keyboard_t *report){
	uint8_t next = (kbuf_head + 1) % KBUF_SIZE;
	if (next != kbuf_tail) {
		kbuf[kbuf_head] = *report;
		kbuf_head = next;
	}
	usbPoll();
	vusb_transfer_keyboard();
}
uint8_t usb_keyboard_send(){
	uint8_t send_required=0;
	usbPoll();
	if (usbConfiguration && usbInterruptIsReady()) {
		send_required=0;
		if(keyboard_report.modifier!=keyboard_buffer.keyboard_modifier_keys){keyboard_report.modifier = keyboard_buffer.keyboard_modifier_keys;send_required=1;}
		if(keyboard_report.keycode[0]!=keyboard_buffer.keyboard_keys[0]){keyboard_report.keycode[0]=keyboard_buffer.keyboard_keys[0];send_required=1;}
		if(keyboard_report.keycode[1]!=keyboard_buffer.keyboard_keys[1]){keyboard_report.keycode[1]=keyboard_buffer.keyboard_keys[1];send_required=1;}
		if(keyboard_report.keycode[2]!=keyboard_buffer.keyboard_keys[2]){keyboard_report.keycode[2]=keyboard_buffer.keyboard_keys[2];send_required=1;}
		if(keyboard_report.keycode[3]!=keyboard_buffer.keyboard_keys[3]){keyboard_report.keycode[3]=keyboard_buffer.keyboard_keys[3];send_required=1;}
		if(keyboard_report.keycode[4]!=keyboard_buffer.keyboard_keys[4]){keyboard_report.keycode[4]=keyboard_buffer.keyboard_keys[4];send_required=1;}
		if(keyboard_report.keycode[5]!=keyboard_buffer.keyboard_keys[5]){keyboard_report.keycode[5]=keyboard_buffer.keyboard_keys[5];send_required=1;}
		if(send_required==1){send_keyboard(&keyboard_report);}
		else{usbPoll(); vusb_transfer_keyboard();}
	}
	return send_required;
}
///////////////////////////////////////////////////////////////////////
uint8_t releasekey(uint8_t key)
{
	uint8_t i;
	uint8_t send_required=0;
	for ( i=0; i < 6; i++) {
		if (keyboard_buffer.keyboard_keys[i] == key) {
			keyboard_buffer.keyboard_keys[i] = 0;
			send_required=1;
			break;
		}
	}
	return send_required;
}
void releaseAll()
{
	uint8_t i;
	for ( i=0; i < 6; i++) {
		keyboard_buffer.keyboard_keys[i] = 0;
	}
	keyboard_buffer.keyboard_modifier_keys=0;
}
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
void releaseModifierKeys(uint8_t key)
{
	keyboard_buffer.keyboard_modifier_keys&=~key;
}
