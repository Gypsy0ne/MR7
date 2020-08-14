#ifndef ValuePicker_h
#define ValuePicker_h

class ValuePicker {
    public:
        ValuePicker(int initialValue);

    private:
        int actualValue;
        int pickValue();
}; 

#endif