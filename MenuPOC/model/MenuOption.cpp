#include "MenuOption.h"
#include <iostream>
#include <cstdarg>


void MenuOption::onChosen(Menu menu) {
    menu.onOptionChosen(this);
    cout << "Hejka" << endl;
}

int MenuOption::getNumberOfMenuLines() {
    std::cout << _entries.size() + _subOptions.size() + _actions.size() << endl;
    return _entries.size() + _subOptions.size() + _actions.size();
}

string MenuOption::toString() {
    return ">" + _title;
}

void MenuOption::vToString() {
    std::cout << ">" << _title << std::endl;
}

list<MenuItem*> MenuOption::getOrderedMenuItems() { // <<<< obiekty trac¹ wlasciwosci po wrzuceniu w mergedItems? patrz: resolve action on chosen, ew. onChosen tutaj ^
    list<MenuItem*> mergedList = list<MenuItem*>();
        for (auto const& i : _actions) {
            mergedList.push_back(i);
        }
        for (auto const& i : _subOptions) {
            mergedList.push_back(i);
        }
        for (auto const& i : _entries) {
            mergedList.push_back(i);
        }
    return mergedList;
}

MenuItem MenuOption::getMenuItemAt(int index) {
    int i = 0;
    list<MenuItem*> menuItemList = getOrderedMenuItems();
    for(MenuItem* item : menuItemList) {
        if(i++==index) {
            return *item;
        }
    }
}

void MenuOption::getLengthOfLongestMenuItemTitle() {
}