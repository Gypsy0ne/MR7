#include "Interface.h"
#include "Config.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "Arduino.h"

#define I2C_ADDR 0x20

LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 3, 4, 5, 6);


	int MenuOption::action(int pos) {
		return _theLayerBehindID;
	}


	int MenuEntry::getValue() {
		return _value;
	}

	int MenuEntry::action(int pos) {
		_value = pos;
		return 0;
	}

	MenuItem* MenuLayer::getItemAt(int i) {
		return &itemsArray[i];
	}


	void Menu::enter(int pos) {
		if (pos) {
			updateLayer(_currentChoice->action(pos));
			_currentChoice = _currentLayer.getItemAt(0);
			_nextChoice = _currentLayer.getItemAt(1);
		}
		else {
			back();
		}
	}

	MenuItem* Menu::updateChoice(int pos) {
		_currentChoice = _currentLayer.getItemAt(pos);
		if (pos < _currentLayer._choices) {
			_nextChoice = _currentLayer.getItemAt(pos + 1);
		} 
		else {
			_nextChoice = nullptr;
		}
		return _currentChoice;
	}

	int Menu::getLayerID() {
		return _currentLayer._ID;
	}

	void Menu::updateLayer(int ID) {
		for (int i = 0; ; i++) {
			if (_layersArr[i]._ID == ID) { // iteration on pointer?
				_currentLayer = _layersArr[i];
			}
		}
	}

	void Menu::back() { // 1 11 111 21 212 etc. %10 
		updateLayer(_currentLayer._ID % 10);
		_currentChoice = _currentLayer.getItemAt(0);
		_nextChoice = _currentLayer.getItemAt(1);
	}


	MenuDisplay::MenuDisplay(Menu* menu) : _menu(menu) {
		lcd.begin(16, 2);
		lcd.setCursor(0, 0);
		lcd.print("MR7");
		Serial.println("Display constructed!");
	}

	void MenuDisplay::printBack() {
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("> BACK");
		lcd.setCursor(0, 1);
		lcd.print(_menu->_currentChoice->_title);
	}

	void MenuDisplay::printItems() {
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("> " + _menu->_currentChoice->_title);
		if (_menu->_currentChoice->_value) {
			lcd.print(": " + _menu->_currentChoice->_value);
		}
		if (_menu->_nextChoice) {
			lcd.setCursor(0, 1);
			lcd.print("> " + _menu->_nextChoice->_title);
		}
	}


int watchController(int _encoderPosition, bool* _buttonPressed) {

}



void interfaceOn() {
	Serial.println("interfaceOn");

	delay(500);


}