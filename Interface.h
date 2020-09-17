#ifndef INTERFACE_H
#define INTERFACE_H

#include "Config.h"
#include "Arduino.h"

class MenuItem {
public:
	String _title;
	int _position;
	int _value;


	virtual int action(int pos) = 0;

};

class MenuOption : public MenuItem {
public:
	inline MenuOption(String title, int pos, int layerBehind) {
		_title = title;
		_position = pos;
		_theLayerBehindID = layerBehind;
		_value = 0;
	}

	int action(int pos);

private:
	int _theLayerBehindID;

};

class MenuEntry : public MenuItem {
public:
	MenuEntry(String title, int pos, int val) {
		_title = title;
		_position = pos;
		_value = val;
	}

	int getValue();

	int action(int pos);

};

class MenuLayer {
public:
	int _ID;
	int _choices;

	inline MenuLayer(int ID, int choices, MenuItem* itemArr) {
		_ID = ID;
		_choices = choices;
		itemsArray = itemArr;
	}

	MenuItem* getItemAt(int i);

private:
	MenuItem* itemsArray;

};

class Menu {
public:
	inline Menu(MenuLayer layers[]) : _layersArr(layers), _currentLayer(layers[0]), _currentChoice(layers[0].getItemAt(0)), _nextChoice(layers[0].getItemAt(1)) {}

	void enter(int pos);

	MenuItem* updateChoice(int pos);

	int getLayerID();
	MenuItem* _currentChoice;
	MenuItem* _nextChoice;

private:
	MenuLayer _currentLayer;
	MenuLayer* _layersArr;

	void updateLayer(int ID);

	void back();
};

class MenuDisplay {
public:
	MenuDisplay(Menu* menu);

	void printBack();

	void printItems();

private:
	Menu* _menu;
};


int watchController(int _encoderPosition, bool* _buttonPresseds);



void interfaceOn();

#endif