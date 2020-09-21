#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Config.h"
/* In such case of the code, connections on the register are fixed in a specific order: 
SENSOR MULTIPLEXERS(a, b, c) - Q0, Q1, Q2; 
PUMP MULTIPLEXERS - Q3-Q5; 
Q6 and Q7 are for pump activation. (CRUCIAL! Transistors activated with Q6 Q7 must have maximum Ib (base current) of 30 mA (max. source current of Q outputs))*/

// MODEL: https://pdf1.alldatasheet.com/datasheet-pdf/view/15644/PHILIPS/74HC595.html


class ShiftRegister {
    protected:
        int _latch = SR_LATCH;
        int _data = SR_DATA;
        int _shift = SR_SHIFT;
    public:
        ShiftRegister();
        void resetStorage();
        void addBit(bool state, int howMany=1);
        void activateLatch();
        // reversal sequence. Example: if you want 001101, sequence = 101100
        void latchBitSequence(int sequence);
};

#endif
