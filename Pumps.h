#ifndef Pumps_h
#define Pumps_h

bool setAllPumps(int Sensor_Values[], const int Moisture_Threshold_Percentage, const unsigned long Working_Time_Seconds); // Sets all pumps on equal conditions. Returns 1 when a pump gets activated.
void activatePump(const int Pump_Number, const unsigned long Working_Time_Seconds); // Activates a specific pump. Pump_Number is the multiplexer channel the pump is on.

#endif  
