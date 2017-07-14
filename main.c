
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <string.h>

#include "Functions.h"

int main(void)
{	
	usb_init();
	while (1)
	{	
		usb_keyboard_send();
		#ifdef MOUSE_ENABLE
		usb_mouse_send();
		#endif
	}
	return 0;
}
