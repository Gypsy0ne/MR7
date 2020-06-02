#include "Pumps.h"

#include "Config.h"
#include "Multiplexers.h"
#include "Arduino.h"

bool setAllPumps(int Sensor_Values[], const int& Moisture_Threshold_Percentage, const unsigned long& Working_Time_Seconds){
    unsigned long time_start = 0, time_end = 0;
    for(int pump_number = 0; pump_number<PUMPS_QTY; pump_number++) // Check every sensor read one after another.
        if(map(Sensor_Values[pump_number], DRY_THRESHOLD, WET_THRESHOLD, 0, 100) < Moisture_Threshold_Percentage){ // If an x read is below the threshold
            setMuxChannel(pump_number); // set mux channel x
            time_start = millis();
            digitalWrite(PUMPING_PIN, HIGH); // activate pump 
            do{
                time_end = millis();
            }while(time_end - time_start < Working_Time_Seconds*1000); // for duration of Working_Time_Seconds.
            digitalWrite(PUMPING_PIN, LOW);
            delay(20000); // reset sensors.
            return 1; // a pump was activated!
        }
    return 0;    
}       

void activatePump(const int& Pump_Number, const unsigned long& Working_Time_Seconds){
    unsigned long time_start = 0, time_end = 0; 
    setMuxChannel(Pump_Number);
    digitalWrite(PUMPING_PIN, HIGH);
    time_start = millis();
    do{
        time_end = millis();
    }while(time_end - time_start < Working_Time_Seconds*1000);
    digitalWrite(PUMPING_PIN, LOW);   
}
