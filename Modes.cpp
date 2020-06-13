#include "Modes.h"

#include "Config.h"
#include "Multiplexers.h"
#include "Moisture.h"
#include "Sensors.h"

void justRead(int readChannels[]){
    readSensors(A0, readChannels);
    printSensors(readChannels);
}

void flags(int readChannels[], bool sensorFlags[], int cycles[]){
    if(SENSORS_QTY >= 8)
        readSensors(A0, A1, readChannels);
    else
        readSensors(A0, readChannels);

    for(int i = 0; i < 8; i++){
        if(isDry(readChannels[i], MOISTURE_THRESHOLD_PERCENTAGE[i]) == 1)
            sensorFlags[i] = 1;
    }

    if(SENSORS_QTY >= 8)
        for(int i = 8; i < 16; i++){
            if(isDry(readChannels[i], MOISTURE_THRESHOLD_PERCENTAGE[i]) == 1)
                sensorFlags[i] = 1;
    }

    for(int i = 0; i < PUMPS_QTY; i++){
        if(sensorFlags[i] == 1){
            setPump(i);
            delay((unsigned long)PUMP_WORKTIME_SECONDS[i]*1000);
            cycles[i]++;
        }
    }

    for(int i = 0; i < SENSORS_QTY; i++)
        sensorFlags[i] = 0;
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