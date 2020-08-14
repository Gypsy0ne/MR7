#ifndef MENU_H
#define MENU_H

class Menu {
    public:
        virtual void start();
        virtual void onActionChosen();
        virtual void onOptionChosen();
};

#endif