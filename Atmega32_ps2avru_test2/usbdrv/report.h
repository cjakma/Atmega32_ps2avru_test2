#ifndef REPORT_H_
#define REPORT_H_

#define CONCAT_EXPANDED(x, y)  x ## y

#define HID_RI_DATA_SIZE_MASK                   0x03
#define HID_RI_TYPE_MASK                        0x0C
#define HID_RI_TAG_MASK                         0xF0

#define HID_RI_TYPE_MAIN                        0x00
#define HID_RI_TYPE_GLOBAL                      0x04
#define HID_RI_TYPE_LOCAL                       0x08

#define HID_RI_DATA_BITS_0                      0x00
#define HID_RI_DATA_BITS_8                      0x01
#define HID_RI_DATA_BITS_16                     0x02
#define HID_RI_DATA_BITS_32                     0x03
#define HID_RI_DATA_BITS(DataBits)              CONCAT_EXPANDED(HID_RI_DATA_BITS_, DataBits)

#define _HID_RI_ENCODE_0(Data)
#define _HID_RI_ENCODE_8(Data)                  , (Data & 0xFF)
#define _HID_RI_ENCODE_16(Data)                 _HID_RI_ENCODE_8(Data)  _HID_RI_ENCODE_8(Data >> 8)
#define _HID_RI_ENCODE_32(Data)                 _HID_RI_ENCODE_16(Data) _HID_RI_ENCODE_16(Data >> 16)
#define _HID_RI_ENCODE(DataBits, ...)           CONCAT_EXPANDED(_HID_RI_ENCODE_, DataBits(__VA_ARGS__))

#define _HID_RI_ENTRY(Type, Tag, DataBits, ...) (Type | Tag | HID_RI_DATA_BITS(DataBits)) _HID_RI_ENCODE(DataBits, (__VA_ARGS__))

#define HID_IOF_CONSTANT                        (1 << 0)
#define HID_IOF_DATA                            (0 << 0)
#define HID_IOF_VARIABLE                        (1 << 1)
#define HID_IOF_ARRAY                           (0 << 1)
#define HID_IOF_RELATIVE                        (1 << 2)
#define HID_IOF_ABSOLUTE                        (0 << 2)
#define HID_IOF_WRAP                            (1 << 3)
#define HID_IOF_NO_WRAP                         (0 << 3)
#define HID_IOF_NON_LINEAR                      (1 << 4)
#define HID_IOF_LINEAR                          (0 << 4)
#define HID_IOF_NO_PREFERRED_STATE              (1 << 5)
#define HID_IOF_PREFERRED_STATE                 (0 << 5)
#define HID_IOF_NULLSTATE                       (1 << 6)
#define HID_IOF_NO_NULL_POSITION                (0 << 6)
#define HID_IOF_VOLATILE                        (1 << 7)
#define HID_IOF_NON_VOLATILE                    (0 << 7)
#define HID_IOF_BUFFERED_BYTES                  (1 << 8)
#define HID_IOF_BITFIELD                        (0 << 8)

#define HID_RI_INPUT(DataBits, ...)             _HID_RI_ENTRY(HID_RI_TYPE_MAIN  , 0x80, DataBits, __VA_ARGS__)
#define HID_RI_OUTPUT(DataBits, ...)            _HID_RI_ENTRY(HID_RI_TYPE_MAIN  , 0x90, DataBits, __VA_ARGS__)
#define HID_RI_COLLECTION(DataBits, ...)        _HID_RI_ENTRY(HID_RI_TYPE_MAIN  , 0xA0, DataBits, __VA_ARGS__)
#define HID_RI_FEATURE(DataBits, ...)           _HID_RI_ENTRY(HID_RI_TYPE_MAIN  , 0xB0, DataBits, __VA_ARGS__)
#define HID_RI_END_COLLECTION(DataBits, ...)    _HID_RI_ENTRY(HID_RI_TYPE_MAIN  , 0xC0, DataBits, __VA_ARGS__)
#define HID_RI_USAGE_PAGE(DataBits, ...)        _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x00, DataBits, __VA_ARGS__)
#define HID_RI_LOGICAL_MINIMUM(DataBits, ...)   _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x10, DataBits, __VA_ARGS__)
#define HID_RI_LOGICAL_MAXIMUM(DataBits, ...)   _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x20, DataBits, __VA_ARGS__)
#define HID_RI_PHYSICAL_MINIMUM(DataBits, ...)  _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x30, DataBits, __VA_ARGS__)
#define HID_RI_PHYSICAL_MAXIMUM(DataBits, ...)  _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x40, DataBits, __VA_ARGS__)
#define HID_RI_UNIT_EXPONENT(DataBits, ...)     _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x50, DataBits, __VA_ARGS__)
#define HID_RI_UNIT(DataBits, ...)              _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x60, DataBits, __VA_ARGS__)
#define HID_RI_REPORT_SIZE(DataBits, ...)       _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x70, DataBits, __VA_ARGS__)
#define HID_RI_REPORT_ID(DataBits, ...)         _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x80, DataBits, __VA_ARGS__)
#define HID_RI_REPORT_COUNT(DataBits, ...)      _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0x90, DataBits, __VA_ARGS__)
#define HID_RI_PUSH(DataBits, ...)              _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0xA0, DataBits, __VA_ARGS__)
#define HID_RI_POP(DataBits, ...)               _HID_RI_ENTRY(HID_RI_TYPE_GLOBAL, 0xB0, DataBits, __VA_ARGS__)
#define HID_RI_USAGE(DataBits, ...)             _HID_RI_ENTRY(HID_RI_TYPE_LOCAL , 0x00, DataBits, __VA_ARGS__)
#define HID_RI_USAGE_MINIMUM(DataBits, ...)     _HID_RI_ENTRY(HID_RI_TYPE_LOCAL , 0x10, DataBits, __VA_ARGS__)
#define HID_RI_USAGE_MAXIMUM(DataBits, ...)     _HID_RI_ENTRY(HID_RI_TYPE_LOCAL , 0x20, DataBits, __VA_ARGS__)



enum USB_Descriptor_ClassSubclassProtocol_t
{
	USB_CSCP_NoDeviceClass          = 0x00,
	USB_CSCP_NoDeviceSubclass       = 0x00,
	USB_CSCP_NoDeviceProtocol       = 0x00,
	USB_CSCP_VendorSpecificClass    = 0xFF,
	USB_CSCP_VendorSpecificSubclass = 0xFF,
	USB_CSCP_VendorSpecificProtocol = 0xFF,
	USB_CSCP_IADDeviceClass         = 0xEF,
	USB_CSCP_IADDeviceSubclass      = 0x02,
	USB_CSCP_IADDeviceProtocol      = 0x01,
};
enum USB_DescriptorTypes_t
{
	DTYPE_Device                    = 0x01,
	DTYPE_Configuration             = 0x02,
	DTYPE_String                    = 0x03,
	DTYPE_Interface                 = 0x04,
	DTYPE_Endpoint                  = 0x05,
	DTYPE_DeviceQualifier           = 0x06,
	DTYPE_Other                     = 0x07,
	DTYPE_InterfacePower            = 0x08,
	DTYPE_InterfaceAssociation      = 0x0B,
	DTYPE_CSInterface               = 0x24,
	DTYPE_CSEndpoint                = 0x25,
};
enum HID_Descriptor_ClassSubclassProtocol_t
{
	HID_CSCP_HIDClass             = 0x03,
	HID_CSCP_NonBootSubclass      = 0x00,
	HID_CSCP_BootSubclass         = 0x01,
	HID_CSCP_NonBootProtocol      = 0x00,
	HID_CSCP_KeyboardBootProtocol = 0x01,
	HID_CSCP_MouseBootProtocol    = 0x02,
};
enum HID_DescriptorTypes_t
{
	HID_DTYPE_HID           = 0x21, /**< Descriptor header type value, to indicate a HID class HID descriptor. */
	HID_DTYPE_Report        = 0x22, /**< Descriptor header type value, to indicate a HID class HID report descriptor. */
};
#define NO_DESCRIPTOR 0
#define USB_CONFIG_POWER_MA(mA)           ((mA) >> 1)

#define CPU_TO_LE16(x)  (uint16_t)((((x) & 0xFF00) >> 8) | (((x) & 0x00FF) << 8))
#define VERSION_BCD(Major, Minor, Revision) CPU_TO_LE16( ((Major & 0xFF) << 8) | ((Minor & 0x0F) << 4) | (Revision & 0x0F) )
#define LANGUAGE_ID_ENG                   0x0409
#define USB_CONFIG_ATTR_RESERVED          0x80
#define USB_CONFIG_ATTR_SELFPOWERED       0x40
#define USB_CONFIG_ATTR_REMOTEWAKEUP      0x20
#define ENDPOINT_ATTR_NO_SYNC             (0 << 2)
#define ENDPOINT_ATTR_ASYNC               (1 << 2)
#define ENDPOINT_ATTR_ADAPTIVE            (2 << 2)
#define ENDPOINT_ATTR_SYNC                (3 << 2)
#define ENDPOINT_USAGE_DATA               (0 << 4)
#define ENDPOINT_USAGE_FEEDBACK           (1 << 4)
#define ENDPOINT_USAGE_IMPLICIT_FEEDBACK  (2 << 4)
#define ENDPOINT_DIR_MASK                  0x80
#define ENDPOINT_DIR_OUT                   0x00
#define ENDPOINT_DIR_IN                    0x80
#define PIPE_DIR_MASK                      0x80
#define PIPE_DIR_OUT                       0x00
#define PIPE_DIR_IN                        0x80
#define EP_TYPE_MASK                       0x03
#define EP_TYPE_CONTROL                    0x00
#define EP_TYPE_ISOCHRONOUS                0x01
#define EP_TYPE_BULK                       0x02
#define EP_TYPE_INTERRUPT                  0x03

#endif /* REPORT_H_ */
