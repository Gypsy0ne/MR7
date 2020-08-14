#ifndef MENUACTION_H
#define MENUACTION_H

#include <string>
#include "Command.h"
#include "MenuItem.h"

class MenuAction : public MenuItem {
    private:
        string title;
        Command action;

    public:
        void execute();
        string toString();
        void onChosen(Menu menu);

};

#endif