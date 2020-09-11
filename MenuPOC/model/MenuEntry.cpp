#include "MenuEntry.h"
#include <iostream>

string MenuEntry::toString() {
    return _title + ": " + _value;
}

void MenuEntry::vToString() {
    std::cout << _title + ": " + _value << std::endl;
}

void MenuEntry::onChosen(Menu menu) {

}