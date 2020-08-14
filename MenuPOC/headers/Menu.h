#ifndef Menu_h
#define Menu_h

using namespace std;

class Menu {
    public:
        virtual void start();
        virtual void onActionChosen();
        virtual void onOptionChosen();
};

#endif