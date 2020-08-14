#include "MenuController.h"
#include "ControllerCallback.h"

MenuController::MenuController(ControllerCallback controllerListener) {
    _controllerListener = controllerListener;
};

void MenuController::enter() {
    _controllerListener.onEnterPressed(cursorPosition);
};

void MenuController::up() {
    if (cursorPosition > 0) {
        cursorPosition--;
    }
};

void MenuController::down() {
    if (cursorPosition < actualOptionLines) {
        cursorPosition++;
    }
};

void MenuController::reinitCursor(int optionLinesCount) {
    cursorPosition = 0;
    actualOptionLines = optionLinesCount;
};
