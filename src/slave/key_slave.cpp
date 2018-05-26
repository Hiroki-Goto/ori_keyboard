#include <Keyboard.h>

#include "key_slave.h"

KeySlave::KeySlave(int no_use_num){
    for(int i=0; i<SLAVE_ROW_NUM; i++){
        pinMode(slave_row_pin[i],OUTPUT);
    }
    for(int i=0; i<SLAVE_COL_NUM; i++){
        pinMode(slave_col_pin[i],INPUT_PULLUP);
    }

    for(int i=0; i<SLAVE_ROW_NUM; i++){
        for(int j=0; j<SLAVE_COL_NUM; j++){
            current_key_state[i][j] = HIGH;
            before_key_state[i][j] = HIGH;
        }
        digitalWrite(slave_row_pin[i], HIGH);
    }
}

void KeySlave::scanMatrix(){
    for(int i=0; i<SLAVE_ROW_NUM; i++){
        digitalWrite(slave_row_pin[i],LOW);
        for(int j=0; j<SLAVE_COL_NUM; j++){
            current_key_state[i][j] = digitalRead(slave_col_pin[j]);
            if(current_key_state[i][j] != before_key_state[i][j]){
                if(current_key_state[i][j] == LOW){
                    //Keyboard.press(0x61);
                    sendSerial(PRESS, i, j);
                }else{
                    //Keyboard.release(0x61);
                    sendSerial(RELEASE, i, j);
                }
                before_key_state[i][j] = current_key_state[i][j];
            }
        }
        digitalWrite(slave_row_pin[i],HIGH);
    }
    delay(1);
}

void KeySlave::sendSerial(int is_press, int row, int col){
    uint8_t send_data;
    int send_key_matrix = row * SLAVE_COL_NUM + col;
    send_data = 0b0 << 7 | is_press << 6 | send_key_matrix;
    Serial1.write(send_data);
}
