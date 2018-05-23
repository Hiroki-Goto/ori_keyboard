#ifndef OLED_H_
#define OLED_H_

#include "Arduino.h"
#include "param.h"

class OLED{
public:
    OLED(int a);
    void display(keyboradState *keyboard_state);
private:

};

#endif
