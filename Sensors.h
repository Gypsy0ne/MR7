#ifndef Sensors_h
#define Sensors_h

void readSensors(int Analog_Pin, int Read[]); // Reads all available sensors (how many determined by Sensors_Qty) and passes values to Read[].
void printSensors(const int Sensors_Qty, int Read_Channels[], int Cycles[]); // Prints all available sensor reads (how many determined by Sensors_Qty) in moisture %.
void printSensors(const int Sensors_Qty, int Read_Channels[]);
void calibrateSensors(); // Obligatory first command after Arduino start and after every pump activation. Maybe obsolete when muxes are controlled by seperate pins - research needed.
#endif  
