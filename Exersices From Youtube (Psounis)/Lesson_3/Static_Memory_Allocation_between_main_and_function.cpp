//Static Memory Allocation between main and function

#include <iostream>
using namespace std;

void f();

int main(void)
{
    int x = 5;

    cout << "Inside main" << endl;
    f();

    return 0;
}

void f()
{
    int y = 3;
    cout << "Inside f";
}