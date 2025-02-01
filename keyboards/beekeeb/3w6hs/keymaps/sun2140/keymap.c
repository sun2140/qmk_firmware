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

#define LGUI_XX LGUI_T(XXXXXXX) // Home row
#define LALT_XX LALT_T(XXXXXXX) // Home row
#define LCTL_XX LCTL_T(XXXXXXX) // Home row
#define LSFT_XX LSFT_T(XXXXXXX) // Home row

#define LT_A LGUI_T(FR_A) // Home row
#define LT_S LALT_T(FR_S) // Home row
#define LT_E LCTL_T(FR_E) // Home row
#define LT_N LSFT_T(FR_N) // Home row

#define LT_REP LT(_FUNC, QK_REP)   // Thumb cluster
#define LT_BSPC LT(_NUM, KC_BSPC)  // Thumb cluster
#define LT_ENT KC_ENT     // Thumb cluster

// Right hand
#define OSL_DK OSL(_DEAD)  // Top row

#define RSFT_XX RSFT_T(XXXXXXX) // Home row
#define RCTL_XX RCTL_T(XXXXXXX) // Home row
#define RALT_XX RALT_T(XXXXXXX) // Home row
#define RGUI_XX RGUI_T(XXXXXXX) // Home row

#define LT_R RSFT_T(FR_R) // Home row
#define LT_T RCTL_T(FR_T) // Home row
#define LT_I RALT_T(FR_I) // Home row
#define LT_U RGUI_T(FR_U) // Home row

#define LT_TAB KC_TAB  // Thumb cluster
#define LT_SPC KC_SPC     // Thumb cluster
#define LT_ESC LT(_SYM,KC_ESC)   // Thumb cluster

enum layers {
    _ALPHA,
    _SYM,
    _NUM,
    _FUNC,
    _DEAD,
    _CFG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA] = LAYOUT_split_3x5_3(
           LT_Q,    FR_C,    FR_O,    FR_P,    FR_W,            FR_J,    FR_M,    FR_D,  OSL_DK,    FR_Y,
           LT_A,    LT_S,    LT_E,    LT_N,    FR_F,            FR_L,    LT_R,    LT_T,    LT_I,    LT_U,
           FR_Z,    FR_X, FR_MINS,    FR_V,    FR_B,          FR_DOT,    FR_H,    FR_G, FR_COMM,    FR_K,
                           LT_REP, LT_BSPC,  LT_ENT,          LT_TAB,  LT_SPC,  LT_ESC
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        FR_QUOT,  FR_GRV, FR_DQUO, FR_CIRC, FR_TILD,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        FR_LABK, FR_LCBR, FR_LPRN, FR_LBRC, FR_BSLS,         XXXXXXX, RSFT_XX, RCTL_XX, RALT_XX, RGUI_XX,
        XXXXXXX, FR_HASH,   FR_AT, FR_AMPR, FR_PIPE,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______,  FR_DLR,         XXXXXXX, XXXXXXX, _______
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,    FR_7,    FR_8,    FR_9, XXXXXXX,
        LGUI_XX, LALT_XX, LCTL_XX, LSFT_XX, XXXXXXX,          FR_EQL,    FR_4,    FR_5,    FR_6, FR_SLSH,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,    FR_1,    FR_2,    FR_3, XXXXXXX,
                          XXXXXXX, _______, XXXXXXX,         FR_PERC,    FR_0, FR_UNDS
    ),
    [_FUNC] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12,
        LGUI_XX, LALT_XX, LCTL_XX, LSFT_XX, XXXXXXX,         XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10,
                          _______, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_DEAD] = LAYOUT_split_3x5_3(
        XXXXXXX, FR_CCED,   FR_OE, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,  QK_RBT, XXXXXXX,
          FR_AE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, RSFT_XX, RCTL_XX, RALT_XX, RGUI_XX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_CFG] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,  QK_RBT, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

const key_override_t shift_backspace_is_del =            ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
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
    &shift_backspace_is_del,
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
