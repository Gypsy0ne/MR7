#include "Config.h"
#include "Sensors.h"
#include "Pumps.h"
#include "Time.h"
#include "Interface.h"
#include "Arduino.h"

// TODO: error control for pumps (measure current between VCC and collectors. Analog reads on both nodes of a resistor in a common control line.)


int readChannels[SENSORS_QTY] = {0}; // Table for sensor reads.
bool sensorFlags[SENSORS_QTY] = {0};
int cycles[SENSORS_QTY] = {0}; // Counts pump activations.
unsigned long t = 0;

volatile uint16_t encoderPosition = 0;
volatile bool buttonPressed = 0;
volatile uint16_t prevEncoderPos = 0;

configData dataSet;
Pump PumpArray[PUMPS_QTY];
MoistureSensor MsArray[SENSORS_QTY];

MenuOption temperature("Temperature", 0, 1), moistureSensors("Moist. sensors", 1, 2), pumps("Pumps", 2, 3);
MenuEntry T1("T1", 0, 50), S1("S1", 0, 50), S2("S2", 1, 55), S3("S3", 2, 60), P1("P1", 0, 5), P2("P2", 1, 6), P3("P3", 2, 7);
MenuOption optArr[3] = { temperature, moistureSensors, pumps };
MenuEntry tempArr[1] = { T1 };
MenuEntry sensArr[3] = { S1, S2, S3 };
MenuEntry pumpArr[3] = { P1, P2, P3 };
MenuLayer layer0(0, 3, optArr), layer1(1, 1, tempArr), layer2(2, 3, sensArr), layer3(3, 3, pumpArr);
MenuLayer layerArr[4] = { layer0, layer1, layer2, layer3 };
Menu* menu = new Menu(layerArr);
MenuDisplay* display = new MenuDisplay(menu);

void isrEncoderMoved() {
    prevEncoderPos = encoderPosition;
    encoderPosition += 2 * digitalRead(ENC_R) - 1;
}

void isrButton() {
    buttonPressed = 1;
}

void setup() {
    Serial.begin(9600);
    pinMode(SR_LATCH, OUTPUT);
    pinMode(SR_DATA, OUTPUT);
    pinMode(SR_SHIFT, OUTPUT);
    pinMode(TEMP_SENSOR, INPUT);
    pinMode(PUMP1, OUTPUT);
    pinMode(PUMP2, OUTPUT);
    pinMode(ENC_L, INPUT);
    pinMode(ENC_R, INPUT);
    pinMode(ENC_BUTTON, INPUT_PULLUP);

    for (int i = 0; i < PUMPS_QTY; i++) {
        PumpArray[i].setParameters(i, dataSet.worktimeGetter(i), i);
        if (i < 7) {
            MsArray[i].setParameters(i, dataSet.thresholdGetter(i), i);
        }
        else {
            MsArray[i].setParameters(i, dataSet.thresholdGetter(i), i, A1);
        }
    }

    attachInterrupt(digitalPinToInterrupt(ENC_L), isrEncoderMoved, FALLING);
    attachInterrupt(digitalPinToInterrupt(ENC_BUTTON), isrButton, FALLING);
}

void setSensorFlags() {
    for (int i = 0; i < SENSORS_QTY; i++) {
        MsArray[i].setFlag();
    }
}

void supplyFlaggedSensors() {
    for (int i = 0; i < SENSORS_QTY; i++) {
        if (MsArray[i].checkFlag()) {
            PumpArray[i].run();
            MsArray[i].clearFlag();
        }
    }
}


void loop() {

    Serial.println(menu->_currentChoice->_title);
    /*setSensorFlags();
    supplyFlaggedSensors();
    Serial.println(digitalRead(ENC_BUTTON));
    t = millis();
    while (!digitalRead(ENC_BUTTON)) {
        if (checkTimeSeconds(3, t)) {
            interfaceOn();
        }
    }*/
}
