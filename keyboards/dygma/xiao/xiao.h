#pragma once

#include "quantum.h"
#include "config_led.h"
#include "matrix.h"

#include "i2c_master.h"
#include "led_matrix.h" //For led keycodes
#include "usb/udi_cdc.h"
#include "usb/usb2422.h"

#define LAYOUT( \
    L11, L12, L13, L14, L15, L16, L17, /**/ /**/ R17, R16, R15, R14, R13, R12, R11, \
    L21, L22, L23, L24, L25, L26, /**/ /**/ R28, R27, R26, R25, R24, R23, R22, R21, \
    L31, L32, L33, L34, L35, L36, /**/ /**/ /**/ R37, R36, R35, R34, R33, R32, R31, \
    /**/ L42, L43, L44, L45, L46, L47, /**/ /**/ /**/ R46, R45, R44, R43, R42, R41,  \
    L51, L52, L53, L54, L55, /**/ L57, L58, R58, R57, R56, R55, R54, R53, R52, R51 \
) { \
    {   L11, L12, L13, L14, L15, L16, L17, KC_NO   }, \
    {   L21, L22, L23, L24, L25, L26, KC_NO, KC_NO   }, \
    {   L31, L32, L33, L34, L35, L36, KC_NO, KC_NO   }, \
    {   KC_NO, L42, L43, L44, L45, L46, L47, KC_NO   },	\
    {   L51, L52, L53, L54, L55, KC_NO, L57, L58   },	\
    {   R11, R12, R13, R14, R15, R16, R17, KC_NO   }, \
    {   R21, R22, R23, R24, R25, R26, R27, R28   }, \
    {   R31, R32, R33, R34, R35, R36, R37, KC_NO   }, \
    {   R41, R42, R43, R44, R45, R46, KC_NO, KC_NO   }, \
    {   R51, R52, R53, R54, R55, R56, R57, R58   }, \
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
