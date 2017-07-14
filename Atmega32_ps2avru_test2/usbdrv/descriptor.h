#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include <avr/pgmspace.h>
#include "report.h"
#include "../device/usbconfig.h"

////////////////////////////设置
#define FIXED_CONTROL_ENDPOINT_SIZE      8
#define FIXED_NUM_CONFIGURATIONS         1
#define RAW_ENABLE 1
#define MOUSE_ENABLE 1
//包的大小//usb1.1低速不大于8个字节
#define KEYBOARD_EPSIZE             8
#define MOUSE_EPSIZE                8
#define RAW_EPSIZE              	8
#define CONSOLE_EPSIZE              8
typedef struct
{
	uint8_t Size;
	uint8_t Type;
} __attribute__((packed)) USB_Descriptor_Header_t;
typedef struct
{
	USB_Descriptor_Header_t Header; // Descriptor header, including type and size.
	uint16_t USBSpecification; // BCD of the supported USB specification.
	uint8_t  Class;            //USB device class.
	uint8_t  SubClass;         //USB device subclass.
	uint8_t  Protocol;         // USB device protocol.
	uint8_t  Endpoint0Size; // Size of the control (address 0) endpoint's bank in bytes.
	uint16_t VendorID; // Vendor ID for the USB product.
	uint16_t ProductID; // Unique product ID for the USB product.
	uint16_t ReleaseNumber; // Product release (version) number.
	uint8_t  ManufacturerStrIndex; // String index for the manufacturer's name. The
	uint8_t  ProductStrIndex; // String index for the product name/details.
	uint8_t  SerialNumStrIndex; // String index for the product's globally unique hexadecimal
	uint8_t  NumberOfConfigurations; // Total number of configurations supported by
}__attribute__((packed)) USB_Descriptor_Device_t;
typedef struct
{
	USB_Descriptor_Header_t Header;
	uint16_t TotalConfigurationSize;
	uint8_t  TotalInterfaces;
	uint8_t  ConfigurationNumber;
	uint8_t  ConfigurationStrIndex;
	uint8_t  ConfigAttributes;
	uint8_t  MaxPowerConsumption;
} __attribute__((packed)) USB_Descriptor_Configuration_Header_t;
typedef struct
{
	USB_Descriptor_Header_t Header;
	uint8_t InterfaceNumber;
	uint8_t AlternateSetting;
	uint8_t TotalEndpoints;
	uint8_t Class;
	uint8_t SubClass;
	uint8_t Protocol;
	uint8_t InterfaceStrIndex;
} __attribute__((packed)) USB_Descriptor_Interface_t;
typedef struct
{
	USB_Descriptor_Header_t Header;
	uint16_t                HIDSpec;
	uint8_t                 CountryCode;
	uint8_t                 TotalReportDescriptors;
	uint8_t                 HIDReportType;
	uint16_t                HIDReportLength;
} __attribute__((packed)) USB_HID_Descriptor_HID_t;
typedef struct
{
	USB_Descriptor_Header_t Header;
	uint8_t  EndpointAddress;
	uint8_t  Attributes;
	uint16_t EndpointSize;
	uint8_t  PollingIntervalMS;
} __attribute__((packed)) USB_Descriptor_Endpoint_t;
typedef struct
{
	USB_Descriptor_Configuration_Header_t Config;
	// Keyboard HID Interface
	USB_Descriptor_Interface_t            Keyboard_Interface;
	USB_HID_Descriptor_HID_t              Keyboard_HID;
	USB_Descriptor_Endpoint_t             Keyboard_INEndpoint;
	#ifdef MOUSE_ENABLE
	// Mouse HID Interface
	USB_Descriptor_Interface_t            Mouse_Interface;
	USB_HID_Descriptor_HID_t              Mouse_HID;
	USB_Descriptor_Endpoint_t             Mouse_INEndpoint;
	#endif
	#ifdef RAW_ENABLE// Raw HID Interface
	USB_Descriptor_Interface_t            Raw_Interface;
	USB_HID_Descriptor_HID_t              Raw_HID;
	USB_Descriptor_Endpoint_t             Raw_INEndpoint;
	USB_Descriptor_Endpoint_t             Raw_OUTEndpoint;
	#endif
	#ifdef CONSOLE_ENABLE// Console HID Interface
	USB_Descriptor_Interface_t            Console_Interface;
	USB_HID_Descriptor_HID_t              Console_HID;
	USB_Descriptor_Endpoint_t             Console_INEndpoint;
	USB_Descriptor_Endpoint_t             Console_OUTEndpoint;
	#endif
} USB_Descriptor_Configuration_t;

//接口序号
#define KEYBOARD_INTERFACE          0
#ifdef MOUSE_ENABLE
#   define MOUSE_INTERFACE          (KEYBOARD_INTERFACE + 1)
#else
#   define MOUSE_INTERFACE          KEYBOARD_INTERFACE
#endif
#ifdef RAW_ENABLE
#   define RAW_INTERFACE        	(MOUSE_INTERFACE + 1)
#else
#   define RAW_INTERFACE        	MOUSE_INTERFACE
#endif
#ifdef CONSOLE_ENABLE
#   define CONSOLE_INTERFACE        (RAW_INTERFACE + 1)
#else
#   define CONSOLE_INTERFACE        RAW_INTERFACE
#endif
#define TOTAL_INTERFACES            (CONSOLE_INTERFACE + 1)

//端点序号
#define KEYBOARD_IN_EPNUM           1
#ifdef MOUSE_ENABLE
#   define MOUSE_IN_EPNUM           (KEYBOARD_IN_EPNUM + 1)
#else
#   define MOUSE_IN_EPNUM           KEYBOARD_IN_EPNUM
#endif
#ifdef RAW_ENABLE
#   define RAW_IN_EPNUM         (MOUSE_IN_EPNUM + 1)
#   define RAW_OUT_EPNUM        (MOUSE_IN_EPNUM + 2)
#else
#   define RAW_OUT_EPNUM        MOUSE_IN_EPNUM
#endif
#ifdef CONSOLE_ENABLE
#   define CONSOLE_IN_EPNUM         (RAW_OUT_EPNUM + 1)
#   define CONSOLE_OUT_EPNUM        (RAW_OUT_EPNUM + 1)
#else
#   define CONSOLE_OUT_EPNUM        RAW_OUT_EPNUM
#endif

#define REPORT_ID_MOUSE     1
#define REPORT_ID_SYSTEM    2
#define REPORT_ID_CONSUMER  3
//增加额外的自动以interrupt in debug用
#define REPORT_ID_VENDOR  4

extern const PROGMEM uint8_t KeyboardReport[];
extern const PROGMEM uint8_t MouseReport[];
extern const PROGMEM uint8_t  RawReport[];
extern const PROGMEM uint8_t  ConsoleReport[];
extern const PROGMEM USB_Descriptor_Device_t  DeviceDescriptor;
extern const PROGMEM USB_Descriptor_Configuration_t  ConfigurationDescriptor;

uint8_t lengthofKeyboardReport(void);
uint8_t lengthofRawReport(void);
uint8_t lengthofConsoleReport(void);
uint8_t lengthofMouseReport(void);
#endif