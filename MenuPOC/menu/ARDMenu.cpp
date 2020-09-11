#include "ARDMenu.h"

#include <iostream>
#include <conio.h>
using namespace std;

MenuOption* actualOption;
MenuDisplay* display;
ControllerCallback controllerListener;
MenuController controller(controllerListener);

ARDMenu::ARDMenu(MenuOption* root) {
    actualOption = root;
    display = new MenuDisplay;
    controller.reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::onEnterPressed(int line) {
    resolveAction(line);
}

void ARDMenu::resolveAction(int line) {
    if(line == getActualOptionNumberOfLines()) {
        goBack();
    } else {
        onOptionChosen(actualOption->getMenuItemAt(line));
    }
};

int ARDMenu::getActualOptionNumberOfLines() {
    return actualOption->getNumberOfMenuLines();
};

void ARDMenu::goBack() {
    actualOption = actualOption->_parent; // ?
    controller.reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::start() {
    while(true) {
        display->printOut(actualOption, controller.cursorPosition);
        unsigned char userInput = getch();
        if (userInput == 'w') {
            controller.up(); 
        }
        else if (userInput == 's') {
            controller.down(); 
        }
        else if (userInput == 'x') {
            resolveAction(controller.cursorPosition);
        }
    }
};
 
void ARDMenu::onOptionChosen(MenuOption option) {
    actualOption = &option;
    controller.reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::onActionChosen(MenuAction action) {
    action.execute();
};