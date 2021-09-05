#include QMK_KEYBOARD_H

enum custom_keycodes {
    U_PRVWD = SAFE_RANGE,
    U_NXTWD,
    U_LSTRT,
    U_LEND,
    U_DLINE,

    U_COLE, U_QWERT,
    U_MAC, U_WIN
};

#define U_MAC CG_SWAP
#define U_WIN CG_NORM

enum layers {
    _COLEMAKDH = 0,
    _QWERTY,
    _NUM,
    _SYM,
    _NAV,
    _MOUS,
    _LMOD,
    _RMOD,
    _ADJ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAKDH] = LAYOUT(\
    KC_ESC,    KC_Q,    KC_W,     KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_BSPC,
    KC_TAB,    KC_A,    KC_R,     KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_DEL,
    KC_SPC,    KC_Z,    KC_X,     KC_C,    KC_D,    KC_V,                      KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                      MO(_LMOD),MO(_NAV),MO(_MOUS),MO(_SYM),MO(_NUM),MO(_RMOD)
  ),

  [_QWERTY] = LAYOUT(\
    KC_ESC,    KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    KC_TAB,    KC_A,    KC_S,     KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,  KC_DEL,
    KC_SPC,    KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                      MO(_LMOD),MO(_NAV),MO(_MOUS),MO(_SYM),MO(_NUM),MO(_RMOD)
  ),


  [_NUM] = LAYOUT(
    _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
    _______,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, _______,
                                         KC_DOT,    KC_0, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT(
    _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
    _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, _______,
                                        KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [_NAV] = LAYOUT(\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_AGIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_PGUP, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
    _______, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGDN, U_LSTRT, U_PRVWD, U_NXTWD,  U_LEND, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, KC_BSPC,  KC_DEL
  ),

  [_MOUS] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL2,                   KC_AGIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ACL1,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, KC_ACL0,                   XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2
  ),

  [_LMOD] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, _______, _______, _______, _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [_RMOD] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
    _______, _______, _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [_ADJ] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  U_COLE, U_QWERT,                   U_QWERT,  U_COLE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   U_MAC,   U_WIN,                     U_WIN,   U_MAC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
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
    oled_write_ln_P(PSTR("MODE"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("OS"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("Mac"), false);
    } else {
        oled_write_ln_P(PSTR("Win"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYR"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case _MOUS:
            oled_write_ln_P(PSTR("Mous"), false);
            break;
        case _LMOD:
            oled_write_ln_P(PSTR("Lmod"), false);
            break;
        case _RMOD:
            oled_write_ln_P(PSTR("Rmod"), false);
            break;
        case _ADJ:
            oled_write_ln_P(PSTR("Adj"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
    }


}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
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



layer_state_t default_layer_state_set_user(layer_state_t state) {
    keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
    keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;
    return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case U_QWERT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case U_COLE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;

        case U_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case U_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case U_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case U_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case U_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_AGIN:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL|MOD_LSFT));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL|MOD_LSFT));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}
