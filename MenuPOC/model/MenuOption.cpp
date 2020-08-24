#include "MenuOption.h"

void MenuOption::onChosen(Menu menu) {
    menu.onOptionChosen(*this);
}

int MenuOption::getNumberOfMenuLines() {
    return entries.size() + subOptions.size() + actions.size();
}

string MenuOption::toString() {
    return ">" + title;
}

list<MenuItem> MenuOption::getOrderedMenuItems() {
    list<MenuItem> mergedList = list<MenuItem>();
    for(MenuItem const& i : actions) {
        mergedList.push_back(i);
    }
    for(MenuItem const& i : subOptions) {
        mergedList.push_back(i);
    }
    for(MenuItem const& i : entries) {
        mergedList.push_back(i);
    }
    return mergedList;
}

MenuItem MenuOption::getMenuItemAt(int index) {

}

int getLengthOfLongestMenuItemTitle() {
    
}