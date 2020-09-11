#ifndef ARDMENU_H
#define ARDMENU_H

#include "Menu.h"
#include "MenuOption.h"
#include "MenuDisplay.h"
#include "MenuController.h"
#include "ControllerCallback.h"

class ARDMenu : public Menu {
    private:
        void resolveAction(int line);
        int getActualOptionNumberOfLines();
        void goBack();

    public:
        ARDMenu(MenuOption* root);
        void onEnterPressed(int line);
        void start();
        void onOptionChosen(MenuOption option);
        void onActionChosen(MenuAction action);

};

#endif