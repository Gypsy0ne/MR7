#ifndef MenuController_h
#define MenuController_h

#include "ControllerCallback.h"

class MenuController {
    public:
        MenuController(ControllerCallback controllerListener);
        int cursorPosition;
        void enter();
        void up();
        void down();

    private:
        int actualOptionLines;
        ControllerCallback _controllerListener;
        void reinitCursor(int optionLinesCount);
};

#endif