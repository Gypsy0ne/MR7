#include "Moisture.h"
#include "Arduino.h"

int readMoistureInPercent(int pin) {
    int sensorRead = analogRead(pin);
    return map(sensorRead, DRY_THRESHOLD, WET_THRESHOLD, 0, 100);
}

float readMoistureInVolts(int pin) {
    return analogRead(pin) / 1023.0 * INPUT_VOLTAGE;
}
