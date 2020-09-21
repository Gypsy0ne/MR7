#ifndef Pump_h
#define Pump_h

//todo add min, max, unit, stepValue
class Pump {
    public:
        // inline Pump() {}
        inline Pump(String n, int v) {
            name = n;
            value = v;
        }
        int value;
    
    private:
        String name;
};

#endif