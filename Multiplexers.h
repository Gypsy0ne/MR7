#ifndef Multiplexers_h
#define Multiplexers_h

// MODEL: CD4051BM https://www.ti.com/lit/ds/symlink/cd4051b.pdf?&ts=1589798832366

class Multiplexer {
    protected:
        virtual void setChannel(int channel)=0;
};

class PumpMuxDuo : public Multiplexer {
    public:
        inline PumpMuxDuo(int channel) { setChannel(channel); }
    private:
        void setChannel(int channel);
};

class SensorMuxDuo : public Multiplexer {
    public:
        inline SensorMuxDuo(int channel) { setChannel(channel); }
    private:
        void setChannel(int channel);
};

#endif

