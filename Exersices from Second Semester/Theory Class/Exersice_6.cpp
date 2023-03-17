#include <iostream>
using namespace std;

int addnumber(int ,int );

int main(void)
{
  int num1,num2,sum;
  cout << "Give two numbers: " << endl;
  cin >> num1 >> num2;
  sum = addnumber(num1,num2);
  cout << "The sum is: " << sum << endl;
  return 0;
}

int addnumber(int a,int b)
{
    return a+b;
}