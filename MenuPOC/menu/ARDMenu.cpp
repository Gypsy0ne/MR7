#include "ARDMenu.h"

#include "Menu.h"
#include "MenuOption.h"
#include "MenuDisplay.h"
#include "MenuController.h"

#include <iostream>
#include <conio.h>
using namespace std;

MenuOption* actualOption;
MenuDisplay display;
ControllerCallback controllerListener;
MenuController controller(controllerListener);

ARDMenu::ARDMenu(MenuOption root) {
    actualOption = &root;
    display = MenuDisplay();
    controller.reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::resolveAction(int line) {
    if(line == getActualOptionNumberOfLines()) {
        goBack();
    } else {
        actualOption->getMenuItemAt(line).onChosen(*this); // ?
    }
};

int ARDMenu::getActualOptionNumberOfLines() {
    return actualOption->getNumberOfMenuLines();
};

void ARDMenu::goBack() {
    actualOption->parent; // ?
    controller.reinitCursor(getActualOptionNumberOfLines());
};

void ARDMenu::start() {
    while(true) {
        cout << actualOption << controller.cursorPosition << endl;
        unsigned char userInput = getch();
        if (userInput == 'w') {
            controller.up(); 
        }
        else if (userInput == 's') {
            controller.down(); 
        }
        else if (userInput == 'x') {
            controller.enter(); 
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