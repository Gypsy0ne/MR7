#include "MenuDisplay.h"

#include <iostream>
#include <string>
#include <list>
using namespace std;

void MenuDisplay::printOut(MenuOption* actualOption, int cursorPosition){
    printMenu(actualOption->getOrderedMenuItems());
    if (actualOption->_parent) {
        printBack();
    }
    printCursorPosition(cursorPosition);
}

void MenuDisplay::printMenu(list<MenuItem*> menuItems) {
    for (MenuItem* i : menuItems) {
        // Serial.println(to_string(x));
        cout << i->_title;
        if (i->_value != "-") {
            cout << ": " << i->_value;
        }
        cout << endl;
    }
}

void MenuDisplay::printBack() {
    // Serial.println("BACK<");
    cout << "BACK<" << endl;
}

void MenuDisplay::printCursorPosition(int position) {
    // Serial.println((String)"cursor line:" + position);
    cout << "cursor line: " << position << endl;
}