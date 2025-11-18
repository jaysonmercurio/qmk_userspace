#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK_DH = 0,
  _GAME,
  _NAV,
  _FUNC,
  _SYM,
  _ADJUST
};

enum custom_keycodes {
  WINDOWS = SAFE_RANGE,
  COPY,
  CUT,
  PASTE,
  UNDO,
  REDO,
  SAVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |GUI/N |SFT/E |CTL/I |ALT/O |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/ SYM   /     \      \-----------------------------------------'
 *                   | ALT  | LGUI | NAV  | /[Space]/       \Enter \  | FUNC |BackSP| Del  |
 *                   |[Caps]|      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_COLEMAK_DH] = LAYOUT(
  QK_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  SC_LSPO,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    RGUI_T(KC_N),    RSFT_T(KC_E),    RCTL_T(KC_I),    LALT_T(KC_O),    KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_LBRC,  KC_RBRC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
                        LALT_T(KC_CAPS), KC_LGUI, MO(_NAV), LT(_SYM,KC_SPC), KC_ENT, MO(_FUNC), KC_BSPC, KC_DEL
),
/* GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   6  |   7  |   Q  |   W  |   E  |   R  |                    | Vol+ |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   8  |LShift|   A  |   S  |   D  |   F  |-------.    ,-------| Vol- |      |      |      |      |      |
 * |------+------+------+------+------+------|   G   |    |       |------+------+------+------+------+------|
 * |   9  | Crtl |   Z  |   X  |   C  |   V  |-------|    |-------| Mute |      |      |      |      |  F4  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  Alt |  Tab | NAV  | /Space  /       \Enter \  | FUNC | LGUI |  Alt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_GAME] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_6,    KC_7,    KC_Q,    KC_W,    KC_E,    KC_R,                     KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_8,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                     KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_9,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V, KC_G,      XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,
                             KC_LALT, KC_TAB, MO(_NAV),  KC_SPACE, KC_ENT,  MO(_FUNC), KC_LGUI, KC_RALT
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |  ^Up |      | Home |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |^Left |  Up  |^Right| PgUp |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Left | Down |Right | PgDn |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|GAMING |    |COLEMAK|------+------+------+------+------+------|
 * |      |      |      |^Down |      | End  |-------|    |-------|      |      |      |      |      |Sleep |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | NAV  | /Space  /       \Enter \  | LOCK |BackSP|  Del |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAV] = LAYOUT(
  _______, _______, _______,    C(KC_UP),    _______,       KC_HOME,                              _______, _______,       _______,       _______, _______, _______,
  _______, _______, C(KC_LEFT), KC_UP,       C(KC_RGHT),    KC_PGUP,                              _______, LGUI(KC_PGDN), LGUI(KC_PGUP), _______, _______, _______,
  _______, _______, KC_LEFT,    KC_DOWN,     KC_RGHT,       KC_PGDN,                              _______, _______,       _______,       _______, _______, _______,
  _______, _______,   _______,  C(KC_DOWN),  _______,       KC_END,  DF(_GAME), DF(_COLEMAK_DH),  _______, _______,       _______,       _______, _______, KC_SLEP,
                             _______, _______, _______,              _______, _______,        QK_LLCK, _______, _______
),
/* FUNC 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ` ~  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    | Vol+ |   7  |   8  |   9  |   -  |   /  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  |-------.    ,-------| Vol- |   4  |   5  |   6  |   +  |   *  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      | F11  | F12  | F13  | F14  | PrtS |-------|    |-------|   0  |   1  |   2  |   3  |   \  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | SYM  | LGUI | LOCK | /Space  /       \Enter \  | FUNC |BackSP|  Del |
 *                   |[Caps]|      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUNC] = LAYOUT(
  KC_GRV , _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_VOLU, KC_7,    KC_8,   KC_9,    KC_PMNS, KC_PSLS,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    KC_VOLD, KC_4,    KC_5,   KC_6,    KC_PPLS, KC_PAST,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14, KC_PSCR, _______, _______,  KC_0,    KC_1,    KC_2,   KC_3,    KC_BSLS, KC_PIPE,
                             _______, _______, QK_LLCK, _______, _______,  _______, _______, _______
),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  `   |  <   |  >   |  -   |  |   |                    |  ^   |  {   |  }   |  $   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  *   |  /   |  =   |  &   |-------.    ,-------|  #   |  (   |  )   |  ;   |  "   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  ~   |  +   |  [   |  ]   |  %   |-------|    |-------|  @   |  :   |  ,   |  .   |  '   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | SYM  | LGUI | NAV  | /Space  /       \Enter \  | LOCK |BackSP|  Del |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_GRV , KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                   KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , _______, _______,
  _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL , KC_AMPR,                   KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, _______,
  _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC, _______, _______, KC_AT  , KC_COLN, KC_COMM, KC_DOT , KC_QUOT, _______,
                              _______, _______, _______, _______, _______,  QK_LLCK, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |isWIN |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  | FUNC |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, WINDOWS, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  //return update_tri_layer_state(state, _NAV, _FUNC, _ADJUST);
  // switch (get_highest_layer(state)) {
  //   case _FUNC:
  //       rgblight_setrgb (0x00,  0x00, 0xFF);
  //       break;
  //   case _NAV:
  //       rgblight_setrgb (0xFF,  0x00, 0x00);
  //       break;
  //   case _GAME:
  //       rgblight_setrgb (0x27,  0xAE, 0x96);
  //       break;
  //   case _QWERTY:
  //       rgblight_setrgb (0xAE,  0xF0, 0xE8);
  //       break;
  //   default: //  for any other layers, or the default layer
  //       rgblight_setrgb (0xFF,  0xFF, 0xFF);
  //       break;
  //   }
  return state;
}

// bool rgb_matrix_indicators_kb(void) {
//     if (!rgb_matrix_indicators_user()) {
//         return false;
//     }
//     rgb_matrix_set_color_all(0, 0, 0);
//     return true;
// }
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//  static bool isWin = false;
  mod_state = get_mods();
//   switch (keycode) {
//       case WINDOWS:
//           if (record->event.pressed) {
//               isWin = !isWin;
//           }
//           return false;
//       case COPY:
//           if (record->event.pressed) {
//               if (isWin) {
//                   tap_code16(LCTL(KC_C));
//               } else {
//                   tap_code16(LGUI(KC_C));
//               }
//               return false;
//           }
//       case PASTE:
//           if (record->event.pressed) {
//               if (isWin) {
//                   tap_code16(LCTL(KC_V));
//               } else {
//                   tap_code16(LGUI(KC_V));
//               }
//           return false;
//           }
//       case CUT:
//           if (record->event.pressed) {
//               if (isWin) {
//                   tap_code16(LCTL(KC_X));
//               } else {
//                   tap_code16(LGUI(KC_X));
//               }
//               return false;
//           }
//       case UNDO:
//           if (record->event.pressed) {
//               if (isWin) {
//                   tap_code16(LCTL(KC_Z));
//               } else {
//                   tap_code16(LGUI(KC_Z));
//               }
//               return false;
//           }
//       case REDO:
//           if (record->event.pressed) {
//               if (isWin) {
//                   tap_code16(LCTL(KC_Y));
//               } else {
//                   tap_code16(LSG(KC_Z));
//               }
//               return false;
//           }
//       case SAVE:
//           if (record->event.pressed) {
//               if (isWin) {
//                   tap_code16(LCTL(KC_S));
//               } else {
//                   tap_code16(LGUI(KC_S));
//               }
//               return false;
//           }
//   }
  return true;
}
