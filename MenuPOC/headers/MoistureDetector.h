#ifndef MoistureDetector_h
#define MoistureDetector_h



//for now components dont have any particular role, they are here to present commanding system
class MoistureDetector {
    public:
        // inline MoistureDetector() {}
        inline MoistureDetector(String n, int v) {
            value = v;
            name = n;
        }
        int value;
    private:
        String name;
};

#endif