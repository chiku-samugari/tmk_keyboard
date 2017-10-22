//#include "hhkb.h"
#include "keymap_common.h"
#include "config.h"

#define _______ KC_TRNS

typedef uint8_t Layer;

enum layer_ids {
    BASE = 0,
    SELECTOR,
    FIXED_RIGHT_PINKY_ON_ASCII,
    FIXED_RIGHT_PINKY_ON_JIS,
    SHIFT_FIXED_RIGHT_PINKY_ON_JIS,
    AUXILIARY,
    MOUSE,
    REFERENCE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap ASCII Art Template
     * ,--------------------------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     * |--------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |
     * |------------------------------------------------------------------\       |
     * |       |    |    |    |    |    |    |    |    |    |    |    |    |      |
     * |--------------------------------------------------------------------------|
     * |        |    |    |    |    |    |    |    |    |    |    |     |    |    |
     * |--------------------------------------------------------------------------|
     * |    | |    |    |    |    |          |    |    |    |    | |    |    |    |
     * `--------------------------------------------------------------------------'
     *
     * Keymap Template
     * [] = KEYMAP_JP(
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
     * ),
     */

    /* Layer BASE: Default Layer
     *
     * Fn0: Activates MOUSE Layer on hold, toggles AUXILIARY layer
     *      on TAPPING_TOGGLE times tap.
     * Fn1: Activates AUXILIARY Layer on hold, toggles AUXILIARY layer
     *      on TAPPING_TOGGLE times tap.
     * Fn2: Activates AUXILIARY Layer on hold, switches on SELECTOR
     *      layer on TAPPING_TOGGLE times tap. Beforehand, layer_state
     *      is cleared on first tap.
     *
     * ,--------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |BSpc|BSpc|
     * |--------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |       |
     * |------------------------------------------------------------------\ Enter |
     * |L-Ctrl |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' | Ent|      |
     * |--------------------------------------------------------------------------|
     * |L-Shift |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  \  | Up |RSft|
     * |--------------------------------------------------------------------------|
     * | Fn0| | Fn1|LGUI|LAlt|LAlt|  Space   |  ` |  = |RAlt| Fn2| |Left|Down|Rght|
     * `--------------------------------------------------------------------------'
     */

  [BASE] = KEYMAP_JP_KC(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,  KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,   KC_UP, KC_RSFT,
    KC_FN0, KC_FN1, KC_LGUI, KC_LALT, KC_LALT,         KC_SPC,     KC_GRV,   KC_EQL, KC_RALT,  KC_FN2, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Layer SELECTOR:
   *   pick a layer that is thought as an independent keyboard such as
   *   FIXED_RIGHT_PINKY_ON_ASCII or MOUSE.
   *
   * Fn6: activates FIXED_RIGHT_PINKY_ON_ASCII and deactivates SELECTOR
   * Fn7: activated MOUSE and deactivates SELECTOR
   * Fn8:activates FIXED_RIGHT_PINKY_ON_JIS and deactivates SELECTOR
   */

  [SELECTOR] = KEYMAP_JP_KC(
    _______,  KC_FN6,  KC_FN7, _______, _______, _______, _______, _______, _______, _______,  KC_FN8, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
  ),

  /* Layer FIXED_RIGHT_PINKY_ON_ASCII:
   *    Left Shift key + Semicolon key issues KC_QUOTE without Left
   *    Shift bit, Quote key issues KC_LSFT and KC_SCLN. My favorite
   *    setup and I normally achieve it by xmodmap. This layer is
   *    intended to be activated when I have to work on computers that
   *    I do not have such kind of control. Even in such situation,
   *    the keyboard layout is expected to be correctly recognized.
   *
   * ,--------------------------------------------------------------------------.
   * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   * |--------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |
   * |------------------------------------------------------------------\       |
   * |       |    |    |    |    |    |    |    |    |    | Fn4| Fn4|    |      |
   * |--------------------------------------------------------------------------|
   * |  Fn4   |    |    |    |    |    |    |    |    |    |    |     |    |    |
   * |--------------------------------------------------------------------------|
   * |    | |    |    |    |    |          |    |    |    |    | |    |    |    |
   * `--------------------------------------------------------------------------'
   */

  [FIXED_RIGHT_PINKY_ON_ASCII] = KEYMAP_JP_KC(
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_FN4,  KC_FN4, _______, _______,
        KC_FN4, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
       ),

  /* Layer FIXED_RIGHT_PINKY_ON_JIS:
   *   The layer behaves as a right pinky fixed US keyboard when the
   *   keyboard is recognized as a JIS keyboard. Since this layer is for
   *   me, the position of Backslash key, Grave key, Equal key, and
   *   Backspace key are changed.
   *
   * Fn5: Shift emulating key. It registers Left Shift bit on press,
   * unregisters the bit on release. Simultaneously,
   * SHIFT_FIXED_RIGHT_PINKY_ON_JIS layer is activated on press, and
   * deactivated on release.
   *
   * ,--------------------------------------------------------------------------.
   * |    |    |    |    |    |    |    |    |    |    |    |    |BSpc|BSpc|BSpc|
   * |--------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |  ] |  \ |       |
   * |------------------------------------------------------------------\       |
   * |       |    |    |    |    |    |    |    |    |    |    |    |    |      |
   * |--------------------------------------------------------------------------|
   * |  Fn5   |    |    |    |    |    |    |    |    |    |    | Yen |    |    |
   * |--------------------------------------------------------------------------|
   * |    | |    |    |    |S(-)|          |S([)|    |    |    | |    |    |    |
   * `--------------------------------------------------------------------------'
   */

  [FIXED_RIGHT_PINKY_ON_JIS] = KEYMAP_JP_KC(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     KC_FN5, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_JYEN, _______, _______,
    _______, _______, _______, _______,S(KC_MINS),   _______   ,S(KC_LBRC), _______, _______, _______, _______, _______, _______
  ),

  /* Layer SHIFT_FIXED_RIGHT_PINKY_ON_JIS:
   *   The layer behaves as a right pinky fixed US layout keyboard whose
   *   left shift key is held when the keyboard is recognized as a JIS
   *   keyboard.
   */

     [SHIFT_FIXED_RIGHT_PINKY_ON_JIS] = KEYMAP_JP_KC(
       S(KC_ESC), S(KC_1), KC_FN3, S(KC_3), S(KC_4), S(KC_5), KC_FN3,  S(KC_6), S(KC_QUOT), S(KC_8), S(KC_9), S(KC_RO), S(KC_BSPC), S(KC_BSPC), S(KC_BSPC),
       S(KC_TAB), S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), S(KC_RBRC), S(KC_BSLS),
       S(KC_LCTL),S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_7), S(KC_2), S(KC_ENT), S(KC_ENT),
       _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_JYEN), S(KC_UP), S(KC_RSFT),
       _______, _______, S(KC_LGUI), S(KC_LALT), S(KC_SCLN), S(KC_SPC), S(KC_EQL), S(KC_RSFT), S(KC_RALT), _______, S(KC_LEFT), S(KC_DOWN), S(KC_RGHT)
     ),
  /* Layer Auxiliary: Extended version of HHKB Fn layer.
   *
   *  + Function keys
   *  + Volume Down, Volume Up, Mute
   *  + Power, Print Screen, Pause, Scroll lock, Insert
   *  + Symbols on number keys are located on more easy-to-type keys
   *  + Cursor keys on HJKL
   *
   * ,--------------------------------------------------------------------------.
   * |Powr| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F0 | F11| F12| Ins| Del|
   * |--------------------------------------------------------------------------|
   * |Caps  |    |VoDw|VoUp|Mute|    |    |    |  ( |  ) |PrSc|ScLk|Paus|       |
   * |------------------------------------------------------------------\ Enter |
   * |       |  ! |  @ |  # |  $ |  % |Left|Rght| Up| Down|  + |  * |    |      |
   * |--------------------------------------------------------------------------|
   * |        |    |    |    |    |    |  ^ |  & |    |    |  _ |     |    |    |
   * |--------------------------------------------------------------------------|
   * |    | |    |    |    |    |          |    |    |    |    | |    |    |    |
   * `--------------------------------------------------------------------------'
   */

  [AUXILIARY] = KEYMAP_JP_KC(
    KC_PWR,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
    KC_CAPS, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSCR, KC_SLCK, KC_PAUS,
    _______, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ASTR, KC_PLUS, _______, KC_PENT,
    _______, _______, _______, _______, _______, _______, KC_CIRC, KC_AMPR, _______, _______, KC_UNDS, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
  ),

    /* Layer MOUSE: Mouse Cursor, Mouse Wheel, and Mouse Buttons
     * ,--------------------------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     * |--------------------------------------------------------------------------|
     * |      |    |    |    |    |    | MwL| MwD| MwU| MwR|    | McU|    |       |
     * |------------------------------------------------------------------\       |
     * |       | Mb5| Mb4| Mb3| Mb2|    | McL| McD| McU| McR| McL| McR|    |      |
     * |--------------------------------------------------------------------------|
     * |        |    |    |    |    |    |    |    |    |    | McD|     | McU|    |
     * |--------------------------------------------------------------------------|
     * |    | |    |    |    |    |   Mb1    |    |    |    |    | | McL| McD| McR|
     * `--------------------------------------------------------------------------'
     */

     [MOUSE] = KEYMAP_JP_KC(
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, KC_MS_U, _______,
       _______, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MS_L, KC_MS_R, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_D, _______, KC_MS_U, _______,
       _______, _______, _______, _______, _______,     KC_BTN1     , _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
     ),

    /* Layer REFERENCE: A utility layer to locate which of phisical key
     * was actually operated. We can use keymap_key_to_keycode function
     * offered by Q.M.K to locate the phisical key because all the keys
     * of this layer issues unique keycode. It is quite convenient to
     * implement UNSHIFT action.
     *
     *  Let me explain about how I decide keycodes. Almost all key is
     * based on HHKB Pro2 layout. If a phisical key exists in both of
     * HHKB Pro2 and and HHKB JP, then the keycode issued by the key on
     * HHKB Pro2 keyboard is mapped to that key. The lowest row is based
     * on HHKB JP keyboard because there are too many keys compared to
     * HHKB Pro2. Fn0 and Fn1 are replaced by Del and RGUI.  KC_ZKHK is
     * replaced by Backspace because KC_ZKHK is identical to KC_GRAVE
     * and that is already on the right upper corner. Yen and RO are
     * used to fill middle line and one below line.
     *
     * ,--------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |  \ |  ` |
     * |--------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |       |
     * |------------------------------------------------------------------\ Enter |
     * |L-Ctrl |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' | Yen|      |
     * |--------------------------------------------------------------------------|
     * |L-Shift |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  RO | Up |RSft|
     * |--------------------------------------------------------------------------|
     * | Del| |BSpc|LGUI|LAlt|MHEN|  Space   |HENK|KANA|RAlt|RGUI| |Left|Down|Rght|
     * `--------------------------------------------------------------------------'
     */

  [REFERENCE] = KEYMAP_JP_KC(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL, KC_JYEN, KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_BSLS,  KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,   KC_RO,   KC_UP, KC_RSFT,
     KC_DEL, KC_GRAVE, KC_LGUI, KC_LALT, KC_MHEN,      KC_SPC   , KC_HENK,  KC_KANA, KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
};

enum fn_action_ids {
    HOLD_MOUSE_TAP_AUXILIARY = 0,
    HOLD_AUXILIARY_TAP_AUXILIARY,
    HOLD_AUXILIARY_TAP_SELECTOR,
    MOMENTARY_LAYER_AND_LEFT_SHIFT,
    UNSHIFT,
    FIXED_RIGHT_PINKY,
    SELECT_KEYBOARD,
    WITH_LEFT_SHIFT,
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION_TAP(HOLD_MOUSE_TAP_AUXILIARY),
    [1] = ACTION_FUNCTION_TAP(HOLD_AUXILIARY_TAP_AUXILIARY),
    [2] = ACTION_FUNCTION_TAP(HOLD_AUXILIARY_TAP_SELECTOR),
    [3] = ACTION_FUNCTION(UNSHIFT),
    [4] = ACTION_FUNCTION(FIXED_RIGHT_PINKY),
    [5] = ACTION_FUNCTION_OPT(MOMENTARY_LAYER_AND_LEFT_SHIFT, SHIFT_FIXED_RIGHT_PINKY_ON_JIS),
    [6] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, FIXED_RIGHT_PINKY_ON_ASCII),
    [7] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, MOUSE),
    [8] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, FIXED_RIGHT_PINKY_ON_JIS),
};

// Momentary swtich to layer ``hold'', toggles layer ``tap'' on tap.
void layer_tap_toggle_ab(const keyrecord_t * const record, Layer hold, Layer tap) {
    if(record->event.pressed) {
        layer_on(hold);
    }else {
        layer_off(hold);
        if(record->tap.count == TAPPING_TOGGLE) {
            layer_invert(tap);
        }
    }
}

static bool lshift = false;
static uint8_t semicolon = 0;
static uint8_t quote = 0;

void mod_us(const keyrecord_t * const record, uint8_t keycode) {
    // uint8_t real_shift = real_mods & (MOD_LSFT | MOD_RSFT);
    // uint8_t weak_shift = weak_mods & (MOD_LSFT | MOD_RSFT);
    switch(keycode) {
        case KC_LSFT:
            if(record->event.pressed) {
                register_mods(MOD_LSFT);
                lshift = true;
            }else {
                unregister_mods(MOD_LSFT);
                lshift = false;
            }
            break;
        case KC_SCLN:
            if(record->event.pressed) {
                if(lshift) {
                    del_mods(MOD_LSFT);
                    add_key(KC_QUOT);
                    semicolon = KC_QUOT;
                }else {
                    add_key(KC_SCLN);
                    semicolon = KC_SCLN;
                }
            }else {
                del_key(semicolon);
                if(lshift) {
                    add_mods(MOD_LSFT);
                }
                semicolon = 0;
            }
            send_keyboard_report();
            break;
        case KC_QUOT:
            if(record->event.pressed) {
                if(lshift) {
                    add_key(KC_QUOT);
                    quote = KC_QUOT;
                }else {
                    add_mods(MOD_LSFT);
                    add_key(KC_SCLN);
                    quote = KC_SCLN;
                }
            }else {
                del_key(quote);
                if(!lshift) {
                    del_mods(MOD_LSFT);
                }
                quote = 0;
            }
            send_keyboard_report();
            break;
    }
}

static uint8_t unshift_count = 0;

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case HOLD_MOUSE_TAP_AUXILIARY:
            layer_tap_toggle_ab(record, MOUSE, AUXILIARY);
            break;
        case HOLD_AUXILIARY_TAP_AUXILIARY:
            layer_tap_toggle_ab(record, AUXILIARY, AUXILIARY);
            break;
        case HOLD_AUXILIARY_TAP_SELECTOR:
            if(record->event.pressed) {
                layer_on(AUXILIARY);
            }else {
                layer_off(AUXILIARY);
                if(record->tap.count == 1) {
                    layer_clear();
                }
                // This `if` statement should be an independent one
                // because TAPPING_TOGGLE can be 1.
                if(record->tap.count == TAPPING_TOGGLE) {
                    layer_on(SELECTOR);
                }
            }
            break;
        case MOMENTARY_LAYER_AND_LEFT_SHIFT:
            unshift_count = 0;
            if(record->event.pressed) {
                layer_on(opt);
                register_mods(MOD_LSFT);
            }else {
                unregister_mods(MOD_LSFT);
                layer_off(opt);
            }
            break;
        case UNSHIFT:
            if(record->event.pressed) {
                del_mods(MOD_LSFT);
                unshift_count += 1;
                switch(keymap_key_to_keycode(REFERENCE, record->event.key)) {
                    case KC_2:      // @
                        add_key(KC_LBRC);
                        break;
                    case KC_6:      // ^
                        add_key(KC_EQL);
                        break;
                    case KC_SCLN:   // :
                        add_key(KC_QUOT);
                        break;
                }
            } else {
                unshift_count -= 1;
                switch(keymap_key_to_keycode(REFERENCE, record->event.key)) {
                    case KC_2:
                        del_key(KC_LBRC);
                        break;
                    case KC_6:
                        del_key(KC_EQL);
                        break;
                    case KC_SCLN:
                        del_key(KC_QUOT);
                        break;
                }
                if(unshift_count == 0) {
                    add_mods(MOD_LSFT);
                }
            }
            send_keyboard_report();
            break;
        case FIXED_RIGHT_PINKY:
            mod_us(record, keymap_key_to_keycode(REFERENCE, record->event.key));
            break;
        case SELECT_KEYBOARD:
            if(record->event.pressed) {
                layer_off(SELECTOR);
                layer_on(opt);
            }
            break;
    }
}
