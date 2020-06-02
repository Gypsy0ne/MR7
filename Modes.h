#ifndef Modes_h
#define Modes_h

// Header for working modes of the MR7. 
/* Pumps always activate one after another. No simultaneity possible using mux-transistor circuit. If needed, multiple pumps can be connected to a single mux channel (if DC source can provide enough current).
If any pump is activated during the cycle, sensors need 20-60 seconds to stabilize their state. That's (probably) because the muxes are not seperated electrically. 
When sensors are in various moisture zones, they need time to calibrate before program starts (40-60 seconds). This is not an issue when they are in similar moisture. (wtf?)*/

void justRead();

void Pair(int Channel, int Moisture_Threshold_Percentage, int Pumps_Worktime_Seconds, int Read_Channels[], int Cycles[]);
/* Sensors and pumps work in pairs (Channel 0 sensor on mux1 - channel 0 pump on mux2 etc.)
Sets a single pair on the same channel. */

/*
void allPairsEqual(int Seconds_Between_Checks, int Moisture_Threshold_Percentage, int Pumps_Worktime_Seconds);
/* Sensors and pumps work in pairs (Channel 0 sensor on mux1 - channel 0 pump on mux2 etc.)
All pumps have common moisture threshold, below which they are activated. 
*/

#endif
