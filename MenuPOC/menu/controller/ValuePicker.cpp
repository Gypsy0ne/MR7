#include "./headers/ValuePicker.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

ValuePicker::ValuePicker(int initialValue) {
    actualValue = initialValue;
}

int ValuePicker::pickValue() {
    unsigned char userInput = 0; 
    do {
        cout << "actual value: " << actualValue << endl;
        userInput = getch();
        // std::getline(); LINUX :: curses.h
        if (userInput == 'w') {
            --actualValue;
        }
        if (userInput == 's') {
            ++actualValue;
        }
    } while (userInput != 'x');

    return actualValue; 
}