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

#include QMK_KEYBOARD_H

// Currently compiled with my QMK fork
#include "sendstring_czech_mac_ansi.h"
#include "keymap_czech_mac_ansi.h"

#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_HYPR OSM(MOD_HYPR)

#define HM_A LGUI_T(CZ_A)   // Hold for Command, tap for 'a'
#define HM_S LALT_T(CZ_S)   // Hold for Option, tap for 's'
#define HM_D LCTL_T(CZ_D)   // Hold for Control, tap for 'd'
#define HM_F LSFT_T(CZ_F)   // Hold for Shift, tap for 'f'

#define HM_J RSFT_T(CZ_J)   // Hold for Shift, tap for 'j'
#define HM_K RCTL_T(CZ_K)   // Hold for Control, tap for 'k'
#define HM_L RALT_T(CZ_L)   // Hold for Option, tap for 'l'
#define HM_SCLN RGUI_T(KC_EQL) // Hold for Command, tap for ';'

#define HM_1 LGUI_T(CZ_1)   // Hold for Command, tap for '1'
#define HM_2 LALT_T(CZ_2)   // Hold for Option, tap for '2'
#define HM_3 LCTL_T(CZ_3)   // Hold for Control, tap for '3'
#define HM_4 LSFT_T(CZ_4)   // Hold for Shift, tap for '4'

#define HM_EQL RSFT_T(CZ_EQL)   // Hold for Shift, tap for '='
#define HM_DQUO RCTL_T(CZ_DQUO)   // Hold for Control, tap for '"'
#define HM_LBRC RALT_T(CZ_LBRC)   // Hold for Option, tap for '['
#define HM_RBRC RGUI_T(CZ_RBRC) // Hold for Command, tap for ']'

enum layers{
  _DEFAULT = 0,
  _GAME,
  _GAMESYMBOL,
  _SYMBOL,
 _CZSYM,
  _FUNCTION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    CZ_Q,    CZ_W,    CZ_E,    CZ_R,    CZ_T,                         CZ_Z,    CZ_U,    CZ_I,    CZ_O,   CZ_P,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    HM_A,    HM_S,    HM_D,    HM_F,    CZ_G,                         CZ_H,    HM_J,    HM_K,    HM_L, HM_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSM_LSFT,    CZ_Y,    CZ_X,    CZ_C,    CZ_V,    CZ_B,                         CZ_N,    CZ_M, CZ_COMM,  CZ_DOT, CZ_BSLS,  KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_SYMBOL),  KC_ENT,      HYPR_T(KC_SPC), KC_BSPC, MO(_CZSYM)
                                      //`--------------------------'  `--------------------------'

  ),

    [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_RALT, CZ_EXLM,    CZ_AT,CZ_HASH,  CZ_DLR, CZ_TILD,                      CZ_CIRC, CZ_AMPR, CZ_ASTR, CZ_LCBR, CZ_RCBR,  CZ_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    HM_1,    HM_2,    HM_3,   HM_4,     CZ_5,                      CZ_MINS,  HM_EQL, HM_DQUO, HM_LBRC, HM_RBRC, CZ_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSM_LSFT,    CZ_6,    CZ_7,    CZ_8,    CZ_9,    CZ_0,                      CZ_QUOT, CZ_PLUS, CZ_SLSH, CZ_LPRN, CZ_RPRN, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_ENT,     KC_SPC,  KC_BSPC , MO(_FUNCTION)
                                      //`--------------------------'  `--------------------------'
  ),

    [_CZSYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, CZ_ECAR, CZ_SCAR, CZ_CCAR, CZ_RCAR,                      CZ_ZCAR, CZ_YACU, CZ_AACU, CZ_IACU, CZ_EACU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LGUI, KC_RALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSM_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_FUNCTION),  KC_ENT,     KC_SPC, KC_BSPC, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUNCTION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                    DF(_GAME), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_ENT,     KC_SPC,OSM_HYPR, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    CZ_Q,    CZ_W,    CZ_E,    CZ_R,    CZ_T,                         CZ_Z,    CZ_U,    CZ_I,    CZ_O,   CZ_P,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_RALT,    CZ_A,    CZ_S,    CZ_D,    CZ_F,    CZ_G,                         CZ_H,    CZ_J,    CZ_K,    CZ_L,  KC_EQL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    CZ_Y,    CZ_X,    CZ_C,    CZ_V,    CZ_B,                         CZ_N,    CZ_M, CZ_COMM,  CZ_DOT, CZ_BSLS,  KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC,   MO(_GAMESYMBOL),  KC_LGUI,      HYPR_T(KC_SPC), KC_BSPC, DF(_DEFAULT)
                                      //`--------------------------'  `--------------------------'
  ),
    [_GAMESYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_RALT, CZ_EXLM,    CZ_AT,CZ_HASH,  CZ_DLR, CZ_TILD,                      CZ_CIRC, CZ_AMPR, CZ_ASTR, CZ_LCBR, CZ_RCBR,  CZ_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,   CZ_PLUS,    CZ_ECAR,    CZ_SCAR,   CZ_CCAR,     CZ_RCAR,                      CZ_MINS,  CZ_EQL, CZ_DQUO, CZ_LBRC, CZ_RBRC, CZ_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSM_LSFT,   CZ_ZCAR,    CZ_YACU,    CZ_AACU,    CZ_IACU,    CZ_EACU,                      CZ_QUOT, CZ_PLUS, CZ_SLSH, CZ_LPRN, CZ_RPRN, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_ENT,     KC_SPC,  KC_BSPC , MO(_FUNCTION)
                                      //`--------------------------'  `--------------------------'
  ),

};

// Needed because Mod-Tap doesn't work with shifted keys
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_1:
            if (!record->tap.count && record->event.pressed) {
                // Hold: Send LGUI (Command)
                tap_code16(KC_LGUI);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                // Tap: Send Shift + CZ_1 (Shifted '1' instead of '+')
                tap_code16(CZ_1); 
                return false;
            }
            return true;

        case HM_2:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_LALT);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                tap_code16(CZ_2);
                return false;
            }
            return true;

        case HM_3:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_LCTL);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                tap_code16(CZ_3);
                return false;
            }
            return true;

        case HM_4:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_LSFT);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                tap_code16(CZ_4);
                return false;
            }
            return true;

        case HM_EQL:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_RSFT);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                tap_code16(CZ_EQL);
                return false;
            }
            return true;

        case HM_DQUO:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_RCTL);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                tap_code16(CZ_DQUO);
                return false;
            }
            return true;

        case HM_LBRC:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_RALT);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                tap_code16(CZ_LBRC);
                return false;
            }
            return true;

        case HM_RBRC:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_RGUI);
                return false;
            } else if (record->tap.count && record->event.pressed) {
                tap_code16(CZ_RBRC);
                return false;
            }
            return true;
    }

    return true;
}
