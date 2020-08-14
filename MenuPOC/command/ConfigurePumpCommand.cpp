 #include "ConfigurePumpCommand.h"
 #include "Pump.h"
 #include "ValuePicker.h"

 void ConfigurePumpCommand::execute() {
        ValuePicker(_pump.value).pickValue();
        _pump.value = ValuePicker(_pump.value).pickValue();
 };