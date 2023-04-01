//Dynamic Memory Allocation in c++

#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    int x;
    int *p;

    p = new int;
    if(!p)
    {
        cout << "Error Allocating Memory!" << endl;
        exit(653);
    }
    x = 1;
    *p = 5;

    cout << "x = " << x << "(address:" << &x << ")" << endl;
    cout << "*p = " << *p << "(address:" << p << ")" << endl;

    return 0;
 
}