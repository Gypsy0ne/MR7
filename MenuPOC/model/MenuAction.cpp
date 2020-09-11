#include "MenuAction.h"
#include <string>
#include <iostream>

using namespace std;

void MenuAction::execute() {
    _action.execute();
};

void MenuAction::onChosen(Menu menu) {
    menu.onActionChosen(this);
};
