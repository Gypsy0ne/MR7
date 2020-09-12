#include "Config.h"
#include "Sensors.h"
#include "Pumps.h"
#include "Modes.h"
#include "Arduino.h"

// TODO: error control for pumps (measure current between VCC and collectors. Analog reads on both nodes of a resistor in a common control line.)


int readChannels[SENSORS_QTY] = {0}; // Table for sensor reads.
bool sensorFlags[SENSORS_QTY] = {0};
int cycles[SENSORS_QTY] = {0}; // Counts pump activations.
unsigned long t = 0;

configData dataSet;
Pump PumpArray[PUMPS_QTY];
MoistureSensor MsArray[SENSORS_QTY];

void setup() {
    Serial.begin(9600);
    pinMode(SR_LATCH, OUTPUT);
    pinMode(SR_DATA, OUTPUT); 
    pinMode(SR_SHIFT, OUTPUT);   
    pinMode(TEMP_SENSOR, INPUT);
    pinMode(PUMP1, OUTPUT);
    pinMode(PUMP2, OUTPUT);
    pinMode(ENC_L, INPUT);
    pinMode(ENC_R, INPUT);
    pinMode(ENC_BUTTON, INPUT_PULLUP);

    for(int i = 0; i < PUMPS_QTY; i++) {
        PumpArray[i].setParameters(i, dataSet.worktimeGetter(i), i);
        if (i < 7) {
            MsArray[i].setParameters(i, dataSet.thresholdGetter(i), i);
        } else {
            MsArray[i].setParameters(i, dataSet.thresholdGetter(i), i, A1);
        }
    }
}

void setSensorFlags() {
    for (int i = 0; i < SENSORS_QTY; i++) {
        MsArray[i].setFlag();
    }
}

void supplyFlaggedSensors() {
    for (int i = 0; i < SENSORS_QTY; i++) {
        if (MsArray[i].checkFlag()) {
            PumpArray[i].run();
            MsArray[i].clearFlag();
        }
    }
}

void loop() {
    setSensorFlags();
    supplyFlaggedSensors();
}
