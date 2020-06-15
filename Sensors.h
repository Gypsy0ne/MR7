#ifndef Sensors_h
#define Sensors_h

void getSensorReads(int analogPin1, int readChannels[]);
void getSensorReads(int analogPin1, int analogPin2, int readChannels[]);
void printSensorReads(int readChannels[], int cycles[]);
void printSensorReads(int readChannels[]);
void collectFlags(int readChannels[], bool sensorFlags[]);
void clearFlags(bool sensorFlags[]);
bool isDry(int& read, const int moistureThresholdPercentage);
void calibrateSensors(); // Obligatory first command after Arduino start and after every pump activation. Maybe obsolete when muxes are controlled by seperate pins - research needed.


#endif  
