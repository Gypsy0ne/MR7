#include "MenuOption.h"
#include <iostream>
#include <cstdarg>


void MenuOption::onChosen(Menu menu) {
    menu.onOptionChosen(this);
    cout << "Hejka" << endl;
}

int MenuOption::getNumberOfMenuLines() {
    return _entries.size() + _subOptions.size() + _actions.size();
}

list<MenuItem*> MenuOption::getOrderedMenuItems() { 
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

MenuItem* MenuOption::getMenuItemAt(int index) {
    int i = 0;
    list<MenuItem*> menuItemList = getOrderedMenuItems();
    for(MenuItem* item : menuItemList) {
        if(i++==index) {
            return item;
        }
    }
}

void MenuOption::getLengthOfLongestMenuItemTitle() {
}