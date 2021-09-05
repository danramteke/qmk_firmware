#include QMK_KEYBOARD_H

enum sc2_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    U_LOWER = SAFE_RANGE,
    U_RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(\

  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                          KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,     KC_G,                          KC_H,     KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
KC_SPACE,   KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,                          KC_N,     KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                                    KC_LSFT, U_LOWER, KC_LCTL,     KC_ENT,  U_RAISE,  KC_LALT
  ),


  [_LOWER] = LAYOUT(
    KC_MINS, KC_LBRC,  KC_7,     KC_8,    KC_9,  KC_RBRC,                     KC_PGUP,  XXXXXXX,   KC_UP,  XXXXXXX,  XXXXXXX, _______,
     KC_DOT, KC_SCLN,  KC_4,     KC_5,    KC_6,   KC_EQL,                     KC_PGDN,  KC_LEFT, KC_DOWN,  KC_RGHT,   KC_DEL, XXXXXXX,
       KC_0,  KC_GRV,  KC_1,     KC_2,    KC_3,  KC_BSLS,                       KC_NO,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, _______,
                               _______,  _______,  _______,           _______,  _______,  _______
  ),
};



#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("SC2"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case U_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case U_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
    }
    return true;
}
