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
const PROGMEM uint8_t  ConsoleReport[] =
{
	HID_RI_USAGE_PAGE(16, 0xFF31), /* Vendor Page(PJRC Teensy compatible) */
	HID_RI_USAGE(8, 0x74), /* Vendor Usage(PJRC Teensy compatible) */
	HID_RI_COLLECTION(8, 0x01), /* Application */
	HID_RI_USAGE(8, 0x75), /* Vendor Usage 0x75 */
	HID_RI_LOGICAL_MINIMUM(8, 0x00),
	HID_RI_LOGICAL_MAXIMUM(16, 0x00FF),
	HID_RI_REPORT_COUNT(8, CONSOLE_EPSIZE),
	HID_RI_REPORT_SIZE(8, 0x08),
	HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),
	HID_RI_USAGE(8, 0x76), /* Vendor Usage 0x76 */
	HID_RI_LOGICAL_MINIMUM(8, 0x00),
	HID_RI_LOGICAL_MAXIMUM(16, 0x00FF),
	HID_RI_REPORT_COUNT(8, CONSOLE_EPSIZE),
	HID_RI_REPORT_SIZE(8, 0x08),
	HID_RI_OUTPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE | HID_IOF_NON_VOLATILE),
	HID_RI_END_COLLECTION(0)
};

uint8_t lengthofKeyboardReport(){
	return sizeof(KeyboardReport);
}
uint8_t lengthofRawReport(){
	return sizeof(RawReport);
}
uint8_t lengthofConsoleReport(){
	return sizeof(ConsoleReport);
}
uint8_t lengthofMouseReport(){
	return sizeof(MouseReport);
}
/*******************************************************************************
* Device Descriptors
******************************************************************************/
const PROGMEM USB_Descriptor_Device_t  DeviceDescriptor =
{
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

	.USBSpecification       = VERSION_BCD(1,1,0), //0x0110
	.Class                  = USB_CSCP_NoDeviceClass,
	.SubClass               = USB_CSCP_NoDeviceSubclass,
	.Protocol               = USB_CSCP_NoDeviceProtocol,

	.Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

	/* specified in config.h */
	.VendorID               = VENDOR_ID,
	.ProductID              = PRODUCT_ID,
	.ReleaseNumber          = DEVICE_VER,//0x0100

	.ManufacturerStrIndex   = 0x01,
	.ProductStrIndex        = 0x02,
	.SerialNumStrIndex      = NO_DESCRIPTOR,

	.NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS //0x01
};
/*******************************************************************************
* Configuration Descriptors
******************************************************************************/
const PROGMEM USB_Descriptor_Configuration_t  ConfigurationDescriptor =
{
	.Config =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},
		.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
		.TotalInterfaces        = TOTAL_INTERFACES,
		.ConfigurationNumber    = 1,
		.ConfigurationStrIndex  = NO_DESCRIPTOR,
		.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_REMOTEWAKEUP),
		.MaxPowerConsumption    = USB_CONFIG_POWER_MA(USB_CFG_MAX_BUS_POWER)
	},
	.Keyboard_Interface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},
		.InterfaceNumber        = KEYBOARD_INTERFACE,
		.AlternateSetting       = 0x00,
		.TotalEndpoints         = 1,
		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_BootSubclass,
		.Protocol               = HID_CSCP_KeyboardBootProtocol,
		.InterfaceStrIndex      = NO_DESCRIPTOR
	},
	.Keyboard_HID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},
		.HIDSpec                = VERSION_BCD(1,1,1),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(KeyboardReport)
	},
	.Keyboard_INEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = (ENDPOINT_DIR_IN | KEYBOARD_IN_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = KEYBOARD_EPSIZE,
		.PollingIntervalMS      = USB_CFG_INTR_POLL_INTERVAL
	},
	#ifdef MOUSE_ENABLE
	.Mouse_Interface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},
		.InterfaceNumber        = MOUSE_INTERFACE,
		.AlternateSetting       = 0x00,
		.TotalEndpoints         = 1,
		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_BootSubclass,
		.Protocol               = HID_CSCP_MouseBootProtocol,
		.InterfaceStrIndex      = NO_DESCRIPTOR
	},

	.Mouse_HID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},
		.HIDSpec                = VERSION_BCD(1,1,1),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(MouseReport)
	},

	.Mouse_INEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = (ENDPOINT_DIR_IN | MOUSE_IN_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = MOUSE_EPSIZE,
		.PollingIntervalMS      = USB_CFG_INTR_POLL_INTERVAL
	},
	#endif

	#ifdef RAW_ENABLE
	.Raw_Interface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},
		.InterfaceNumber        = RAW_INTERFACE,
		.AlternateSetting       = 0x00,
		.TotalEndpoints         = 2,
		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_NonBootSubclass,
		.Protocol               = HID_CSCP_NonBootProtocol,
		.InterfaceStrIndex      = NO_DESCRIPTOR
	},

	.Raw_HID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},
		.HIDSpec                = VERSION_BCD(1,1,1),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(RawReport)
	},

	.Raw_INEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = (ENDPOINT_DIR_IN | RAW_IN_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = RAW_EPSIZE,
		.PollingIntervalMS      = 0x01
	},

	.Raw_OUTEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = (ENDPOINT_DIR_OUT | RAW_OUT_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = RAW_EPSIZE,
		.PollingIntervalMS      = 0x01
	},
	#endif
	#ifdef CONSOLE_ENABLE
	.Console_Interface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},
		.InterfaceNumber        = CONSOLE_INTERFACE,
		.AlternateSetting       = 0x00,
		.TotalEndpoints         = 2,
		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_NonBootSubclass,
		.Protocol               = HID_CSCP_NonBootProtocol,
		.InterfaceStrIndex      = NO_DESCRIPTOR
	},
	.Console_HID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},
		.HIDSpec                = VERSION_BCD(1,1,1),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(ConsoleReport)
	},
	.Console_INEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = (ENDPOINT_DIR_IN | CONSOLE_IN_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = CONSOLE_EPSIZE,
		.PollingIntervalMS      = 0x01
	},
	.Console_OUTEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = (ENDPOINT_DIR_OUT | CONSOLE_OUT_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = CONSOLE_EPSIZE,
		.PollingIntervalMS      = 0x01
	},
	#endif
};
USB_PUBLIC usbMsgLen_t usbFunctionDescriptor(struct usbRequest *rq)
{
	usbMsgLen_t len = 0;
	switch (rq->wValue.bytes[1]) {
		case USBDESCR_DEVICE:
		usbMsgPtr = (uchar *)&DeviceDescriptor;
		len    = sizeof(USB_Descriptor_Device_t);
		break;
		case USBDESCR_CONFIG:
		//DescriptorType=2
		usbMsgPtr = (uchar *)&ConfigurationDescriptor;
		len    = sizeof(USB_Descriptor_Configuration_t);
		break;
		case USBDESCR_HID:
		//DescriptorType=0x21
		switch (rq->wValue.bytes[0]) {
			case KEYBOARD_INTERFACE:
			usbMsgPtr = (uchar *)&ConfigurationDescriptor.Keyboard_HID;
			len = sizeof(USB_HID_Descriptor_HID_t);
			break;
			#ifdef MOUSE_ENABLE
			case MOUSE_INTERFACE:
			usbMsgPtr =(uchar *) &ConfigurationDescriptor.Mouse_HID;
			len    = sizeof(USB_HID_Descriptor_HID_t);
			break;
			#endif
			#ifdef RAW_ENABLE
			case RAW_INTERFACE:
			usbMsgPtr = (uchar *)&ConfigurationDescriptor.Raw_HID;
			len    = sizeof(USB_HID_Descriptor_HID_t);
			break;
			#endif
			#ifdef CONSOLE_ENABLE
			case CONSOLE_INTERFACE:
			usbMsgPtr = (uchar *)&ConfigurationDescriptor.Console_HID;
			len    = sizeof(USB_HID_Descriptor_HID_t);
			break;
			#endif
		}
		break;
		case USBDESCR_HID_REPORT:
		//DescriptorType=0x22
		switch (rq->wIndex.word) {
			case KEYBOARD_INTERFACE:
			usbMsgPtr = (uchar *)&KeyboardReport;
			len    = sizeof(KeyboardReport);
			break;
			#ifdef MOUSE_ENABLE
			case MOUSE_INTERFACE:
			usbMsgPtr = (uchar *) &MouseReport;
			len    = sizeof(MouseReport);
			break;
			#endif
			#ifdef RAW_ENABLE
			case RAW_INTERFACE:
			usbMsgPtr = (uchar *)&RawReport;
			len    = sizeof(RawReport);
			break;
			#endif
			#ifdef CONSOLE_ENABLE
			case CONSOLE_INTERFACE:
			usbMsgPtr = (uchar *)&ConsoleReport;
			len    = sizeof(ConsoleReport);
			break;
			#endif
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