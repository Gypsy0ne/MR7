#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << "autos ";
    }
    cout << argv[1];
    cout << endl;
}