#include "ConfigureMoistureDetector.h"

void ConfigureMoistureDetector::execute() {
    ValuePicker(_moistureDetector.value).pickValue();
    _moistureDetector.value = ValuePicker(_moistureDetector.value).pickValue();
};