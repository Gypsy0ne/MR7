 #include "ConfigurePumpCommand.h"

 void ConfigurePumpCommand::execute() {
        ValuePicker(_pump.value).pickValue();
        _pump.value = ValuePicker(_pump.value).pickValue();
 };