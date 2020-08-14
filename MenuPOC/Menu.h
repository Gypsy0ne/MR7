// Example program
#include <iostream>
#include <string>

using namespace std;

class StatsMenuEntry {
    protected:
        string _title;
};

class StatsMenuDataEntry: public StatsMenuEntry {
    private:
        string _value;
    
    public:
        StatsMenuDataEntry(string title, string value) {
            _title = title;
            _value = value;
        };
};

class StatsMenuOption: public StatsMenuEntry {
    private:
        StatsMenuEntry *content[];
};

class Menu {
    private:
        StatsMenuEntry stats[];
    
    public:
        Menu(StatsMenuEntry stats[])
}

int main()
{

}
