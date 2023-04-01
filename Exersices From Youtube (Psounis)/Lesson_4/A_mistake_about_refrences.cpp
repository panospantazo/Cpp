#include <iostream>
using namespace std;

int main(void)
{
    int x = 3, y = 4;
    int &r = x;

    cout << "r = " << r << endl;

    r = y; //Tries to change the refrence to another variable

    cout << "x = " << x << endl;
    return 0;
}