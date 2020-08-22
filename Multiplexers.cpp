#include "Multiplexers.h"

#include "ShiftRegister.h"
#include "Arduino.h"

// Hardware note: The same channel is set for both sensor MUXes. One MUX is connected to, for example, A0 and the other A1. 
void SensorMuxDuo::setChannel(int channel) { 
    ShiftRegister SR;
    switch(channel) { // Q0/a Q1/b Q2/c
        case 0: // 0 0 0 
            delay(1); // Give the mux some time to process the redirection.
            break;
        case 1: // 1 0 0
            SR.latchBitSequence(1);
            delay(1);
            break;
        case 2: // 0 1 0
            SR.latchBitSequence(10);
            delay(1);
            break;
        case 3: // 1 1 0
            SR.latchBitSequence(11);
            delay(1);
            break;
        case 4: // 0 0 1
            SR.latchBitSequence(100);
            delay(1);
            break;
        case 5: // 1 0 1
            SR.latchBitSequence(101);
            delay(1);
            break;
        case 6: // 0 1 1
            SR.latchBitSequence(110);
            delay(1);
            break;
        case 7:  // 1 1 1
            SR.latchBitSequence(111);
            delay(1);
            break;
    }
}

// Hardware note: Same channel is set for both muxes, last two digits may determine which one gets high input.
void PumpMuxDuo::setChannel(int channel) { 
    ShiftRegister SR;
    switch(channel) { // Q3/a Q4/b Q5/c
        case 0: // 0 0 0 0 0 0  0 1
            SR.latchBitSequence(10000000);
            delay(1); // Give the mux some time to process the redirection.
            break;
        case 1: // 0 0 0 1 0 0  0 1
            SR.latchBitSequence(10001000);
            delay(1);
            break;
        case 2: // 0 0 0 0 1 0  0 1
            SR.latchBitSequence(10010000);
            delay(1);
            break;
        case 3: // 0 0 0 1 1 0  0 1
            SR.latchBitSequence(10011000);
            delay(1);
            break;
        case 4: // 0 0 0 0 0 1  0 1
            SR.latchBitSequence(10100000);
            delay(1);
            break;
        case 5: // 0 0 0 1 0 1  0 1
            SR.latchBitSequence(10101000);
            delay(1);
            break;
        case 6: // 0 0 0 0 1 1  0 1
            SR.latchBitSequence(10110000);
            delay(1);
            break;
        case 7: // 0 0 0 1 1 1  0 1
            SR.latchBitSequence(10111000);
            delay(1);
            break;
        case 8: // 0 0 0 0 0 0  1 0
            SR.latchBitSequence(1000000);
            delay(1); // Give the mux some time to process the redirection.
            break;
        case 9: // 0 0 0 1 0 0  1 0
            SR.latchBitSequence(1001000);
            delay(1);
            break;
        case 10: // 0 0 0 0 1 0  1 0
            SR.latchBitSequence(1010000);
            delay(1);
            break;
        case 11: // 0 0 0 1 1 0  1 0
            SR.latchBitSequence(1011000);
            delay(1);
            break;
        case 12: // 0 0 0 0 0 1  1 0
            SR.latchBitSequence(1100000);
            delay(1);
            break;
        case 13: // 0 0 0 1 0 1  1 0
            SR.latchBitSequence(1101000);
            delay(1);
            break;
        case 14: // 0 0 0 0 1 1  1 0
            SR.latchBitSequence(1110000);
            delay(1);
            break;
        case 15: // 0 0 0 1 1 1  1 0
            SR.latchBitSequence(1111000);
            delay(1);
            break;
    }
}
