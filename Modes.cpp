#include "Modes.h"

#include "Config.h"
#include "Moisture.h"
#include "Sensors.h"
#include "Pumps.h"
#include "Arduino.h"

void justRead(int Read_Channels[]){
    readSensors(A0, Read_Channels);
    printSensors(SENSORS_QTY, Read_Channels);
}

void Pair(int Channel, int Moisture_Threshold_Percentage, int Pumps_Worktime_Seconds, int Read_Channels[], int Cycles[]){  
    if(map(Read_Channels[Channel], DRY_THRESHOLD, WET_THRESHOLD, 0, 100) < Moisture_Threshold_Percentage){
        activatePump(Channel, Pumps_Worktime_Seconds);
        Cycles[Channel]++;
        calibrateSensors();
    }
}    