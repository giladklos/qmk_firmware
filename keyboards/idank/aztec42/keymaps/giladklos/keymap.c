// Copyright 2022 LucW (@luc-languagetools)
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H
#include <stdio.h>
#include "features/achordion.h"

enum custom_keycodes {
    QMKPSSWD = SAFE_RANGE,
    CPPSTD,
    EQEQ,
    NEQ,
    LSEQ,
    GTEQ,

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
    switch (keycode) {
    case QMKPSSWD:
        if (record->event.pressed) {
            SEND_STRING_DELAY("Gtyk^^123KS",25);
        } else {
        }
        break;
    case CPPSTD:
        if (record->event.pressed) {
            SEND_STRING_DELAY("std::",25);
        } else {
        }
        break;
    case EQEQ:
        if (record->event.pressed) {
            SEND_STRING_DELAY("==",25);
        } else {
        }
        break;
    case NEQ:
        if (record->event.pressed) {
            SEND_STRING_DELAY("!=",25);
        } else {
        }
        break;
    case LSEQ:
        if (record->event.pressed) {
            SEND_STRING_DELAY("<=",25);
        } else {
        }
        break;
    case GTEQ:
        if (record->event.pressed) {
            SEND_STRING_DELAY(">=",25);
        } else {
        }
        break;
    }
    return true;
};
// ACHORDION SETUP
void matrix_scan_user(void) {
  achordion_task();
}

// void keyboard_post_init_user(void) {
//     // Set RGB Underglow to Swirl Effect
//     rgblight_mode(RGBLIGHT_MODE_TWINKLE);


//     // Set RGB Matrix to Solid Reactive Wide Effect
//     rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_WIDE);
// }



// LAYERS SETUP

enum keymap_layers{
LAYER_BASE = 0,
LAYER_NUM,
LAYER_SYM,
LAYER_FUN,
LAYER_MOUSE,
LAYER_NAV,
LAYER_MEDIA,
};

// layer movement defenitions

#define L_NUM LT(LAYER_NUM, KC_BSPC)
#define L_SYM LT(LAYER_SYM, KC_ENT)
#define L_FUN LT(LAYER_FUN, KC_DELETE)
#define L_MOUSE LT(LAYER_MOUSE, KC_TAB) 
#define L_NAV LT(LAYER_NAV, KC_SPC)
#define L_MEDIA LT(LAYER_MEDIA, KC_ESC)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)

// to build: qmk compile -kb crkbd/rev1 -km dvorak_42_key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_TAB,   KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,                         KC_Y,   KC_U,   KC_I,     KC_O,    KC_P,    KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_LSFT,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                         KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,   KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                          KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,   KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        L_MEDIA, L_MOUSE, L_NAV,      L_NUM,  L_SYM,   L_FUN
                                      //`--------------------------'  `--------------------------'

  ),

  [LAYER_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS, KC_LEFT_BRACKET,  KC_7,    KC_8,    KC_9,    KC_RIGHT_BRACKET,    EQEQ,    NEQ,     LSEQ,    GTEQ,    KC_LT,   KC_GT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_SEMICOLON,     KC_4,    KC_5,    KC_6,    KC_EQUAL,            KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_PEQL, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_GRAVE,         KC_1,    KC_2,    KC_3,    KC_BACKSLASH,        KC_LCBR, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_DOT,  KC_0, KC_MINUS,      XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),


  [LAYER_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),


  [LAYER_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
    KC_TRNS, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                           |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,              XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'            `--------------------------'
  ),

  [LAYER_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
    XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                                     REDO,    PASTE,   KC_MS_UP,   CUT,     UNDO,    KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                 |--------+--------+--------+--------+--------+--------|
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                        CUT,     KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                 |--------+--------+--------+--------+--------+--------|
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX,  XXXXXXX, XXXXXXX,                  KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2
                                      //`--------------------------'                `--------------------------'
  ),

  [LAYER_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                   REDO,    PASTE,   KC_UP,   CUT,     UNDO,    KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                   CUT,     KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                   KC_HOME,    KC_PGUP, KC_PGDN, KC_END,  KC_INS,  KC_TRNS,
//|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX,  XXXXXXX, XXXXXXX,               KC_ENT, KC_BSPC, KC_DELETE
                                      //`--------------------------'            `--------------------------'
  ),
  
  [LAYER_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  XXXXXXX,   XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,                    UG_TOGG,   UG_NEXT,  UG_HUEU,   UG_HUED,  UG_SATU,  UG_SATD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_MNXT, KC_MPLY,  KC_MPRV,   XXXXXXX,  UG_VALU,  UG_VALD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,                  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  CPPSTD,  QMKPSSWD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  /*
  // empty layer
  [15] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
  */


};