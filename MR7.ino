#include "Config.h"
#include "Modes.h"
#include "Sensors.h"
#include "Time.h"
#include "Arduino.h"

// system flagowy? kazdy odczyt ponizej progu stawia flage -> sprawdz flagi -> odpalaj pompy
// wysoka czestotliwosc odczytu (czesciej niz 1/s) spowalnia stabilizacje czujnika
// class pair kazda para sensor-pompa jest obiektem?

int read_channels[SENSORS_QTY] = {0}; // Table for sensor reads.
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
    calibrateSensors();
    while(1){
        t=millis();
        while(1){
            if(checkTimeSeconds(10, t)==1){
                readSensors(A0, read_channels);
                printSensors(SENSORS_QTY, read_channels, cycles);
                Pair(0, 50, 5, read_channels, cycles); // (Channel, Moisture_Threshold_Percentage, Pump_Worktime_Seconds, table to keep cycles record)
                Pair(1, 40, 10, read_channels, cycles);
                break;
            }
        }
    }

}
