#include "Multiplexers.h"

#include "Config.h"
#include "Arduino.h"

void setMuxChannel(int Channel){
    switch(Channel){
        case 0:
            digitalWrite(MUX_CONTROL[2],0);
            digitalWrite(MUX_CONTROL[1],0);
            digitalWrite(MUX_CONTROL[0],0);
            delay(1); // Give the mux some time to process the redirection.
            break;
        case 1:
            digitalWrite(MUX_CONTROL[2],0);
            digitalWrite(MUX_CONTROL[1],0);
            digitalWrite(MUX_CONTROL[0],1);
            delay(1);
            break;
        case 2:
            digitalWrite(MUX_CONTROL[2],0);
            digitalWrite(MUX_CONTROL[1],1);
            digitalWrite(MUX_CONTROL[0],0);
            delay(1);
            break;
        case 3:
            digitalWrite(MUX_CONTROL[2],0);
            digitalWrite(MUX_CONTROL[1],1);
            digitalWrite(MUX_CONTROL[0],1);
            delay(1);
            break;
        case 4:
            digitalWrite(MUX_CONTROL[2],1);
            digitalWrite(MUX_CONTROL[1],0);
            digitalWrite(MUX_CONTROL[0],0);
            delay(1);
            break;
        case 5:
            digitalWrite(MUX_CONTROL[2],1);
            digitalWrite(MUX_CONTROL[1],0);
            digitalWrite(MUX_CONTROL[0],1);
            delay(1);
            break;
        case 6:
            digitalWrite(MUX_CONTROL[2],1);
            digitalWrite(MUX_CONTROL[1],1);
            digitalWrite(MUX_CONTROL[0],0);
            delay(1);
            break;
        case 7:
            digitalWrite(MUX_CONTROL[2],1);
            digitalWrite(MUX_CONTROL[1],1);
            digitalWrite(MUX_CONTROL[0],1);
            delay(1);
            break;
    }
}
