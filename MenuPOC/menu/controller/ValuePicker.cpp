#include "ValuePicker.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int ValuePicker::pickValue() {
    int userInput = 0;
    do {
        cout << "actual value: " << actualValue << endl;
        userInput = getch();
        // std::getline(); LINUX :: curses.h
        if (userInput == 161) {
            --actualValue;
        }
        if (userInput == 164) {
            ++actualValue;
        }
    } while (userInput != 184);

    return actualValue;
}