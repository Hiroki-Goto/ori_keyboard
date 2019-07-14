#include <Wire.h>
#include "param.h"
#include "key_slave.h"

KeySlave keySlave(0);

void setup() {
     //Serial.begin(9600);
     Serial1.begin(9600);
     Wire.begin(SLAVE_ID);
     Wire.onRequest(requestEvent);
}

void loop() {
    keySlave.scanMatrix();

}
