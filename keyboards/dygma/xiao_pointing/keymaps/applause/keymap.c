#include QMK_KEYBOARD_H

#include "stdio.h"
#include "arm_atsam/printf.h"

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

enum layer_number {
    QWERTY,
    DVORAK,
    CTRL,
    ALT,
    GUI,
    LOWER,
    RAISE,
    FUNC,
    NAVI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LM(CTRL, MOD_LCTL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        MO(NAVI), LM(GUI, MOD_LGUI), LM(ALT, MOD_LALT), MO(LOWER), KC_SPC, /*    */ KC_BTN4, KC_WH_U, KC_BTN1, KC_BTN2, /*    */ KC_HENK,  MO(RAISE), KC_RALT, MO(FUNC), LT(FUNC, KC_APP), KC_RCTL
    ),
    [DVORAK] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,
        _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, KC_ENT,
        _______, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
        _______, _______, _______, _______, _______, /*    */ _______, _______, _______, _______, /*    */ _______, _______, _______, _______, _______, _______
    ),
    [CTRL] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, /*    */ _______, _______, _______, _______, /*    */ _______, _______, _______, _______, _______, _______
    ),
    [ALT] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, /*    */ _______, _______, _______, _______, /*    */ _______, _______, _______, _______, _______, _______
    ),
    [GUI] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, /*    */ _______, _______, _______, _______, /*    */ _______, _______, _______, _______, _______, _______
    ),
    [LOWER] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_AMPR, KC_LPRN, KC_RPRN, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_CIRC, KC_ASTR, KC_LCBR, KC_RCBR, KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, /*    */ _______, _______, KC_BTN3, KC_BTN5, /*    */ _______, _______, _______, _______, _______, _______
    ),
    [RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, /*    */ _______, _______, _______, _______, /*    */ LSFT(KC_INS), _______, _______, _______, _______, _______
    ),
    [FUNC] = LAYOUT(
        RESET,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
	KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  LALT(KC_PSCR), /*    */ KC_SPC,  KC_SPC,  KC_LSFT,  KC_ENT, /*    */ KC_PSCR,  KC_LSFT,  KC_RALT, KC_APP,  KC_RGUI, KC_RCTL
    ),
    [NAVI] = LAYOUT(
        KC_LGUI,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_BSPC, KC_UP,   KC_LEFT, KC_RIGHT,KC_DOWN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC, /*    */ KC_SPC,  KC_SPC,  KC_LSFT,  KC_ENT, /*    */ KC_HENK,  KC_LSFT,  KC_RALT, KC_APP,  KC_RGUI, KC_RCTL
    ),
    /*
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    */
    /*
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

void keyboard_post_init_user(void) {
    default_layer_set(1 << DVORAK);
}


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
	    // send_string("UNEXPECTED");
	    __xprintf("Unexpected-Left\n");
	} else if (err == -2) {
	    // send_string("TIMEOUT");
	    __xprintf("Timeout-Left\n");
	} else {
	    // send_string("ERROR");
	    __xprintf("ERROR-Left\n");
	}
    } else {
	uint16_t crc16 = 0xffff;
	for (int i = 0; i < 6; i++) {
	    crc16 = _crc_ccitt_update(crc16, dat[i]);
	}
	if (crc16 == (((uint16_t)dat[6] << 8) | dat[7])) {
	    // send_string("OK");
	} else {
	    // send_string("CRC");
	    __xprintf("CRC-Left\n");
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
#if 1
    err = i2c0_read(0x59, dat, 8, 1000);
    if (err < 0) {
	if (err == -3) {
	    // send_string("UNEX-R");
	    __xprintf("Unexpected-Right\n");
	} else if (err == -2) {
	    // send_string("TO-R");
	    __xprintf("Timeout-Right\n");
	} else {
	    // send_string("ERR-R");
	    __xprintf("ERROR-Right\n");
	}
    } else {
	uint16_t crc16 = 0xffff;
	for (int i = 0; i < 6; i++) {
	    crc16 = _crc_ccitt_update(crc16, dat[i]);
	}
	if (crc16 == (((uint16_t)dat[6] << 8) | dat[7])) {
	    // send_string("OK");
	} else {
	    // send_string("CRC-R");
	    __xprintf("CRC-Right\n");
	}
	if (dat[0] == 1) {
	    for (int i=1; i < 6; i++) {
		tmp_mtx_right[i - 1] = dat[i];
	    }
	}
    }
#endif
    // send_string(SS_TAP(X_ENT));
}

extern uint32_t adhoc_dir;
extern uint32_t adhoc_out;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static char buf[256];
    if (IS_PRESSED(record->event)) {
#if 0
	static int count = 0;
	snprintf(buf, 256, "Hoge=%d", count++);
	send_string(buf);
	return false;
#endif
	// send_string("A");
	// return false;
    } else if(IS_RELEASED(record->event)) {
    } else {
	static int last = 0;
	int curr = record->event.time / 10;
	if (last != curr) {
	    last = curr;
	    static int count = 0;
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
	    snprintf(buf, 256, "Count=%d", count++);
	    // send_string(buf);
	    // oled_test();
	    // dygma_raise_send_test();
	    dygma_raise_read_test();
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
