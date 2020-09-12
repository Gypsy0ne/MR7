#ifndef ValuePicker_h
#define ValuePicker_h

class ValuePicker {
    public:
        ValuePicker(int initialValue);
        int pickValue();

    private:
        int actualValue;
}; 

#endif