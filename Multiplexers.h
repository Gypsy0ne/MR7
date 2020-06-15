#ifndef Multiplexers_h
#define Multiplexers_h

// MODEL: CD4051BM https://www.ti.com/lit/ds/symlink/cd4051b.pdf?&ts=1589798832366

void setSensorMuxChannel(int channel); // Sets multiplexer control pins to a state combination unlocking a given channel.
void setPumpMuxChannel(int channel);

#endif

