#include "Modes.h"

#include "Config.h"
#include "Time.h"
#include "Multiplexers.h"
#include "Sensors.h"
#include "Pumps.h"
#include "Arduino.h"

void flagSystem(int readChannels[], bool sensorFlags[], int cycles[], unsigned long time) {
    calibrateSensors();
    time = millis();
    while(1){
        if(checkTimeMinutes(60, time) == 1) {
            digitalWrite(SR_LATCH, LOW);
            getSensorReads(A0, readChannels);
            collectFlags(readChannels, sensorFlags);
            runFlaggedPumps(sensorFlags, cycles);
            printSensorReads(readChannels, cycles);
            break;
        }
    }
}