#include "Moisture.h"
#include "Config.h"
#include "Arduino.h"

int readMoistureInPercent(int& sensorRead) {
    return map(sensorRead, DRY_THRESHOLD, WET_THRESHOLD, 0, 100);
}

float readMoistureInVolts(int& sensorRead) {
    return sensorRead / 1023.0 * INPUT_VOLTAGE;
}
