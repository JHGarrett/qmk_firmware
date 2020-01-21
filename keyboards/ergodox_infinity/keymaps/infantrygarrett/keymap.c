#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  NUM,
  EPRM,
  VRSN,
  ARROW,
  COPY_ALL,
  RGB_SLD,
  SEL_CPY,
  TRIPEQL,
  NOTEQL,
  CC_PRN,
  CC_BRC,
  CC_CBR,
  DBL_AND,
  ALTF4,
  ALTTAB
};

void tap(uint16_t keycode){
    register_code(keycode);
    unregister_code(keycode);
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | =    |           | _    |  6  |  7  |  8  |  9  |  0  |   Del  |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  [{  |           |  ]}  |  Y  |  U  |  I  |  O  |  P  |  BSPC  |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  BSCP  |  A  |  S  |  D  |  F  |  G  |------|           |------|  H  |  J  |  K  |  L  |  ;  |    '   |
 * |--------+-----+-----+-----+-----+-----| LEFT |           | RIGHT|-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  N  |  M  |  ,  |  .  |  /  | Enter  |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Num  |ALT  | GUI |CNRL |Lower|                                     |Raise|Left |Down | Up  |Right |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |Play |  L1  |          |  L2  |Play |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     | Alt  |          | CTRL |     |     |
 *                             |Space|BSCP |------|          |------|ENTER|Space|
 *                             |     |     | LGUI |          | LGUI |     |     |
 *                             `------------------'          `------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,  KC_5, KC_PLUS,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_LBRACKET,
  KC_BSPC,   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_LEFT,
  KC_LCTRL, KC_LALT, KC_LGUI, KC_LCTL, LOWER,

                                                  KC_MPLY,  KC_MNXT,
                                                            KC_LALT,
                                      KC_BSPC,   KC_BSPC,    KC_LGUI,

  // right hand
  KC_MINS,      KC_6, KC_7,  KC_8,    KC_9,    KC_0,                KC_BSPC,
  KC_RBRACKET, KC_Y, KC_U,  KC_I,    KC_O,    KC_P,                KC_BSPACE,
               KC_H, KC_J,  KC_K,    KC_L,    KC_SCOLON,           KC_QUOTE,
  KC_RIGHT,     KC_N, KC_M,  KC_COMM, KC_DOT,  LT(_MOUSE, KC_SLSH), RSFT_T(KC_ENT),
                     RAISE, KC_LEFT, KC_DOWN, KC_UP,               KC_RIGHT,

  KC_MPRV, KC_MPLY,
  KC_LCTL,
  KC_LGUI, KC_ENTER,   KC_SPACE
),

/* Keymap 0: Basic Dvorak layer
 *
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   Del  |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  '  |  ,  |  .  |  P  |  Y  |  [{  |           |  ]}  |  F  |  G  |  C  |  R  |  L  |  BSPC  |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  ESC   |  A  |  O  |  E  |  U  |  I  |------|           |------|  D  |  H  |  T  |  N  |  S  |   /    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * | LShift |  ;  |  Q  |  J  |  K  |  X  |      |           |      |  B  |  M  |  W  |  V  |  Z  | Enter  |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Num  |Ctrl | Alt |LGUI |Lower|                                     |Raise|Left |Down | Up  |Right |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |Play |      |          |      |Play |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     | Alt  |          | Alt  |     |     |
 *                             |Space|LOWER|------|          |------|RAISE|Space|
 *                             |     |     | LGUI |          | LGUI |     |     |
 *                             `------------------'          `------------------'
 */
// [_DVORAK] = LAYOUT_ergodox(
//   // left hand
//   KC_GRV,   KC_1,      KC_2,    KC_3,    KC_4,  KC_5, KC_ESC,
//   KC_TAB,   KC_QUOT,   KC_COMM, KC_DOT,  KC_P,  KC_Y, KC_LBRACKET,
//   KC_ESC,   KC_A,      KC_O,    KC_E,    KC_U,  KC_I,
//   KC_LSFT,  KC_SCOLON, KC_Q,    KC_J,    KC_K,  KC_X, _______,
//   TT(_NUM), KC_LCTL,   KC_LALT, KC_LGUI, LOWER,

//                                                   KC_MPLY,  _______,
//                                                             KC_LALT,
//                                       KC_SPACE,   LOWER,    KC_LGUI,

//   // right hand
//   KC_ESC,      KC_6, KC_7,  KC_8,    KC_9,    KC_0,  KC_DEL,
//   KC_RBRACKET, KC_F, KC_G,  KC_C,    KC_R,    KC_L,  KC_BSPACE,
//                KC_D, KC_H,  KC_T,    KC_N,    KC_S,  LT(MOUSE, KC_SLSH),
//   _______,     KC_B, KC_M,  KC_W,    KC_V,    KC_Z,  RSFT_T(KC_ENT),
//                      RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,

//   _______, KC_MPLY,
//   KC_LALT,
//   KC_LGUI, RAISE,   KC_SPACE
// ),

/* Keymap 0: Basic Colemak layer
 *
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   Del  |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  G  |  [{  |           |  ]}  |  J  |  L  |  U  |  Y  |  ;  |  BSPC  |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  ESC   |  A  |  R  |  S  |  T  |  D  |------|           |------|  H  |  N  |  E  |  I  |  O  |    '   |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  K  |  M  |  ,  |  .  |  /  | Enter  |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Num  |Ctrl | Alt |LGUI |Lower|                                     |Raise|Left |Down | Up  |Right |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |Play |      |          |      |Play |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     | Alt  |          | Alt  |     |     |
 *                             |Space|LOWER|------|          |------|RAISE|Space|
 *                             |     |     | LGUI |          | LGUI |     |     |
 *                             `------------------'          `------------------'
 */
[_COLEMAK] = LAYOUT_ergodox(
  // left hand
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_ESC,
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, KC_LBRACKET,
  KC_ESC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______,
  TT(_QWERTY), KC_LCTL, KC_LALT, KC_LGUI, LOWER,

                                                  _QWERTY,  QWERTY,
                                                            KC_LALT,
                                      KC_SPACE,   LOWER,    KC_LGUI,

  // right hand
  KC_ESC,      KC_6, KC_7,  KC_8,    KC_9,    KC_0,                KC_DEL,
  KC_RBRACKET, KC_J, KC_L,  KC_U,    KC_Y,    KC_SCOLON,           KC_BSPACE,
               KC_H, KC_N,  KC_E,    KC_I,    KC_O,                KC_QUOTE,
  _______,     KC_K, KC_M,  KC_COMM, KC_DOT,  LT(_MOUSE, KC_SLSH), RSFT_T(KC_ENT),
                     RAISE, KC_LEFT, KC_DOWN, KC_UP,               KC_RIGHT,

  _______, KC_MPLY,
  KC_LALT,
  KC_LGUI, RAISE,   KC_SPACE
),


/* Lower
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    ~    |  !   |  @   |  #   |  $   |  %   |  F6  |           |  F5  |  ^   |  &   |  *   |  (   |  )   |   DEL  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Del   |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |  _   |  +   |  {   |  }   |   |    |
 * |---------+------+------+------+------+------| F12  |           | F11  |------+------+------+------+------+--------|
 * |         |  F7  |  F8  |  F9  | F10  | F11  |      |           |      | F12  |ISO ~ |ISO | | Home | End  |  ENTER |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      | Play | Vol- | Vol+ | Next |
 *   `-----------------------------------'                                       `----------------------------------'
*                                           ,------------.          ,------------.
*                                           |Play | PRV  |          |  L2  | NXT |
*                                     ,-----|-----|------|          |------+-----+-----.
*                                     |     |     | Alt  |          | CTRL |     |     |
*                                     |Space|BSCP |------|          |------|ENTER|Space|
*                                     |     |     | LGUI |          | LGUI |     |     |
*                                     `------------------'          `------------------'
*/
[_LOWER] = LAYOUT_ergodox(
  // left hand
  KC_DEL,    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F11,
  ALTTAB, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_F6,
  KC_BSPC,  KC_1,   KC_2,   KC_3,   KC_4,    KC_5,
  ALTF4, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_F12,
  QWERTY, NUM, _______, _______, _______,

                                                  KC_MPLY,  KC_MPRV,
                                                            KC_LALT,
                                      KC_BSPC,   KC_BSPC,    KC_LGUI,

// right hand
  KC_F12, KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,
  KC_F5,  KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
          KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  KC_F11, KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  RSFT_T(KC_ENT),
                   _______,    KC_MPLY,    KC_VOLD, KC_VOLU, KC_MNXT,

  KC_MNXT, KC_MPLY,
  KC_LCTL,
  KC_LGUI, KC_ENTER,   KC_SPACE
),

/* Raise
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    `    |   1  |   2  |   3  |   4  |   5  |  (   |           |   )  |   6  |   7  |   8  |   9  |   0  |  DEL   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    TAB  |      |  UP  | PGUP | CCPRN|  (   | COPY |           |  F5  |  )   |  === |  !=  |   <  |   >  |  BSPC  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   BSPC  | LEFT | DOWN | RIGHT| CCCBR|   {  |------|           |------|  }   |   _  |  =   |   @  |  &&  |   |    |
 * |---------+------+------+------+------+------|  =>  |           | F11  |------+------+------+------+------+--------|
 * |  S/ENT  |      |      | PGDN | CCBRC|   [  |      |           |      |  ]   |   -  |  +   |   \  |   /  |  S/ENT |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |  ALT |  GUI |  CTL |      |                                       |      | Play | Vol- | Vol+ | Next |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       | PLAY | PREV |           |Toggle|Solid |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |  ALT |           |      |Hue-  |Hue+  |
 *                                | BSPC | BSPC |------|           |------|      |      |
 *                                |      |      |  GUI |           |      |      |      |
 *                                `--------------------'           `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
  // left hand
  KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_LPRN,
  KC_TAB,  _______,    KC_UP,    KC_PGUP,    CC_PRN,    KC_LPRN,    COPY_ALL,
  KC_BSPC,  KC_LEFT,   KC_DOWN,   KC_RIGHT,   CC_CBR,   KC_LCBR,
  KC_SFTENT, _______,   _______,   KC_PGDN,   CC_BRC,  KC_LBRC,  ARROW,
  _______, KC_LALT, KC_LGUI, KC_LCTL, _______,


                                                  KC_MPLY,  KC_MPRV,
                                                            KC_LALT,
                                      KC_BSPC,   KC_BSPC,    KC_LGUI,

  // right hand
  KC_RPRN, KC_6,  KC_7,   KC_8,   KC_9,   KC_0,  KC_DEL,
  LCTL(KC_DEL),  KC_RPRN,   TRIPEQL,    NOTEQL,    KC_LABK,    KC_RABK,    KC_BSPC,
          KC_RCBR,  KC_UNDS, KC_EQL,  KC_AT, DBL_AND, KC_PIPE,
  LCTL(KC_BSPC), KC_MINS, KC_PLUS, KC_NUBS, KC_BSLASH, KC_SLSH, KC_SFTENT,
                  _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,

  KC_MNXT, KC_MPLY,
  KC_LCTL,
  KC_LGUI, KC_ENTER,   KC_SPACE
),

/* Adjust
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |QWERTY|COLEMA|DVORAK| MOUSE|NUMPAD|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |Reset |Debug |      |      |      |      |           |      |      |TRM on|TRMoff|      |      |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CPSLCK |      |      |      |      |AG Nrm|------|           |------|AG Swp|      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_ADJUST] = LAYOUT_ergodox(
  // left hand
  VRSN,    QWERTY, _______, _______, MOUSE, NUM, _______,
  _______, RESET,   DEBUG,   BL_TOGG, BL_STEP, _______, _______,
  KC_CAPS, _______, _______, _______, _______, AG_NORM,
  _______, _______, _______, _______, _______, _______, _______,
  QWERTY, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL,
           AG_SWAP, _______,  _______,  _______,  _______, _______,
  _______, _______, _______, _______,  _______, _______, _______,
                    _______, _______,  _______, _______, _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MS_U | WHLD | WHLL | WHLR |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MS_L | MS_D | MS_R |      |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|  BB  |           |  BF  |------+------+------+------+------+--------|
 * |        |      |      | WHLU |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      | WHLD |           |  WHLD|      |      |
 *                               | Lclk |      |------|           |------| MCLCK| RCLK |
 *                               |      |      | WHLU |           |  WHLU|      |      |
 *                               `--------------------'           `--------------------'
 */
// MOUSE
[_MOUSE] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,
  _______, _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, KC_WBAK,
  QWERTY, _______, _______, _______, _______,

                                       _______, _______,
                                                KC_WH_D,
                              KC_BTN1, _______, KC_WH_U,

  // right hand
  _______,   _______, _______, _______, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, KC_MPLY,
  KC_WBAK, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                      KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,

  _______, _______,
  KC_WH_D,
  KC_WH_U, KC_BTN3, KC_BTN2
),


/* Keymap 2: NUMPAD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   ✗  |   ✗  |   ✗  |   ✗  |   ✗  |   ✗  |           |   ✗  |   ✗  |   ✗  |   /  |   *  |   -  |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |   ✗  | Home |  Up  |  End | PgUp |      |           |      |   ✗  |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ✗  | Left | Down | Right| PgDn |------|           |------|   ✗  |   4  |   5  |   6  |   +  |    ✗   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   /  |   *  |   -  |   +  | Enter|      |           |      |   ✗  |   1  |   2  |   3  | Enter|  Enter |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | QWERT|      |      |      |   ✗  |                                       |   0  |   0  |   .  | Enter|   =  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_NUM] = LAYOUT_ergodox(
  // left hand
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  _______, KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO,
  _______, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
  _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PENT, KC_NO,
  QWERTY, _______, QWERTY, _______, KC_NO,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  KC_NO, KC_NO, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, _______,
  KC_NO, KC_NO, KC_P7, KC_P8,   KC_P9,   KC_PPLS, _______,
         KC_NO, KC_P4, KC_P5,   KC_P6,   KC_PPLS, KC_NO,
  KC_NO, KC_NO, KC_P1, KC_P2,   KC_P3,   KC_PENT, KC_PENT,
                KC_P0, KC_P0,   KC_PDOT, KC_PENT, KC_PEQL,

  _______, _______,
  _______,
  _______, _______,  _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      case NUM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NUM);
      }
      return false;
      case MOUSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MOUSE);
      }
      return false;

    // case WORKMAN:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_WORKMAN);
    //   }
    //   return false;
    // case DVORAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_DVORAK);
    //   }
    //   return false;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_LOWER);
          layer_off(_RAISE);
        }
      } else {
        layer_off(_LOWER);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_ADJUST);
          layer_on(_RAISE);
        }
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_RAISE);
          layer_off(_LOWER);
        }
      } else {
        layer_off(_RAISE);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_ADJUST);
          layer_on(_LOWER);
        }
      }
      return false;
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
        #endif
      }
      return false;
                 case SEL_CPY:
            // Select word under cursor and copy. Double mouse click then ctrl+c
            if (record->event.pressed) {
                tap_code16(KC_BTN1);
                tap_code16(KC_BTN1);
                tap_code16(C(KC_C));
            }
            return false;

      case ALTF4:
            // ALT + F4 TO CLOSE WINDOWS IN LINUX
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap(KC_F4);
                unregister_code(KC_LALT);
            }
            return false;

             case ALTTAB:
            // ALT + TAB TO SWITCH APPLICATIONS.
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap(KC_TAB);
                unregister_code(KC_LALT);
            }
            return false;

         case COPY_ALL:
            if (record->event.pressed) {
                // Selects all and text and copy
                SEND_STRING(SS_LCTRL("ac"));
            }
            return false;
             case ARROW:
            if (record->event.pressed){
                SEND_STRING("=>");
            }
            return false;

             case TRIPEQL:
            if (record->event.pressed){
                SEND_STRING("===");
            }
            return false;

             case NOTEQL:
            if (record->event.pressed){
                SEND_STRING("!=");
            }
            return false;

            case DBL_AND:
            if (record->event.pressed){
                SEND_STRING("&&");
            }
            return false;

            case CC_PRN:
            if (record->event.pressed){
            SEND_STRING("()"SS_TAP(X_LEFT));
            }
            return false;

            case CC_BRC:
            if (record->event.pressed){
            SEND_STRING("[]"SS_TAP(X_LEFT));
            }
            return false;

            case CC_CBR:
            if (record->event.pressed){
            SEND_STRING("{}"SS_TAP(X_LEFT));
            }
            return false;

  }
  return true;
}
