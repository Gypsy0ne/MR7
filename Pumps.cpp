#include "Pumps.h"

#include "Config.h"
#include "Multiplexers.h"
#include "Arduino.h"
// OBSOLETE.

/*
bool setAllPumps(int sensorValues[], const int moistureThresholdPercentage, const unsigned long workingTimeSeconds){
    unsigned long timeStart = 0, timeEnd = 0;
    for(int pumpNumber = 0; pumpNumber<PUMPS_QTY; pumpNumber++) // Check every sensor read one after another.
        if(map(sensorValues[pumpNumber], DRY_THRESHOLD, WET_THRESHOLD, 0, 100) < moistureThresholdPercentage){ // If an x read is below the threshold
            setMuxChannel(pumpNumber); // set mux channel x
            timeStart = millis();
            digitalWrite(PUMPING_PIN, HIGH); // activate pump 
            do{
                timeEnd = millis();
            }while(timeEnd - timeStart < workingTimeSeconds*1000); // for duration of workingTimeSeconds.
            digitalWrite(PUMPING_PIN, LOW);
            delay(20000); // reset sensors.
            return 1; // a pump was activated!
        }
    return 0;    
}       

void activatePump(const int pumpNumber, const unsigned long workingTimeSeconds){
    unsigned long timeStart = 0, timeEnd = 0; 
    setMuxChannel(pumpNumber);
    digitalWrite(PUMPING_PIN, HIGH);
    timeStart = millis();
    do{
        timeEnd = millis();
    }while(timeEnd - timeStart < workingTimeSeconds*1000);
    digitalWrite(PUMPING_PIN, LOW);   
}
*/