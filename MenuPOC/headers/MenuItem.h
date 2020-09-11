#ifndef MenuItem_h
#define MenuItem_h

#include "Menu.h"

#include <string>
using namespace std;

class MenuItem {
    public:
        string _title;
        virtual void onChosen(Menu menu);
        virtual void vToString();

};

#endif