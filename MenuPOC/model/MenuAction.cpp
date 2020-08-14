#include "MenuAction.h"
#include <string>

using namespace std;

void MenuAction::execute() {
    action.execute();
};

string MenuAction::toString() {
    return title;
};

void MenuAction::onChosen(Menu menu) {
    menu.onActionChosen()
}
