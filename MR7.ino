#include "Config.h"
#include "Modes.h"
#include "Temperature.h"
#include "Arduino.h"

// TODO: error control for pumps (measure current between VCC and collectors. Analog reads on both nodes of a resistor in a common control line.)

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
    pinMode(PUMP1, OUTPUT);
    pinMode(PUMP2, OUTPUT);
}


void loop() {
    flagSystem(readChannels, sensorFlags, cycles, t);
}
