#ifndef Config_h
#define Config_h

//Overalls
const int DRY_THRESHOLD = 610;
const int WET_THRESHOLD = 255;
const float INPUT_VOLTAGE = 5.0;

//Arduino
const int MUX_CONTROL[3] = {2,3,4}; // Multiplexer control. Table size equals to quantity of control pins. MX_CONTROL[0] = S0(a), MX_CONTROL[1] = S1(b) etc.
const int PUMPING_PIN = 5; // High-state activation of pump-controlling transistors.

//Sensors
const int SENSORS_QTY = 2; // Quantity of sensors.
const int SENSOR_CALIBRATING_TIME = 60;

//Pumps
const int PUMPS_QTY = 2; // Quantity of pumps.

/* struct Channel_Properties
{
    int moisture_threshold_percentage;
    int pump_working_time;
};
*/

#endif  
