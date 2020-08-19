#ifndef MENU_H
#define MENU_H

#include "MenuAction.h"
#include "MenuOption.h"
using namespace std;

class Menu {
    public:
        virtual void start();
        virtual void onActionChosen(MenuAction action);
        virtual void onOptionChosen(MenuOption option);
};

#endif