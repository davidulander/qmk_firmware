// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // Symbols
#define ARRW 2 // Arrows
#define MOUS 3 // Mouse


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  | 3/L3 |   4  |   5  |   @  |           |   $  |   6  |   7  | 8/L3 |   9  |   0  |   ?+   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | TAB  |           | Del  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | NO     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------| BkSp |           | BkSp |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  |   NO   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  NO  | Ctrl |  Alt |  CMD |Space |                                       |Space |   NO |   NO |   NO |   NO  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  NO  |  NO  |       |  NO  |  NO  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  NO  |       |  NO  |        |      |
 *                                 | Space|BSpace|------|       |------|  CMD   |Enter |
 *                                 | /L2  |      |WSpace|       | Ctrl |        | /L1  |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,           KC_1,             KC_2,             LT(MOUS,KC_3),        KC_4,               KC_5,               LALT(KC_2),
        KC_TAB,           KC_Q,             KC_W,             KC_E,                 KC_R,               KC_T,               KC_TAB,
        KC_NO,            KC_A,             KC_S,             KC_D,                 KC_F,               KC_G,
        KC_LSFT,          KC_Z,             KC_X,             KC_C,                 KC_V,               KC_B,               KC_BSPC,
        KC_NO,            KC_LCTL,          KC_LALT,          KC_LGUI,                KC_SPC,
                                                                                      KC_NO,     KC_NO,
                                                                                      KC_NO,
                                                                              KC_SPC, KC_BSPC,   LALT(KC_BSPC),
        // right hand
             LALT(KC_4),  KC_6,           KC_7,           LT(MOUS,KC_8),  KC_9,           KC_0,             KC_MINS,
             KC_DEL,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,             KC_LBRACKET,
                          KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,        KC_QUOTE,
             KC_BSPC,     KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,          KC_NO,
                                          KC_SPC,         KC_NO,          KC_NO,          KC_NO,            KC_NO,
             KC_NO,     KC_NO,
             KC_NO,
             KC_LCTL,   KC_LGUI, LT(SYMB,KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    ~   |   !  |   "  |   [  |   ]  |   =  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    %   |   /  |   '  |   (  |   )  |   |  |------|           |------| Down |   4  |   5  |   6  |   +  |   /    |
 * |--------+------+------+------+------+------| BkSp |           | BkSp |------+------+------+------+------+--------|
 * |    <   |   >  |   `  |   {  |   }  |   &  |      |           |      |   /  |   1  |   2  |   3  |   -  |   <    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  ^   |   #  |   $   |PgDown|Space|                                       |Space | PgUp |   0  |   =  |   '  |
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
       KC_NO,    	   KC_F1,          KC_F2,      	   KC_F3,   	 KC_F4,   	    KC_F5,   	    KC_NO,
       RALT(KC_RBRC),  RSFT(KC_1),     RSFT(KC_2),	   RALT(KC_8), 	 RALT(KC_9), 	RSFT(KC_0),     KC_NO,
       RSFT(KC_5),     RSFT(KC_7),     KC_BSLS,        RSFT(KC_8),   RSFT(KC_9),    RALT(KC_7),
       KC_GRAVE, 	   RSFT(KC_GRAVE), KC_PLUS,        LSA(KC_8), 	 LSA(KC_9), 	RSFT(KC_6),     KC_TRNS,
       RSFT(KC_RBRC),  RSFT(KC_3),     RALT(KC_4),     KC_PGDN,      KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,              KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,     RSFT(KC_BSLS),       KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,     KC_MINS,             RSFT(KC_7),
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,     KC_SLSH,             KC_TRNS,
                         KC_TRNS ,KC_PGUP,KC_0,     RSFT(KC_0),          KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: ARROWS and MEDIA
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | PgUp |CMD-UP| Up   |CMDDWN| PdDn |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Shft | Ctrl | Alt  | CMD  |------|           |------|w/Left|Left  |Down  | Right|w/Rght|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Home |      | End  |      |        |
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
       KC_NO,    KC_NO,         KC_NO,       KC_NO,   KC_NO,          KC_NO,            KC_NO,
       KC_TRNS,  KC_PGUP,       LGUI(KC_UP), KC_UP,   LGUI(KC_DOWN),  KC_PGDN,          KC_NO,
                 RALT(KC_LEFT), KC_LEFT,     KC_DOWN, KC_RIGHT,       RALT(KC_RIGHT),   KC_NO,
       KC_TRNS,  KC_NO,         KC_HOME,     KC_NO,   KC_END,         KC_NO,            KC_NO,
                                KC_VOLD,     KC_VOLU, KC_MUTE,        KC_NO,            KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: MOUSE
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Acc0 | ScUp | Acc1 |      |      |           |      |      |CMD-UP| MsUp |CMDDWN|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | ScLf | ScDn | ScLf |      |------|           |------|      | MsLf | MsDn | MsRt |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Click |lClick|------|       |------|lClick|Click |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUS] = LAYOUT_ergodox(
       KC_NO, KC_NO,   KC_NO,       KC_NO,      KC_NO,      KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_ACL0,     KC_WH_U,    KC_ACL1,    KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_WH_L,     KC_WH_D,    KC_WH_R,    KC_NO,
       KC_NO, KC_NO,   KC_NO,       KC_NO,      KC_NO,      KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_NO,       KC_NO,      KC_NO,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_NO,    KC_NO,   KC_NO,       KC_NO,      KC_NO,          KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,   LGUI(KC_UP), KC_MS_UP,   LGUI(KC_DOWN),  KC_NO,    KC_NO,
                 KC_NO,   KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,    KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,   KC_NO,       KC_NO,      KC_NO,          KC_NO,    KC_NO,
                          KC_NO,       KC_NO,      KC_NO,          KC_NO,    KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN2, KC_BTN1
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
    case MOUS:
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
  }

};
