#include "Config.h"
#include "Modes.h"
#include "Multiplexers.h"
#include "Sensors.h"
#include "Time.h"
#include "Arduino.h"

// wysoka czestotliwosc odczytu (czesciej niz 1/s) spowalnia stabilizacje czujnika

int readChannels[SENSORS_QTY] = {0}; // Table for sensor reads.
bool sensorFlags[SENSORS_QTY] = {0};
int cycles[SENSORS_QTY] = {0}; // Counts pump activations.
unsigned long t = 0;

void setup() {
    Serial.begin(9600);
    pinMode(SR_LATCH, OUTPUT);
    pinMode(SR_DATA, OUTPUT); 
    pinMode(SR_SHIFT, OUTPUT);   
}


void loop() {
    flagSystem(readChannels, sensorFlags, cycles, t);
}

