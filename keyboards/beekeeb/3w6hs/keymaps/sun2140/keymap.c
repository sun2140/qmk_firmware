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

#define OSL_LIG OSL(_LIGATURES)

enum layers {
    _ALPHA_ERGOL,
    _LIGATURES,
    _CFG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ERGOL] = LAYOUT_split_3x5_3(
        LT(_CFG,FR_Q), FR_C, FR_O,         FR_P,   FR_W,        FR_J,    FR_M,   FR_D,         OSL_LIG,     FR_Y,
        FR_A,          FR_S, LSFT_T(FR_E), FR_N,   FR_F,        FR_L,    FR_R,   RSFT_T(FR_T), FR_I,        FR_U,
        FR_Z,          FR_X, FR_MINS,      FR_V,   FR_B,        FR_DOT,  FR_H,   FR_G,         FR_COMM,     FR_K,

                             XXXXXXX,      KC_ESC, KC_SPC,      KC_BSPC, KC_ENT, XXXXXXX
    ),
    [_LIGATURES] = LAYOUT_split_3x5_3(
        XXXXXXX,    XXXXXXX, ALGR(FR_O), XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        ALGR(FR_A), XXXXXXX, KC_LSFT,    XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_RSFT, XXXXXXX, XXXXXXX,
        XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX,    _______, XXXXXXX,        XXXXXXX, _______, XXXXXXX
    ),
    [_CFG] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, QK_REBOOT, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                         XXXXXXX, _______, XXXXXXX,     XXXXXXX, _______, XXXXXXX
    ),
};

const key_override_t shift_backspace_is_del = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t shift_hyphen_is_question_mark = ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_QUES);
const key_override_t shift_dot_is_colon = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_COLN);
const key_override_t shift_comma_is_semicolon = ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_SCLN);
const key_override_t shift_osl_ligatures_is_exclamation = ko_make_basic(MOD_MASK_SHIFT, OSL_LIG, FR_EXLM);

const key_override_t shift_oe_is_capital_oe = ko_make_basic(MOD_MASK_SHIFT, ALGR(FR_O), SAGR(FR_O));
const key_override_t shift_ae_is_capital_ae = ko_make_basic(MOD_MASK_SHIFT, ALGR(FR_A), SAGR(FR_A));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&shift_backspace_is_del,
    &shift_hyphen_is_question_mark,
	&shift_osl_ligatures_is_exclamation,
	&shift_dot_is_colon,
	&shift_comma_is_semicolon
};
