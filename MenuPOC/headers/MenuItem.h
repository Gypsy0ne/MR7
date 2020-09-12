#ifndef MenuItem_h
#define MenuItem_h

#include "Menu.h"


class MenuItem {
    public:
        string _title = "-";
        string _value = "-";
        virtual void onChosen(Menu* menu)=0;
};

#endif