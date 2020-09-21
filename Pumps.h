#ifndef Pumps_h
#define Pumps_h

#include "Config.h"

//todo add min, max, unit, stepValue

class Pump {
public:
    Pump();
    void setParameters(int ID, int worktime, int channel);
    bool timesUp();
    void activate();
    bool run();
    int _value;
    int _worktime; //seconds


private:
    int _ID;
    int _channel;
    int _cyclesPassed;

    const int _activatingPin1 = PUMP1;
    const int _activatingPin2 = PUMP2;

    unsigned long _timer;

    void on();
    void off();
    // TODO: Error Control (current measurement)
};

#endif  
