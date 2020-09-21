#ifndef MenuController_h
#define MenuController_h

#include "../../Config.h"
#include "ControllerCallback.h"

class MenuController {
    public:
        MenuController(ControllerCallback controllerListener);
        int cursorPosition;
        void reinitCursor(int optionLinesCount);
        void enter();
        void up();
        void down();
        int listenToInput(volatile bool* flag);

    private:
        int actualOptionLines;
        ControllerCallback _controllerListener;
};

MenuController::MenuController(ControllerCallback controllerListener) {
    _controllerListener = controllerListener;
}

int MenuController::listenToInput(volatile bool* flag) {
    while (1) {
        Serial.println(digitalRead(ENC_BUTTON));
        if (!digitalRead(ENC_BUTTON)) {
          delay(250);
            return 2;
        }
        else if (*flag) {
          delay(250);
          *flag = 0
            return digitalRead(ENC_R);
        }

    }
}

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

#endif
