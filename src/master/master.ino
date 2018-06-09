#include <Wire.h>
#include <Keyboard.h>

#include <Mouse.h>


#include "key_master.h"
#include "param.h"
//#include "keycode.h"
#include "OLED.h"

KeyMaster keyMaster(0);
OLED oled(0);
keyboradState keyboard_state_t;

void setup() {
    keyboard_state_t.current_layer = _DEFAULT;
    keyboard_state_t.num_lock = false;
    keyboard_state_t.caps_lock = false;
    keyboard_state_t.scr_lock = false;

    Serial.begin(9600);
    Serial1.begin(9600);
    Keyboard.begin();
    Wire.begin();
}

void loop() {
    keyMaster.scanMatrix(&keyboard_state_t);
    oled.display(&keyboard_state_t);
}
