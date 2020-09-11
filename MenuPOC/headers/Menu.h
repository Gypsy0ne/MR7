#ifndef MENU_H
#define MENU_H

class MenuAction;
class MenuOption;

class Menu {
    public:
        virtual void start();
        virtual void onActionChosen(MenuAction action);
        virtual void onOptionChosen(MenuOption* option);
};

#endif