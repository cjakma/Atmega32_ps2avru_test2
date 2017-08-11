#include "descriptor.h"
#include "usbdrv.h"
/*******************************************************************************
* HID Report Descriptors
******************************************************************************/
const PROGMEM uint8_t  KeyboardReport[] =
{
	0x05, 0x01,          // Usage Page (Generic Desktop),
	0x09, 0x06,          // Usage (Keyboard),
	0xA1, 0x01,          // Collection (Application),
	0x75, 0x01,          //   Report Size (1),
	0x95, 0x08,          //   Report Count (8),
	0x05, 0x07,          //   Usage Page (Key Codes),
	0x19, 0xE0,          //   Usage Minimum (224),
	0x29, 0xE7,          //   Usage Maximum (231),
	0x15, 0x00,          //   Logical Minimum (0),
	0x25, 0x01,          //   Logical Maximum (1),
	0x81, 0x02,          //   Input (Data, Variable, Absolute), ;Modifier byte
	0x95, 0x01,          //   Report Count (1),
	0x75, 0x08,          //   Report Size (8),
	0x81, 0x03,          //   Input (Constant),                 ;Reserved byte
	0x95, 0x05,          //   Report Count (5),
	0x75, 0x01,          //   Report Size (1),
	0x05, 0x08,          //   Usage Page (LEDs),
	0x19, 0x01,          //   Usage Minimum (1),
	0x29, 0x05,          //   Usage Maximum (5),
	0x91, 0x02,          //   Output (Data, Variable, Absolute), ;LED report
	0x95, 0x01,          //   Report Count (1),
	0x75, 0x03,          //   Report Size (3),
	0x91, 0x03,          //   Output (Constant),                 ;LED report padding
	0x95, 0x06,          //   Report Count (6),
	0x75, 0x08,          //   Report Size (8),
	0x15, 0x00,          //   Logical Minimum (0),
	0x26, 0xFF, 0x00,    //   Logical Maximum(255),
	0x05, 0x07,          //   Usage Page (Key Codes),
	0x19, 0x00,          //   Usage Minimum (0),
	0x29, 0xFF,          //   Usage Maximum (255),
	0x81, 0x00,          //   Input (Data, Array),
	0xc0                 // End Collection
};
const  PROGMEM  uint8_t MouseReport[] =
{
	/* mouse */
	0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
	0x09, 0x02,                    // USAGE (Mouse)
	0xa1, 0x01,                    // COLLECTION (Application)
	0x85, REPORT_ID_MOUSE,         //   REPORT_ID (1)
	0x09, 0x01,                    //   USAGE (Pointer)
	0xa1, 0x00,                    //   COLLECTION (Physical)
	// ----------------------------  Buttons
	0x05, 0x09,                    //     USAGE_PAGE (Button)
	0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
	0x29, 0x05,                    //     USAGE_MAXIMUM (Button 5)
	0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
	0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
	0x75, 0x01,                    //     REPORT_SIZE (1)
	0x95, 0x05,                    //     REPORT_COUNT (5)
	0x81, 0x02,                    //     INPUT (Data,Var,Abs)
	0x75, 0x03,                    //     REPORT_SIZE (3)
	0x95, 0x01,                    //     REPORT_COUNT (1)
	0x81, 0x03,                    //     INPUT (Cnst,Var,Abs)
	// ----------------------------  X,Y position
	0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)
	0x09, 0x30,                    //     USAGE (X)
	0x09, 0x31,                    //     USAGE (Y)
	0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
	0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
	0x75, 0x08,                    //     REPORT_SIZE (8)
	0x95, 0x02,                    //     REPORT_COUNT (2)
	0x81, 0x06,                    //     INPUT (Data,Var,Rel)
	// ----------------------------  Vertical wheel
	0x09, 0x38,                    //     USAGE (Wheel)
	0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
	0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
	0x35, 0x00,                    //     PHYSICAL_MINIMUM (0)        - reset physical
	0x45, 0x00,                    //     PHYSICAL_MAXIMUM (0)
	0x75, 0x08,                    //     REPORT_SIZE (8)
	0x95, 0x01,                    //     REPORT_COUNT (1)
	0x81, 0x06,                    //     INPUT (Data,Var,Rel)
	// ----------------------------  Horizontal wheel
	0x05, 0x0c,                    //     USAGE_PAGE (Consumer Devices)
	0x0a, 0x38, 0x02,              //     USAGE (AC Pan)
	0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
	0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
	0x75, 0x08,                    //     REPORT_SIZE (8)
	0x95, 0x01,                    //     REPORT_COUNT (1)
	0x81, 0x06,                    //     INPUT (Data,Var,Rel)
	0xc0,                          //   END_COLLECTION
	0xc0,                          // END_COLLECTION
	/* system control */
	0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
	0x09, 0x80,                    // USAGE (System Control)
	0xa1, 0x01,                    // COLLECTION (Application)
	0x85, REPORT_ID_SYSTEM,        //   REPORT_ID (2)
	0x15, 0x01,                    //   LOGICAL_MINIMUM (0x1)
	0x26, 0xb7, 0x00,              //   LOGICAL_MAXIMUM (0xb7)
	0x19, 0x01,                    //   USAGE_MINIMUM (0x1)
	0x29, 0xb7,                    //   USAGE_MAXIMUM (0xb7)
	0x75, 0x10,                    //   REPORT_SIZE (16)
	0x95, 0x01,                    //   REPORT_COUNT (1)
	0x81, 0x00,                    //   INPUT (Data,Array,Abs)
	0xc0,                          // END_COLLECTION
	/* consumer */
	0x05, 0x0c,                    // USAGE_PAGE (Consumer Devices)
	0x09, 0x01,                    // USAGE (Consumer Control)
	0xa1, 0x01,                    // COLLECTION (Application)
	0x85, REPORT_ID_CONSUMER,      //   REPORT_ID (3)
	0x15, 0x01,                    //   LOGICAL_MINIMUM (0x1)
	0x26, 0x9c, 0x02,              //   LOGICAL_MAXIMUM (0x29c)
	0x19, 0x01,                    //   USAGE_MINIMUM (0x1)
	0x2a, 0x9c, 0x02,              //   USAGE_MAXIMUM (0x29c)
	0x75, 0x10,                    //   REPORT_SIZE (16)
	0x95, 0x01,                    //   REPORT_COUNT (1)
	0x81, 0x00,                    //   INPUT (Data,Array,Abs)
	0xc0                        // END_COLLECTION
};
const PROGMEM uint8_t  RawReport[] =
{
	0x06, 0x31 ,0xFF,//Usage Page (Vendor-Defined 50 31FF)
	0x09 ,0x74,//Usage (Vendor-Defined 116)
	0xA1, 0x01,//Collection (Application)
	0x09 ,0x75,//Usage (Vendor-Defined 117)
	0x15 ,0x00,//Logical Minimum (0)
	0x26, 0xFF ,0x00,//Logical Maximum (255 FF00)
	0x95 ,RAW_EPSIZE ,//Report Count (8)
	0x75 ,0x08 ,//Report Size (8)
	0x81 ,0x02 ,//Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
	0x09 ,0x76 ,//Usage (Vendor-Defined 118)
	0x15, 0x00 ,//Logical Minimum (0)
	0x26 ,0xFF ,0x00 ,//Logical Maximum (255)
	0x95 ,RAW_EPSIZE , //Report Count (8)
	0x75 ,0x08 ,//Report Size (8)
	0x91 ,0x02, //Output (Data,Var,Abs,NWrp,Lin,Pref,NNul,NVol,Bit)
	0xC0 //End Collection
};
/*******************************************************************************
* Device Descriptors
******************************************************************************/
const PROGMEM uint8_t  DeviceDescriptor[] =
{
	0x12,
	0x01,
	0x10,0x01,//USB Version 0x0110
	0x00,
	0x00,
	0x00,
	MAX_EPSIZE,
	USB_CFG_VENDOR_ID,
	USB_CFG_DEVICE_ID,
	USB_CFG_DEVICE_VERSION,
	0x01,
	0x02,
	0x00,
	0x01
};
/*******************************************************************************
* Configuration Descriptors
******************************************************************************/
#define CONFIG1_DESC_SIZE        (9+9+9+7+9+9+7+9+9+7+7)
#define KEYBOARD_HID_DESC_OFFSET (9+9)
#define MOUSE_HID_DESC_OFFSET    (9+9+9+7+9)
#define RAW_HID_DESC_OFFSET      (9+9+9+7+9+9+7+9)
const PROGMEM uint8_t  ConfigurationDescriptor[] =
{
	9,
	0x02,
	CONFIG1_DESC_SIZE,0x00, //9+(9+9+7)+(9+9+7+7)
	0x03,          /* number of interfaces in this configuration */
	1,          /* index of this configuration */
	0,          /* configuration name string index */
	0xA0,
	0xFA, /* max USB current in 2mA units */
	//Interface Descriptor 0/0 HID, 1 Endpoint
	9,          /* sizeof(usbDescrInterface): length of descriptor in bytes */
	0x04, /* descriptor type */
	KEYBOARD_INTERFACE,          /* index of this interface */
	0,          /* alternate setting for this interface */
	0x01,
	0x03,
	0x01,
	0x01,
	0,          /* string index for interface */
	//HID descriptor
	9,          /* sizeof(usbDescrHID): length of descriptor in bytes */
	0x21,   /* descriptor type: HID */
	0x01, 0x01, /* BCD representation of HID version */
	0x00,       /* target country code */
	0x01,       /* number of HID Report (or other HID class) Descriptor infos to follow */
	0x22,       /* descriptor type: report */
	sizeof(KeyboardReport), 0x00,  /* total length of report descriptor */
	//endpoint descriptor for endpoint 1
	0x07,          /* sizeof(usbDescrEndpoint) */
	0x05,  /* descriptor type = endpoint */
	0x80+KEYBOARD_ENDPOINT, /* IN endpoint number 1 */
	0x03,       /* attrib: Interrupt endpoint */
	KEYBOARD_EPSIZE,0x00,       /* maximum packet size */
	0x0A, /* in ms */
	
	//Interface Descriptor 1/0 HID, 1 Endpoints
	0x09,
	0x04,  //interface
	MOUSE_INTERFACE,  //interface number
	0x00,
	0x01,
	0x03, //hid
	0x01, //boot interface
	0x02, //mouse
	0x00,
	//HID descriptor
	0x09,
	0x21,
	0x11, 0x01,
	0x00,
	0x01,
	0x22,
	sizeof(MouseReport),0x00,
	//endpoint descriptor for endpoint 4
	0x07,          /* sizeof(usbDescrEndpoint) */
	0x05,  /* descriptor type = endpoint */
	0x80+MOUSE_ENDPOINT, /* IN endpoint number 1 */
	0x03,       /* attrib: Interrupt endpoint */
	MOUSE_EPSIZE,0x00,       /* maximum packet size */
	0x0A, /* in ms */
	//Interface Descriptor 1/0 HID, 2 Endpoints
	0x09,
	0x04,
	RAW_INTERFACE, //interface number
	0x00,
	0x02,
	0x03,
	0x00,
	0x00,
	0x00,
	//HID descriptor
	0x09,
	0x21,
	0x11, 0x01,
	0x00,
	0x01,
	0x22,
	sizeof(RawReport),0x00,
	//endpoint descriptor for endpoint 2
	0x07,          /* sizeof(usbDescrEndpoint) */
	0x05,  /* descriptor type = endpoint */
	0x80+RAW_ENDPOINT_IN, /* IN endpoint number 1 */
	0x03,       /* attrib: Interrupt endpoint */
	RAW_EPSIZE,0x00,       /* maximum packet size */
	0x01, /* in ms */
	//endpoint descriptor for endpoint 3
	0x07,          /* sizeof(usbDescrEndpoint) */
	0x05,  /* descriptor type = endpoint */
	RAW_ENDPOINT_OUT, /* IN endpoint number 1 */
	0x03,       /* attrib: Interrupt endpoint */
	RAW_EPSIZE,0x00,       /* maximum packet size */
	0x01 /* in ms */

};
USB_PUBLIC usbMsgLen_t usbFunctionDescriptor(struct usbRequest *rq)
{
	usbMsgLen_t len = 0;
	switch (rq->wValue.bytes[1]) {
		case USBDESCR_DEVICE:
		usbMsgPtr =(uchar *)&DeviceDescriptor;
		len    = sizeof(DeviceDescriptor);
		break;
		case USBDESCR_CONFIG:
		//DescriptorType=2
		usbMsgPtr = (uchar *)&ConfigurationDescriptor;
		len    = sizeof(ConfigurationDescriptor);
		break;
		case USBDESCR_HID:
		//DescriptorType=0x21
		switch (rq->wValue.bytes[0]) {
			case KEYBOARD_INTERFACE:
			usbMsgPtr = (uchar *)(ConfigurationDescriptor+KEYBOARD_HID_DESC_OFFSET);
			len = 9;
			break;
			case MOUSE_INTERFACE:
			usbMsgPtr =(uchar *)(ConfigurationDescriptor+MOUSE_HID_DESC_OFFSET);
			len    =9;
			break;			
			case RAW_INTERFACE:
			usbMsgPtr =(uchar *)( ConfigurationDescriptor+RAW_HID_DESC_OFFSET);
			len    = 9;
			break;		
		}
		break;
		case USBDESCR_HID_REPORT:
		//DescriptorType=0x22
		switch (rq->wIndex.word) {
			case KEYBOARD_INTERFACE:
			usbMsgPtr = (uchar *)&KeyboardReport;
			len    = sizeof(KeyboardReport);
			break;
			case MOUSE_INTERFACE:
			usbMsgPtr = (uchar *) &MouseReport;
			len    = sizeof(MouseReport);
			break;		
			case RAW_INTERFACE:
			usbMsgPtr = (uchar *)&RawReport;
			len    = sizeof(RawReport);
			break;		
		}
		break;
	}
	return len;
}
//未使用部分
#if USB_CFG_DESCR_PROPS_CONFIGURATION
const PROGMEM char usbDescriptorConfiguration[] ={};
#endif
#if USB_CFG_DESCR_PROPS_DEVICE
const PROGMEM char usbDescriptorDevice[]={};
#endif