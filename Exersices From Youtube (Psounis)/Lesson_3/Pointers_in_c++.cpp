//pointers in c++
#include <iostream>
using namespace std;

int main(void)
{
    int x=5;
    int *p = NULL;

    p = &x;
    
    cout << "x = " << x << "(address:" << &x << ")" << endl;
    cout << "*p=" << *p << "(address:" << p << ")" << endl;

    return 0;
}