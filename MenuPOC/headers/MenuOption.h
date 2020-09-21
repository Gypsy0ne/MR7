#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <LinkedList.h>
#include "Menu.h"
#include "ARDMenu.h"
#include "MenuAction.h"
#include "MenuEntry.h"
#include "MenuItem.h"


using namespace std;

class MenuOption : public MenuItem {
    private:
        mutable LinkedList<MenuOption*> *_subOptions;
        LinkedList<MenuEntry*> *_entries;
        LinkedList<MenuAction*> *_actions;


    public:
        MenuOption* _parent;

        String getTitle();

        inline MenuOption(String title, MenuOption* parent) {
            _parent = parent;
            _title = title;
            _entries = new LinkedList<MenuEntry*>();
            _actions = new LinkedList<MenuAction*>();
            _subOptions = new LinkedList<MenuOption*>();
        }
        inline MenuOption(String title, MenuOption* parent, LinkedList<MenuEntry*> *entries) {

            _parent = parent;
            _title = title;
            _entries = entries;
            _actions = new LinkedList<MenuAction*>();
            _subOptions = new LinkedList<MenuOption*>();

        }
        inline MenuOption(String title, MenuOption* parent, LinkedList<MenuAction*> *actions) {

            _parent = parent;
            _title = title;
            _actions = actions;
            _entries = new LinkedList<MenuEntry*>();
            _subOptions = new LinkedList<MenuOption*>();

        }
        
        void onChosen(Menu* menu);
        MenuItem* getMenuItemAt(int index);
        LinkedList<MenuItem*>* getOrderedMenuItems();
        int getNumberOfMenuLines();
        void getLengthOfLongestMenuItemTitle();
        
        template<class T>
        void addSubOption(T* arg) {
            _subOptions->add(arg);
        }

        template<class T, class ... Args> 
        void addSubOption(T* first, Args& ... args) {
            _subOptions->add(first);
            addSubOption(args...);
        }
        // void addSubOption(const MenuOption* fmt...);
};



String MenuOption::getTitle() {
    return _title;
}

void MenuOption::onChosen(Menu* menu) {
    menu->onOptionChosen(this);
}

int MenuOption::getNumberOfMenuLines() {
    return _entries->size() + _subOptions->size() + _actions->size();
}

LinkedList<MenuItem*>* MenuOption::getOrderedMenuItems() {
    LinkedList<MenuItem*> *mergedList = new LinkedList<MenuItem*>();
    for (int i = 0; i < _actions->size(); i++) {
        mergedList->add(_actions->get(i));
    }
    for (int i = 0; i < _subOptions->size(); i++) {
        mergedList->add(_subOptions->get(i));
    }
    for (int i = 0; i < _entries->size(); i++) {
        mergedList->add(_entries->get(i));
    }
    Serial.println((String)"getOrderedMenuItems():" + mergedList->size()); 
    return mergedList;
}

MenuItem* MenuOption::getMenuItemAt(int index) {
    LinkedList<MenuItem*> *menuItemList = getOrderedMenuItems();
    for (int i = 0; i < menuItemList->size(); i++) {
        if (i == index) {
            return menuItemList->get(i);
        }
    }
}

void MenuOption::getLengthOfLongestMenuItemTitle() {
}

#endif