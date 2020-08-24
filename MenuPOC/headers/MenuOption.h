#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <string>
#include <list>
#include "MenuAction.h"
#include "MenuEntry.h"
#include "MenuItem.h"

using namespace std;


class MenuOption : public MenuItem {
    private:
        string title;
        mutable list<MenuOption> subOptions;
        list<MenuEntry> entries;
        list<MenuAction> actions;

    public:
        MenuOption& parent;
        void onChosen(Menu menu);
        MenuItem getMenuItemAt(int index);
        list<MenuItem> getOrderedMenuItems();
        int getNumberOfMenuLines();
        void addSubOption(const MenuOption* fmt...); // ??
        string toString();
        int getLengthOfLongestMenuItemTitle();
};

#endif