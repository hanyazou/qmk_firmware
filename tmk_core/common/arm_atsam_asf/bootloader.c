#include "bootloader.h"
#include <system/system.h>
#include <wdt/wdt.h>

void bootloader_jump(void)
{
    struct wdt_conf config_wdt;

    printf("Set WDT to invoke the bootloader and stay in programming mode.\r\n");
    wdt_get_config_defaults(&config_wdt);
    config_wdt.always_on = false;
    config_wdt.timeout_period = WDT_PERIOD_2048CLK;
    wdt_set_config(&config_wdt);

    // wait for bite
    while (true);
}
