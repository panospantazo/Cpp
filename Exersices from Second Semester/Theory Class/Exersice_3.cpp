#include <iostream>
using namespace std;

int main(void)
{
    int num1 = 10;
    int num2 = 5;
    int sum = num1 + num2;
    int difference = num1 - num2;
    bool greater_than = (num1 > num2);
    bool andOperator = (num1 > 0 && num2 > 0);
    bool orOperator = (num1 > 0 || num2 > 0);
    if(greater_than && difference > 0)
    {
        cout << "mpla mpla mpla" << endl;
    }
    return 0;
}