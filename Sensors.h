#ifndef Sensors_h
#define Sensors_h

#include "Config.h"
#include "OneWire.h"

class Sensor {
    public:
        bool checkFlag() {
            return _flag;
        }
        bool clearFlag() {
            _flag = 0;
        }
    protected:
        int _ID;
        int _minValue;
        int _maxValue;
        bool _flag;
};

class MoistureSensor : Sensor {
    public:
        inline MoistureSensor(int ID, int thresholdPercentage, int muxChannel, int analogPin=A0) {
            _muxChannel = muxChannel;
            _ID = ID;
            _analogPin = analogPin;
            _thresholdPercentage = thresholdPercentage;
            _minValue = WET_THRESHOLD;
            _maxValue = DRY_THRESHOLD;
            _flag = 0;
            _value = 0;
        }
        bool isDry();

    private:
        int readValue();
        int mapValue();
        int _thresholdPercentage;

        int _analogPin;
        int _muxChannel;
        int _value;
};

class TSensorsBus : Sensor { // temperature sensors TODO
    public:
        inline TSensorsBus(int digitalPin) { 
            _digitalPin = TEMP_SENSOR;
            _flag = 0; }
        float callSensors();

    private:
        int _digitalPin;
        byte i;
        byte present = 0;
        byte type_s;
        byte data[12];
        byte addr[8];
};  

#endif  
