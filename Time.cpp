#include "Time.h"

#include "Arduino.h"

bool setTime(unsigned long& timeMark){
    if(timeMark == 0){
        timeMark = millis();
        return 1; 
    }
    else
        return 0;
}

bool countSeconds(unsigned long seconds, unsigned long& timeMark){
    unsigned long t=millis();
    if(t-timeMark>seconds*1000)
        return 1;
    else
        return 0;
}

bool checkTimeMinutes(unsigned long count, unsigned long& timeMark){
    unsigned long currentTime = millis();
    if(currentTime - timeMark >= count*60000){
        timeMark = 0;
        return 1;
    }
    else 
        return 0;
}

bool checkTimeSeconds(unsigned long count, unsigned long& timeMark){
    unsigned long currentTime = millis();
    if(currentTime - timeMark >= count*1000){
        timeMark = 0;
        return 1;
    }
    else
        return 0;
}
