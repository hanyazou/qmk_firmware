#include QMK_KEYBOARD_H

#include "stdio.h"
#include "arm_atsam_protocol.h"
#include "usb/udi_cdc.h"
#include "print.h"

extern inbuf_t inbuf; // udi_cdc.c

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_VOLU,    KC_VOLD,    KC_7,    KC_8,    KC_9,    KC_AT
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

#define OLED_I2C_ADDR 0x78
#if 0
#define DisplayWidth 128
#define DisplayHeight 64
#define USE_128x64
#else
#define DisplayWidth 128
#define DisplayHeight 32
#undef USE_128x64
#endif

enum ssd1306_cmds {
  DisplayOff = 0xAE,
  DisplayOn = 0xAF,

  SetContrast = 0x81,
  DisplayAllOnResume = 0xA4,

  DisplayAllOn = 0xA5,
  NormalDisplay = 0xA6,
  InvertDisplay = 0xA7,
  SetDisplayOffset = 0xD3,
  SetComPins = 0xda,
  SetVComDetect = 0xdb,
  SetDisplayClockDiv = 0xD5,
  SetPreCharge = 0xd9,
  SetMultiPlex = 0xa8,
  SetLowColumn = 0x00,
  SetHighColumn = 0x10,
  SetStartLine = 0x40,

  SetMemoryMode = 0x20,
  ColumnAddr = 0x21,
  PageAddr = 0x22,

  ComScanInc = 0xc0,
  ComScanDec = 0xc8,
  SegRemap = 0xa0,
  SetChargePump = 0x8d,
  ExternalVcc = 0x01,
  SwitchCapVcc = 0x02,

  ActivateScroll = 0x2f,
  DeActivateScroll = 0x2e,
  SetVerticalScrollArea = 0xa3,
  RightHorizontalScroll = 0x26,
  LeftHorizontalScroll = 0x27,
  VerticalAndRightHorizontalScroll = 0x29,
  VerticalAndLeftHorizontalScroll = 0x2a,
};

void send_cmd1(uint8_t cmd) {
    uint8_t dat[2];
    dat[0] = 0x00;
    dat[1] = cmd;
    i2c0_transmit(OLED_I2C_ADDR, dat, 2, 1000);
}

void send_cmd2(uint8_t cmd, uint8_t opt) {
    uint8_t dat[3];
    dat[0] = 0x00;
    dat[1] = cmd;
    dat[2] = opt;
    i2c0_transmit(OLED_I2C_ADDR, dat, 3, 1000);
}

void send_cmd3(uint8_t cmd, uint8_t opt1, uint8_t opt2) {
    uint8_t dat[4];
    dat[0] = 0x00;
    dat[1] = cmd;
    dat[2] = opt1;
    dat[3] = opt2;
    i2c0_transmit(OLED_I2C_ADDR, dat, 4, 1000);
}

void oled_test(void) {
    send_cmd1(DisplayOff);
    CLK_delay_ms(100);
    send_cmd2(SetDisplayClockDiv, 0x80);
    send_cmd2(SetMultiPlex, DisplayHeight - 1);

    send_cmd2(SetDisplayOffset, 0);


    send_cmd1(SetStartLine | 0x0);
    send_cmd2(SetChargePump, 0x14 /* Enable */);
    send_cmd2(SetMemoryMode, 0 /* horizontal addressing */);

#ifdef OLED_ROTATE180
// the following Flip the display orientation 180 degrees
    send_cmd1(SegRemap);
    send_cmd1(ComScanInc);
#endif
#ifndef OLED_ROTATE180
// Flips the display orientation 0 degrees
    send_cmd1(SegRemap | 0x1);
    send_cmd1(ComScanDec);
#endif
  
#ifdef USE_128x64
    send_cmd2(SetComPins, 0x12);
#else
    send_cmd2(SetComPins, 0x2);
#endif
    send_cmd2(SetContrast, 0x8f);
    send_cmd2(SetPreCharge, 0xf1);
    send_cmd2(SetVComDetect, 0x40);
    send_cmd1(DisplayAllOnResume);
    send_cmd1(NormalDisplay);
    send_cmd1(DeActivateScroll);
    send_cmd1(DisplayOn);

    send_cmd1(DisplayOn);
    send_cmd2(SetContrast, 0); // Dim

  send_cmd3(PageAddr, 0, (DisplayHeight / 8) - 1);
  send_cmd3(ColumnAddr, 0, DisplayWidth - 1);

    uint8_t dat[9];
    dat[0] = 0x40;
    dat[1] = 0xF0;
    dat[2] = 0xF0;
    dat[3] = 0xF0;
    dat[4] = 0xF0;
    dat[5] = 0x0F;
    dat[6] = 0x0F;
    dat[7] = 0x0F;
    dat[8] = 0x0F;
    for(int i = 0; i < (128 / 8 * 32 / 8); i++) {
	i2c0_transmit(OLED_I2C_ADDR, dat, 9, 1000);
    }

    send_cmd3(PageAddr, 0, (DisplayHeight / 8) - 1);
    send_cmd3(ColumnAddr, 0, DisplayWidth - 1);
    i2c0_read(OLED_I2C_ADDR, dat, 8, 1000);
    for (int i=0; i < 8; i++) {
	char buf[16];
	snprintf(buf, 16, "[%02X]", dat[i]);
	send_string(buf);
    }
    send_string(SS_TAP(X_ENT));
}

static inline uint16_t _crc_ccitt_update(uint16_t crc, uint8_t data) {
  data ^= (crc & 255);
  data ^= data << 4;

  return ((((uint16_t)data << 8) | (crc >> 8)) ^ (uint8_t)(data >> 4)
          ^ ((uint16_t)data << 3));
}

void dygma_raise_send_test(void) {
    uint8_t dat[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    uint16_t crc16;
    dat[0] = 3; // TWI_CMD_LED_SET_ALL_TO
#if 0
    dat[1] = 0x80;
    dat[2] = 0x40;
    dat[3] = 0x20;
#endif
    dat[1] = rand();
    dat[2] = rand();
    dat[3] = rand();
    crc16 = 0xffff;
    for (int i = 0; i < 4; i++) {
	crc16 = _crc_ccitt_update(crc16, dat[i]);
    }
    dat[4] = (crc16 >> 8) & 0xff;
    dat[5] = crc16 & 0xff;
    static uint8_t addr = 0x58;
    int err = i2c0_transmit(addr, dat, 6, 1000);
    if (err < 0) {
	if (err == -2) {
	    send_string("TIMEOUT");
	} else {
	    send_string("ERROR");
	}
	// char buf[16];
	// snprintf(buf, 16, "[%02X]", addr);
	// send_string(buf);
	// addr += 1;
    } else {
	send_string("PASS");
    }
}

uint8_t tmp_mtx[5] = { 0, 0, 0, 0, 0 };
uint8_t tmp_mtx_right[5] = { 0, 0, 0, 0, 0 };

void dygma_raise_read_test(void) {
    uint8_t dat[8] = { 255, 255, 3, 4, 5, 6, 7, 8 };
    int err = i2c0_read(0x58, dat, 8, 1000);
    if (err < 0) {
	if (err == -3) {
	    send_string("UNEXPECTED");
	} else if (err == -2) {
	    send_string("TIMEOUT");
	} else {
	    send_string("ERROR");
	}
    } else {
	uint16_t crc16 = 0xffff;
	for (int i = 0; i < 6; i++) {
	    crc16 = _crc_ccitt_update(crc16, dat[i]);
	}
	if (crc16 == (((uint16_t)dat[6] << 8) | dat[7])) {
	    // send_string("OK");
	} else {
	    send_string("CRC");
	}
	if (dat[0] == 1) {
#if 0
	    send_string("[");
	    for (int i=1; i < 6; i++) {
		char buf[16];
		snprintf(buf, 16, "%02X", dat[i]);
		send_string(buf);
	    }
	    send_string("]");
#endif
	    for (int i=1; i < 6; i++) {
		tmp_mtx[i - 1] = dat[i];
	    }
	}
    }
    err = i2c0_read(0x59, dat, 8, 1000);
    if (err < 0) {
	if (err == -3) {
	    send_string("UNEX-R");
	} else if (err == -2) {
	    send_string("TO-R");
	} else {
	    send_string("ERR-R");
	}
    } else {
	uint16_t crc16 = 0xffff;
	for (int i = 0; i < 6; i++) {
	    crc16 = _crc_ccitt_update(crc16, dat[i]);
	}
	if (crc16 == (((uint16_t)dat[6] << 8) | dat[7])) {
	    // send_string("OK");
	} else {
	    send_string("CRC-R");
	}
	if (dat[0] == 1) {
	    for (int i=1; i < 6; i++) {
		tmp_mtx_right[i - 1] = dat[i];
	    }
	}
    }
    // send_string(SS_TAP(X_ENT));
}

extern uint32_t adhoc_dir;
extern uint32_t adhoc_out;

extern char sbuf[256];


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    // static char buf[256];
    if (IS_PRESSED(record->event)) {
#if 0
	static int count = 0;
	snprintf(buf, 256, "Hoge=%d", count++);
	send_string(buf);
	return false;
#endif
	// send_string("A");
	// return false;
	// CDC_printf("HOGE %04X\n", keycode);
	__xprintf("HOGE %04X\n", keycode);
    } else if(IS_RELEASED(record->event)) {
    } else {
	static int last = 0;
	int curr = record->event.time / 10;
	if (last != curr) {
	    last = curr;
	    // static int count = 0;
#if 0
	    if (count == 0) {
		// snprintf(buf, 256, "PORTA DIR=%08lX", adhoc_dir);
		snprintf(buf, 256, "PORTA DIR=%08lX", (uint32_t)(PORT->Group[0].DIR.reg));
		send_string(buf);
		// snprintf(buf, 256, "PORTA OUT=%08lX", adhoc_out);
		snprintf(buf, 256, "PORTA OUT=%08lX", (uint32_t)(PORT->Group[0].OUT.reg));
		send_string(buf);
	    }
#endif
	    // snprintf(buf, 256, "Count=%d", count++);
	    // send_string(buf);
	    // oled_test();
	    // dygma_raise_send_test();
	    // dygma_raise_read_test();
	    if (CDC_input()) {
		// __xprintf("%s", inbuf.buf);
		__xprintf("%s", sbuf);
	    }
	}
	return false;
    }

    switch (keycode) {
        case U_T_AUTO:
#ifdef USB_DUALPORT_ENABLE
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
#endif
            return false;
        case U_T_AGCR:
#ifdef USB_DUALPORT_ENABLE
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
#endif
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
#ifdef RGB_MATRIX_ENABLE
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
#endif
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
