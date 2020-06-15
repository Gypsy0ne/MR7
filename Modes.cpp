#include "Modes.h"

#include "Config.h"
#include "Multiplexers.h"
#include "Moisture.h"
#include "Sensors.h"

void readAndPrint(int pin, int readChannels[]) {
    getSensorReads(pin, readChannels);
    printSensorReads(readChannels);
}

void readAndPrint(int pin, int pin2, int readChannels[]) {
    getSensorReads(pin, pin2, readChannels);
    printSensorReads(readChannels);
}

void collectFlags(int readChannels[], bool sensorFlags[]) {
    for(int i = 0; i < SENSORS_QTY; i++)
        if(isDry(readChannels[i], MOISTURE_THRESHOLD_PERCENTAGE[i]))
            sensorFlags[i] = 1;
}

void runFlaggedPumps(bool sensorFlags[], int cycles[]) {
    for(int i = 0; i < PUMPS_QTY; i++)
        if(sensorFlags[i]){
            setPumpMuxChannel(i);
            delay((unsigned long)PUMP_WORKTIME_SECONDS[i]*1000);
            cycles[i]++;
        }

    for(int i = 0; i < SENSORS_QTY; i++)
        sensorFlags[i] = 0;
}