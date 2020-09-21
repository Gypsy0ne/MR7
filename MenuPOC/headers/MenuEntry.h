#ifndef MENUENTRY_H
#define MENUENTRY_H

#include "Menu.h"
#include "MenuItem.h"

using namespace std;

class MenuEntry : public MenuItem {
    public:
        inline MenuEntry(String title, String value) {
            _title = title;
            _value = value;
        }
        void onChosen(Menu* menu);   
};


void MenuEntry::onChosen(Menu* menu) {

}

#endif