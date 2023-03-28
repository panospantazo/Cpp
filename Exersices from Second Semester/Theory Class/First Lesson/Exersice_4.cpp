#include <iostream>
using namespace std;
int main(void)
{
    int num1 = 10;
    int num2 = 5;
    int sum,product;
    sum = num1 + num2;
    product = num1 * num2;
    cout << "Sum is: " << sum << endl << "Product is: " << product << endl;
    if(product > 50)
    {
        cout << "Product is more than 50" << endl;
    }
    else
    {
        cout << "Product is equal/less than 50" << endl;
    }
    for(int i=0;i<5;i++)
    {
        cout << "i is now: " << i << endl;
    }
    return 0;    
}