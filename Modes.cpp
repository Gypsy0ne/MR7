#include "Modes.h"

#include "Config.h"
#include "Moisture.h"
#include "Sensors.h"
#include "Pumps.h"
#include "Arduino.h"

void justRead(int readChannels[]){
    readSensors(A0, readChannels);
    printSensors(readChannels);
}

void pair(int channel, int moistureThresholdPercentage, int pumpsWorktimeSeconds, int readChannels[], int cycles[]){  
    if(map(readChannels[channel], DRY_THRESHOLD, WET_THRESHOLD, 0, 100) < moistureThresholdPercentage){
        activatePump(channel, pumpsWorktimeSeconds);
        cycles[channel]++;
        calibrateSensors();
    }
}    