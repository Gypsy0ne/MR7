#include "Temperature.h"
#include "Config.h"
#include "OneWire.h"

OneWire ds(TEMP_SENSOR);

float returnCelsius() {
    byte present = 0;
    byte data[12];
    byte addr[8];
  
    if (!ds.search(addr)) {
        ds.reset_search();
        delay(250);
        return;
    } 
    
    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1);        // start conversion, with parasite power on at the end
    
    delay(1000);     // maybe 750ms is enough, maybe not
    // we might do a ds.depower() here, but the reset will take care of it.
    
    present = ds.reset();
    ds.select(addr);    
    ds.write(0xBE);         // Read Scratchpad

    for(byte i = 0; i < 9; i++) {           // we need 9 bytes
        data[i] = ds.read();
    }

    // Convert the data to actual temperature
    // because the result is a 16 bit signed integer, it should
    // be stored to an "int16_t" type, which is always 16 bits
    // even when compiled on a 32 bit processor.
    int16_t raw = ((data[1] << 8) | data[0]) & ~7;

    float celsius = raw / 16.0;
    // fahrenheit = celsius * 1.8 + 32.0;
    Serial.println((String)"Temperature = " + celsius + "C");
    return celsius;
}
  