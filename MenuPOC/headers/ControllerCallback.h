#ifndef ControllerCallback_h
#define ControllerCallback_h

class ControllerCallback {
    public:
        virtual void onEnterPressed(int line);

};

void ControllerCallback::onEnterPressed(int line) { };

#endif