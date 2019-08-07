#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _COLEMAK  (0)
#define _SHIFT    (1)
#define _NUMPAD   (2)
#define _SYMBOL   (3)
#define _ARROW    (4)
#define _BRACKET  (5)
#define _FUNCTION (6)
#define _MOUSE    (7)

#define SKC_A LSFT(KC_A)
#define SKC_B LSFT(KC_B)
#define SKC_C LSFT(KC_C)
#define SKC_D LSFT(KC_D)
#define SKC_E LSFT(KC_E)
#define SKC_F LSFT(KC_F)
#define SKC_G LSFT(KC_G)
#define SKC_H LSFT(KC_H)
#define SKC_I LSFT(KC_I)
#define SKC_J LSFT(KC_J)
#define SKC_K LSFT(KC_K)
#define SKC_L LSFT(KC_L)
#define SKC_M LSFT(KC_M)
#define SKC_N LSFT(KC_N)
#define SKC_O LSFT(KC_O)
#define SKC_P LSFT(KC_P)
#define SKC_Q LSFT(KC_Q)
#define SKC_R LSFT(KC_R)
#define SKC_S LSFT(KC_S)
#define SKC_T LSFT(KC_T)
#define SKC_U LSFT(KC_U)
#define SKC_V LSFT(KC_V)
#define SKC_W LSFT(KC_W)
#define SKC_X LSFT(KC_X)
#define SKC_Y LSFT(KC_Y)
#define SKC_Z LSFT(KC_Z)

#define T_ARROW LT(ARROW, KC_T)
#define N_BRACK LT(BRACKET, KC_N)
#define SPC_PAD LT(NUMPAD, KC_SPC)
#define MIN_SYM LT(SYMBOL, KC_MINS)
#define ENT_SFT LT(SHIFT, KC_ENT)

#define KC_A_CT MT(MOD_LCTL, KC_A)
#define KC_R_AT MT(MOD_LALT, KC_R)
#define KC_S_UI MT(MOD_LGUI, KC_S)
#define KC_O_CT MT(MOD_LCTL, KC_O)
#define KC_I_AT MT(MOD_LALT, KC_I)
#define KC_E_UI MT(MOD_LGUI, KC_E)
#define COM_CTL MT(MOD_LCTL, KC_COMM)
#define KC_6_AT MT(MOD_LALT, KC_6)
#define SFT_TAB LSFT(KC_TAB)

enum custom_layers {
  COLEMAK,
  SHIFT,
  NUMPAD,
  SYMBOL,
  ARROW,
  BRACKET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
    KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,                    KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_ESC,
    KC_ESC,  KC_A_CT, KC_R_AT, KC_S_UI, T_ARROW, KC_G,                      KC_M,    N_BRACK, KC_E_UI, KC_I_AT, KC_O_CT, KC_ESC,
    KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_QUES, KC_ESC,
                                        _______, _______, SPC_PAD,  ENT_SFT, _______, _______
  ),

  [_SHIFT] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, SKC_Q,   SKC_W,   SKC_F,   SKC_P,   SKC_B,                     SKC_J,   SKC_L,   SKC_U,   SKC_Y,   KC_COLN, _______,
    _______, SKC_A,   SKC_R,   SKC_S,   SKC_T,   SKC_G,                     SKC_M,   SKC_N,   SKC_E,   SKC_I,   SKC_O,   _______,
    _______, SKC_Z,   SKC_X,   SKC_C,   SKC_D,   SKC_V,   _______, _______, SKC_K,   SKC_H,   KC_QUOT, KC_DQUO, KC_EXLM, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, KC_GRV,  KC_TILD, KC_ASTR, KC_SLSH, KC_PERC,                   _______, KC_7,    KC_8,    KC_9,    KC_PEQL, _______,
    _______, SFT_TAB, KC_TAB,  KC_PLUS, MIN_SYM, KC_UNDS,                   KC_SPC,  KC_4,    KC_5,    KC_6_AT, COM_CTL, _______,
    _______, _______, _______, _______, KC_BSLS, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                                        _______, _______, _______, KC_0,    _______, _______
  ),
  [_SYMBOL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_AMPR, KC_ASTR, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_DLR,  KC_PERC, KC_CIRC, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [_ARROW] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_DEL,  _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [_BRACKET] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LPRN, KC_RPRN, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LCBR, KC_RCBR, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LABK, KC_RABK, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  )

  /* [_QWERTY] = LAYOUT( */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,           KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* ), */
  /*  */
  /* [_LOWER] = LAYOUT( */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_HOME, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_END, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0 */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* ), */
  /*  */
  /* [_RAISE] = LAYOUT( */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   _______, _______, _______,                   _______, _______, _______ */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* ), */
  /*  */
  /* [_ADJUST] = LAYOUT( */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   _______, _______, _______,                   _______, _______, _______ */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* ) */
};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case QWERTY: */
/*       if (record->event.pressed) { */
/*         set_single_persistent_default_layer(_QWERTY); */
/*       } */
/*       return false; */
/*       break; */
/*     case LOWER: */
/*       if (record->event.pressed) { */
/*         layer_on(_LOWER); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } else { */
/*         layer_off(_LOWER); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*     case RAISE: */
/*       if (record->event.pressed) { */
/*         layer_on(_RAISE); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } else { */
/*         layer_off(_RAISE); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*     case ADJUST: */
/*       if (record->event.pressed) { */
/*         layer_on(_ADJUST); */
/*       } else { */
/*         layer_off(_ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*   } */
/*   return true; */
/* } */
