#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <string>
#include "Menu.h"
#include "MenuItem.h"

using namespace std;

class MenuEntry : public MenuItem {
    public:
        inline MenuEntry(string title, string value) {
            _title = title;
            _value = value;
        }
        void onChosen(Menu* menu);   
};

#endif