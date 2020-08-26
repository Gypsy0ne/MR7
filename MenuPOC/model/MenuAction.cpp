#include "MenuAction.h"
#include <string>

using namespace std;

void MenuAction::execute() {
    _action.execute();
};

string MenuAction::toString() {
    return _title;
};

void MenuAction::onChosen(Menu menu) {
    menu.onActionChosen(*this);
};
