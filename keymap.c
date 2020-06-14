/*
 * Copyright 2020 nutty7t <blackhole@nutty.email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Shift Tab
#define SFT_TAB LSFT(KC_TAB)

// Layers
#define _COLEMAK  (0)
#define _ARROW    (1)
#define _MEDIA    (2)
#define _FUNCTION (3)
#define _NUMPAD   (4)
#define _SYMBOL   (5)

// Momentary Layer Keys
#define ARROWS MO(ARROW_LAYER)
#define LAMBDA MO(FUNCTION_LAYER)
#define MEDIA MO(MEDIA_LAYER)
#define MOUSE MO(MOUSE_LAYER)
#define NUMPAD MO(NUMPAD_LAYER)
#define SYMBOLS MO(SYMBOL_LAYER)
#define SYSTEM MO(SYSTEM_LAYER)

enum custom_layers {
  COLEMAK_LAYER,
  ARROW_LAYER,
  MEDIA_LAYER,
  FUNCTION_LAYER,
  NUMPAD_LAYER,
  SYMBOL_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_ortho_5x15(
    KC_ESC,  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  KC_BSPC,
    SFT_TAB, KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    NUMPAD,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_GRV,  _______,
    KC_CAPS, ARROWS,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_ESC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
    _______, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_SLSH, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT, _______,
    KC_LCTL, _______, _______, MEDIA,   KC_LALT, KC_LGUI, KC_SPC,  KC_LSFT, SYMBOLS, KC_RCTL, LAMBDA,  _______, _______, _______, _______
  ),

  [_ARROW] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MEDIA] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_STOP, _______, _______, _______, _______,
    _______, _______, _______, RESET,   _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRIU, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MFFD, KC_BRID, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FUNCTION] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUMPAD] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, KC_NLCK, _______, KC_PEQL, KC_PSLS, KC_PAST, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______,
    _______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, KC_PENT,
    _______, _______, _______, _______, KC_DEL,  KC_BSPC, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_COMM, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_P0,   KC_PDOT, _______, _______, _______
  ),

  [_SYMBOL] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, KC_PIPE, KC_AMPR, KC_ASTR, KC_EQL,  _______, _______, _______,
    _______, _______, KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, _______, _______, KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_ENT,  _______, _______,
    _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_MINS, KC_EXLM, KC_AT,   KC_HASH, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT,  _______, _______, _______
  ),

};

#define LSHIFT_MASK (MOD_BIT(KC_LSHIFT))
#define RSHIFT_MASK (MOD_BIT(KC_RSHIFT))
#define SHIFT_MASK (LSHIFT_MASK | RSHIFT_MASK)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    // ',' -> '?'
    case KC_COMMA:
      if (keyboard_report->mods & SHIFT_MASK) {
        if (record->event.pressed) {
          register_code(KC_SLASH);
        } else {
          unregister_code(KC_SLASH);
        }
        return false;
      }
      break;

    // '.' -> '!'
    case KC_DOT:
      if (keyboard_report->mods & SHIFT_MASK) {
        if (record->event.pressed) {
          register_code(KC_1);
        } else {
          unregister_code(KC_1);
        }
        return false;
      }
      break;

    // '/' => '\'
    case KC_SLASH:
      if (keyboard_report->mods & SHIFT_MASK) {
        if (record->event.pressed) {
          if (keyboard_report->mods & LSHIFT_MASK) {
            unregister_code(KC_LSHIFT);
            register_code(KC_BSLASH);
            register_code(KC_LSHIFT);
          } else if (keyboard_report->mods & RSHIFT_MASK) {
            unregister_code(KC_RSHIFT);
            register_code(KC_BSLASH);
            register_code(KC_RSHIFT);
          }
        } else {
          unregister_code(KC_BSLASH);
        }
        return false;
      }
      break;
  }

  return true;
}

void led_set_keymap(uint8_t usb_led) {
  // Enable Num Lock if it's not already enabled
  if (!(usb_led & (1 << USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    capslock_led_on();
  } else {
    capslock_led_off();
  }
}
