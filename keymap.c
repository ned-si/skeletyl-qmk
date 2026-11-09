#include "nedsi.h"

// The handwired thumbs sit at matrix columns 2-4 on both halves; upstream puts
// the outer left thumb at [3, 0] and the inner right one at [7, 0]. So this
// keymap fills the matrix itself instead of using LAYOUT_split_3x5_3.
// clang-format off
#define LAYOUT_handwired(                               \
  k00, k01, k02, k03, k04,     k44, k43, k42, k41, k40, \
  k10, k11, k12, k13, k14,     k54, k53, k52, k51, k50, \
  k20, k21, k22, k23, k24,     k64, k63, k62, k61, k60, \
            k32, k33, k34,     k74, k73, k72            \
)                                                       \
{                                                       \
  {   k00,   k01,   k02,   k03,   k04 },                \
  {   k10,   k11,   k12,   k13,   k14 },                \
  {   k20,   k21,   k22,   k23,   k24 },                \
  { KC_NO, KC_NO,   k32,   k33,   k34 },                \
  {   k40,   k41,   k42,   k43,   k44 },                \
  {   k50,   k51,   k52,   k53,   k54 },                \
  {   k60,   k61,   k62,   k63,   k64 },                \
  { KC_NO, KC_NO,   k72,   k73,   k74 },                \
}
// clang-format on

// Expands the userspace row macros before handing them to the layout above.
#define LAYOUT_skeletyl(...) LAYOUT_handwired(__VA_ARGS__)

// The shared userspace dropped these when the Scylla gaming layer was
// reworked; this board keeps its gaming layer as it was, so they live here.
// GAME_Z used to tap A (a copy-paste slip); it taps Z now.
#define GAME_A LSFT_T(KC_A)
#define GAME_Z LCTL_T(KC_Z)
#define ________________GAMING_L2_________________     GAME_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________GAMING_L3_________________     GAME_Z,    KC_X,    KC_C,    KC_V,    KC_B

// Gaming toggle on NAV, where it was before the userspace change.
#undef ________________NAV_L3________________
#define ________________NAV_L3________________      _______, _______,TG(_GAMING), _______, UNIWL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_skeletyl(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________MAIN_L2________________,                                ________________MAIN_R2________________,
    ________________MAIN_L3________________,                                ________________MAIN_R3________________,
                    MO(_SYM), LT(_MISC, KC_TAB), CACCCV,                    KC_MPLY, KC_SPC, MO(_NUM)
    ),

    [_GAMING] = LAYOUT_skeletyl(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________GAMING_L2_________________,                             ________________MAIN_R2________________,
    ________________GAMING_L3_________________,                             ________________MAIN_R3________________,
                      LT(_SYM, KC_ESC), KC_SPC, KC_TAB,                    KC_LALT, KC_SPC, LT(_NUM, KC_ENT)
    ),

    [_SYM] = LAYOUT_skeletyl(
    ________________SYM_L1________________,                                ________________SYM_R1________________,
    ________________SYM_L2________________,                                ________________SYM_R2________________,
    ________________SYM_L3________________,                                ________________SYM_R3________________,
                        _______, _______, _______,                      KC_UNDS, _______,MO(_NAV)
    ),

    [_ACC] = LAYOUT_skeletyl(
    ________________ACC_L1________________,                                ________________ACC_R1________________,
    ________________ACC_L2________________,                                ________________ACC_R2________________,
    ________________ACC_L3________________,                                ________________ACC_R3________________,
                        _______, _______, _______,                      _______, _______, _______
    ),

    [_NUM] = LAYOUT_skeletyl(
    ________________NUM_L1________________,                                ________________NUM_R1________________,
    ________________NUM_L2________________,                                ________________NUM_R2________________,
    ________________NUM_L3________________,                                ________________NUM_R3________________,
                       MO(_NAV),  KC_SPC, _______,                      _______, _______, _______
    ),

    [_NAV] = LAYOUT_skeletyl(
    ________________NAV_L1________________,                                ________________NAV_R1________________,
    ________________NAV_L2________________,                                ________________NAV_R2________________,
    ________________NAV_L3________________,                                ________________NAV_R3________________,
                        _______, _______, _______,                      _______, _______, _______
    ),

    [_MISC] = LAYOUT_skeletyl(
    ________________MISC_L1________________,                                ________________MISC_R1________________,
    ________________MISC_L2________________,                                ________________MISC_R2________________,
    ________________MISC_L3________________,                                ________________MISC_R3________________,
                        _______, _______, _______,                          _______, KC_MPLY, _______
    )
};


__attribute__ ((weak))
void matrix_init_keymap(void) {}
void matrix_init_user(void) {
  set_unicode_input_mode(UNICODE_MODE_LINUX);

  matrix_init_keymap();
}
