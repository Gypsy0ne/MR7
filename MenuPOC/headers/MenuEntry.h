#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <string>
#include "Menu.h"

using namespace std;

class MenuEntry {
    private: 
        string title;
        string value;

    public:
        string toString();
        void onChosen(Menu menu);   
};

#endif