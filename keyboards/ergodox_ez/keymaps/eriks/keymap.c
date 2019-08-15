#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define ARRW 2 // arrow keys
#define MOUS 3 // mouse

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD,
  LCTL_AMP,
  LALT_EXCL,
  LSUP_QUOTE,
  LSFT_STPAR,
  BSLASH,
  LESSTHAN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |           | ´    |   7  |   8  |   9  |   0  |   +  | BackSp |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | Space|                                       | Space|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Alt  |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Ins  |       | PgUp |      |      |
 *                                 |Bspace| Tab  |------|       |------| Super|Enter |
 *                                 |      |      | Del  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE,        KC_1,        KC_2,          KC_3,    KC_4,               KC_5,            KC_EQL,
  KC_NO,           KC_Q,        KC_W,          KC_E,    KC_R,               KC_T,            KC_NO,
  KC_CAPSLOCK,     LCTL_T(KC_A),ALT_T(KC_S),   LGUI_T(KC_D),    LSFT_T(KC_F),       KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,               LT(ARRW, KC_B),  KC_NO,
  KC_NO,           KC_NO,       KC_NO,         LT(ARRW, KC_NO),   LT(SYMB, KC_SPACE),
                                                           KC_NO, KC_NO,
                                                                          KC_INSERT,
                                                         KC_BSPACE, KC_TAB, KC_DELETE,
  // right hand
  KC_BSLS,      KC_6,                  KC_7,         KC_8,        KC_9,              KC_0,          KC_MINS,
  KC_NO,        KC_Y,                  KC_U,         KC_I,        KC_O,              KC_P,              KC_LBRACKET,
                KC_H,                  RSFT_T(KC_J), ALGR_T(KC_K), LALT_T(KC_L),      RCTL_T(KC_SCOLON), KC_QUOTE,
  KC_NO,        LT(MOUS, KC_N),        KC_M,         KC_COMM,     KC_DOT,            CTL_T(KC_SLSH),    KC_RSFT,
  LT(SYMB, KC_SPACE),    LT(MOUS, KC_NO), KC_NO, KC_NO,  KC_NO,
  KC_VOLD, KC_VOLU,
  KC_NO,
  KC_ESC, KC_LGUI, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                    h
 LKHljk                    |Animat|      |       |Toggle|Solid |
 *                                         ------|------|------|       |------+------+------.
 *       ASsa<>"['|||       %!'(                          |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                     a                   |ness- |ness+ |------|       |------|      |      |
 *          d                              |      |      |      |       |      |      |      |
 *                     /\                   `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_NO,    	KC_F1,      	KC_F2,      		KC_F3,   	KC_F4,   	KC_F5,   	KC_NO,
  ALGR(KC_4),   RSFT(KC_3), 	ALGR(KC_NUBS),	RSFT(KC_2), 	RALT(KC_8), 	RALT(KC_9), 	KC_NO,
  RSFT(KC_5),  	LCTL_AMP, 	LALT_EXCL, 		LSUP_QUOTE, 	LSFT_STPAR, 	RSFT(KC_9),
  KC_NO,    	KC_NUBS, 	RSFT(KC_NUBS),	        RALT(KC_2), 	RALT(KC_7), 	RALT(KC_0), 	KC_NO,
  KC_NO,    	KC_NO,		KC_NO,    		KC_NO, 		KC_NO,
                                                           KC_NO, KC_NO,
                                                                          KC_INSERT,
                                                         KC_BSPACE, KC_TAB, KC_DELETE,
  // right hand
  KC_NO,   KC_F6,            KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
  KC_NO,   KC_NO,   	     KC_P7,    KC_P8,    KC_P9,    KC_KP_PLUS, KC_F12,
           LSFT(KC_7),       RSFT_T(KC_P4),    ALGR_T(KC_P5),    LALT_T(KC_P6),    RCTL_T(KC_KP_MINUS), KC_NO,
  KC_NO,   ALGR(KC_MINUS),   KC_P1,    KC_P2,    KC_P3,    KC_KP_ASTERISK,  KC_NO,
                             KC_P0,    KC_KP_DOT,KC_KP_EQUAL,KC_KP_SLASH,KC_NO,
  KC_VOLD, KC_VOLU,
  KC_NO,
  KC_ESC, KC_LGUI, KC_ENT
),
/* Keymap 2: Arrow keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | PgUp |      |  Up  | Home | End  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| PgDn | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
[ARRW] = LAYOUT_ergodox(
  // left hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSHIFT, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                               KC_NO, KC_NO,
                                                      KC_NO,
                                        KC_NO, KC_NO, KC_NO,
  // right hand
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,
  KC_NO, KC_NO,   KC_HOME, KC_UP,   KC_END,   KC_NO,  KC_NO,
         KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,  KC_NO,
  KC_NO, KC_NO,   KC_PGUP, KC_NO,   KC_PGDN,  KC_NO,  KC_NO,
                  KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_NO, KC_NO, KC_NO
),
/* Keymap 3: Mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      | Acc2 |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | MsLf | MsDn | MsRt | Acc1 |------|           |------|      | LClk | Rclk |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | ScUp | ScDn | Acc0 |      |           |      |      |      |      |      |      |        |
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
[MOUS] = LAYOUT_ergodox(
  // left hand
  KC_NO, KC_NO, KC_NO,      KC_NO,      KC_NO,        KC_NO,   KC_NO,
  KC_NO, KC_NO, KC_NO,      KC_MS_UP,   KC_NO,        KC_ACL2, KC_NO,
  KC_NO, KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,  KC_ACL1,
  KC_NO, KC_NO, KC_NO,      KC_WH_U,    KC_WH_D,      KC_ACL0, KC_NO,
  KC_NO, KC_NO, KC_NO,      KC_NO,      KC_NO,
                                               KC_NO, KC_NO,
                                                      KC_NO,
                                        KC_NO, KC_NO, KC_NO,
  // right hand
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,
         KC_NO,   KC_BTN1, KC_BTN2, KC_NO,    KC_NO,  KC_NO,
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,
                  KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_NO, KC_NO, KC_NO
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t lctl_amp_timer, lalt_excl_timer, lsup_quote_timer, lsft_endpar_timer;

  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
      case LESSTHAN:
	tap_code(0x38);
    }
  }
  switch (keycode) {
    case LCTL_AMP:
      if(record->event.pressed) {
          lctl_amp_timer = timer_read();
          register_code(KC_LCTL); // Change the key to be held here
        } else {
          unregister_code(KC_LCTL); // Change the key that was held here, too!
          if (timer_elapsed(lctl_amp_timer) < TAPPING_TERM) {
            SEND_STRING("^"); // Change the character(s) to be sent on tap here
          }
        }
        return false;
    case LALT_EXCL:
      if(record->event.pressed) {
          lalt_excl_timer = timer_read();
          register_code(KC_LALT); // Change the key to be held here
        } else {
          unregister_code(KC_LALT); // Change the key that was held here, too!
          if (timer_elapsed(lalt_excl_timer) < TAPPING_TERM) {
            SEND_STRING("!"); // Change the character(s) to be sent on tap here
          }
        }
        return false;
    case LSUP_QUOTE:
      if(record->event.pressed) {
          lsup_quote_timer = timer_read();
          register_code(KC_RGUI); // Change the key to be held here
        } else {
          unregister_code(KC_RGUI); // Change the key that was held here, too!
          if (timer_elapsed(lsup_quote_timer) < TAPPING_TERM) {
            tap_code(KC_BSLASH); // Change the character(s) to be sent on tap here
          }
        }
        return false;
    case LSFT_STPAR:
      if(record->event.pressed) {
          lsft_endpar_timer = timer_read();
          register_code(KC_LSFT); // Change the key to be held here
        } else {
          unregister_code(KC_LSFT); // Change the key that was held here, too!
          if (timer_elapsed(lsft_endpar_timer) < TAPPING_TERM) {
            register_code(KC_LSFT);
            tap_code(KC_8);
            unregister_code(KC_LSFT);
          }
        }
        return false;
  }
  return true;
}	

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
