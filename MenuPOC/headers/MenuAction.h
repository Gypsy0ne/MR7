#ifndef MENUACTION_H
#define MENUACTION_H

#include <string>
#include "Command.h"
#include "MenuItem.h"

class MenuAction : public MenuItem {
    private:
        string _title;
        Command _action;

    public:
        inline MenuAction(string title, Command action) { 
            _title = title;
            _action = action;
        }
        void execute();
        string toString();
        void onChosen(Menu menu);

};

#endif