#include "Pumps.h"

#include "Config.h"
#include "Multiplexers.h"
#include "ShiftRegister.h"
#include "Time.h"
#include "Arduino.h"

Pump::Pump(int worktime, int channel) {
    _worktime = worktime;
    _channel = channel;
}

void Pump::on() {
    if(_channel < 8) {
        digitalWrite(_activatingPin1, HIGH);
    } else {
        digitalWrite(_activatingPin2, HIGH);
    }
}

void Pump::off() {
    if(_channel < 8) {
        digitalWrite(_activatingPin1, LOW);
    } else {
        digitalWrite(_activatingPin2, LOW);
    }
}

bool Pump::timesUp() {
    unsigned long t = millis();
    if(t - _timer >= _worktime*1000) {
        return 1;
    } else {
        return 0;
    }
}

void Pump::activate() {
    PumpMuxDuo Pmd(_channel);
    on();
    _timer = millis();
    // if(currentControl)
        Serial.println((String) "Pump " + _channel + " activated.");
}

void runFlaggedPumps(bool sensorFlags[], int cycles[]) {
    for(int i = 0; i < PUMPS_QTY; i++)
        if(sensorFlags[i]){
            runSinglePump(i);
            cycles[i]++;
        }
}