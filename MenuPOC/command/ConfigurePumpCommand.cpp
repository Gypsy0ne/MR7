 #include "ConfigurePumpCommand.h"

 void ConfigurePumpCommand::execute() {
        _pump->value = ValuePicker(_pump->value).pickValue();
 };