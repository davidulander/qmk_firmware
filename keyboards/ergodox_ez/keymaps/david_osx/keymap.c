// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define ARRW 2 // Arrows

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |   @  |           |   $  |   6  |   7  |   8  |   9  |   0  |   ?+   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | TAB  |           | Del  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | NO     |   A  |Shft/S|Ctrl/D|F/Alt |G/CMD |------|           |------|Shft/H|Ctrl/J|Alt/K |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------| BkSp |           | BkSp |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  | B/L2 |      |           |      |   N  |   M  |   ,  |   .  |-/Ctrl|   <    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt |  CMD  | NO | Space/L1 |                                   |Space/L1|  NO  |   ¨^  |   ´` |  '   |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  | LGui |       | Alt  |Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Enter | CMD  |------|       |------|  CMD   |Space |
 *                                 | /L2  |      | End  |       | PgDn |        | /L1  |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,           KC_1,             KC_2,             KC_3,         KC_4,       KC_5,       LALT(KC_2),
        KC_TAB,           KC_Q,             KC_W,             KC_E,         KC_R,       KC_T,       KC_TAB,
        KC_NO,            KC_A,             LSFT_T(KC_S),     CTL_T(KC_D),  ALT_T(KC_F),LGUI_T(KC_G),
        KC_LSFT,          KC_Z,             KC_X,             KC_C,         KC_V,       LT(ARRW,KC_B),       KC_BSPC,
        KC_LCTL,          KC_LALT,      KC_LGUI,           KC_NO,   LT(SYMB,KC_SPC),
                                                       KC_LALT, KC_LGUI,
                                                                KC_HOME,
                                              LT(ARRW,KC_ENT),  KC_LGUI, KC_END,
        // right hand
             LALT(KC_4),  KC_6,           KC_7,           KC_8,           KC_9,           KC_0,             KC_MINS,
             KC_DEL,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,             KC_LBRACKET,
                          RSFT_T(KC_H),   CTL_T(KC_J),    ALT_T(KC_K),    KC_L,           KC_SCOLON,        KC_QUOTE,
             KC_BSPC,     KC_N,           KC_M,           KC_COMM,        KC_DOT,         CTL_T(KC_SLSH),   KC_NUBS,
                                          LT(SYMB,KC_SPC),KC_NO,          KC_RBRC,        KC_EQL,           KC_BSLS,
             KC_LALT,   KC_LCTL,
             KC_PGUP,
             KC_PGDN,   KC_LGUI, LT(SYMB,KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    &   |   !  |   "  |   '  |   [  |   ]  |   `  |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    %   |   /  |   {  |   }  |   (  |   )  |------|           |------| Down |   4  |   5  |   6  |   +  |    /   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    &   |   <  |   >  |   =  |   |  |   ~  |      |           |      |   /  |   1  |   2  |   3  |   -  |   <    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |PgDown| HOME |                                       | END  | PgUp |   0  |   =  |   ' |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_NO,    	KC_F1,       KC_F2,      	   KC_F3,   	KC_F4,   	    KC_F5,   	    KC_NO,
       RSFT(KC_6),  RSFT(KC_1),  RSFT(KC_2),	   KC_BSLS, 	RALT(KC_8), 	RALT(KC_9),     KC_PLUS,
       RSFT(KC_5),  RSFT(KC_7),  LSA(KC_8),        LSA(KC_9), 	RSFT(KC_8),     RSFT(KC_9),
       RSFT(KC_6),  KC_NUBS, 	 RSFT(KC_NUBS),	   RSFT(KC_0), 	RALT(KC_7), 	RALT(KC_RBRC),  KC_NO,
       KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_PGDN,     KC_HOME,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,              KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,     RSFT(KC_BSLS),       KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,     KC_MINS,             RSFT(KC_7),
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,     KC_SLSH,             KC_TRNS,
                         KC_END ,KC_PGUP, KC_0,     RSFT(KC_0),          KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: ARROWS and MEDIA
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Home | Up   | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Shft | Ctrl | Alt  | CMD  |------|           |------|      |Left  |Down  |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgUp |      | PdDn |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolDn |VolUp | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// ARROWS and MEDIA
[ARRW] = LAYOUT_ergodox(
       KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_NO,
       KC_NO,  KC_NO, KC_HOME, KC_UP,   KC_END,    KC_NO, KC_NO,
               KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_NO, KC_NO,
       KC_NO,  KC_NO, KC_PGUP, KC_NO,   KC_PGDN,   KC_NO, KC_NO,
                          KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case ARRW:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
