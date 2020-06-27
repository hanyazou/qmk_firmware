#pragma once

#include "quantum.h"
#include "config_led.h"
#include "matrix.h"

#include "i2c_master.h"
#include "led_matrix.h" //For led keycodes
#include "usb/udi_cdc.h"
#include "usb/usb2422.h"

#define LAYOUT( K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11 ) \
{ \
    {   K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11   }, \
}

#define TOGGLE_FLAG_AND_PRINT(var, name) { \
        if (var) { \
            dprintf(name " disabled\r\n"); \
            var = !var; \
        } else { \
            var = !var; \
            dprintf(name " enabled\r\n"); \
        } \
    }
