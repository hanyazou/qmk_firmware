#include <udc.h>
#include <udi_hid.h>
#include "host.h"
#include "usb.h"

uint8_t keyboard_protocol = 1;
uint8_t keyboard_idle = 0;

static uint8_t keyboard_leds = 0;

void configure_usb(void)
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

void arm_atsam_asf_udi_hid_callback_keyboard_led(uint8_t value)
{
	keyboard_leds = value;
}

uint8_t udb_get_leds()
{
	return keyboard_leds;
}
