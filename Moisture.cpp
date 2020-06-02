#include "Moisture.h"
#include "Config.h"
#include "Arduino.h"

int readMoistureInPercent(int& Sensor_Read) {
    return map(Sensor_Read, DRY_THRESHOLD, WET_THRESHOLD, 0, 100);
}

float readMoistureInVolts(int& Sensor_Read) {
    return Sensor_Read / 1023.0 * INPUT_VOLTAGE;
}
