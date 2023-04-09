#include <iostream>
using namespace std;

int sum(int x1 = 0,int x2 = 0,int x3 = 0,int x4 = 0);

int main(void)
{
    cout << sum(1,2,3,4) << endl;
    cout << sum(1,2,3) << endl;
    cout << sum(1,2) << endl;
    cout << sum(1) << endl;
}

int sum(int x1,int x2,int x3,int x4)
{
    return(x1+x2+x3+x4);
}