#include "bbq10usb.h"

#define CAPSLOCK_PIN PIN_PA18
#define NUMLOCK_PIN PIN_PA28

void matrix_init_kb(void) {
    matrix_init_user();
    led_init_ports();
};

void led_init_ports(void) {
    setPinOutput(NUMLOCK_PIN);
    setPinOutput(CAPSLOCK_PIN);
    writePin(NUMLOCK_PIN, false);
    writePin(CAPSLOCK_PIN, false);
}

void led_set_kb(uint8_t usb_led) {
    printf("%s: usb_led=%02x\n\r", __func__, usb_led);
    writePin(NUMLOCK_PIN, IS_LED_ON(usb_led, USB_LED_NUM_LOCK));
    writePin(CAPSLOCK_PIN, IS_LED_ON(usb_led, USB_LED_CAPS_LOCK));
}
