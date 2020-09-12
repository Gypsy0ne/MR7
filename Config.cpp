#include "Config.h"
#include "Arduino.h"

configData::configData() {
//                                         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
    int moistureThresholdPercentage[16] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
    int pumpWorktimeSeconds[16] =         {5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5};
    int sensorCalibratingTime = 5;
}

int configData::thresholdGetter(int ID) {
    return moistureThresholdPercentage[ID];
}

bool configData::thresholdSetter(int ID, int value) {
    if(value < 100 && ID <= SENSORS_QTY) {
        moistureThresholdPercentage[ID] = value;
    } else {
        Serial.println("thresholdSetter(): Wrong input.");
        return 0;
    }
}

int configData::worktimeGetter(int ID) {
    return pumpWorktimeSeconds[ID];
}

bool configData::worktimeSetter(int ID, int value) {
    if(value > 0 && ID <= PUMPS_QTY) {
        pumpWorktimeSeconds[ID] = value;
    } else {
        Serial.println("worktimeSetter(): Wrong input.");
        return 0;
    }
}