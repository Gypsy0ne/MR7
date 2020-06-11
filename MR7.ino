#include "Config.h"
#include "Modes.h"
#include "Multiplexers.h"
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
    pinMode(SR_LATCH, OUTPUT);
    pinMode(SR_DATA, OUTPUT); 
    pinMode(SR_SHIFT, OUTPUT);   
}


void loop(){ // tested like this. all fine. sensors still need a break(calibration) after a pump kicks off.
  digitalWrite(SR_LATCH, LOW);
  readSensors(A0, readChannels);
  printSensors(readChannels);
  if(readChannels[4] > 426)
  setPump(4, 0);
  delay(5000);
  readSensors(A1, readChannels);
  printSensors(readChannels);
  if(readChannels[4] > 426)
  setPump(4, 1);
  delay(5000);
}



/*void loop() {
    digitalWrite(SR_LATCH, LOW);
    calibrateSensors(); // Sometimes, sensors need time to catch up with the real value. It happens when sensors are planted in various moisture levels.
    while(1){
        t=millis();
        while(1){
            if(checkTimeSeconds(10, t)==1){ // Returns 1 when 10 seconds passes since t
                readSensors(A0, readChannels);
                printSensors(readChannels, cycles);
                pair(0, 50, 5, readChannels, cycles); // (Channel, Moisture_Threshold_Percentage, Pump_Worktime_Seconds, table of reads, table to keep cycles record)
                pair(1, 40, 10, readChannels, cycles);
                break;
            }
        }
    }

}
*/
