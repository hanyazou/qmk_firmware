#pragma once

#include "quantum.h"

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
