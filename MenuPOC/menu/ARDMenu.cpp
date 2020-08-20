#include "ARDMenu.h"

#include "Menu.h"
#include "MenuOption.h"
#include "MenuDisplay.h"
#include "MenuController.h"

#include <iostream>
#include <conio.h>
using namespace std;

ARDMenu::ARDMenu(MenuOption root) {
    actualOption = &root;
    display = MenuDisplay()

};

void ARDMenu::resolveAction(int line) {

};

int ARDMenu::getActualOptionNumberOfLines() {
    actualOption->getNumberOfMenuLines();
};

void ARDMenu::goBack() {

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

};

void ARDMenu::onActionChosen(MenuAction action) {

};