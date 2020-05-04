#include "Moisture.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
    Serial.println((String)readMoistureInPercent(0) + "%");
    Serial.println((String)readMoistureInVolts(0) + "V");
    delay(1000);
}
