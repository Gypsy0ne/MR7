#ifndef ConfigureMoistureDetector_h
#define ConfigureMoistureDetector_h

#include "MoistureDetector.h"
#include "ValuePicker.h"
#include "Command.h"

//lcd display reference will be passed during creation and used in value picker initialization
class ConfigureMoistureDetector : Command {
    public:
        void execute();
        ConfigureMoistureDetector(MoistureDetector moistureDetector);

    private:
        MoistureDetector _moistureDetector;

};

#endif