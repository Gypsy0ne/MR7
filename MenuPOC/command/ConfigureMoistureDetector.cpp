#include "ConfigureMoistureDetector.h"

void ConfigureMoistureDetector::execute() {
    _moistureDetector->value = ValuePicker(_moistureDetector->value).pickValue();
};