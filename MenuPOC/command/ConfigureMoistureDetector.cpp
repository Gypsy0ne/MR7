#include "ConfigureMoistureDetector.h"
#include "MoistureDetector.h
#include "ValuePicker.h"

void ConfigureMoistureDetector::execute() {
        picker = ValuePicker(moistureDetector.value)
        moistureDetector.value = picker.pickValue()
    }
}