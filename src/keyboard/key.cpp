#include <Keyboard.h>
#include <string.h>

#include "Arduino.h"
#include "key.h"
//#include "keymap.h"


Key::Key(int a){
    for(int i=0; i<ROW_NUM; i++){
        pinMode(row_pin[i],OUTPUT);
    }
    for(int i=0; i<COL_NUM; i++){
        pinMode(col_pin[i],INPUT_PULLUP);
    }

    for(int i=0; i<ROW_NUM; i++){
        for(int j=0; j<COL_NUM; j++){
            current_key_state[i][j] = HIGH;
            before_key_state[i][j] = HIGH;

            current_keymap[i][j] = default_keymap[i][j];
        }
        digitalWrite(row_pin[i], HIGH);
    }

    change_layer = false;
}

void Key::scanMatrix(keyboradState *keyboard_state){
    for(int i=0; i<ROW_NUM; i++){
        digitalWrite(row_pin[i],LOW);
        for(int j=0; j<COL_NUM; j++){
            current_key_state[i][j] = digitalRead(col_pin[j]);
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
                      //Keyboard.release(KC_Z);
                    }else{
                        Keyboard.release(current_keymap[i][j]);
                    }
                }
                before_key_state[i][j] = current_key_state[i][j];
            }
        }
        digitalWrite(row_pin[i],HIGH);
    }

    if(change_layer){
        //keyboard_state.current_layer = to_layer;
        changeLayer(to_layer);
        change_layer = false;
    }
}

void Key::changeLayer(uint8_t layer){


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
