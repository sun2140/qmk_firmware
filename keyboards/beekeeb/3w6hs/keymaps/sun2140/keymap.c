/* Copyright 2021 weteor
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

#include "keymap_french.h"
#include "process_key_override.h"

#define FR_AE ALGR(FR_A)
#define FR_OE ALGR(FR_O)

// Left hand
#define LT_Q LT(_CFG,FR_Q)      // Top row
#define S_TAB S(KC_TAB)

#define LGUI_XX LGUI_T(XXXXXXX) // Home row
#define LALT_XX LALT_T(XXXXXXX) // Home row
#define LCTL_XX LCTL_T(XXXXXXX) // Home row
#define LSFT_XX LSFT_T(XXXXXXX) // Home row

#define LT_A LGUI_T(FR_A) // Home row
#define LT_S LALT_T(FR_S) // Home row
#define LT_E LCTL_T(FR_E) // Home row
#define LT_N LSFT_T(FR_N) // Home row

#define LT_BSPC LT(_NAV_NUM,KC_BSPC)  // Thumb cluster
#define LT_TAB LT(_SYM, KC_TAB)       // Thumb cluster

// Right hand
#define OSL_DK OSL(_DEAD)  // Top row

#define RSFT_XX RSFT_T(XXXXXXX) // Home row
#define RCTL_XX RCTL_T(XXXXXXX) // Home row
#define RALT_XX RALT_T(XXXXXXX) // Home row
#define RGUI_XX RGUI_T(XXXXXXX) // Home row

#define LT_R LSFT_T(FR_R) // Home row
#define LT_T LCTL_T(FR_T) // Home row
#define LT_I LALT_T(FR_I) // Home row
#define LT_U LGUI_T(FR_U) // Home row


#define LT_SPC LT(_NAV_NUM, KC_SPC)   // Thumb cluster
#define LT_ENT LT(_SYM, KC_ENT)       // Thumb cluster

enum layers {
    _ALPHA,
    _SYM,
    _NAV_NUM,
    _FUN,
    _DEAD,
    _CFG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA] = LAYOUT_split_3x5_3(
           LT_Q,    FR_C,    FR_O,    FR_P,    FR_W,            FR_J,    FR_M,    FR_D,  OSL_DK,    FR_Y,
           LT_A,    LT_S,    LT_E,    LT_N,    FR_F,            FR_L,    LT_R,    LT_T,    LT_I,    LT_U,
           FR_Z,    FR_X, FR_MINS,    FR_V,    FR_B,          FR_DOT,    FR_H,    FR_G, FR_COMM,    FR_K,
                          XXXXXXX, LT_TAB,  LT_BSPC,          LT_SPC,  LT_ENT, XXXXXXX
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        FR_CIRC, FR_LABK, FR_RABK,  FR_DLR, FR_PERC,           FR_AT, FR_AMPR, FR_ASTR, FR_QUOT,  FR_GRV,
        FR_LCBR, FR_LPRN, FR_RPRN, FR_RCBR,  FR_EQL,         FR_BSLS, FR_PLUS, FR_MINS, FR_SLSH, FR_DQUO,
        FR_TILD, FR_LBRC, FR_RBRC, FR_UNDS, FR_HASH,         FR_PIPE, FR_EXLM, FR_SCLN, FR_COLN, FR_QUES,
                          _______, _______, _______,         _______, _______, _______
    ),
    [_NAV_NUM] = LAYOUT_split_3x5_3(
         KC_TAB, KC_HOME,   KC_UP,  KC_END, KC_PGUP,         FR_SLSH,    FR_7,    FR_8,    FR_9, XXXXXXX,
        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,         FR_MINS,    FR_4,    FR_5,    FR_6,    FR_0,
        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU,   S_TAB,         FR_COMM,    FR_1,    FR_2,    FR_3,  FR_DOT,
                          _______, _______,  KC_DEL,         _______,  KC_ESC, _______
    ),
    [_FUN] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,
                          _______, _______, _______,         _______, _______, _______
    ),
    [_DEAD] = LAYOUT_split_3x5_3(
        XXXXXXX, FR_CCED,   FR_OE, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          FR_AE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,         _______, _______, _______
    ),
    [_CFG] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,  QK_RBT, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,         _______, _______, _______
    ),
};

const key_override_t shift_hyphen_is_question_mark =     ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_QUES);
const key_override_t shift_dot_is_colon =                ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_COLN);
const key_override_t shift_comma_is_semicolon =          ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_SCLN);
const key_override_t shift_osl_dead_key_is_exclamation = ko_make_basic(MOD_MASK_SHIFT, OSL_DK, FR_EXLM);
const key_override_t shift_rep_is_alt_rep =              ko_make_basic(MOD_MASK_SHIFT, QK_REP, QK_AREP);

// symbol layer
const key_override_t shift_opening_brace_is_closing_brace =             ko_make_basic(MOD_MASK_SHIFT, FR_LCBR, FR_RCBR);
const key_override_t shift_opening_bracket_is_closing_bracket =         ko_make_basic(MOD_MASK_SHIFT, FR_LBRC, FR_RBRC);
const key_override_t shift_opening_parenthesis_is_closing_parenthesis = ko_make_basic(MOD_MASK_SHIFT, FR_LPRN, FR_RPRN);

// num layer
const key_override_t shift_four_is_plus_sign =  ko_make_basic(MOD_MASK_SHIFT, FR_4, FR_PLUS);
const key_override_t shift_five_is_minus_sign = ko_make_basic(MOD_MASK_SHIFT, FR_5, FR_MINS);
const key_override_t shift_six_is_multiply_sign = ko_make_basic(MOD_MASK_SHIFT, FR_6, FR_ASTR);

const key_override_t shift_oe_is_capital_oe = ko_make_basic(MOD_MASK_SHIFT, FR_OE, S(FR_OE));
const key_override_t shift_ae_is_capital_ae = ko_make_basic(MOD_MASK_SHIFT, FR_AE, S(FR_AE));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &shift_osl_dead_key_is_exclamation,
    &shift_rep_is_alt_rep,
    &shift_hyphen_is_question_mark,
    &shift_dot_is_colon,
    &shift_comma_is_semicolon,
    &shift_opening_brace_is_closing_brace,
    &shift_opening_bracket_is_closing_bracket,
    &shift_opening_parenthesis_is_closing_parenthesis,
    &shift_four_is_plus_sign,
    &shift_five_is_minus_sign,
    &shift_six_is_multiply_sign,
    &shift_oe_is_capital_oe,
    &shift_ae_is_capital_ae
};
