#ifndef KEY_H_
#define KEY_H_
#include "param.h"

class Key{
public:
    Key(int a);

    uint8_t current_keymap[ROW_NUM][COL_NUM];
    static const uint8_t default_keymap[ROW_NUM][COL_NUM];
    static const uint8_t rower_keymap[ROW_NUM][COL_NUM];
    bool current_key_state[ROW_NUM][COL_NUM];
    bool before_key_state[ROW_NUM][COL_NUM];
    
    void scanMatrix(keyboradState keyboard_state);

    void changeLayer(uint8_t current_layer[ROW_NUM][COL_NUM], uint8_t to_layer);

private:
    static int state;
    
    #define toLayer(layer) state=layer
};

#endif
