#include <delay/delay.h>
#include <system/system.h>

#include "config.h"
#include "keyboard.h"
#include "print.h"
#include "arm_atsam_asf/usb.h"
#include "arm_atsam_asf/uart.h"

int main(void)
{

    system_init();
    delay_init();
    configure_uart();

    println("Hello world!");

    configure_usb();
    keyboard_setup();
    keyboard_init();

    return 0;
}
