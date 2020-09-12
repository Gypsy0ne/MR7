#ifndef MENUACTION_H
#define MENUACTION_H

#include <string>
#include "Command.h"
#include "MenuItem.h"
#include "Menu.h"

using namespace std;

class MenuAction : public MenuItem {
    private:
        Command* _action;

    public:
        inline MenuAction(string title, Command* action) { 
            _title = title;
            _action = action;
        }
        void execute();
        void onChosen(Menu* menu);

};

#endif