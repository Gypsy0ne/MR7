#include "Time.h"

#include "Arduino.h"

bool setTime(unsigned long& Time_Mark){
    if(Time_Mark == 0){
        Time_Mark = millis();
        return 1; 
    }
    else
        return 0;
}

bool countSeconds(unsigned long Seconds, unsigned long& Time_Mark){
    unsigned long t=millis();
    if(t-Time_Mark>Seconds*1000)
        return 1;
    else
        return 0;
}

bool checkTimeMinutes(unsigned long Count, unsigned long& Time_Mark){
    unsigned long current_time = millis();
    if(current_time - Time_Mark >= Count*60000){
        Time_Mark = 0;
        return 1;
    }
    else 
        return 0;
}

bool checkTimeSeconds(unsigned long Count, unsigned long& Time_Mark){
    unsigned long current_time = millis();
    if(current_time - Time_Mark >= Count*1000){
        Time_Mark = 0;
        return 1;
    }
    else
        return 0;
}
