/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {{
        {KC_Q,      KC_W,      KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,   KC_O,     KC_P,     KC_BSPACE,},
        {KC_A,      KC_S,      KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,   KC_L,     KC_SCLN,  L_RAISE,},
        {KC_LSFT,   KC_Z,      KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,   KC_QUOT,  KC_SLSH,  KC_ENT,},
        {KC_TAB,    KC_ESC,    KC_LCTL, KC_LALT, KC_COMMA, L_LOWER, KC_SPACE,        KC_DOT,   KC_LGUI}
    }};

 
void setupKeymap() {
   

    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        KC_F2, KC_F3,   KC_F4,  KC_F5,  KC_F6, KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11, KC_F12, 
        KC_1,  KC_2,    KC_3,   KC_4,   KC_5,  KC_6,   KC_7,   KC_8,   KC_9,    KC_0,   ______,
        _____, KC_PSCR, _____,  _____,  _____, _____,  _____,  _____,  _____,   _____,  ______,
        _____, KC_F1,   _____,  _____,  _____, _____,  _____,          _____,   _____,);

    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, KC_PLUS, KC_UNDS, KC_MINS, KC_EQL,  KC_DEL,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, ______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ______,
        _______, _______, _______, _______, _______, _______,          _______, _______,);

    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        RESET,   _______,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI,  RGB_SAD,    RGB_VAI,    RGB_VAD,   KC_DEL ,
        _______, _______,  _______, _______, _______, _______, _______,  KM_QWERTY,  KM_COLEMAK, KM_DVORAK, KM_PLOVER, 
        _______, _______,  _______, _______, _______, _______, _______,  _______,    _______,    _______,   _______,
        _______, _______, _______,  _______, L_LOWER, _______,           L_RAISE,    _______,);

    uint32_t macro[MATRIX_ROWS][MATRIX_COLS] =            // XXXXXXX = nothing    _______ = transparent = use lower layer keycode
        KEYMAP(
        PRINT_BATTERY, HOME_ADD, EMAIL_1, NAME_1,  CBR_FN,  PHONE_1, TAB_DOWN_RTRN, INOWORD,   IN_R,     IPADDR,   SMILE, 
        PRINT_INFO   , WORK_ADD, EMAIL_2, NAME_2,  BRC_FN,  PHONE_2, TAB_UP_RTRN,   FOREXMPL,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX      , XXXXXXX,  XXXXXXX, NAME_3,  PRN_FN,  XXXXXXX, XXXXXXX,       FF_TEXT,   XXXXXXX,  LARW_L,   LARW_R, 
        L_MACRO      , XXXXXXX,  XXXXXXX, XXXXXXX, L_LOWER, XXXXXXX,                KM_COLEMAK, KM_PLOVER);

    /*
     * add the other layers
     */
 
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_LOWER,  Method::PRESS,   lower[row][col]);
            matrix[row][col].addActivation(_RAISE,  Method::PRESS,   raise[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS,  adjust[row][col]);
            matrix[row][col].addActivation(_MACRO,  Method::PRESS,   macro[row][col]);
        }
    }

}


void process_user_macros(uint16_t macroid)
{

     uint32_t qwerty[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPACE,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA, KC_DOT,   KC_ENTER, 
        KC_LCTL, KC_LALT, KC_LGUI, L_LOWER, KC_SPC,  KC_SPC,           KC_UP,    KC_RIGHT);
    
    uint32_t colemak[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LALT, KC_LGUI, L_LOWER, KC_SPC,  L_RAISE,          KC_UP,   KC_RGHT);
    
    uint32_t dvorak[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
        KC_LCTL, KC_LALT, KC_LGUI, L_LOWER, KC_SPC,  L_RAISE,          KC_DOWN, KC_RGHT);
    

    uint32_t plover[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
        KC_LCTL, KC_LALT, KC_LGUI, L_LOWER, KC_SPC,  L_RAISE,          KC_DOWN, KC_RGHT);
    
 switch ((macroid))
 { 
     case (KM_QWERTY):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_QWERTY, Method::PRESS,  qwerty[row][col]);
            }
        }
        break;
     case (KM_COLEMAK):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_COLEMAK, Method::PRESS, colemak[row][col]);
            }
        }
        break;
     case KM_DVORAK:
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_DVORAK, Method::PRESS,  dvorak[row][col]);
            }
        }
        break;
    case KM_PLOVER:
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_PLOVER, Method::PRESS,  plover[row][col]);
            }
        }
        break;
     case HOME_ADD:
     addStringToQueue("123 Quiet Crescent");
     break;
     case WORK_ADD:
     addStringToQueue("123 Work Place");
      break;
     case EMAIL_1:
     addStringToQueue("Primary@Email");
      break;
     case EMAIL_2:
     addStringToQueue("Other@Email");
      break;
     case NAME_1:
     addStringToQueue("First Name");
      break;
     case NAME_2:
     addStringToQueue("Middle Name");
      break;
     case NAME_3:
     addStringToQueue("Last Name");
      break;
     case (CBR_FN):
      addStringToQueue("{}"); 
      addKeycodeToQueue(KC_LEFT);
      break;
     case (BRC_FN):
      addStringToQueue("[]");
      addKeycodeToQueue(KC_LEFT);
      break;
     case PRN_FN:
      addStringToQueue("()"); 
      addKeycodeToQueue(KC_LEFT);
      break;
     case TAB_DOWN_RTRN:
      addKeycodeToQueue(KC_TAB);
      addKeycodeToQueue(KC_DOWN);
      addKeycodeToQueue(KC_ENTER);
      break;
     case TAB_UP_RTRN:
       addKeycodeToQueue(KC_TAB);
       addKeycodeToQueue(KC_UP);
       addKeycodeToQueue(KC_ENTER);
      break;
     case PHONE_1:
     addStringToQueue("234-567-8901");
      break;
     case PHONE_2:
     addStringToQueue("987-654-3210");
      break;
     case INOWORD:
     addStringToQueue("(i.e., )");  
     addKeycodeToQueue(SEND_KC(KC_LEFT));
      break;
     case FOREXMPL:
     addStringToQueue("(e.g., )"); 
     addKeycodeToQueue(KC_LEFT);
      break;
     case FF_TEXT:
     addKeycodeToQueue(KC_LALT);
     addStringToQueue("rff"); 
     addKeycodeToQueue(KC_LEFT);
     addKeycodeToQueue(KC_ENTER);
      break;
     case IN_R:
     addStringToQueue("%in%");
      break;
     case LARW_L:
     addStringToQueue("<-");
      break;
     case LARW_R:
     addStringToQueue("->");
     break;
     case IPADDR:
     addStringToQueue("192.168.1.");
     break;
     case SMILE:
     addStringToQueue(":)");
     break;
     case IPSUM:
     addStringToQueue("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
     break;
     case GITCOMMIT:
      addStringToQueue("git add .");
      addKeycodeToQueue(KC_ENTER);
      addStringToQueue("git commit -m \"\""); 
      addKeycodeToQueue(KC_LEFT);
     break;
 }
}


void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_LOWER, _RAISE, _ADJUST);
}
