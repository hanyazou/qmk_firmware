/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID           0x03EB
#define PRODUCT_ID          0x201D
#define DEVICE_VER          0x0001

#define MANUFACTURER        "Atmel Corp."
#define PRODUCT             "BB Q10 USB keyboard"
#define SERIAL_NUM          "Unavailable"

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 5

/* Port and Pin definition of key row hardware configuration */
#define MATRIX_ROW_PINS  { PIN_PA19, PIN_PA23, PIN_PA02, PIN_PA04, PIN_PA05, PIN_PA06, PIN_PA07 }

/* Port and Pin definition of key column hardware configuration */
#define MATRIX_COL_PINS  { PIN_PA22, PIN_PA27, PIN_PA00, PIN_PA01, PIN_PA03 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 25
