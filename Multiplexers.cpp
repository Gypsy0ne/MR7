#include "Multiplexers.h"

#include "Config.h"
#include "ShiftRegister.h"
#include "Arduino.h"

void setSensor(int channel){ // Both sensor MUXes are set to the same channel. One MUX is connected to, for example, A0 and the other A1. 
    SR_resetStorage();
    switch(channel){ // Q0/a Q1/b Q2/c
        case 0: // 0 0 0 
            SR_latchIt();
            delay(1); // Give the mux some time to process the redirection.
            break;
        case 1: // 1 0 0
            SR_addBit(1);
            SR_latchIt();
            delay(1);
            break;
        case 2: // 0 1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_latchIt();
            delay(1);
            break;
        case 3: // 1 1 0
            SR_addBit(1, 2);
            SR_latchIt();
            delay(1);
            break;
        case 4: // 0 0 1
            SR_addBit(1);
            SR_addBit(0, 2);
            SR_latchIt();
            delay(1);
            break;
        case 5: // 1 0 1
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1);
            SR_latchIt();
            delay(1);
            break;
        case 6: // 0 1 1
            SR_addBit(1, 2);
            SR_addBit(0);
            SR_latchIt();
            delay(1);
            break;
        case 7:  // 1 1 1
            SR_addBit(1, 3);
            SR_latchIt();
            delay(1);
            break;
    }
}


void setPump(int channel){ // Activates pump on a given channel, side determines which MUX out of 2.
    SR_resetStorage(); 
    switch(channel){ // Q3/a Q4/b Q5/c Q6/side0 Q7/side1
        case 0: // 0 0 0 0 0 0  0 1
            SR_addBit(0);
            SR_addBit(1);        
            SR_addBit(0, 5);
            SR_latchIt();
            delay(1); // Give the mux some time to process the redirection.
            break;
        case 1: // 0 0 0 1 0 0  0 1
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(0, 2);
            SR_addBit(1);
            SR_addBit(0, 3);
            SR_latchIt();
            delay(1);
            break;
        case 2: // 0 0 0 0 1 0  0 1
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(0, 4);
            SR_latchIt();
            delay(1);
            break;
        case 3: // 0 0 0 1 1 0  0 1
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1, 2);
            SR_addBit(0, 3);
            SR_latchIt();
            delay(1);
            break;
        case 4: // 0 0 0 0 0 1  0 1
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(1);
            SR_addBit(0, 5);
            SR_latchIt();
            delay(1);
            break;
        case 5: // 0 0 0 1 0 1  0 1
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(1, 3);
            SR_latchIt();
            delay(1);
            break;
        case 6: // 0 0 0 0 1 1  0 1
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(1, 2);
            SR_addBit(0, 4);
            SR_latchIt();
            delay(1);
            break;
        case 7: // 0 0 0 1 1 1  0 1
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(1, 3);
            SR_addBit(0, 3);
            SR_latchIt();
            delay(1);
            break;
        case 8: // 0 0 0 0 0 0  1 0
            SR_addBit(1);
            SR_addBit(0);        
            SR_addBit(0, 5);
            SR_latchIt();
            delay(1); // Give the mux some time to process the redirection.
            break;
        case 9: // 0 0 0 1 0 0  1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(0, 2);
            SR_addBit(1);
            SR_addBit(0, 3);
            SR_latchIt();
            delay(1);
            break;
        case 10: // 0 0 0 0 1 0  1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(0, 4);
            SR_latchIt();
            delay(1);
            break;
        case 11: // 0 0 0 1 1 0  1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(0);
            SR_addBit(1, 2);
            SR_addBit(0, 3);
            SR_latchIt();
            delay(1);
            break;
        case 12: // 0 0 0 0 0 1  1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(0, 5);
            SR_latchIt();
            delay(1);
            break;
        case 13: // 0 0 0 1 0 1  1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1);
            SR_addBit(1, 3);
            SR_latchIt();
            delay(1);
            break;
        case 14: // 0 0 0 0 1 1  1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1, 2);
            SR_addBit(0, 4);
            SR_latchIt();
            delay(1);
            break;
        case 15: // 0 0 0 1 1 1  1 0
            SR_addBit(1);
            SR_addBit(0);
            SR_addBit(1, 3);
            SR_addBit(0, 3);
            SR_latchIt();
            delay(1);
            break;
    }
}
