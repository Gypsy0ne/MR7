#ifndef Moisture_h
#define Moisture_h

#include "Arduino.h"

const int DRY_THRESHOLD = 620;
const int WET_THRESHOLD = 255;
const float INPUT_VOLTAGE = 5.0;

int readMoistureInPercent(int pin);
float readMoistureInVolts(int pin);

#endif
