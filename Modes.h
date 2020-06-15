#ifndef Modes_h
#define Modes_h

// Header for working modes of the MR7. 

void readAndPrint(int pin, int readChannels[]);

void readAndPrint(int pin, int pin2, int readChannels[]);

void collectFlags(int readChannels[], bool sensorFlags[]);

void runFlaggedPumps(bool sensorFlags[], int cycles[]);

#endif
