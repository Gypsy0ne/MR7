#include "MenuDisplay.h"

#include "MenuItem.h"
#include "MenuOption.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

void MenuDisplay::printOut(MenuOption actualOption, int cursorPosition){
    printMenu(actualOption.getOrderedMenuItems());
    printBack();
    printCursorPosition(cursorPosition);
}

void MenuDisplay::printMenu(list<MenuItem> menuItems) {
    for (MenuItem x : menuItems) {
        // Serial.println(to_string(x));
        cout << (string) x << endl;
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