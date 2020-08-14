
#ifndef MenuDisplay_h
#define MenuDisplay_h

#include "MenuItem.h"
#include "MenuOption.h"
#include <list>
using namespace std;

class MenuDisplay {

    public:
    void printOut(MenuOption actualOption, int cursorPosition);

    private:
    void printMenu(list<MenuItem> menuItems);
    void printBack();
    void printCursorPosition(int position);

};

#endif