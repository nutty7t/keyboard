// @nutty7t's keyboard layout
//
// TODO Some of the media keys only work in macOS. Eventually, I want to get
// them working in Windows. An idea is to split the MEDIA layer into two
// OS-specific layers, and then create base layers for each OS that switch to
// the correct layer.
//
// TODO Get the ENDASH and the EMDASH into the SYMBOL layer. Need to enable
// UNICODE_ENABLE in rules.mk.
//
// TODO Implement the mouse and navigation layer.
//
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _COLEMAK  (0)
#define _ARROW    (1)
#define _MEDIA    (2)
#define _MOUSE    (3)
#define _SYSTEM   (4)
#define _FUNCTION (5)
#define _NUMPAD   (6)
#define _SYMBOL   (7)

// Shift Tab
#define SFT_TAB LSFT(KC_TAB)

// Home Row Mod Tap
#define KC_A_ST MT(MOD_LSFT, KC_A)
#define KC_R_CT MT(MOD_LCTL, KC_R)
#define KC_S_AT MT(MOD_LALT, KC_S)
#define KC_T_UI MT(MOD_LGUI, KC_T)
#define KC_N_UI MT(MOD_RGUI, KC_N)
#define KC_E_AT MT(MOD_RALT, KC_E)
#define KC_I_CT MT(MOD_RCTL, KC_I)
#define KC_O_ST MT(MOD_RSFT, KC_O)

// Momentary Layer Keys
#define HJKL MO(ARROW_LAYER)
#define MEDIA MO(MEDIA_LAYER)
#define MOUSE MO(MOUSE_LAYER)
#define SYSTEM MO(SYSTEM_LAYER)

// Mod Tap Layer Keys
#define KC_F_FN LT(FUNCTION_LAYER, KC_F)
#define SPC_PAD LT(NUMPAD_LAYER, KC_SPC)
#define ENT_SYM LT(SYMBOL_LAYER, KC_ENT)

enum custom_layers {
  COLEMAK_LAYER,
  ARROW_LAYER,
  MEDIA_LAYER,
  MOUSE_LAYER,
  SYSTEM_LAYER,
  FUNCTION_LAYER,
  NUMPAD_LAYER,
  SYMBOL_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_F_FN, KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, _______,
    HJKL,    KC_A_ST, KC_R_CT, KC_S_AT, KC_T_UI, KC_G,                      KC_M,    KC_N_UI, KC_E_AT, KC_I_CT, KC_O_ST, KC_ESC,
    _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SCLN, _______,
                               MEDIA,   MOUSE,   SPC_PAD,                   ENT_SYM, SYSTEM,  _______
  ),

  [_ARROW] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,                   _______, _______, _______
  ),

  [_MEDIA] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_MPLY, KC_STOP, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_MUTE, KC_VOLD, KC_VOLU, KC_BRIU, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MFFD, KC_BRID, _______, _______,
                               _______, _______, _______,                   _______, _______, _______
  ),

  [_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,                   _______, _______, _______
  ),

  [_SYSTEM] = LAYOUT(
    _______, _______, _______, _______, _______,  _______,                   _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, _______, KC_POWER, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, KC_SLEP, KC_WAKE, _______,  _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______,  _______, _______,                   _______, _______, _______
  ),

  [_FUNCTION] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                               _______, _______, _______,                   _______, _______, _______
  ),

  [_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, KC_EQL,  KC_SLSH, KC_ASTR, KC_BSPC, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
    _______, _______, _______, SFT_TAB, KC_TAB,  _______,                   KC_SPC,  KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
    _______, _______, _______, KC_DEL,  KC_BSPC, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                               _______, _______, _______,                   _______, KC_0,    KC_DOT
  ),

  [_SYMBOL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LCBR, KC_RCBR, KC_PLUS,                   KC_PIPE, KC_AMPR, KC_ASTR, KC_EQL,  KC_GRV,  _______,
    _______, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_MINS,                   KC_TILD, KC_DLR,  KC_PERC, KC_CIRC, KC_SLSH, _______,
    _______, _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

};
