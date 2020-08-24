#ifndef Config_h
#define Config_h

//Overalls
const int DRY_THRESHOLD = 610;
const int WET_THRESHOLD = 255;
const float INPUT_VOLTAGE = 5.0;

struct configData {

        configData();
        int thresholdGetter(int ID);
        bool thresholdSetter(int ID, int value);
        int worktimeGetter(int ID);
        bool worktimeSetter(int ID, int value);

    private:
        int moistureThresholdPercentage[16];
        int pumpWorktimeSeconds[16];
        int sensorCalibratingTime;

};

//Arduino
const int SR_LATCH = 2; // Shift Register Controls. vv
const int SR_SHIFT = 3;
const int SR_DATA = 4;
const int PUMP1 = 5;
const int PUMP2 = 6;
const int TEMP_SENSOR = 8;

//Shift Registers


//Sensors
const int SENSORS_QTY = 16; // Quantity of sensors.

//Pumps
const int PUMPS_QTY = 16; // Quantity of pumps.

#endif  
