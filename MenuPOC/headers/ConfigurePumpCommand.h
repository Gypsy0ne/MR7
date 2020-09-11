#include "Pump.h"
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