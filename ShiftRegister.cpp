#include "ShiftRegister.h"

#include "Config.h"
#include "Arduino.h"

void SR_resetStorage() {
    digitalWrite(SR_LATCH, HIGH);
    digitalWrite(SR_DATA, LOW);
    for(int i = 0; i < 8; i++){
        digitalWrite(SR_SHIFT, HIGH);
        digitalWrite(SR_SHIFT, LOW);
    }
    digitalWrite(SR_LATCH, LOW);
}

void SR_addBit(bool state, int howMany) {
    digitalWrite(SR_DATA, state);
    for(int i = 0; i < howMany; i++){
        digitalWrite(SR_SHIFT, HIGH);
        digitalWrite(SR_SHIFT, LOW);
    }
}

void SR_activateLatch() {
    digitalWrite(SR_LATCH, HIGH);
    digitalWrite(SR_LATCH, LOW);
}

void SR_addBitSequence(int sequence) {
    int digit[8];
    int q = 0;
    while (sequence) {
        digit[q++] = sequence % 10;
        sequence /= 10;
    }
    for(int i = 0; i < q; i++) {
        SR_addBit(digit[i]);
    }
}