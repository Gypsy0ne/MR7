#include "Config.h"
#include "Modes.h"
#include "Temperature.h"
#include "Arduino.h"

int readChannels[SENSORS_QTY] = {0}; // Table for sensor reads.
bool sensorFlags[SENSORS_QTY] = {0};
int cycles[SENSORS_QTY] = {0}; // Counts pump activations.
unsigned long t = 0;

void setup() {
    Serial.begin(9600);
    pinMode(SR_LATCH, OUTPUT);
    pinMode(SR_DATA, OUTPUT); 
    pinMode(SR_SHIFT, OUTPUT);   
    pinMode(TEMP_SENSOR, INPUT);
}


void loop() {
    flagSystem(readChannels, sensorFlags, cycles, t);
}
