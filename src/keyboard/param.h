#ifndef PARAM_H_
#define PARAM_H_

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
    int current_layer;
    bool num_lock;
    bool caps_lock;
    bool scr_lock;
};

//OLED周り
#define FONT_SIZE 10
#endif
