
#ifndef MenuDisplay_h
#define MenuDisplay_h

#include <LinkedList.h>
#include "MenuItem.h"
#include "MenuOption.h"

class MenuDisplay {

    public:
    void printOut(MenuOption* actualOption, int cursorPosition);

    private:
    void printMenu(LinkedList<MenuItem*>* menuItems);
    void printBack();
    void printCursorPosition(int position);

};

void MenuDisplay::printOut(MenuOption* actualOption, int cursorPosition) {
    printMenu(actualOption->getOrderedMenuItems());
    if (actualOption->_parent) {
        printBack();
    }
    printCursorPosition(cursorPosition);
}

void MenuDisplay::printMenu(LinkedList<MenuItem*>* menuItems) {
    for (int i = 0; i < menuItems->size(); i++) {
        Serial.print(menuItems->get(i)->_title);
        if (menuItems->get(i)->_value != "-") {
            Serial.print((String)": " + menuItems->get(i)->_value);
        }
        Serial.println();
    }
}

void MenuDisplay::printBack() {
    Serial.println("BACK<");
}

void MenuDisplay::printCursorPosition(int position) {
    Serial.println((String)"cursor line:" + position);
}
#endif