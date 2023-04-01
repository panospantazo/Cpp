//A overloading learning program
#include <iostream>
using namespace std;

int sum(int x,int y);
double sum(double x,double y);

int main(void)
{
    cout << sum(5,3);
    cout << " ";
    cout << sum(1.1,2.2);
    return 0;
}

int sum(int x, int y)
{
    return x+y;
}

double sum(double x, double y)
{
    return x+y;
}