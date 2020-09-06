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

// Colon (:)
#define KC_CLN LSFT(KC_SCLN)

// Double Quote (")
#define KC_DQT LSFT(KC_QUOT)

// Shift Tab
#define SFT_TAB LSFT(KC_TAB)

// Ctrl Space Mod Tap
#define CTL_SPC LCTL_T(KC_SPC)

// Tmux Keys
#define TMUX_PF LCTL(KC_SPACE)
#define TMUX_L  LCTL(KC_H)
#define TMUX_D  LCTL(KC_J)
#define TMUX_U  LCTL(KC_K)
#define TMUX_R  LCTL(KC_L)

// Layers
#define _COLEMAK  (0)
#define _QWERTY   (1)
#define _ARROW    (2)
#define _MEDIA    (3)
#define _FUNCTION (4)
#define _NUMPAD   (5)
#define _SYMBOL   (6)
#define _TMUX     (7)

// Default Layers
#define QWERTY  DF(QWERTY_LAYER)
#define COLEMAK DF(COLEMAK_LAYER)

// Momentary Layer Keys
#define ARROWS  MO(ARROW_LAYER)
#define LAMBDA  MO(FUNCTION_LAYER)
#define MEDIA   MO(MEDIA_LAYER)
#define MOUSE   MO(MOUSE_LAYER)
#define NUMPAD  MO(NUMPAD_LAYER)
#define SYMBOLS MO(SYMBOL_LAYER)
#define TMUX    MO(TMUX_LAYER)

enum custom_layers {
  COLEMAK_LAYER,
  QWERTY_LAYER,
  ARROW_LAYER,
  MEDIA_LAYER,
  FUNCTION_LAYER,
  NUMPAD_LAYER,
  SYMBOL_LAYER,
  TMUX_LAYER
};

enum {
  CAP
};

void dance_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code(KC_CAPS);
  } else {
    layer_on(ARROW_LAYER);
  }
}

void dance_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    unregister_code(KC_CAPS);
  } else {
    layer_off(ARROW_LAYER);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [CAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_caps_finished, dance_caps_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_ortho_5x15(
    KC_ESC,  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    QWERTY,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  KC_BSPC,
    SFT_TAB, KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_GRV,  _______,
    NUMPAD,  ARROWS,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
    MEDIA,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT, _______,
    KC_LCTL, KC_LCTL, _______, MEDIA,   KC_LCTL, KC_LGUI, KC_SPC,  KC_LSFT, SYMBOLS, KC_LALT, KC_LALT, _______, _______, _______, _______
  ),

  [_QWERTY] = LAYOUT_ortho_5x15(
    KC_ESC,  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    COLEMAK, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  KC_BSPC,
    SFT_TAB, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,  _______,
    NUMPAD,  ARROWS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    MEDIA,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT, _______,
    KC_LCTL, KC_LCTL, _______, MEDIA,   KC_LCTL, KC_LGUI, KC_SPC,  KC_LSFT, SYMBOLS, KC_LALT, KC_LALT, _______, _______, _______, _______
  ),

  [_ARROW] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  KC_BSPC, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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
    _______, _______, KC_GRV,  KC_TILD, KC_LCBR, KC_RCBR, KC_SLSH, _______, KC_PIPE, KC_AMPR, KC_ASTR, KC_EQL,  KC_CLN,  _______, _______,
    NUMPAD,  _______, KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, KC_ESC,  _______, KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_ENT,  KC_DQT,  _______,
    _______, _______, SFT_TAB, KC_TAB,  KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_MINS, KC_EXLM, KC_AT,   KC_HASH, KC_TAB,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT,  _______, _______, _______
  ),

  [_TMUX] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, TMUX_L,  TMUX_D,  TMUX_U,  TMUX_R,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, TMUX_PF, _______, TMUX_PF, _______, _______, _______, _______, _______, _______
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
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_SLASH);
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
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_1);
      }
      break;
  }

  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // [p]rint [u]sername
    SEQ_TWO_KEYS(KC_P, KC_U) {
      SEND_STRING("nutty7t");
    }

    // [p]rint [p]gp fingerprint
    SEQ_TWO_KEYS(KC_P, KC_P) {
      SEND_STRING("6CA54B7A2A23A66A");
    }
  }
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
