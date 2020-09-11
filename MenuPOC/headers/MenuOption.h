#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <string>
#include <iostream>
#include <list>
#include "Menu.h"
#include "ARDMenu.h"
#include "MenuAction.h"
#include "MenuEntry.h"
#include "MenuItem.h"


using namespace std;

class MenuOption : public MenuItem {
    private:
        mutable list<MenuOption*> _subOptions;
        list<MenuEntry*> _entries;
        list<MenuAction*> _actions;
        string toString();


    public:
        MenuOption* _parent;

        inline MenuOption(string title, MenuOption* parent) {
            _parent = parent;
            _title = title;
            _entries = list<MenuEntry*>();
            _actions = list<MenuAction*>();
            _subOptions = list<MenuOption*>();
        }
        inline MenuOption(string title, MenuOption* parent, list<MenuEntry*> entries) {

            _parent = parent;
            _title = title;
            _entries = entries;
            _actions = list<MenuAction*>();
            _subOptions = list<MenuOption*>();

        }
        inline MenuOption(string title, MenuOption* parent, list<MenuAction*> actions) {

            _parent = parent;
            _title = title;
            _actions = actions;
            _entries = list<MenuEntry*>();
            _subOptions = list<MenuOption*>();

        }
        
        void onChosen(Menu menu);
        MenuItem getMenuItemAt(int index);
        list<MenuItem*> getOrderedMenuItems();
        int getNumberOfMenuLines();
        void vToString();
        void getLengthOfLongestMenuItemTitle();
        
        template<class T>
        void addSubOption(T* arg) {
            _subOptions.push_back(arg);
        }

        template<class T, class ... Args> 
        void addSubOption(T* first, Args& ... args) {
            _subOptions.push_back(first);
            addSubOption(args...);
        }
        // void addSubOption(const MenuOption* fmt...);
};

#endif