#ifndef PARAM_H_
#define PARAM_H_
#include "keycode.h"

enum layer_state{
    _DEFAULT=0xF0,
    _RAISE,
    _ROWER
};

//キーボード周り
#define ROW_NUM 1
#define COL_NUM 2
const int row_pin[ROW_NUM] = {9};
const int col_pin[COL_NUM] = {10, 16};

typedef struct keyboradState{
    uint8_t current_layer;
    bool num_lock;
    bool caps_lock;
    bool scr_lock;
};

const uint8_t default_keymap[ROW_NUM][COL_NUM] = {
    {KC_A, _ROWER}
};

const uint8_t rower_keymap[ROW_NUM][COL_NUM] = {
    {KC_B, _DEFAULT}
};


#endif
