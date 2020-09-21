#ifndef MENUPOC_H
#define MENUPOC_H

#include "headers/ARDMenu.h"
#include <LinkedList.h>
#include "headers/ConfigureMoistureDetector.h"
#include "headers/ConfigurePumpCommand.h"
#include "headers/MoistureDetector.h"
#include "headers/Pump.h"
//#include "../Pumps.h"
#include "headers/ARDMenu.h"
#include "headers/Menu.h"
#include "headers/MenuAction.h"
#include "headers/MenuEntry.h"
#include "headers/MenuOption.h"


ARDMenu createMenu() {

    MenuOption* root = new MenuOption("ffp", NULL);
    MenuOption* stats = new MenuOption("Stats", root);
    MenuOption* config = new MenuOption("Config", root);
    MenuEntry* tempEntry[4] = { new MenuEntry("TS1", "30"), new MenuEntry("TS2", "31"), new MenuEntry("TS3", "32"), new MenuEntry("TS4", "33") };
    MenuEntry* moistEntry[4] = { new MenuEntry("M1", "20"), new MenuEntry("M2", "21"), new MenuEntry("M3", "22"), new MenuEntry("M4", "23") };
    LinkedList<MenuEntry*>* tempEntries = new LinkedList<MenuEntry*>();
    LinkedList<MenuEntry*>* moistEntries = new LinkedList<MenuEntry*>();

    Pump* P1 = new Pump("Pompa", 20);
    Pump* P2 = new Pump("Cinek", 30);

    MoistureDetector* S1 = new MoistureDetector("Wilgotnosc 1", 70);
    MoistureDetector* S2 = new MoistureDetector("Wilgotnosc 2", 80);

    LinkedList<MenuAction*>* pumpList = new LinkedList<MenuAction*>();
    LinkedList<MenuAction*>* sensorList = new LinkedList<MenuAction*>();

    root->addSubOption(stats, config);

    for (int i = 0; i < 4; i++) {
        tempEntries->add(tempEntry[i]);
        moistEntries->add(moistEntry[i]);
    }

    MenuOption* temperature = new MenuOption("Temperature", stats, tempEntries);
    MenuOption* moisture = new MenuOption("Moisture", stats, moistEntries);
    stats->addSubOption(temperature, moisture);

    ARDMenu menuFeedback(root);
    return menuFeedback;
}

void interfaceOn(volatile bool* flag) {

    while (1) {
        ARDMenu mainMenu = createMenu();
        mainMenu.start(flag);
    }
}

void testFun(volatile bool* flag) {
    while (1) {
        if (*flag) {
            Serial.println("Jest.");
            *flag = 0;
            break;
        }
    }
}

#endif