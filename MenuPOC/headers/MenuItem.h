#ifndef MenuItem_h
#define MenuItem_h

#include "Menu.h"

class MenuItem {
    public:
    virtual void onChosen(Menu menu);
};

#endif