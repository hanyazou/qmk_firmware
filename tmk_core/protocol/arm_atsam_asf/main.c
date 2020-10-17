#include <delay/delay.h>
#include <port/port.h>
#include <usart/usart.h>

#include "keyboard.h"
#include "usb.h"

int main(void)
{

    system_init();
    delay_init();

    printf("Hello world!\n");

    arm_atsam_asf_usb_init();
    keyboard_setup();
    keyboard_init();

    return 0;
}
