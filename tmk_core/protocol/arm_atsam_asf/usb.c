#include <udc.h>
#include <udi_hid.h>
#include "host.h"
#include "usb.h"

uint8_t keyboard_protocol = 1;
uint8_t keyboard_idle = 0;

void arm_atsam_asf_usb_init(void)
{
	udc_start();
}

bool arm_atsam_asf_udi_hid_callback_keyboard_enable(void)
{
	printf("USB keyboard enabled\r\n");

	return true;
}

void arm_atsam_asf_udi_hid_callback_keyboard_disable(void)
{
	printf("USB keyboard disabled\r\n");
}

