#pragma once

#include "quantum.h"
#include "config_led.h"
#include "matrix.h"

#include "i2c_master.h"
#include "led_matrix.h" //For led keycodes
#include "usb/udi_cdc.h"
#include "usb/usb2422.h"

#define LAYOUT( \
C01, C02, C03, C04, \
C05, C06, C07, C08, \
C09, C10, C11, C12, \
C13, C14, C15, C16, \
R01, R02, R03, R04, \
R05, R06, R07, R08, \
R09, R10, R11, R12, \
R13, R14, R15, R16 \
) \
{ \
    { KC_NO, KC_NO, KC_NO, KC_NO, C01, C02, C03, C04 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, C05, C06, C07, C08 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, C09, C10, C11, C12 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, C13, C14, C15, C16 }, \
    { R01, R02, R03, R04, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R05, R06, R07, R08, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R09, R10, R11, R12, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R13, R14, R15, R16, KC_NO, KC_NO, KC_NO, KC_NO }, \
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
