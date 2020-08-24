#ifndef Sensors_h
#define Sensors_h

#include "Config.h"
#include "OneWire.h"

class Sensor {
    public:
        bool checkFlag();
        bool clearFlag();
    protected:
        int _ID;
        int _minValue;
        int _maxValue;
        bool _flag;
};

class MoistureSensor : Sensor {
    public:
        inline MoistureSensor() {
            _muxChannel = 0;
            _ID = 0;
            _analogPin = A0;
            _thresholdPercentage = 0;
            _minValue = WET_THRESHOLD;
            _maxValue = DRY_THRESHOLD;
            _flag = 0;
            _value = 0;
        }
        void setParameters(int ID, int thresholdPercentage, int muxChannel, int analogPin=A0);
        void setFlag();

    private:
        bool isDry();
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
