#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <string>
#include "Menu.h"
#include "MenuItem.h"

using namespace std;

class MenuEntry : public MenuItem {
    private: 
        string toString();
        string _value;

    public:
        inline MenuEntry(string title, string value) {
            _title = title;
            _value = value;
        }
        void vToString();
        void onChosen(Menu menu);   
};

#endif