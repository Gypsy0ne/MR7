#ifndef ConfigurePumpCommand_h
#define ConfigurePumpCommand_h

#include "Pump.h"
//#include "../../Pumps.h"
#include "ValuePicker.h"
#include "Command.h"

//lcd display reference will be passed during creation and used in value picker initialization
class ConfigurePumpCommand : public Command {
    public:
        void execute();
        inline ConfigurePumpCommand(Pump* pump) : _pump(pump) {
        }

    private:
        Pump* _pump;
};


void ConfigurePumpCommand::execute() {
    _pump->value = ValuePicker(_pump->value).pickValue();
};

#endif