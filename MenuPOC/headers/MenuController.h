#ifndef MenuController_h
#define MenuController_h

#include "ControllerCallback.h"

class MenuController {
    public:
        MenuController(ControllerCallback controllerListener);
        int cursorPosition;
        
    private:
        int actualOptionLines;
        ControllerCallback _controllerListener;
        void enter();
        void up();
        void down();
        void reinitCursor(int optionLinesCount);
};

#endif