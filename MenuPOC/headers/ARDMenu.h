#ifndef ARDMENU_H
#define ARDMENU_H

#include "Menu.h"
#include "MenuOption.h"
#include "MenuDisplay.h"
#include "MenuController.h"

class ARDMenu : public Menu {
    private:
        MenuOption* actualOption;
        MenuDisplay display;
        MenuController controller;
        void resolveAction(int line);
        int getActualOptionNumberOfLines();
        void goBack();

    public:
        ARDMenu(MenuOption root);
        void start();
        void onOptionChosen(MenuOption option);
        void onActionChosen(MenuAction action);

};

#endif