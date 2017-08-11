#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include <avr/pgmspace.h>
#include "usbconfig.h"

//包的大小//usb1.1低速不大于8个字节
#define MAX_EPSIZE                  8
#define KEYBOARD_EPSIZE             8
#define MOUSE_EPSIZE                8
#define RAW_EPSIZE              	MAX_EPSIZE

//接口序号
#define KEYBOARD_INTERFACE      0
#define MOUSE_INTERFACE         1
#define RAW_INTERFACE        	2
#define TOTAL_INTERFACES        3

//端点序号
#define KEYBOARD_ENDPOINT        1
#define MOUSE_ENDPOINT           2
#define RAW_ENDPOINT_IN          3
#define RAW_ENDPOINT_OUT         4

#define REPORT_ID_MOUSE     1
#define REPORT_ID_SYSTEM    2
#define REPORT_ID_CONSUMER  3
//增加额外的自动以interrupt in debug用
#define REPORT_ID_VENDOR  4

extern const PROGMEM uint8_t KeyboardReport[];
extern const PROGMEM uint8_t MouseReport[];
extern const PROGMEM uint8_t  RawReport[];
extern const PROGMEM uint8_t  ConsoleReport[];
extern const PROGMEM uint8_t  DeviceDescriptor[];
extern const PROGMEM uint8_t  ConfigurationDescriptor[];

#endif