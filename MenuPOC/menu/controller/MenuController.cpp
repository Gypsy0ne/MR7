#include "MenuController.h"
#include "ControllerCallback.h"

MenuController::MenuController(ControllerCallback controllerListener) {
    int cursorPosition = 0;
    int actualOptionLines = 1;
}

void MenuController::enter() {
    controllerListener.onEnterPressed(cursorPosition);
}

void MenuController::up() {
    if (cursorPosition > 0) {
        cursorPosition--;
    }
}

void MenuController::down() {
    if (cursorPosition < actualOptionLines) {
        cursorPosition++;
    }
}

void MenuController::reinitCursor(int optionLinesCount) {
    cursorPosition = 0;
    actualOptionLines = optionLinesCount;
}
