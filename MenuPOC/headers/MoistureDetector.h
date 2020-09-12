#ifndef MoistureDetector_h
#define MoistureDetector_h

#include <string>

using namespace std;

//for now components dont have any particular role, they are here to present commanding system
class MoistureDetector {
    public:
        // inline MoistureDetector() {}
        inline MoistureDetector(string n, int v) {
            value = v;
            name = n;
        }
        int value;
    private:
        string name;
};

#endif