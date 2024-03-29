#include "nedsi.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_wrapper(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________MAIN_L2________________,                                ________________MAIN_R2________________,
    ________________MAIN_L3________________,                                ________________MAIN_R3________________,
                    MO(_SYM), LT(_MISC, KC_TAB), CACCCV,                    KC_MPLY, KC_SPC, MO(_NUM)
    ),

    [_GAMING] = LAYOUT_wrapper(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________GAMING_L2_________________,                             ________________MAIN_R2________________,
    ________________GAMING_L3_________________,                             ________________MAIN_R3________________,
                      LT(_SYM, KC_ESC), KC_SPC, KC_TAB,                    KC_LALT, KC_SPC, LT(_NUM, KC_ENT)
    ),

    [_SYM] = LAYOUT_wrapper(
    ________________SYM_L1________________,                                ________________SYM_R1________________,
    ________________SYM_L2________________,                                ________________SYM_R2________________,
    ________________SYM_L3________________,                                ________________SYM_R3________________,
                        _______, _______, _______,                      KC_UNDS, _______,MO(_NAV)
    ),

    [_ACC] = LAYOUT_wrapper(
    ________________ACC_L1________________,                                ________________ACC_R1________________,
    ________________ACC_L2________________,                                ________________ACC_R2________________,
    ________________ACC_L3________________,                                ________________ACC_R3________________,
                        _______, _______, _______,                      _______, _______, _______
    ),

    [_NUM] = LAYOUT_wrapper(
    ________________NUM_L1________________,                                ________________NUM_R1________________,
    ________________NUM_L2________________,                                ________________NUM_R2________________,
    ________________NUM_L3________________,                                ________________NUM_R3________________,
                       MO(_NAV),  KC_SPC, _______,                      _______, _______, _______
    ),

    [_NAV] = LAYOUT_wrapper(
    ________________NAV_L1________________,                                ________________NAV_R1________________,
    ________________NAV_L2________________,                                ________________NAV_R2________________,
    ________________NAV_L3________________,                                ________________NAV_R3________________,
                        _______, _______, _______,                      _______, _______, _______
    ),

    [_MISC] = LAYOUT_wrapper(
    ________________MISC_L1________________,                                ________________MISC_R1________________,
    ________________MISC_L2________________,                                ________________MISC_R2________________,
    ________________MISC_L3________________,                                ________________MISC_R3________________,
                        _______, _______, _______,                          _______, KC_MPLY, _______
    )
};


__attribute__ ((weak))
void matrix_init_keymap(void) {}
void matrix_init_user(void) {


  set_unicode_input_mode(UC_LNX);

  matrix_init_keymap();
}
