#include <iostream>
using namespace std;

int add(int a,int b)
{
    return a+b;
}
int add(int a,int b,int c)
{
    return a+b+c;
}
double add (double a,double b)
{
    return a+b;
}
double add(double a,double b,double c)
{
    return a+b+c;
}

int main(void)
{
    int num1=5,num2 = 10,num3 = 4;
    double num4=3.14,num5 = 7.21,num6 = 6.13;
    int result1 = add(num1,num2);
    int result2 = add(num1,num2,num3);
    double result3 = add(num4,num5);
    double result4 = add(num4,num5,num6);
    cout << "Result1 = " << result1 << endl << "Result2 = " << result2 << endl << "Result3 = " << result3 << endl << "Result4 = " << result4 << endl;
}
