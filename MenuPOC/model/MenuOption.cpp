#include "MenuOption.h"
#include <cstdarg>

void MenuOption::onChosen(Menu menu) {
    menu.onOptionChosen(*this);
}

int MenuOption::getNumberOfMenuLines() {
    return _entries.size() + _subOptions.size() + _actions.size();
}

string MenuOption::toString() {
    return ">" + _title;
}

list<MenuItem> MenuOption::getOrderedMenuItems() {
    list<MenuItem> mergedList = list<MenuItem>();
    for(MenuItem const& i : _actions) {
        mergedList.push_back(i);
    }
    for(MenuItem const& i : _subOptions) {
        mergedList.push_back(i);
    }
    for(MenuItem const& i : _entries) {
        mergedList.push_back(i);
    }
    return mergedList;
}

MenuItem MenuOption::getMenuItemAt(int index) {
    int i = 0;
    list<MenuItem> menuItemList = getOrderedMenuItems();
    for(MenuItem const& item : menuItemList) {
        if(i++==index) {
            return item;
        }
    }
}

int MenuOption::getLengthOfLongestMenuItemTitle() {
    
}