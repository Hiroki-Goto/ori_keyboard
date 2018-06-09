#ifndef PARAM_H_
#define PARAM_H_
#include "keycode.h"

enum layer_state{
    _DEFAULT=0xF0,
    _RAISE,
    _ROWER
};

#define SLAVE_ID 8
#define MSG_BYTE 1

//キーボード周りmaster_col_pin
#define MASTER_ROW_NUM 1
#define MASTER_COL_NUM 2
#define SLAVE_ROW_NUM 1
#define SLAVE_COL_NUM 2

const int master_row_pin[MASTER_ROW_NUM] = {9};
const int master_col_pin[MASTER_COL_NUM] = {10, 16};

typedef struct keyboradState{
    uint8_t current_layer;
    bool num_lock;
    bool caps_lock;
    bool scr_lock;
};

const uint8_t default_keymap[MASTER_ROW_NUM][MASTER_COL_NUM+SLAVE_COL_NUM] = {
    {KC_A, _ROWER, KC_A, _ROWER}
};

const uint8_t rower_keymap[MASTER_ROW_NUM][MASTER_COL_NUM+SLAVE_COL_NUM] = {
    {KC_B, _DEFAULT, KC_B, _DEFAULT}
};


#endif
