#ifndef ConfigureMoistureDetector_h
#define ConfigureMoistureDetector_h

#include "MoistureDetector.h"
#include "ValuePicker.h"
#include "Command.h"

//lcd display reference will be passed during creation and used in value picker initialization
class ConfigureMoistureDetector : public Command {
    public:
        void execute();
        inline ConfigureMoistureDetector(MoistureDetector* moistureDetector) : _moistureDetector(moistureDetector) {
        }

    private:
        MoistureDetector* _moistureDetector;

};

void ConfigureMoistureDetector::execute() {
    _moistureDetector->value = ValuePicker(_moistureDetector->value).pickValue();
};
#endif