#include "MenuAction.h"
#include <string>
#include <iostream>

using namespace std;

void MenuAction::execute() {
    _action.execute();
};

string MenuAction::toString() {
    return _title;
};

void MenuAction::vToString() {
    cout << _title << endl;
};

void MenuAction::onChosen(Menu menu) {
    menu.onActionChosen(*this);
};
