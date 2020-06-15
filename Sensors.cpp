#include "Sensors.h"

#include "Config.h"
#include "Moisture.h"
#include "Multiplexers.h"
#include "Time.h"
#include "Arduino.h"

void getSensorReads(int analogPin1, int readChannels[]) {
    for(int i = 0; i < 8; i++) {
        setSensorMuxChannel(i);
        readChannels[i]=analogRead(analogPin1);
    }
}

void getSensorReads(int analogPin1, int analogPin2, int readChannels[]) {
    for(int i = 0; i < SENSORS_QTY; i++) {
        setSensorMuxChannel(i);
        if(i <= 8)
            readChannels[i]=analogRead(analogPin1);
        else
            readChannels[i]=analogRead(analogPin2);
    }
}

void printSensorReads(int readChannels[], int cycles[]) {
    for(int i = 0; i < SENSORS_QTY; i++) {
        Serial.print((String)" " + i + "(" + cycles[i] + ")" + ": " + readMoistureInPercent(readChannels[i]) + "%");
    }
    Serial.print("\n");
}

void printSensorReads(int readChannels[]) {
    for(int i = 0; i < SENSORS_QTY; i++) {
        Serial.print((String)" " + i + ": " + readMoistureInPercent(readChannels[i]) + "%" + " (" + readChannels[i] + ")");
    }
    Serial.print("\n");
}

bool isDry(int& read, const int moistureThresholdPercentage) {
    if(map(read, DRY_THRESHOLD, WET_THRESHOLD, 0, 100) < moistureThresholdPercentage)
        return 1;
    else
        return 0;
}

void collectFlags(int readChannels[], bool sensorFlags[]) {
    for(int i = 0; i < SENSORS_QTY; i++)
        if(isDry(readChannels[i], MOISTURE_THRESHOLD_PERCENTAGE[i]))
            sensorFlags[i] = 1;
}

void clearFlags(bool sensorFlags[]) {
    for(int i = 0; i < SENSORS_QTY; i++)
        sensorFlags[i] = 0;
}

void calibrateSensors() {
    unsigned long t=millis();
    int seconder = SENSOR_CALIBRATING_TIME;
    Serial.println((String)"Calibrating sensors... " + "[" + (seconder) + "s left]");                    
    do {
        if(countSeconds(10,t)) {
            Serial.println((String)"Calibrating sensors... " + "[" + (seconder) + "s left]");
            seconder-=10;
            t=millis();
            for(int i = 0; i<SENSORS_QTY; i++) {
                setSensorMuxChannel(i);
                analogRead(A0);
                analogRead(A1); // After pumps interrupt sensor reads, further read values are going crazy. Reading the sensors seems to be necessary for stabilization.
            }
        }
    }while(seconder>0);
}