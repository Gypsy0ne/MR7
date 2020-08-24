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

}

MenuItem MenuOption::getMenuItemAt(int index) {

}

int getLengthOfLongestMenuItemTitle() {
    
}