#include "Modes.h"

#include "Config.h"
#include "Multiplexers.h"
#include "Moisture.h"
#include "Sensors.h"

void justRead(int readChannels[]){
    readSensors(A0, readChannels);
    printSensors(readChannels);
}


/* void pair(int channel, int moistureThresholdPercentage, int pumpsWorktimeSeconds, int readChannels[], int cycles[]){  
    if(map(readChannels[channel], DRY_THRESHOLD, WET_THRESHOLD, 0, 100) < moistureThresholdPercentage){
        setPump(channel, 0);
        delay(pumpsWorktimeSeconds*1000);
        cycles[channel]++;
        calibrateSensors();
    }
}    
    //nie podoba mi sie
*/