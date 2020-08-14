#ifndef MenuController_h
#define MenuController_h

#include "ControllerCallback.h"

class MenuController {
    public:
        int cursorPosition;
        MenuController(ControllerCallback controllerListener);

    private:
        int actualOptionLines;

        void enter();
        void up();
        void down();
        void reinitCursor(int optionLinesCount);
};

#endif