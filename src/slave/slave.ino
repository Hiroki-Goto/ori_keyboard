#include <Wire.h>
#include "param.h"
#include "key_slave.h"

KeySlave keySlave(0);

void setup() {
  // put your setup code here, to run once:
     //Serial.begin(9600);
     Serial1.begin(9600);
     Wire.begin(8);// Slave ID #8
}

void loop() {
  // put your main code here, to run repeatedly:
    keySlave.scanMatrix();
}
