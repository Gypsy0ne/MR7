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
        MenuOption& parent;

    public:
        void onChosen(Menu menu);
        MenuItem getMenuItemAt(int index);
        list<MenuItem> getOrderedMenuItems();
        int getNumberOfMenuLines();
        string toString();
        int getLengthOfLongestMenuItemTitle();
        
        template<class T>
        void addSubOption(T arg) {
            subOptions.push_back(arg);
        }
        
        template<class T, class ... Args> 
        void addSubOption(T first, Args& ... args) {
            subOptions.push_back(first);
            addSubOption(args...);
        }

        // void addSubOption(const MenuOption* fmt...);
};

#endif