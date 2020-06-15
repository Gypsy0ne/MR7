#include "Pumps.h"

#include "Config.h"
#include "Multiplexers.h"
#include "ShiftRegister.h"
#include "Time.h"
#include "Arduino.h"

void runSinglePump(int channel) {
    unsigned long t = millis();
    setPumpMuxChannel(channel);
    Serial.println((String) "Pump " + channel + " activated.");
    do {

    }while(!checkTimeSeconds(PUMP_WORKTIME_SECONDS[channel], t));
    SR_resetStorage();
}

void runFlaggedPumps(bool sensorFlags[], int cycles[]) {
    for(int i = 0; i < PUMPS_QTY; i++)
        if(sensorFlags[i]){
            runSinglePump(i);
            cycles[i]++;
        }
}