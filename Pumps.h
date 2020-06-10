#ifndef Pumps_h
#define Pumps_h

bool setAllPumps(int sensorValues[], const int moistureThresholdPercentage, const unsigned long workingTimeSeconds); // Sets all pumps on equal conditions. Returns 1 when a pump gets activated.
void activatePump(const int pumpNumber, const unsigned long workingTimeSeconds); // Activates a specific pump. pumpNumber is the multiplexer channel the pump is on.

#endif  
