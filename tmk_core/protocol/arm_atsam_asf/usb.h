#pragma once

extern void configure_usb(void);
extern uint8_t udb_get_leds(void);
extern bool arm_atsam_asf_udi_hid_callback_keyboard_enable(void);
extern void arm_atsam_asf_udi_hid_callback_keyboard_disable(void);
extern void arm_atsam_asf_udi_hid_callback_keyboard_led(uint8_t value);

extern bool udi_hid_kbd_report_raw(void* report, int size);
