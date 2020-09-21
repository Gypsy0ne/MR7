#ifndef ValuePicker_h
#define ValuePicker_h

class ValuePicker {
    public:
        ValuePicker(int initialValue);
        int pickValue();

    private:
        int actualValue;
}; 


ValuePicker::ValuePicker(int initialValue) {
    actualValue = initialValue;
}

int ValuePicker::pickValue() {
    unsigned char userInput = 0;
    do {
        Serial.println((String)"actual value: " + actualValue);
        // userInput = control.listenToInput();
        if (userInput == 0) {
            --actualValue;
        }
        if (userInput == 1) {
            ++actualValue;
        }
    } while (userInput != 2);

    return actualValue;
}

#endif