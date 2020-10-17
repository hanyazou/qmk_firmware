#include <delay/delay.h>
#include <port/port.h>
#include <usart/usart.h>

int main(void)
{

    system_init();
    delay_init();

    printf("Hello world!\n");

    return 0;
}
