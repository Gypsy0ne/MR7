#include "Config.h"

class Controller {
public:
	int _encoderPosition = 0;
	bool _buttonPressed = 0;

	void isrEncoderMoved() {
		if (digitalRead(ENC_R)) {
			_encoderPosition++;
		}
		else if (!digitalRead(ENC_R)) {
			_encoderPosition--;
		}
	}

	void isrButton() {
		buttonPressed = 1;
	}

	Controller() {
		attachInterrupt(digitalPinToInterrupt(ENC_L), isrEncoderMoved, FALLING);
		attachInterrupt(digitalPinToInterrupt(ENC_BUTTON), isrButton, FALLING);
	}
	~Controller() {
		detachInterrupt(digitalPinToInterrupt(ENC_L));
		detachInterrupt(digitalPinToInterrupt(ENC_BUTTON));
	}
};

class MenuOption {
	public:
		String _title;
		MenuOption(String title, MenuOption* parent) : _title(title), _parent(parent) {

		}
		
	private:
		MenuOption* _parent;
};

class MenuLayer {
	public:
		MenuLayer(MenuOption layer[], int positionsOnLayer) : _layer[](layer[]), _positionsOnLayer(positionsOnLayer) {
		}

	private:
		int _positionsOnLayer;
		MenuOption _layer[];

};

class MenuDisplay {
	public:
		void Begin() {
			lcd.begin(16, 2);
			lcd.setCursor(0, 0);
			lcd.print("MR7 front page");
		}

		void printBack() {

		}

		void printLayer() {

		}

};

class Menu {
	public:
		MenuOption* actualOption;


};

void interfaceOn() {
	Controller* encoder = new Controller();
}