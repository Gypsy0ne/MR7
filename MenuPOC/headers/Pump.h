#ifndef Pump_h
#define Pump_h

#include <string>

using namespace std;

//todo add min, max, unit, stepValue
class Pump {
    public:
        // inline Pump() {}
        inline Pump(string n, int v) {
            name = n;
            value = v;
        }
        int value;
    
    private:
        string name;
};

#endif