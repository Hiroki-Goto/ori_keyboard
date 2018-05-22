#ifndef KEY_H_
#define KEY_H_
#include "param.h"

class Key{
public:
    Key(int a);
    bool current_key_state[ROW_NUM][COL_NUM];
    bool before_key_state[ROW_NUM][COL_NUM];

    void scanMatrix(keyboradState keyboard_state);

    void changeLayer(uint8_t layer);

private:
    uint8_t to_layer;
    uint8_t current_keymap[ROW_NUM][COL_NUM];
    bool change_layer;

};

#endif
