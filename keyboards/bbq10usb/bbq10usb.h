#pragma once

#include "quantum.h"
#include "config_led.h"
#include "matrix.h"

#include "i2c_master.h"
#include "usb/udi_cdc.h"
#include "usb/usb2422.h"

#define LAYOUT( \
    L00, L01, L02, L03, L04, R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14, R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24, R20, R21, R22, R23, R24, \
    C30, C31, C32, C33, C34 \
) { \
    { L00, L01, L02, L03, L04 }, \
    { R00, R01, R02, R03, R04 }, \
    { L10, L11, L12, L13, L14 }, \
    { R10, R11, R12, R13, R14 }, \
    { L20, L21, L22, L23, L24 }, \
    { R20, R21, R22, R23, R24 }, \
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
