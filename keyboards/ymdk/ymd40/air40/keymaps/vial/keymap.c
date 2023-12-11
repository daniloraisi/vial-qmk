/* Copyright 2022 Dennis Kruyt (dennis@kruyt.org)
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

enum {
    TD_ESC_CAPS,
};

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        TD(TD_ESC_CAPS),  KC_A,    KC_S,    KC_D,    KC_F,  KC_G, KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_CAPS,          KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_LOWER] = LAYOUT_ortho_4x12_1x2uC(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,       KC_ASTR,       KC_LPRN, KC_RPRN, KC_DEL,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,       KC_PLUS,       KC_LCBR, KC_RCBR, KC_PIPE,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  LSFT(KC_BSLS), LSFT(KC_BSLS), KC_HOME, KC_END,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV,       KC_MNXT,       KC_VOLD, KC_VOLU, KC_MPLY
    ),
    [_RAISE] = LAYOUT_ortho_4x12_1x2uC(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,  KC_BSLS, KC_BSLS, KC_PGUP, KC_PGDN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),
    [_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
        QK_BOOT, RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI, AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DB_TOGG,
        KC_TRNS, RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, AG_NORM, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

