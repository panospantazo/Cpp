#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s1("abcd");
    string s2;

    s2 = s1 + s1 + s1;
    cout << s2 << endl;
   
    s2[4] = 'A';

    cout << s2 << endl;
    cout << s1 << endl;

    if(s1 > s2)
    {
        cout << s1;
    }
    else
    {
        cout << s2;
    }

    return 0;
}