#include <iostream>
#include <string>
#include "headers/ConfigureMoistureDetector.h"
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
    MenuOption root("MR7 front page", NULL);
    MenuOption stats("Stats", &root);
    MenuOption config("Config", &root);
    root.addSubOption(stats, config);

    MenuEntry tempEntry[4] = {MenuEntry("TS1", "30"), MenuEntry("TS2", "31"), MenuEntry("TS3", "32"), MenuEntry("TS4", "33")};
    MenuEntry moistEntry[4] = {MenuEntry("M1", "20"), MenuEntry("M2", "21"), MenuEntry("M3", "22"), MenuEntry("M4", "23")};
    list<MenuEntry> tempEntries;
    list<MenuEntry> moistEntries;

    for(int i = 0; i < 4; i++) {
        tempEntries.push_back(tempEntry[i]);
        moistEntries.push_back(moistEntry[i]);
    }

    MenuOption temperature("Temperature", &stats, tempEntries);
    MenuOption moisture("Moisture", &stats, moistEntries);
    stats.addSubOption(temperature, moisture);

    Pump P1("Pompa", 20), P2("Cinek", 30);
    ConfigurePumpCommand CP1(P1), CP2(P2);

    MoistureDetector S1("Wilgotnosc 1", 70), S2("Wilgotnosc 2", 80);
    ConfigureMoistureDetector CS1(S1), CS2(S2);

    MenuAction pumpAction[2] = { MenuAction("Configure Pompa", CP1), MenuAction("Configure Cinek", CP2) };
    MenuAction sensorAction[2] = { MenuAction("Config wilgotnosc 1", CS1), MenuAction("Config wilgotnosc 2", CS2) };
    list<MenuAction> pumpList;
    list<MenuAction> sensorList;

    for(int i = 0; i < 2; i++) {
        pumpList.push_back(pumpAction[i]);
        sensorList.push_back(sensorAction[i]);
    }
    
    MenuOption pumps("Pumps", &config, pumpList);
    MenuOption sensors("Moisture Sensors", &config, sensorList);
    config.addSubOption(pumps, sensors);

    return ARDMenu(root);
}

int main() {
    Menu mainMenu = createMenu();
    mainMenu.start();
}

