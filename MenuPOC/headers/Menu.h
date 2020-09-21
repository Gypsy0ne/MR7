#ifndef MENU_H
#define MENU_H

class MenuAction;
class MenuOption;

class Menu {
    public:
        virtual void start();
        virtual void onActionChosen(MenuAction* action);
        virtual void onOptionChosen(MenuOption* option);
};

void Menu::start() { }
void Menu::onActionChosen(MenuAction* action) { }
void Menu::onOptionChosen(MenuOption* option) { }

#endif