#include "usbdevice.h"
#ifdef MOUSE_ENABLE

#define MBUF_SIZE 8
static report_mouse_t mbuf[MBUF_SIZE];
static uint8_t mbuf_head = 0;
static uint8_t mbuf_tail = 0;
static void vusb_transfer_mouse()
{
	//因为interrupt in只有两个，所以consumer和mouse定义在同一endpoint通道，所以不可能同时发送。
	if (usbInterruptIsReady3()) {
		if (mbuf_head != mbuf_tail) {
			if(mbuf[mbuf_tail].send_required==REPORT_ID_MOUSE){
				report_mouse0_t temp1=mbuf[mbuf_tail].mouse;
				usbSetInterrupt3((void*)&temp1, sizeof(report_mouse0_t));
			}
			else if(mbuf[mbuf_tail].send_required==REPORT_ID_SYSTEM){
				report_extra_t temp2=mbuf[mbuf_tail].system_keys;
				usbSetInterrupt3((void*)&temp2, sizeof(report_extra_t));
			}
			else if(mbuf[mbuf_tail].send_required==REPORT_ID_CONSUMER){
				report_extra_t temp3=mbuf[mbuf_tail].consumer_keys;
				usbSetInterrupt3((void*)&temp3, sizeof(report_extra_t));
			}
			mbuf_tail = (mbuf_tail + 1) % MBUF_SIZE;
		}
	}
}
static void send_mouse(report_mouse_t *report){
	
	uint8_t next = (mbuf_head + 1) % MBUF_SIZE;
	if (next != mbuf_tail) {
		mbuf[mbuf_head] = *report;
		mbuf_head = next;
	}
	usbPoll();
	vusb_transfer_mouse();
}
void pressmousekey(uint8_t key){
	mouse_buffer.mouse_keys|=key;
}
void releasemousekey(uint8_t key){
	mouse_buffer.mouse_keys&=~key;
}
void releaseAllmousekey(){
	mouse_buffer.mouse_keys=0x00;
}
#endif
uint8_t usb_raw_send(){
	uint8_t send_required=0;
	usbPoll();
	while (1){
		if(usbConfiguration && usbInterruptIsReady3()) {
			usbSetInterrupt3((void *)&raw_report_in, RAW_EPSIZE);
			send_required=1;
			break;
		}
		usbPoll();
	}
	return send_required;
}
uint8_t usb_mouse_send(){
	uint8_t send_required=0;
	usbPoll();
	#ifdef MOUSE_ENABLE
	if (usbConfiguration && usbInterruptIsReady3()) {
		send_required=0;
		if(mouse_report.mouse.buttons!=mouse_buffer.mouse_keys)
		{
			mouse_report.mouse.buttons=mouse_buffer.mouse_keys;
			send_required=REPORT_ID_MOUSE;
		}
		if(mouse_report.system_keys.usage!=mouse_buffer.system_keys)
		{
			mouse_report.system_keys.usage=mouse_buffer.system_keys;
			send_required=REPORT_ID_SYSTEM;
		}
		if(mouse_report.consumer_keys.usage!=mouse_buffer.consumer_keys)
		{
			mouse_report.consumer_keys.usage=mouse_buffer.consumer_keys;
			send_required=REPORT_ID_CONSUMER;
		}
		//mouse
		if(send_required!=0){
			mouse_report.send_required=send_required;
			send_mouse(&mouse_report);
			}else{usbPoll(); vusb_transfer_mouse();}
		}
		#endif
		return send_required;
}
