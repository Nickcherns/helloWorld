#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "And the C++ Extension"};
    int i = 0;

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}