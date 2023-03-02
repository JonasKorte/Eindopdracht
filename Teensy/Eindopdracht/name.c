#include <usb_names.h>

#define MANUFACTURER_NAME          \
	{                          \
		'O', 'J', 'A' \
	}
#define MANUFACTURER_NAME_LEN 3

#define PRODUCT_NAME                                                            \
	{                                                                       \
		'E', 'i', 'n', 'd', 'o', 'p', 'd', 'r', 'a', 'c', 'h', 't', '1' \
	}
#define PRODUCT_NAME_LEN 13

#define SERIAL_NUMBER                                            \
	{                                                        \
		'O', 'J', 'A', '_', '0', '0', '1' \
	}
#define SERIAL_NUMBER_LEN 7

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
	2 + MANUFACTURER_NAME_LEN * 2,
	3,
	MANUFACTURER_NAME};

struct usb_string_descriptor_struct usb_string_product_name = {
	2 + PRODUCT_NAME_LEN * 2,
	3,
	PRODUCT_NAME};

struct usb_string_descriptor_struct usb_string_serial_number = {
	2 + SERIAL_NUMBER_LEN * 2,
	3,
	SERIAL_NUMBER};