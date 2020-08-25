#include <iostream>
#include <string>
#include "ConfigureMoistureDetector.h"
#include "ConfigurePumpCommand.h"
#include "MoistureDetector.h"
#include "Pump.h"
#include "ARDMenu.h"
#include "Menu.h"
#include "MenuAction.h"
#include "MenuEntry.h"
#include "MenuOption.h"

using namespace std;

Menu createMenu() {
    
}

int main() {
    Menu mainMenu = createMenu();
    mainMenu.start();
}

