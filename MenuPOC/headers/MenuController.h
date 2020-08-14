#ifndef MenuController_h
#define MenuController_h

#include "ControllerCallback.h"

class MenuController {
    public:
        MenuController(ControllerCallback controllerListener);

    private:
        int cursorPosition;
        int actualOptionLines;
        ControllerCallback controllerListener;

        void enter();
        void up();
        void down();
        void reinitCursor(int optionLinesCount);
};

#endif