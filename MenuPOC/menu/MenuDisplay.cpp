#include "MenuDisplay.h"

#include <Arduino.h>
#include "MenuItem.h"
#include "MenuOption.h"
#include <string>
#include <list>
using namespace std;

void MenuDisplay::printOut(MenuOption actualOption, int cursorPosition){
    printMenu(MenuOption::getOrderedMenuItems(actualOption));
    printBack();
    printCursorPosition(cursorPosition);
}

void MenuDisplay::printMenu(list<MenuItem> menuItems) {
    for (MenuItem x : menuItems) {
        Serial.println(to_string(x));
    }
}

void MenuDisplay::printBack() {
    Serial.println("BACK<");
}

void MenuDisplay::printCursorPosition(int position) {
    Serial.println((string)"cursor line:" + position);
}