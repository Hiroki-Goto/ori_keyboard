#ifndef KEY_H_
#define KEY_H_
#include "param.h"

class KeyMaster{
public:
    KeyMaster(int a);
    bool current_key_state[MASTER_ROW_NUM][MASTER_COL_NUM];
    bool before_key_state[MASTER_ROW_NUM][MASTER_COL_NUM];

    void scanMatrix(keyboradState *keyboard_state);

    void changeLayer(uint8_t layer);

    void readSerial(keyboradState *keyboard_state);
    void readI2c(keyboradState *keyboard_state);

private:
    uint8_t to_layer;
    uint8_t current_keymap[MASTER_ROW_NUM][MASTER_COL_NUM+SLAVE_COL_NUM];
    bool change_layer;

};

#endif
