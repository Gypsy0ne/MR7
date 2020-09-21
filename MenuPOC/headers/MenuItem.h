#ifndef MenuItem_h
#define MenuItem_h

#include "Menu.h"


class MenuItem {
    public:
        String _title = "-";
        String _value = "-";
        virtual void onChosen(Menu* menu)=0;
};


void MenuItem::onChosen(Menu* menu) { };


#endif