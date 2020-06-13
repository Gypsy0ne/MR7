#ifndef Sensors_h
#define Sensors_h

void readSensors(int analogPin, int readChannels[]); // Reads all available sensors (how many determined by Sensors_Qty) and passes values to read[].
void printSensors(int readChannels[], int cycles[]); // Prints all available sensor reads (how many determined by Sensors_Qty) in moisture %.
void printSensors(int readChannels[]);
void calibrateSensors(); // Obligatory first command after Arduino start and after every pump activation. Maybe obsolete when muxes are controlled by seperate pins - research needed.
bool isDry(int& channel, int& moistureThresholdPercentage, int readChannels[]); // Return 1 if readChannels[channel](mapped %) < moistureThresholdPercentage.

#endif  
