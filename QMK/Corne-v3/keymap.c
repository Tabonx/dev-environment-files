/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
QMK Keycodes for MacOS with Czech layout

S(KC_1) = 1

S(KC_2) = 2

S(KC_3) = 3

S(KC_4) = 4

S(KC_5) = 5

S(KC_6) = 6

S(KC_7) = 7

S(KC_8) = 8

S(KC_9) = 9

S(KC_0) = 0

KC_1 = +

KC_2 = ě

KC_3 = š

KC_4 = č

KC_5 = ř

KC_6 = ž

KC_7 = ý

KC_8 = á

KC_9 = í

KC_0 = é

KC_SCLN = ů

S(KC_SCLN) = "

ALGR(KC_SCLN) = ;

S(ALGR(KC_SCLN)) = …

KC_LBRC = ú

S(KC_LBRC) = /

ALGR(KC_LBRC) = [

S(ALGR(KC_LBRC)) = ‹

KC_RBRC = )

S(KC_RBRC) = (

ALGR(KC_RBRC) = ]

S(ALGR(KC_RBRC)) = ›

KC_QUOT = §

S(KC_QUOT) = !

ALGR(KC_QUOT) = '

S(ALGR(KC_QUOT)) = ~

ALGR(KC_2) = @

ALGR(KC_3) = #

ALGR(KC_4) = $

ALGR(KC_5) = ~

ALGR(KC_6) = ^

ALGR(KC_7) = &

ALGR(KC_8) = *

ALGR(KC_9) = {

ALGR(KC_0) = }

KC_MINS = =

S(KC_MINS) = %

S(ALGR(KC_MINS)) = ,

S(KC_EQL) = ˇ

S(ALGR(KC_EQL)) = - ?(Minus)?

KC_EQL = '

KC_BSLS = ¨

S(KC_BSLS) = `

ALGR(KC_BSLS) = ¨

S(ALGR(KC_BSLS)) = ""

KC_COMM = ,

S(KC_COMM) = ?

ALGR(KC_COMM) = <

S(ALGR(KC_COMM)) = ≤

KC_DOT = .

S(KC_DOT) = :

ALGR(KC_DOT) = >

S(ALGR(KC_DOT)) = ≥

KC_MINS = - (Minus)

S(KC_MINS) = _ (Underscore)

ALGR(KC_MINS) = – (Dash)

S(ALGR(KC_MINS)) = — (Em Dash)

KC_GRV = \

KC_PIPE = `

KC_NUBS =  >< button

*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ESC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_EQL, KC_EQL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_LBRC, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(1), KC_ENT, KC_SPC, KC_BSPC, MO(2)
        //`--------------------------'  `--------------------------'

        ),

    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, S(KC_QUOT), ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), ALGR(KC_5), ALGR(KC_6), ALGR(KC_7), ALGR(KC_8), ALGR(KC_9), ALGR(KC_0), S(KC_MINS),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_SLSH, KC_MINS, S(KC_SCLN), ALGR(KC_LBRC), ALGR(KC_RBRC), KC_GRV,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), XXXXXXX, KC_1, S(KC_LBRC), S(KC_RBRC), KC_RBRC, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_ENT, KC_SPC, KC_BSPC, MO(3)
        //`--------------------------'  `--------------------------'
        ),

    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, KC_GRV,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUBS,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(3), KC_ENT, KC_SPC, KC_BSPC, _______
        //`--------------------------'  `--------------------------'
        ),

    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_ENT, KC_SPC, OSM(MOD_HYPR), _______
        //`--------------------------'  `--------------------------'
        )};
