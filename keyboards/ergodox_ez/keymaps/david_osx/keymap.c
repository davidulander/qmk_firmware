// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "sendstring_keymap_swedish.h"

#define BASE 0 // default layer
#define SYMB 1 // Symbols
#define ARRW 2 // Arrows
#define MOUS 3 // Mouse
#define NUMB 4 // Numbers

enum custom_keycodes {
    VAR = EZ_SAFE_RANGE,
    SH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   ?+   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  | E/L3 |   R  |   T  | ScUp |           |      |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  | S/L4 | D/L2 | F/L1 |   G  |------|           |------|   H  | J/L1 | K/Alt| L/CMD|   Ö  |   Ä    |
 * |--------+------+------+------+------+------| ScDn |           | ESC  |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  |   @    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Ctrl |  Alt |  CMD |                                       | Ctrl |      |      |      |       |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | ScLf | ScRt |       | Frwrd|       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Ref  |       | Back |       |      |
 *                                 | BSpc |  Del |------|       |------| Enter |Space |
 *                                 |      |      | SH   |       | F12  |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,           KC_1,             KC_2,             KC_3,                 KC_4,               KC_5,               KC_NO,
        KC_TAB,           KC_Q,             KC_W,             LT(MOUS,KC_E),        KC_R,               KC_T,               KC_WH_U,
        KC_NO,            KC_A,             LT(NUMB,KC_S),    LT(ARRW,KC_D),        LT(SYMB,KC_F),      KC_G,
        KC_LSFT,          KC_Z,             KC_X,             KC_C,                 KC_V,               KC_B,               KC_WH_D,
        KC_NO,            KC_NO,            KC_LCTL,          KC_LALT,              KC_LGUI,
                                                                                      KC_WH_L,              KC_WH_R,
                                                                                      SGUI(KC_F12),
                                                                                      KC_BSPC,  KC_DEL,     SH,
        // right hand
             KC_NO,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,             KC_MINS,
             KC_NO,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,             KC_LBRACKET,
                           KC_H,           LT(SYMB,KC_J),  LALT_T(KC_K),   LGUI_T(KC_L),   KC_SCOLON,        KC_QUOTE,
             KC_ESC,       KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,          LALT(KC_2),
                                           KC_RCTL,        KC_NO,          KC_NO,          KC_NO,            KC_NO,
             LCTL(KC_DOT),   KC_NO,
             LCTL(KC_SLSH),
             KC_F12, KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   %  |   [  |   ]  |   ?  |      |           |      |   *  |   "  |  =   |  |   |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   ~  |   (  |   )  |   !  |------|           |------|   /  |   '  |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   ^  |   {  |   }  |   $  |      |           |      |   \  |   `  |  -   |  #   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   <  |   >  |                                       |  ${} | Mute |VolDn |VolUp |      |
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
       KC_NO,  KC_F1,     KC_F2,      	  KC_F3,   	          KC_F4,   	     KC_F5,   	     KC_NO,
       KC_NO,  KC_NO,     RSFT(KC_5),	  RALT(KC_8), 	      RALT(KC_9), 	 RSFT(KC_MINS),  KC_NO,
       KC_NO,  KC_NO,     RALT(KC_RBRC),  RSFT(KC_8),         RSFT(KC_9),    RSFT(KC_1),
       KC_NO,  KC_NO,     RSFT(KC_RBRC),  LSA(KC_8), 	      LSA(KC_9), 	 RALT(KC_4),     KC_TRNS,
       KC_NO,  KC_NO,     KC_NO,          KC_GRAVE,           RSFT(KC_GRAVE),
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,          KC_F7,          KC_F8,      KC_F9,          KC_F10,       KC_F11,
       KC_TRNS, RSFT(KC_BSLS),  RSFT(KC_2),     RSFT(KC_0), RALT(KC_7),     KC_NO,        KC_F12,
                KC_AMPR,        KC_BSLS,        KC_MINS,    RSFT(KC_6),     KC_NO,        KC_NO,
       KC_TRNS, RALT(KC_AMPR),  KC_PLUS,        KC_SLSH,    RSFT(KC_3),     KC_NO,        KC_NO,
                                VAR,            KC_MUTE,    KC_VOLD,        KC_VOLU,      KC_NO,
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
 * |        |      | Shft |      | Alt  | CMD  |------|           |------|w/Left|Left  |Down  | Right|w/Rght|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Home |      | End  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// ARROWS and MEDIA
[ARRW] = LAYOUT_ergodox(
       KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_LSFT,  KC_NO,   KC_LALT, KC_LGUI,
       KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_TRNS,  KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_NO,    KC_NO,         KC_NO,          KC_NO,   KC_NO,          KC_NO,            KC_NO,
       KC_TRNS,  KC_PGUP,       LGUI(KC_UP),    KC_UP,   LGUI(KC_DOWN),  KC_PGDN,          KC_NO,
                 RALT(KC_LEFT), KC_LEFT,        KC_DOWN, KC_RIGHT,       RALT(KC_RIGHT),   KC_NO,
       KC_TRNS,  KC_NO,         LGUI(KC_LEFT),  KC_NO,   LGUI(KC_RIGHT),         KC_NO,            KC_NO,
                                KC_TRNS,        KC_TRNS, KC_TRNS,        KC_NO,            KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,
),
/* Keymap 3: MOUSE
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | ScUp | MsUp | ScDn |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Acc0 |      | Acc1 |      |------|           |------| ScLf | MsLf | MsDn | MsRt | ScRt |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|lClick|Click |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUS] = LAYOUT_ergodox(
       KC_NO, KC_NO,   KC_NO,       KC_NO,      KC_NO,      KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_NO,       KC_NO,      KC_NO,      KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_ACL0,     KC_NO,      KC_ACL1,    KC_NO,
       KC_NO, KC_NO,   KC_NO,       KC_NO,      KC_NO,      KC_NO, KC_NO,
       KC_NO, KC_NO,   KC_NO,       KC_NO,      KC_NO,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_NO,    KC_NO,   KC_NO,       KC_NO,      KC_NO,          KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,   KC_WH_U,     KC_MS_UP,   KC_WH_D,        KC_NO,    KC_NO,
                 KC_WH_L, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,    KC_WH_R,  KC_NO,
       KC_TRNS,  KC_NO,   KC_NO,       KC_NO,      KC_NO,          KC_NO,    KC_NO,
                          KC_NO,       KC_NO,      KC_NO,          KC_NO,    KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN2, KC_BTN1
),
/* Keymap 4: Number Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |       |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   =  |   7  |   8  |   9  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   *  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   /  |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NUMBERS
[NUMB] = LAYOUT_ergodox(
       // left hand
       KC_NO,      KC_NO,     KC_NO,      	KC_NO,   	   KC_NO,    KC_NO,   	KC_NO,
       KC_NO,      KC_NO,     KC_NO,	    KC_NO, 	       KC_NO, 	 KC_NO,     KC_NO,
       KC_NO,      KC_NO,     KC_NO,        KC_NO,         KC_NO,    KC_NO,
       KC_NO,      KC_NO,     KC_NO,        KC_NO, 	       KC_NO, 	 KC_NO,     KC_NO,
       KC_NO,      KC_NO,     KC_NO,        KC_NO,         KC_NO,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_NO, KC_NO,          KC_NO,  KC_NO,   KC_NO,    KC_NO,        KC_NO,
       KC_NO, RSFT(KC_0),     KC_7,   KC_8,    KC_9,     KC_SLSH,      KC_NO,
              RSFT(KC_BSLS),  KC_4,   KC_5,    KC_6,     KC_MINS,      KC_NO,
       KC_NO, KC_AMPR,        KC_1,   KC_2,    KC_3,     KC_NO,        KC_NO,
                              KC_0,   KC_NO,   KC_NO,    KC_NO,        KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
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
    case NUMB:
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
  }

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LT(SYMB,KC_F):
        //     return 300;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VAR:
        if (record->event.pressed) {
            SEND_STRING("$" SS_RSFT("[") SS_RSFT("]") SS_TAP(X_LEFT));
        } else {}
        break;
    case SH:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RCTL) SS_TAP(X_LBRACKET) SS_UP(X_RCTL));
        } else {}
        break;
    }
    return true;
};
