#ifndef Multiplexers_h
#define Multiplexers_h

// MODEL: CD4051BM https://www.ti.com/lit/ds/symlink/cd4051b.pdf?&ts=1589798832366

class Multiplexer {
    public:
        virtual void setChannel(int channel)=0;
};

class PumpMuxDuo : Multiplexer {
    public:
        void setChannel(int channel);
};

class SensorMuxDuo : Multiplexer {
    public:
        void setChannel(int channel);
};

#endif

