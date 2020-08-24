#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <string>
#include "Menu.h"
#include "MenuItem.h"

using namespace std;

class MenuEntry : MenuItem {
    private: 
        string title;
        string value;

    public:
        string toString();
        void onChosen(Menu menu);   
};

#endif