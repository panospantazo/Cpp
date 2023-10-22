#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s("Initial string");

    cout << s << endl;

    cout << "Give a new string: ";
    getline(cin,s);

    cout << s;

    return 0;
}