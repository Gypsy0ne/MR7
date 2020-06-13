#include "Sensors.h"

#include "Config.h"
#include "Moisture.h"
#include "Multiplexers.h"
#include "Time.h"
#include "Arduino.h"

/*void readSensors(int analogPin, int Read[]){ // Sets multiplexer controls in a chronological order ( 0 0 0; 0 0 1; 0 1 0; etc.) while getting a value from each sensor. Fajne ale chyba mało eleganckie
    int sensor_number = 0;
    bool break_nest = 0;
    for(int i=0;i<2;i++){
        if(break_nest == 1) break;
        for(int b=0;b<2;b++){
            if(break_nest == 1) break;
            for(int a=0;a<2;a++){
                digitalWrite(MUX_CONTROL[2],i);
                digitalWrite(MUX_CONTROL[1],b);
                digitalWrite(MUX_CONTROL[0],a);
                delay(1);
                Read[sensor_number]=analogRead(analogPin);
                sensor_number++;
                if(sensor_number>=SENSORS_QTY){
                    break_nest = 1;
                    break;
                }
            }
        }
    }
}*/

void readSensors(int analogPin, int read[]){
    for(int i = 0; i < SENSORS_QTY; i++) {
        setSensor(i);
        read[i]=analogRead(analogPin);
    }
}


void printSensors(int readChannels[], int cycles[]){
    for(int i = 0; i < SENSORS_QTY; i++) {
        Serial.print((String)" " + i + "(" + cycles[i] + ")" + ": " + readMoistureInPercent(readChannels[i]) + "%");
    }
    Serial.print("\n");
}

void printSensors(int readChannels[]){
    for(int i = 0; i < SENSORS_QTY; i++) {
        Serial.print((String)" " + i + ": " + readMoistureInPercent(readChannels[i]) + "%" + " (" + readChannels[i] + ")");
    }
    Serial.print("\n");
}


void calibrateSensors(){
    unsigned long t=millis();
    int seconder = SENSOR_CALIBRATING_TIME;                    
    do{
        if(countSeconds(1,t)){
            Serial.println((String)"Calibrating sensors... " + "[" + (seconder) + "]");
            seconder--;
            t=millis();
            for(int i = 0; i<SENSORS_QTY; i++)
                setSensor(i);
                analogRead(A0);
                analogRead(A1); // After pumps interrupt sensor reads, further read values are going crazy. Reading the sensors seems to be necessary for stabilization.
            }
    }while(seconder>0);
}

bool isDry(int& channel, int& moistureThresholdPercentage, int readChannels[]){
    if(map(readChannels[channel], DRY_THRESHOLD, WET_THRESHOLD, 0, 100) < moistureThresholdPercentage)
        return 1;
    else
        return 0;
}