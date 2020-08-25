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
        string _title;
        mutable list<MenuOption> _subOptions;
        list<MenuEntry> _entries;
        list<MenuAction> _actions;

    public:
        MenuOption& _parent;

        inline MenuOption(string title, MenuOption& parent) : _title(title),_parent(parent) {}
        inline MenuOption(string title, MenuOption& parent, list<MenuEntry> entries) : _title(title),_parent(parent),_entries(entries) {}
        inline MenuOption(string title, MenuOption& parent, list<MenuAction> actions) : _title(title),_parent(parent),_actions(actions) {}
        

        void onChosen(Menu menu);
        MenuItem getMenuItemAt(int index);
        list<MenuItem> getOrderedMenuItems();
        int getNumberOfMenuLines();
        string toString();
        int getLengthOfLongestMenuItemTitle();
        
        template<class T>
        void addSubOption(T arg) {
            _subOptions.push_back(arg);
        }

        template<class T, class ... Args> 
        void addSubOption(T first, Args& ... args) {
            _subOptions.push_back(first);
            addSubOption(args...);
        }

        // void addSubOption(const MenuOption* fmt...);
};

#endif