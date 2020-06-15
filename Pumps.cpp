#include "Pumps.h"

#include "Config.h"
#include "Multiplexers.h"
#include "Arduino.h"

void runSinglePump(int channel) {
    setPumpMuxChannel(channel);
    delay((unsigned long)PUMP_WORKTIME_SECONDS[channel]*1000);
}

void runFlaggedPumps(bool sensorFlags[], int cycles[]) {
    for(int i = 0; i < PUMPS_QTY; i++)
        if(sensorFlags[i]){
            runSinglePump(i);
            cycles[i]++;
        }
}