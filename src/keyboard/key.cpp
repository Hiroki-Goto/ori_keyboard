#include <Keyboard.h>

#include "Arduino.h"
#include "key.h"
#include "keycode.h"


Key::Key(int a){
    for(int i=0; i<ROW_NUM; i++){
        pinMode(row_pin[i],OUTPUT);
    }
    for(int i=0; i<COL_NUM; i++){
        pinMode(col_pin[i],INPUT);
    }

    for(int i=0; i<ROW_NUM; i++){
        for(int j=0; j<COL_NUM; j++){
            current_key_state[i][j] = LOW;
            before_key_state[i][j] = LOW;

            current_keymap[i][j] = default_keymap[i][j];
        }
        digitalWrite(row_pin[i],LOW);
    }
}

void Key::scanMatrix(keyboradState keyboard_state){
    for(int i=0; i<ROW_NUM; i++){
        digitalWrite(row_pin[i],HIGH);
        for(int j=0; j<COL_NUM; j++){
            current_key_state[i][j] = digitalRead(col_pin[j]);
            if(current_key_state[i][j] != before_key_state[i][j]){
                if(current_key_state[i][j] == HIGH){
                    if(current_keymap[i][j] >= 0xF0){
                        Keyboard.press(KC_Z);
                    }else{
                        Keyboard.press(current_keymap[i][j]);
                    }
                }else{
                    if(current_keymap[i][j] >= 0xF0){
                      Keyboard.release(KC_Z);
                    }else{
                        Keyboard.release(current_keymap[i][j]);
                    }
                }
                before_key_state[i][j] = current_key_state[i][j];
            }
        }
        digitalWrite(row_pin[i],LOW);
    }
}

void Key::changeLayer(uint8_t current_layer[ROW_NUM][COL_NUM], uint8_t to_layer){
}

const uint8_t Key::default_keymap[ROW_NUM][COL_NUM] = {
    {KC_A, _DEFAULT}
};

const uint8_t Key::rower_keymap[ROW_NUM][COL_NUM] = {
    {KC_C, KC_B}
};
