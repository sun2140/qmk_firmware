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

enum layers {
    _ALPHA_ERGOL,
    _CFG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ERGOL] = LAYOUT_split_3x5_3(
        LT(_CFG,FR_Q), FR_C, FR_O,         FR_P,   FR_W,        FR_J,    FR_M,   FR_D,         FR_EXLM, FR_Y,
        FR_A,          FR_S, LSFT_T(FR_E), FR_N,   FR_F,        FR_L,    FR_R,   RSFT_T(FR_T), FR_I,    FR_U,
        FR_Z,          FR_X, FR_QUES,      FR_V,   FR_B,        FR_DOT,  FR_H,   FR_G,         FR_COMM, FR_K,

                             XXXXXXX,      KC_ESC, KC_SPC,      KC_BSPC, KC_ENT, KC_DEL
    ),
    [_CFG] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, QK_REBOOT, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                         XXXXXXX, _______, XXXXXXX,     XXXXXXX, _______, XXXXXXX
    ),
};
