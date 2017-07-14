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

#endif /* FUNCTIONS_H_ */