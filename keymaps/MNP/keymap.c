// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END 4

enum layer_names {
    _Macro_ = 0,
    _NumPad_ = 1,
    _Media_ = 2,
    _Gaming_ = 3
};

#ifdef OLED_ENABLE 

bool oled_task_user() {

    oled_set_cursor(0, 1); 
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _Macro_ :
            oled_write("Macro", false);
            break;
        case _NumPad_ :
            oled_write("Num/Calc", false);
            break;
        case _Gaming_ : 
            oled_write("Gaming", false);
            break;
        case _Media_ :
            oled_write("Media", false);
            break;
        default:
            oled_write("Undefined", false);
    } 
    
    led_t led_state = host_keyboard_led_state(); 
    oled_write_P(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("NAV "), false);
    
    return false;
    
}

#endif



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ X │ X │ACT│LYR│
     * ├───┼───┼───┼───┤
     * │NUM│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 8 │ + │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ + │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ENT│
     * ├───┼───┼───┼───┤
     * │B S│ 0 │ . │ENT│
     * └───┴───┴───┴───┘
     */
    
    // Macro Layer 
    [_Macro_] = LAYOUT(
        KC_NO, KC_NO, KC_NO, TO(_NumPad_),
        KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_P4, KC_P5, KC_P6, KC_NO,
        KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_NO, KC_P0, KC_PDOT, KC_NO
    ),

    // Numpad/Calculator Layer

    [_NumPad_] = LAYOUT(
        KC_NO, KC_NO, KC_CALC, TO(_Media_),
        KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_P4, KC_P5, KC_P6, KC_NO,
        KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_BSPC, KC_P0, KC_PDOT, KC_NO
    ),

    [_Media_] = LAYOUT(
        KC_NO, KC_NO, KC_CALC, TO(_Gaming_),
        KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_P4, KC_P5, KC_P6, KC_NO,
        KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_BSPC, KC_P0, KC_PDOT, KC_NO
    ),

    [_Gaming_] = LAYOUT(
        KC_NO, KC_NO, KC_CALC, TO(_Macro_),
        KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_P4, KC_P5, KC_P6, KC_NO,
        KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_BSPC, KC_P0, KC_PDOT, KC_NO
    )

};