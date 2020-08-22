#ifndef Config_h
#define Config_h

//Overalls
const int DRY_THRESHOLD = 610;
const int WET_THRESHOLD = 255;
const float INPUT_VOLTAGE = 5.0;
//                                             0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
const int MOISTURE_THRESHOLD_PERCENTAGE[16] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
const int PUMP_WORKTIME_SECONDS[16] =         {5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5};

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
const int SENSOR_CALIBRATING_TIME = 60;

//Pumps
const int PUMPS_QTY = 16; // Quantity of pumps.

#endif  
