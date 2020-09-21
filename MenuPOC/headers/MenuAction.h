#ifndef MENUACTION_H
#define MENUACTION_H

#include "Command.h"
#include "MenuItem.h"
#include "Menu.h"


class MenuAction : public MenuItem {
    private:
        Command* _action;

    public:
        inline MenuAction(String title, Command* action) { 
            _title = title;
            _action = action;
        }
        void execute();
        void onChosen(Menu* menu);

};

void MenuAction::execute() {
    _action->execute();
};

void MenuAction::onChosen(Menu* menu) {
    menu->onActionChosen(this);
};

#endif