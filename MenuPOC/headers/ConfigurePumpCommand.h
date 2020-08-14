#include "Pump.h"
#include "ValuePicker.h"
#include "Command.h"

//lcd display reference will be passed during creation and used in value picker initialization
class ConfigurePumpCommand : Command {
    public:
        void execute();
        ConfigurePumpCommand(Pump pump);

    private:
        Pump _pump;
};