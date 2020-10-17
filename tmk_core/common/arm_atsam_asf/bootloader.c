#include "bootloader.h"
#include <system/system.h>

void bootloader_jump(void)
{
    system_reset();
}
