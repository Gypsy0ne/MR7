#include <iostream>
#include <string>
#include "headers/ConfigureMoistureDetector.h"
#include "headers/ConfigurePumpCommand.h"
#include "headers/MoistureDetector.h"
#include "headers/Pump.h"
#include "headers/ARDMenu.h"
#include "headers/Menu.h"
#include "headers/MenuAction.h"
#include "headers/MenuEntry.h"
#include "headers/MenuOption.h"

using namespace std;

MenuOption* root = new MenuOption("ffp", NULL);
MenuOption* stats = new MenuOption("Stats", root);
MenuOption* config = new MenuOption("Config", root);
MenuEntry* tempEntry[4] = { new MenuEntry("TS1", "30"), new MenuEntry("TS2", "31"), new MenuEntry("TS3", "32"), new MenuEntry("TS4", "33") };
MenuEntry* moistEntry[4] = { new MenuEntry("M1", "20"), new MenuEntry("M2", "21"), new MenuEntry("M3", "22"), new MenuEntry("M4", "23") };
list<MenuEntry*> tempEntries = list<MenuEntry*>();
list<MenuEntry*> moistEntries = list<MenuEntry*>();

Pump* P1 = new Pump("Pompa", 20);
Pump* P2 = new Pump("Cinek", 30);

MoistureDetector* S1 = new MoistureDetector("Wilgotnosc 1", 70); 
MoistureDetector* S2 = new MoistureDetector("Wilgotnosc 2", 80);

list<MenuAction*> pumpList = list<MenuAction*>();
list<MenuAction*> sensorList = list<MenuAction*>();

ARDMenu createMenu() {

    root->addSubOption(stats, config);

    for(int i = 0; i < 4; i++) {
        tempEntries.push_back(tempEntry[i]);
        moistEntries.push_back(moistEntry[i]);
    }
    MenuOption* temperature = new MenuOption("Temperature", stats, tempEntries);
    MenuOption* moisture = new MenuOption("Moisture", stats, moistEntries);
    ConfigurePumpCommand CP1(P1), CP2(P2);
    ConfigureMoistureDetector CS1(S1), CS2(S2);

    MenuAction* pumpAction[2] = { new MenuAction("Configure Pompa", CP1), new MenuAction("Configure Cinek", CP2) };
    MenuAction* sensorAction[2] = { new MenuAction("Config wilgotnosc 1", CS1), new MenuAction("Config wilgotnosc 2", CS2) };


    stats->addSubOption(temperature, moisture);



    for(int i = 0; i < 2; i++) {
        pumpList.push_back(pumpAction[i]);
        sensorList.push_back(sensorAction[i]);
    }
    MenuOption* pumps = new MenuOption("Pumps", config, pumpList);
    MenuOption* sensors = new MenuOption("Moisture Sensors", config, sensorList);


    config->addSubOption(pumps, sensors);

    ARDMenu menuFeedback(root);
    return menuFeedback;
}

int main() {
        ARDMenu mainMenu = createMenu();
        mainMenu.start();
}

