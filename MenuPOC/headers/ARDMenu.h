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
        MenuOption* actualOption;
        MenuDisplay* display;
        ControllerCallback* controllerListener;
        MenuController* controller;

    public:
        ARDMenu(MenuOption* root);
        ~ARDMenu();
        void onEnterPressed(int line);
        void start(volatile bool* flag);
        void onOptionChosen(MenuOption* option);
        void onActionChosen(MenuAction* action);

};



ARDMenu::ARDMenu(MenuOption* root) {
    actualOption = root;
    display = new MenuDisplay();
    controllerListener = new ControllerCallback();
    controller = new MenuController(*controllerListener);
    controller->reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::onEnterPressed(int line) {
    resolveAction(line);
}

void ARDMenu::resolveAction(int line) {
    if (line == getActualOptionNumberOfLines()) {
        goBack();
    }
    else {
        actualOption->getMenuItemAt(line)->onChosen(this);
    }
};

int ARDMenu::getActualOptionNumberOfLines() {
    return actualOption->getNumberOfMenuLines();
};

void ARDMenu::goBack() {
    actualOption = actualOption->_parent;
    controller->reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::start(volatile bool* flag) {
    while (true) {
        display->printOut(actualOption, controller->cursorPosition);
        int userInput = controller->listenToInput(flag);
        if (userInput == 0) {
            controller->up();
        }
        else if (userInput == 1) {
            controller->down();
        }
        else if (userInput == 2) {
            Serial.println("Enter.");
            resolveAction(controller->cursorPosition);
        }
    }
};

void ARDMenu::onOptionChosen(MenuOption* option) {
    actualOption = option;
    controller->reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::onActionChosen(MenuAction* action) {
    action->execute();
};

#endif