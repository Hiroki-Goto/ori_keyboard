#include <Wire.h>
#include <Keyboard.h>
#include <string.h>

#include "Arduino.h"
#include "key_master.h"

KeyMaster::KeyMaster(int a){
    //ピン設定
    for(int i=0; i<MASTER_ROW_NUM; i++){
        pinMode(master_row_pin[i],OUTPUT);
    }
    for(int i=0; i<MASTER_COL_NUM; i++){
        pinMode(master_col_pin[i],INPUT_PULLUP);
    }

    //状態の初期化
    for(int i=0; i<MASTER_ROW_NUM; i++){
        for(int j=0; j<MASTER_COL_NUM; j++){
            current_key_state[i][j] = HIGH;
            before_key_state[i][j] = HIGH;
        }
        digitalWrite(master_row_pin[i], HIGH);
    }
    for(int i=0; i<MASTER_ROW_NUM; i++){
        for(int j=0; j<(SLAVE_COL_NUM); j++){
            current_key_state_slave[i][j] = HIGH;
            before_key_state_slave[i][j] = HIGH;
        }
    }

    //キーマップの初期化
    for(int i=0; i<MASTER_ROW_NUM; i++){
        for(int j=0; j<(MASTER_COL_NUM+SLAVE_COL_NUM); j++){
            current_key_state_slave[i][j] = HIGH;
            before_key_state_slave[i][j] = HIGH;
            current_keymap[i][j] = default_keymap[i][j];
        }
    }

    change_layer = false;
}

void KeyMaster::scanMatrix(keyboradState *keyboard_state){
    for(int i=0; i<MASTER_ROW_NUM; i++){
        digitalWrite(master_row_pin[i],LOW);
        for(int j=0; j<MASTER_COL_NUM; j++){
            current_key_state[i][j] = digitalRead(master_col_pin[j]);
            if(current_key_state[i][j] != before_key_state[i][j]){
                if(current_key_state[i][j] == LOW){
                    if(current_keymap[i][j] >= 0xF0){
                        to_layer = current_keymap[i][j];
                        keyboard_state->current_layer = to_layer;
                        change_layer = true;
                    }else{
                        Keyboard.press(current_keymap[i][j]);
                    }
                }else{
                    if(current_keymap[i][j] >= 0xF0){
                    }else{
                        Keyboard.release(current_keymap[i][j]);
                    }
                }
                before_key_state[i][j] = current_key_state[i][j];
            }
        }
        digitalWrite(master_row_pin[i],HIGH);
    }

    if(change_layer){
        changeLayer(to_layer);
        change_layer = false;
    }
    /*
    if(Serial1.available()){
        readSerial(keyboard_state);
    }
    */

    Wire.requestFrom(SLAVE_ID, MSG_BYTE);// request 1 bytes from Slave ID #8
    if(Wire.available()){
        readI2c(keyboard_state);
    }


}

void KeyMaster::changeLayer(uint8_t layer){
    switch (layer) {
        case _DEFAULT:
            memcpy(current_keymap, default_keymap, sizeof(rower_keymap));
        break;

        case _ROWER:
            memcpy(current_keymap, rower_keymap, sizeof(rower_keymap));
        break;

        default:
        break;
    }

}

void KeyMaster::readSerial(keyboradState *keyboard_state){
    uint8_t read_data;
    read_data = Serial1.read();

    int is_press;
    int slave_matrix,row,col;
    if(read_data & 0b10000000 ){

    }else{
        is_press = read_data >> 6;
        slave_matrix = read_data & 0b00111111;
        row = slave_matrix / SLAVE_COL_NUM;
        col = slave_matrix % SLAVE_COL_NUM;
    }
    if(is_press){
        if(current_keymap[row][col] >= 0xF0){
            to_layer = current_keymap[row]

            [col];
            keyboard_state->current_layer = to_layer;
            changeLayer(to_layer);
        }else{
            Keyboard.press(current_keymap[row][col]);
        }
    }else{
        if(current_keymap[row][col] >= 0xF0){
        }else{
            Keyboard.release(current_keymap[row][col]);
        }
    }
}

void KeyMaster::readI2c(keyboradState *keyboard_state){
    uint8_t read_data;
    read_data = Wire.read();

    int is_press;
    int slave_matrix,row,col;

    if(read_data & 0b10000000 ){

    }else{
        is_press = read_data >> 6;
        slave_matrix = read_data & 0b00111111;
        row = slave_matrix / SLAVE_COL_NUM;
        col = slave_matrix % SLAVE_COL_NUM;
    }

    for(int i=0; i<SLAVE_ROW_NUM; i++){
        for(int j=0; j<SLAVE_COL_NUM; j++){
            if(i==row && j==col && is_press){
                current_key_state_slave[i][j] = LOW;
            }else{
                current_key_state_slave[i][j] = HIGH;
            }

            if(current_key_state_slave[i][j] != before_key_state_slave[i][j]){
                if(current_key_state_slave[i][j] == LOW){
                    if(current_keymap[i][MASTER_COL_NUM+j] >= 0xF0){
                        to_layer = current_keymap[i][MASTER_COL_NUM+j];
                        keyboard_state->current_layer = to_layer;
                        change_layer = true;
                    }else{
                        Keyboard.press(current_keymap[i][MASTER_COL_NUM+j]);
                    }
                }else{
                    if(current_keymap[i][MASTER_COL_NUM+j] >= 0xF0){
                    }else{
                        Keyboard.release(current_keymap[i][MASTER_COL_NUM+j]);
                    }
                }
                before_key_state_slave[i][j] = current_key_state_slave[i][j];
            }
        }
    }

    if(change_layer){
        changeLayer(to_layer);
        change_layer = false;
    }
}
