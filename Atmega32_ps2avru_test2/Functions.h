/*
 * Functions.h
 *
 * Created: 2017/5/2 22:26:44
 *  Author: Administrator
 */ 
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <avr/io.h>
#include "usbdevice.h"

#define LOW 0
#define HIGH 1
#define INPUT 0
#define OUTPUT 1
#define LSB(n) (n & 255)
#define MSB(n) ((n >> 8) & 255)

void pinMode(uint8_t IO,uint8_t value);
void digitalWrite(uint8_t IO,uint8_t value);
uint8_t digitalRead(uint8_t IO);
void usb_update();
uint8_t usb_keyboard_send();
uint8_t usb_mouse_send();
uint8_t usb_keyboard_send_required();
uint8_t usb_mouse_send_required();

void pressModifierKeys(uint8_t key);
uint8_t presskey(uint8_t key);
void pressmousekey(uint8_t key);
void presssystemkey(uint8_t key);
void pressconsumerkey(uint8_t key);
void releaseAllmousekeys();
void releaseAllkeyboardkeys();

#define ROWS  8
#define COLS  10
#define _delay_after 0x09
#define _delay_before 0x03

#endif /* FUNCTIONS_H_ */