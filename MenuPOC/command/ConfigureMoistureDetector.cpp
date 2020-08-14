#include "ConfigureMoistureDetector.h"
#include "MoistureDetector.h"
#include "ValuePicker.h"

void ConfigureMoistureDetector::execute() {
    ValuePicker(_moistureDetector.value).pickValue();
    _moistureDetector.value = ValuePicker(_moistureDetector.value).pickValue();
};