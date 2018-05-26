#ifndef KEY_SLAVE_H_
#define KEY_SLAVE_H_

#include "Arduino.h"
#include "param.h"

#define PRESS 1
#define RELEASE 0

class KeySlave{
public:
    KeySlave(int no_use_num);

    void scanMatrix();

private:
    bool current_key_state[SLAVE_ROW_NUM][SLAVE_COL_NUM];
    bool before_key_state[SLAVE_ROW_NUM][SLAVE_COL_NUM];

    void sendSerial(int is_press, int row, int col);
};

#endif
