#include "Config.h"
#include "Modes.h"
#include "Sensors.h"
#include "Time.h"
#include "Arduino.h"

// system flagowy? kazdy odczyt ponizej progu stawia flage -> sprawdz flagi -> odpalaj pompy
// wysoka czestotliwosc odczytu (czesciej niz 1/s) spowalnia stabilizacje czujnika

int readChannels[SENSORS_QTY] = {0}; // Table for sensor reads.
int cycles[SENSORS_QTY] = {0}; // Counts pump activations.
unsigned long t = 0;

void setup() {
    Serial.begin(9600);
    pinMode(MUX_CONTROL[0], OUTPUT);
    pinMode(MUX_CONTROL[1], OUTPUT); 
    pinMode(MUX_CONTROL[2], OUTPUT); 
    pinMode(PUMPING_PIN, OUTPUT);   
}

void loop() {
    calibrateSensors(); // Sometimes, sensors need time to catch up with the real value. It happens when sensors are planted in various moisture levels.
    while(1){
        t=millis();
        while(1){
            if(checkTimeSeconds(10, t)==1){ // Returns 1 when 10 seconds passes since t
                readSensors(A0, readChannels);
                printSensors(SENSORS_QTY, readChannels, cycles);
                pair(0, 50, 5, readChannels, cycles); // (Channel, Moisture_Threshold_Percentage, Pump_Worktime_Seconds, table of reads, table to keep cycles record)
                pair(1, 40, 10, readChannels, cycles);
                break;
            }
        }
    }

}
