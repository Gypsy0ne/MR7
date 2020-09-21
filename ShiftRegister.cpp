#include "ShiftRegister.h"

#include "Arduino.h"

ShiftRegister::ShiftRegister() {
    resetStorage();
}

void ShiftRegister::resetStorage() {
    digitalWrite(_latch, HIGH);
    digitalWrite(_data, LOW);
    for(int i = 0; i < 8; i++){
        digitalWrite(_shift, HIGH);
        digitalWrite(_shift, LOW);
    }
    digitalWrite(_latch, LOW);
}

void ShiftRegister::addBit(bool state, int howMany) {
    digitalWrite(_data, state);
    for(int i = 0; i < howMany; i++){
        digitalWrite(_shift, HIGH);
        digitalWrite(_shift, LOW);
    }
}

void ShiftRegister::activateLatch() {
    digitalWrite(_latch, HIGH);
    digitalWrite(_latch, LOW);
}

void ShiftRegister::latchBitSequence(int sequence) {
    int digit[8];
    int i = 0;
    while (sequence) { // translate sequence into array
        digit[i++] = sequence % 10;
        sequence /= 10;
    }
    for(; i >= 0 ;) {
        addBit(digit[i--]);
    }
    activateLatch();
}